/*
  Name: Tsherque Lee Age:18 years old--Tech class-
  Convert.c
  Writing a atm transaction
   The program must call function for balance, withdraw, deposit, quit
   */

#include <stdio.h>
#include <stdlib.h>

/* first list function prototypes...*/

float amount = 10000;
float withdraw;
char ch;
float deposit;
int Quit;

float check_balance(float balance);
float withdrawal(float withdraw);
float deposite_put(float deposit);
int Quit_end(int Quit);

int transaction(void);

int main(void)
{

    int pin, repeat; //the user should not be alllowed to continue program unless password is correct
    printf("Please enter pin: ");
    fflush(stdout);
    scanf("%d", &pin);
    printf("\n");

    while (pin != 1520)
    {
        printf("Invalid input\n");
        printf("Please enter pin again: ");
        fflush(stdout);
        scanf("%d", &pin);
        printf("\n");
    }

    printf("You can now continue...\n\n"); //once password is correct program continues

    do
    {
        repeat = transaction();
    } while (repeat == 1);

    return 0;
}

int transaction(void)
{

    int choice, exit_loop = 0, inner_loop = 1;

    while (exit_loop == 0)
    {

        printf("********************************************************************\n");
        printf("****************Welcome to NEWBORN BANK ATM Services****************\n");
        printf("***************         SELECT OPTIONS             *****************\n");
        printf("********************************************************************\n");
        printf("\t\t[1] Check Balance\n");
        printf("\t\t[2] Withdraw Cash\n");
        printf("\t\t[3] Deposit Cash\n");
        printf("\t\t[4] Quit\n");
        printf("\n********************************************************************\n");
        printf("\t\tEnter your number: "); //displaying answer requested nu user
        fflush(stdout);
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {

        case 1:

            printf("\nYOUR BALANCE ON YOUR ACCOUNT IS: %f\n\n", amount);
            exit_loop = 1;
            break;

        case 2:

            while (inner_loop == 1)
            {
                printf("Please enter amount to withdraw: ");
                fflush(stdout);
                scanf("%f", &withdraw);
                printf("\n");

                if ((int)withdraw % 100 != 0)
                {
                    printf("ENTER THE AMOUNT IN MULTIPLES OF 100.\n\n");
                }
                else if (amount < 500)
                {
                    printf("INSUFFICENT BALANCE LESS THAN 500$\n\n");
                    inner_loop = 0;
                }
                else if (withdraw > amount)
                {
                    printf("There is insuffient Balance in account.\n\n");
                    inner_loop = 0;
                }
                else
                {
                    amount = amount - withdraw;
                    printf("COLLECT CASH BELOW\n");
                    printf("YOUR BALANCE IS: %f\n\n", amount);
                    inner_loop = 0;
                }
            }
            exit_loop = 1;
            break;

        case 3:

            printf("Please enter amount to deposit: ");
            fflush(stdout);
            scanf("%f", &deposit);
            printf("\n");
            amount = deposit + amount;
            printf("Thank you for depositing, new balance is: %f\n\n", amount);
            exit_loop = 1;
            break;

        case 4:

            printf("**THANKS FOR USING OUR ATM SERVICE**\n");
            return 0;

        default:
            printf("INVALID NUMBER.\n\n");
        }
    }

    printf("DO U WISH TO HAVE ANOTHER TRANSCATION? (y/n): ");
    fflush(stdout);
    ch = getchar();
    printf("\n");
    if (ch == 'y' || ch == 'Y')
    {
        return 1;
    }
    else
    {
        printf("THANKS FOR USING OUT ATM SERVICE\n");
        return 0;
    }
}

/*in this function the balance is 1000 user need to display balance on screen using function */
float check_balance(float balance)
{
    return (amount);
}
/* in this function user will enter how much they want to withdraw*/
float withdrawal(float withdraw)
{
    return (amount -= withdraw);
}
/*in this function user will enter out how they want to deposit using function call*/
float deposite_put(float deposit)
{
    return (amount += deposit);
}
/* in this function user will use to exit program */
int Quit_end(int Quit)
{
    return (Quit);
}
