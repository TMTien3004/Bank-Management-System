#include "system.h"

int main()
{
    int continue_var;
    int position, from, to;
    do
    {
        MainMenu();
        int choice;

        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AddAcc();
            break;
        case 2:
            printf("Enter account number you want to edit: ");
            scanf("%d", &position);
            EditAcc(position - 1);
            break;
        case 3:
            printf("Enter account number you want to delete: ");
            scanf("%d", &position);
            DeleteAcc(position - 1);
            break;
        case 4:
            printf("Enter account number you want to recharge your money: ");
            scanf("%d", &position);
            MoneyRecharge(position - 1);
            break;
        case 5:
            printf("Enter account number you want to withdrawl your money: ");
            scanf("%d", &position);
            MoneyWithdrawal(position - 1);
            break;
        case 6:
            printf("Enter your account number: ");
            scanf("%d", &from);
            printf("Enter the account number you want to tranfer your money to: ");
            scanf("%d", &to);
            MoneyTransfer(from - 1, to - 1);
            break;
        case 7:
            ShowListOfAccount();
            break;
        case 8:
            TextFile();
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
        }

        printf("\nContinue? Yes: 1| No: 0: ");
        scanf("%d", &continue_var);
    } while (continue_var != 0);
    return 0;
}
