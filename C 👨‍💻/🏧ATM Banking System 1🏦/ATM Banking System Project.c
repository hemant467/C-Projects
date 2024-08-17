/*ATM Banking System Project Using C*/

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

#define MAX_TRANSACTIONS 100  // Maximum number of transactions to store

// Structure to store transaction details
struct Transaction {
    char type[10];       // Type of transaction (Withdrawal/Deposit)
    float amount;        // Transaction amount
    float balance_after; // Balance after the transaction
};

void main()
{
    int pin = 9876, option, entered_pin, count = 0, transaction_count = 0;
    float amount = 1, balance = 8765;
    int continue_transaction = 1;
    char name[50];  // Array to store the user's name
    struct Transaction transactions[MAX_TRANSACTIONS];  // Array to store transaction history
    time_t now;

    time(&now);
    printf("\n");
    printf("\t\t\t\t\t       %s", ctime(&now));  // current time and date will appear at the top
    printf("\n\t\t\t******************WELCOME TO ATM*******************");
    printf("\n\t\t\t*******Designed & Developed by HEMANT KATTA********");

    // Prompt the user for their name
    printf("\n\nPlease enter your name: ");
    gets(name);  // Store the user's name in the 'name' array

    while(pin != entered_pin)
    {
        printf("\n\nPlease enter your 4 digit pin: ");
        scanf("%d", &entered_pin);

        if(entered_pin != pin)
        {
            Beep(500, 450);
            printf("Invalid pin!!!");
        }

        count++;
        if(count == 3 && pin != entered_pin)
        { 
            exit(0);
        }
    }

    // Display the user's name once the correct PIN is entered
    printf("\n\n\t\tHello, %s! Welcome to your account.", name);

    while(continue_transaction != 0)
    {
        printf("\n\n\t\t\t*************Available Transactions************");
        printf("\n\n\t\t1. Withdrawal");
        printf("\n\t\t2. Deposit");
        printf("\n\t\t3. Check Balance");
        printf("\n\t\t4. Transaction History");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n\t\tEnter the amount: ");
                scanf("%f", &amount);  // Input as a float

                if(balance < amount)
                {
                    printf("\n\tSorry, insufficient balance!!!");
                }
                else
                {
                    balance -= amount;
                    printf("\n\t\tYou have withdrawn Rs.%.2f \n\t\tYour new balance is Rs.%.2f", amount, balance);
                    // Store the transaction details
                    strcpy(transactions[transaction_count].type, "Withdraw");
                    transactions[transaction_count].amount = amount;
                    transactions[transaction_count].balance_after = balance;
                    transaction_count++;
                }
                break;

            case 2:
                printf("\n\t\tPlease enter the amount: ");
                scanf("%f", &amount);  // Input as a float
                balance += amount;
                printf("\n\t\tYou have deposited Rs.%.2f \n\t\tYour new balance is Rs.%.2f", amount, balance);
                // Store the transaction details
                strcpy(transactions[transaction_count].type, "Deposit");
                transactions[transaction_count].amount = amount;
                transactions[transaction_count].balance_after = balance;
                transaction_count++;
                break;

            case 3:
                printf("\n\t\tYour balance is Rs.%.2f", balance);
                break;

            case 4:
                printf("\n\t\tTransaction History:\n");
                int i;  // Declare 'i' outside the for loop
                for(i = 0; i < transaction_count; i++) {
                    printf("\n\t\t%s: Rs.%.2f \n\t\tBalance after: Rs.%.2f", 
                           transactions[i].type, 
                           transactions[i].amount, 
                           transactions[i].balance_after);
                }
                if(transaction_count == 0) {
                    printf("\n\t\tNo transactions yet.");
                }
                break;

            default:
                Beep(500, 450);
                printf("\n\t\tInvalid Option!!!");
                break;
        }

        printf("\n\n\t\tDo you wish to perform another transaction? Press 1[Yes], 0[No]: ");
        scanf("%d", &continue_transaction);
    }
    printf("\n\t\tTHANK YOU, %s :)", name);  // Personalize the thank you message with the user's name
    printf("\n\t\t\t*******Designed & Developed by HEMANT KATTA********");
}


/*
OUTPUT:


 Sat Aug 17 11:48:08 2024

                        ******************WELCOME TO ATM*******************
                        *******Designed & Developed by HEMANT KATTA********

Please enter your name: Happy


Please enter your 4 digit pin: 9876


                Hello, Happy! Welcome to your account.

                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 3

                Your balance is Rs.8765.00
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 123.25

                You have withdrawn Rs.123.25
                Your new balance is Rs.8641.75
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 123.34

                You have withdrawn Rs.123.34
                Your new balance is Rs.8518.41
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 8516.41

                You have withdrawn Rs.8516.41
                Your new balance is Rs.2.00
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 2

                Please enter the amount: 98

                You have deposited Rs.98.00
                Your new balance is Rs.100.00
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 55.65

                You have withdrawn Rs.55.65
                Your new balance is Rs.44.35
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 3

                Your balance is Rs.44.35
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 45

        Sorry, insufficient balance!!!
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 44.35

                You have withdrawn Rs.44.35
                Your new balance is Rs.0.00
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 1

                Enter the amount: 1

        Sorry, insufficient balance!!!
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 3

                Your balance is Rs.0.00
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History

        Enter your choice: 4

                Transaction History:

                Withdraw: Rs.123.25
                Balance after: Rs.8641.75
                Withdraw: Rs.123.34
                Balance after: Rs.8518.41
                Withdraw: Rs.8516.41
                Balance after: Rs.2.00
                Deposit: Rs.98.00
                Balance after: Rs.100.00
                Withdraw: Rs.55.65
                Balance after: Rs.44.35
                Withdraw: Rs.44.35
                Balance after: Rs.0.00
                
                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 0

                THANK YOU, Happy :)
                *******Designed & Developed by HEMANT KATTA********
--------------------------------
*/
