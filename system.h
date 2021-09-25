#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

int count_arr[max] = {0};

struct client
{
    int acc_no;
    char name[20];
    char gender[2];
    int age;
    char phone_num[10];
    long balance;
};

struct client clientrecord[max];

void MainMenu()
{
    system("clear");
    printf("=============================================\n");
    printf("|     BANKING MANAGEMENT SYSTEM VER 1.0     |\n");
    printf("=============================================\n");
    printf("|  1. Add Account                           |\n");
    printf("|  2. Edit Account                          |\n");
    printf("|  3. Delete Account                        |\n");
    printf("|  4. Recharge Money                        |\n");
    printf("|  5. Withdraw Money                        |\n");
    printf("|  6. Transfer Money                        |\n");
    printf("|  7. Show list of all accounts             |\n");
    printf("|  8. Save file                             |\n");
    printf("=============================================\n\n");
}

void AddAcc()
{
    int choice;
    char temp[20];
    int position;

    system("clear");
    for (int i = 0; i < max; i++)
    {
        if (count_arr[i] == 0)
        {
            position = i;
            break;
        }
    }

    clientrecord[position].acc_no = position + 1;
    count_arr[position] = 1;

    printf("\nEnter your full name: ");
    fflush(stdin);
    gets(temp);
    strcpy(clientrecord[position].name, temp);

    printf("Enter gender (M/F): ");
    fflush(stdin);
    gets(temp);
    strcpy(clientrecord[position].gender, temp);

    printf("Enter age: ");
    scanf("%d", &clientrecord[position].age);

    printf("Enter phone number: ");
    scanf("%s", clientrecord[position].phone_num);

    printf("Your account number is: %d", clientrecord[position].acc_no);
    printf("\n\nAccount created successfully!\n\n");
}

void EditAcc(int position)
{
    int choice;
    char temp[20];

    system("clear");
    if (clientrecord[position].acc_no == position + 1)
    {
        printf("Which information do you want to edit?\n1. Edit all\n2. Name\n3. Gender\n4. Age\n5. Phone Number\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter your full name: ");
            fflush(stdin);
            gets(temp);
            strcpy(clientrecord[position].name, temp);

            printf("Enter gender (M/F): ");
            fflush(stdin);
            gets(temp);
            strcpy(clientrecord[position].gender, temp);

            printf("Enter age: ");
            scanf("%d", &clientrecord[position].age);

            printf("Enter phone number: ");
            scanf("%s", clientrecord[position].phone_num);
            break;

        case 2:
            printf("\nEnter your full name: ");
            fflush(stdin);
            gets(temp);
            strcpy(clientrecord[position].name, temp);
            break;

        case 3:
            printf("Enter gender (M/F): ");
            fflush(stdin);
            gets(temp);
            strcpy(clientrecord[position].gender, temp);
            break;

        case 4:
            printf("Enter age: ");
            scanf("%d", &clientrecord[position].age);
            break;

        case 5:
            printf("Enter phone number: ");
            scanf("%s", clientrecord[position].phone_num);
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    else
        printf("Account does not exist!\n");
}

void DeleteAcc(int position)
{
    int choice;
    system("clear");
    if (clientrecord[position].acc_no == position + 1)
    {
        printf("Are you sure? (Yes: 1 || No: 0): ");
        scanf("%d", &choice);
        if (choice == 1)
            count_arr[position] = 0;
        printf("\nAccount deleted successfully!\n\n");
    }
    else
        printf("Account does not exist!\n");
}

void MoneyRecharge(int position)
{
    long amount;
    system("clear");
    printf("Enter your amount: ");
    scanf("%ld", &amount);

    clientrecord[position].balance += amount;
    printf("\nMoney recharged successfully!\n\n");
}

void MoneyWithdrawal(int position)
{
    long amount;
    system("clear");
    printf("Enter your amount: ");
    scanf("%ld", &amount);

    if (amount > clientrecord[position].balance)
        printf("\nInsufficient Money!\n");
    else
        clientrecord[position].balance -= amount;
    printf("\nMoney withdrawed successfully!\n\n");
}

void MoneyTransfer(int from, int to)
{
    long amount;
    system("clear");
    printf("Enter your amount: ");
    scanf("%ld", &amount);

    if (amount > clientrecord[from].balance)
        printf("\nInsufficient Money!\n");
    else
    {
        clientrecord[from].balance -= amount;
        clientrecord[to].balance += amount;
    }
    printf("\nMoney transferred successfully!\n\n");
}

void ShowInfoAccount(int position)
{
    //Show info 1 account
    printf("\nAccount Number: %d\n", clientrecord[position].acc_no);
    printf("Name: %-20s\n", clientrecord[position].name);
    printf("Gender: %s\n", clientrecord[position].gender);
    printf("Age: %d\n", clientrecord[position].age);
    printf("Phone Number: %s\n", clientrecord[position].phone_num);
    printf("Balance: %ld$\n\n\n", clientrecord[position].balance);
    printf("\n");
}

void ShowListOfAccount()
{
    system("clear");
    printf("==============================================\n");
    printf("|                ACCOUNT LIST                |\n");
    printf("==============================================\n");
    for (int i = 0; i < max; i++)
    {
        if (count_arr[i] == 1)
            ShowInfoAccount(i);
    }
}

void TextFile()
{
    FILE *fptr;
    fptr = fopen("Account.txt", "w");

    for (int position = 0; position < clientrecord[position].acc_no; position++)
    {
        fprintf(fptr, "\nAccount Number: %d\n", clientrecord[position].acc_no);
        fprintf(fptr, "Name: %s\n", clientrecord[position].name);
        fprintf(fptr, "Gender: %s\n", clientrecord[position].gender);
        fprintf(fptr, "Age: %d\n", clientrecord[position].age);
        fprintf(fptr, "Phone Number: %s\n", clientrecord[position].phone_num);
        fprintf(fptr, "Balance: %ld$\n", clientrecord[position].balance);
        fprintf(fptr, "\n");
    }
    fclose(fptr);
    printf("\nFile saved successfully!\n\n");
}
