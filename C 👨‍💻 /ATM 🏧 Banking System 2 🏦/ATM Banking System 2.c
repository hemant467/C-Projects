/*ATM Banking System 2 Project Using C*/

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
    char account_type[10];  // Array to store the account type (Savings/Current)
    struct Transaction transactions[MAX_TRANSACTIONS];  // Array to store transaction history
    time_t now;

    time(&now);
    printf("\n");
    printf("\t\t\t\t\t       %s", ctime(&now));  // Current time and date will appear at the top
    printf("\n\t\t\t******************WELCOME TO ATM*******************");
    printf("\n\t\t\t*******Designed & Developed by HEMANT KATTA********");

    // Prompt the user for their name
    printf("\n\nPlease enter your name: ");
    gets(name);  // Store the user's name in the 'name' array

    // Prompt the user to select an account type
    printf("\n\nPlease select your account type (Savings/Current): ");
    gets(account_type);  // Store the account type in the 'account_type' array

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

    // Display the user's name and account type once the correct PIN is entered
    printf("\n\n\t\tHello, %s! Welcome to your %s account.", name, account_type);

    while(continue_transaction != 0)
    {
        printf("\n\n\t\t\t*************Available Transactions************");
        printf("\n\n\t\t1. Withdrawal");
        printf("\n\t\t2. Deposit");
        printf("\n\t\t3. Check Balance");
        printf("\n\t\t4. Transaction History");
        printf("\n\t\t5. Change PIN");  // Option to change the PIN
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
                if(transaction_count == 0) {
                    printf("\n\t\tNo transactions yet.");
                } else {
                    int i;  // Declare 'i' outside the for loop
                    for(i = 0; i < transaction_count; i++) {
                        printf("\n\t\t%s: Rs.%.2f \n\t\tBalance after: Rs.%.2f", 
                               transactions[i].type, 
                               transactions[i].amount, 
                               transactions[i].balance_after);
                    }
                }
                break;

            case 5:
                printf("\n\t\tEnter your current PIN: ");
                scanf("%d", &entered_pin);

                if(entered_pin == pin)
                {
                    printf("\n\t\tEnter your new PIN: ");
                    scanf("%d", &pin);
                    printf("\n\t\tPIN changed successfully!");
                }
                else
                {
                    Beep(500, 450);
                    printf("\n\t\tIncorrect PIN. Returning to the main menu.");
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
    printf("\n\t\tTHANK YOU, %s for using your %s account :)", name, account_type);  // Personalize the thank you message with the user's name and account type
    printf("\n\t\t\t*******Designed & Developed by HEMANT KATTA********");
}

/*

OUTPUT :

                                               Sat Aug 17 12:10:36 2024

                        ******************WELCOME TO ATM*******************
                        *******Designed & Developed by HEMANT KATTA********

Please enter your name: Happy


Please select your account type (Savings/Current): savings


Please enter your 4 digit pin: 9876


                Hello, Happy! Welcome to your savings account.

                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 3

                Your balance is Rs.8765.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 2

                Please enter the amount: 10000

                You have deposited Rs.10000.00
                Your new balance is Rs.18765.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 2

                Please enter the amount: 4557389

                You have deposited Rs.4557389.00
                Your new balance is Rs.4576154.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 56478

                You have withdrawn Rs.56478.00
                Your new balance is Rs.4519676.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 3446

                You have withdrawn Rs.3446.00
                Your new balance is Rs.4516230.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 9861

                You have withdrawn Rs.9861.00
                Your new balance is Rs.4506369.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 2

                Please enter the amount: 564728

                You have deposited Rs.564728.00
                Your new balance is Rs.5071097.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 859873

                You have withdrawn Rs.859873.00
                Your new balance is Rs.4211224.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 857634

                You have withdrawn Rs.857634.00
                Your new balance is Rs.3353590.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 3350590

                You have withdrawn Rs.3350590.00
                Your new balance is Rs.3000.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 4

                Transaction History:

                Deposit: Rs.10000.00
                Balance after: Rs.18765.00
                Deposit: Rs.4557389.00
                Balance after: Rs.4576154.00
                Withdraw: Rs.56478.00
                Balance after: Rs.4519676.00
                Withdraw: Rs.3446.00
                Balance after: Rs.4516230.00
                Withdraw: Rs.9861.00
                Balance after: Rs.4506369.00
                Deposit: Rs.564728.00
                Balance after: Rs.5071097.00
                Withdraw: Rs.859873.00
                Balance after: Rs.4211224.00
                Withdraw: Rs.857634.00
                Balance after: Rs.3353590.00
                Withdraw: Rs.3350590.00
                Balance after: Rs.3000.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 5

                Enter your current PIN: 7382

                Incorrect PIN. Returning to the main menu.

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 5

                Enter your current PIN: 9876

                Enter your new PIN: 7382

                PIN changed successfully!

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 3

                Your balance is Rs.3000.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 1

                Enter the amount: 2000

                You have withdrawn Rs.2000.00
                Your new balance is Rs.1000.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 2

                Please enter the amount: 1000

                You have deposited Rs.1000.00
                Your new balance is Rs.2000.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 1


                        *************Available Transactions************

                1. Withdrawal
                2. Deposit
                3. Check Balance
                4. Transaction History
                5. Change PIN

        Enter your choice: 2

                Please enter the amount: 2000

                You have deposited Rs.2000.00
                Your new balance is Rs.4000.00

                Do you wish to perform another transaction? Press 1[Yes], 0[No]: 0

                THANK YOU, Happy for using your savings account :)
                        *******Designed & Developed by HEMANT KATTA********

*/
