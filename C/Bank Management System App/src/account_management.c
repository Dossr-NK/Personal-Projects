#include "account_management.h"

#include <stdio.h>
#include <stdbool.h>

void CreateNewCard(BankAccount *bankAccount) {
    int validCards = 0;
    int size = sizeof(bankAccount->cards)/sizeof(bankAccount->cards[0]);
    for(int i = 0; i < size; i++) {
        CardData cardData = bankAccount->cards[i];
        if(cardData.isValid == true) {
            validCards++;
        }
    }

    if(validCards == size) {
        printf("You have reached the maximum number of cards!\n");
        return;
    }

    int newCardAmount = size - validCards;
    printf("\n--------------------------------------\n");
    printf("You can create %d more cards.\n", newCardAmount);

    int newCardIndexes[newCardAmount];
    int index = 0;
    for(int i = 0; i < size; i++) {
        CardData cardData = bankAccount->cards[i];
        if(cardData.isValid == false) {
            newCardIndexes[index] = i;
            index++;
        }
    }

    printf("How many cards would you like to create?\n");
    printf("Enter a number between 1 and %d: ", newCardAmount);
    int amount;
    scanf("%d", &amount);

    while(amount > 0) {
        printf("What type of card would you like to create?\n");
        printf("1. Debit\n");
        printf("2. Credit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                bankAccount->cards[newCardIndexes[amount - 1]].isValid = true;
                bankAccount->cards[newCardIndexes[amount - 1]].type = 'D';
                bankAccount->cards[newCardIndexes[amount - 1]].balance = 0;
                bankAccount->cards[newCardIndexes[amount - 1]].creditDebt = 0;
                break;
            case 2:
                bankAccount->cards[newCardIndexes[amount - 1]].isValid = true;
                bankAccount->cards[newCardIndexes[amount - 1]].type = 'C';
                bankAccount->cards[newCardIndexes[amount - 1]].balance = 0;
                printf("How much credit debt would you like to have?\n");
                printf("Enter a number: ");
                int creditDebt;
                scanf("%d", &creditDebt);
                bankAccount->cards[newCardIndexes[amount - 1]].creditDebt = creditDebt;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        amount--;
    }

    printf("You have created %d cards.\n", newCardAmount);

}

void DeleteCard(BankAccount *bankAccount) {
    int validCards = 0;
    int size = sizeof(bankAccount->cards)/sizeof(bankAccount->cards[0]);
    for(int i = 0; i < size; i++) {
        CardData cardData = bankAccount->cards[i];
        if(cardData.isValid == true) {
            validCards++;
        }
    }

    if(validCards == 0) {
        printf("You have no cards to delete!\n");
        return;
    }

    int newCardIndexes[validCards];
    int index = 0;
    for(int i = 0; i < size; i++) {
        CardData cardData = bankAccount->cards[i];
        if(cardData.isValid == true) {
            newCardIndexes[index] = i;
            index++;
        }
    }

    printf("\n--------------------------------------\n");
    printf("You have %d cards.\n", validCards);
    printf("Which card would you like to delete?\n\n");
    int cardNum = 1;
    for(int i = 0; i < size; i++) {
        CardData cardData = bankAccount->cards[i];
        if(cardData.isValid == false) {
            continue;
        }
        printf("Card %d:\n", cardNum);
        cardNum++;
        printf("Type: %c\n", cardData.type);
        printf("Balance: %d\n", cardData.balance);
        printf("Credit debt: %d\n\n", cardData.creditDebt);
    }
    printf("Enter the number of the card you would like to delete: ");
    int cardNumber;
    scanf("%d", &cardNumber);
    
    if(cardNumber > validCards) {
        printf("Invalid card number!\n");
        return;
    }

    bankAccount->cards[newCardIndexes[cardNumber - 1]].isValid = false;
    bankAccount->cards[newCardIndexes[cardNumber - 1]].type = ' ';
    bankAccount->cards[newCardIndexes[cardNumber - 1]].balance = 0;
    bankAccount->cards[newCardIndexes[cardNumber - 1]].creditDebt = 0;
    printf("You have deleted card %d.\n", cardNumber);
}

void AccessCardData(BankAccount *bankAccount) {
    int size = sizeof(bankAccount->cards)/sizeof(bankAccount->cards[0]);
    printf("\n--------------------------------------\n");
    printf("You have %d cards.\n", size);
    printf("Which card would you like to access?\n\n");

    int cardNum = 1;
    for(int i = 0; i < size; i++) {
        CardData cardData = bankAccount->cards[i];
        if(cardData.isValid == false) {
            continue;
        }
        printf("Card %d:\n", cardNum);
        cardNum++;
        printf("Type: %c\n", cardData.type);
        printf("Balance: %d\n", cardData.balance);
        printf("Credit debt: %d\n\n", cardData.creditDebt);
    }
    printf("Enter the number of the card you would like to access: ");
    int cardNumber;
    scanf("%d", &cardNumber);

    if(cardNumber > size) {
        printf("Invalid card number!\n");
        return;
    }

    printf("\nWhat would you like to do?\n");
    printf("1. Deposit money from savings account\n");
    printf("2. Withdraw money from card\n");
    printf("3. Go back\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("How much would you be depositing?\n");
        double amount;
        scanf("%lf", &amount);
        bankAccount->cards[cardNumber - 1].balance += amount;
        bankAccount->savingsAccountBalance -= amount;
        printf("Your new balance is %d.\n", bankAccount->cards[cardNumber - 1].balance);
        printf("Your new savings account balance is %d.\n", bankAccount->savingsAccountBalance);
    } else if(choice == 2) {
        printf("How much would you be withdrawing?\n");
        double amount;
        scanf("%lf", &amount);
        bankAccount->cards[cardNumber - 1].balance -= amount;
        bankAccount->savingsAccountBalance += amount;
        printf("Your new balance is %d.\n", bankAccount->cards[cardNumber - 1].balance);
        printf("Your new savings account balance is %d.\n", bankAccount->savingsAccountBalance);
    } else if(choice == 3) {
        return;
    } else {
        printf("Invalid choice!\n");
    }

}

void AccessSavingsAccount(BankAccount *bankAccount) {
    printf("\n--------------------------------------\n");
    printf("You currently have %d in your savings account.\n", bankAccount->savingsAccountBalance);
    printf("What would you like to do?\n");
    printf("1. Deposit money\n");
    printf("2. Withdraw money\n");
    printf("3. Go back\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("How much would you be depositing?\n");
        double amount;
        scanf("%lf", &amount);
        bankAccount->savingsAccountBalance += amount;
        printf("Your new balance is %d.\n", bankAccount->savingsAccountBalance);
    } else if(choice == 2) {
        printf("How much would you be withdrawing?\n");
        double amount;
        scanf("%lf", &amount);
        bankAccount->savingsAccountBalance -= amount;
        printf("Your new balance is %d.\n", bankAccount->savingsAccountBalance);
    } else if(choice == 3) {
        return;
    } else {
        printf("Invalid choice!\n");
    }

}

void UserBankAccountManagement(BankAccount *bankAccount) {

    bool isDone = true;
    do {

        int validCards = 0;
        int size = sizeof(bankAccount->cards)/sizeof(bankAccount->cards[0]);
        for(int i = 0; i < size; i++) {
            CardData cardData = bankAccount->cards[i];
            if(cardData.isValid == true) {
                validCards++;
            }
        }
        
        printf("\n--------------------------------------\n");
        printf("You have %d cards.\n", validCards);
        printf("What would you like to do?\n");
        printf("1. Create a new card\n");
        printf("2. Delete a card\n");
        printf("3. Access card data\n");
        printf("4. Access savings account\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                CreateNewCard(bankAccount);
                break;
            case 2:
                DeleteCard(bankAccount);
                break;
            case 3:
                AccessCardData(bankAccount);
                break;
            case 4:
                AccessSavingsAccount(bankAccount);
                break;
            case 5:
                isDone = false;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(isDone);
}