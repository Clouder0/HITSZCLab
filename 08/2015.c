#include <stdio.h>
#include <string.h>

const char* menu = "1.Input record\n\
2.Sort and list records in reverse order by user name\n\
3.Search records by user name\n\
4.Calculate and list per capita income and expenses\n\
5.List records which have more expenses than per capita expenses\n\
6.List all records\n\
0.Exit";

typedef struct
{
    int id, income, outcome;
    char username[11];
} User;

User records[11];
int record_num, isum, osum;

char s[110];

int input_record()
{
    fgets(s, 110, stdin);
    if (sscanf(s, "%d %s %d %d", &records[record_num].id, records[record_num].username, &records[record_num].income, &records[record_num].outcome) != 4) {
        puts("Input error! Please retry.");
        return 0;
    }
    if(records[record_num].id < 10000 || records[record_num].id > 99999) {
        puts("Input error! Please retry.");
        return 0;
    }
    isum += records[record_num].income;
    osum += records[record_num].outcome;
    ++record_num;
    return 1;
}

void input_records()
{
    puts("Please input the number of records:");
    fgets(s, 110, stdin);
    int input_num;
    if (sscanf(s, "%d", &input_num) != 1 || input_num < 1 || record_num + input_num > 10) {
        puts("Invalid input!");
        return;
    }
    puts("Please input in the format of ID, username, income, outcome:");
    while (input_num > 0)
        input_num -= input_record();
}

void output_record(User* record)
{
    printf("%d %s %d %d\n", record->id, record->username, record->income, record->outcome);
}

void sort_records()
{
    // Bubble Sort
    for (int i = 0; i < record_num; ++i)
        for (int j = 0; j < record_num - i - 1; ++j)
            if (strcmp(records[j].username, records[j + 1].username) < 0) {
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

void list_records()
{
    for (int i = 0; i < record_num; ++i)
        output_record(records + i);
}
int main()
{
    while (1) {
        puts(menu);
        int choice;
        fgets(s, 110, stdin);
        int ret = sscanf(s, "%d", &choice);
        if (ret != 1 || (choice < 0 || choice > 6)) {
            puts("Invalid input! Please retry.");
        } else {
            switch (choice) {
            case 0:
                return 0;
            case 1:
                input_records();
                break;
            case 2:
                sort_records();
                list_records();
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
                        output_record(ret);
                }
                break;
            case 4:
                printf("Average income: %.2f\nAverage outcome: %.2f\n", 1.0 * isum / record_num, 1.0 * osum / record_num);
                break;
            case 5:
                double avg = 1.0 * osum / record_num;
                for (int i = 0; i < record_num; ++i)
                    if (records[i].outcome > avg)
                        output_record(records + i);
                break;
            case 6:
                list_records();
                break;
            }
            puts("Done.");
            puts("");
        }
    }
    return 0;
}