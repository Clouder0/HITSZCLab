
#include <stdio.h>
#include <string.h>

const char* menu = "1.Input record\n\
2.Sort and list records lexigraphically by user name\n\
3.Search records by user name\n\
4.Calculate and list per capita income and expenses\n\
5.List records which have more expenses than per capita expenses\n\
6.List all records\n\
7.Save to File\n\
8.Load from File\n\
0.Exit";

typedef struct
{
    int id, income, outcome;
    char username[11];
} User;

User records[11];
int record_num, isum, osum;

char s[110];

int input_record(FILE* fin)
{
    fgets(s, 110, fin);
    if (sscanf(s, "%d %s %d %d", &records[record_num].id, records[record_num].username, &records[record_num].income, &records[record_num].outcome) != 4) {
        puts("Input error! Please retry.");
        return 0;
    }
    if (records[record_num].id < 10000 || records[record_num].id > 99999) {
        puts("Input error! Please retry.");
        return 0;
    }
    isum += records[record_num].income;
    osum += records[record_num].outcome;
    ++record_num;
    return 1;
}

void input_records(FILE* f, int from_terminal)
{
    if (from_terminal)
        puts("Please input the number of records:");
    fgets(s, 110, f);
    int input_num;
    if (sscanf(s, "%d", &input_num) != 1 || input_num < 1 || record_num + input_num > 10) {
        puts("Invalid input!");
        return;
    }
    if (from_terminal)
        puts("Please input in the format of ID, username, income, outcome:");
    while (input_num > 0)
        input_num -= input_record(f);
}

void output_record(User* record, FILE* f)
{
    fprintf(f, "%d %s %d %d\n", record->id, record->username, record->income, record->outcome);
}

int cmp_username(const User* a, const User* b)
{
    return strcmp(a->username, b->username);
}

int cmp_id(const User* a, const User* b)
{
    return a->id - b->id;
}

void sort_records(int cmp(const User* a, const User* b))
{
    // Bubble Sort
    for (int i = 0; i < record_num; ++i)
        for (int j = 0; j < record_num - i - 1; ++j)
            if (cmp(&records[j], &records[j + 1]) > 0) {
                User temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
}

User* find_record(char* target)
{
    for (int i = 0; i < record_num; ++i)
        if (strcmp(records[i].username, target) == 0)
            return records + i;
    return NULL;
}

void list_records(FILE* f)
{
    for (int i = 0; i < record_num; ++i)
        output_record(records + i, f);
}

void save_records()
{
    // puts("Please enter the file location to save to:");
    // fgets(s, 110, stdin);
    FILE* fp = fopen("records.txt", "w+");
    if (fp == NULL) {
        puts("Error opening file!");
        return;
    }
    fprintf(fp, "%d\n", record_num);
    sort_records(cmp_id);
    list_records(fp);
    fclose(fp);
    puts("Saved.");
}

void load_records()
{
    // puts("Please enter the file location to load from:");
    // fgets(s, 110, stdin);
    FILE* fp = fopen("records.txt", "r");
    if (fp == NULL) {
        puts("Error opening file!");
        return;
    }
    input_records(fp, 0);
    fclose(fp);
    puts("Loaded.");
    list_records(stdout);
}

int main()
{
    while (1) {
        puts(menu);
        int choice;
        fgets(s, 110, stdin);
        int ret = sscanf(s, "%d", &choice);
        if (ret != 1 || (choice < 0 || choice > 8)) {
            puts("Invalid input! Please retry.");
        } else {
            double avg;
            switch (choice) {
            case 0:
                return 0;
            case 1:
                input_records(stdin, 1);
                break;
            case 2:
                sort_records(cmp_username);
                list_records(stdout);
                break;
            case 3:
                puts("Please input your target username:");
                char target[11];
                fgets(s, 110, stdin);
                if (sscanf(s, "%s", target) != 1)
                    puts("Invalid input!");
                else {
                    User* ret = find_record(target);
                    if (ret == NULL)
                        puts("No such record!");
                    else
                        output_record(ret, stdout);
                }
                break;
            case 4:
                printf("Average income: %.2f\nAverage outcome: %.2f\n", 1.0 * isum / record_num, 1.0 * osum / record_num);
                break;
            case 5:
                avg = 1.0 * osum / record_num;
                for (int i = 0; i < record_num; ++i)
                    if (records[i].outcome > avg)
                        output_record(records + i, stdout);
                break;
            case 6:
                sort_records(cmp_id);
                list_records(stdout);
                break;
            case 7:
                save_records();
                break;
            case 8:
                load_records();
                break;
            }
            puts("Done.");
            puts("");
        }
    }
    return 0;
}