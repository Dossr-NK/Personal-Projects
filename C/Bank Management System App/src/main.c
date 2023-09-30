#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account_management.h"
#include "user_management.h"

int main(int argc, char **argv){
    printf("\n\nHello to the Bank Management System App!\n");
    printf("----------------------------------------\n\n\n");
    
    BankAccountData bankAccountData1 = {1000, 0};
    BankAccountData bankAccountData2 = {2000, 300};
    BankAccountData bankAccountData3 = {3000, 500};

    CardData cardData1 = {'D', bankAccountData1};
    CardData cardData2 = {'C', bankAccountData2};
    CardData cardData3 = {'C', bankAccountData3};

    BankAccount bankAccount1;
    bankAccount1.accountID = 1;
    strcpy(bankAccount1.bankName, "Chase");
    bankAccount1.creditScore = 750;
    bankAccount1.numberOfCards = 3;

    bankAccount1.cards = (CardData *)malloc(sizeof(CardData) * bankAccount1.numberOfCards);
    
    if(bankAccount1.cards == NULL) {
        printf("Error allocating memory for bank account cards!\n");
        exit(EXIT_FAILURE);
    }

    bankAccount1.cards[0] = cardData1;
    bankAccount1.cards[1] = cardData2;
    bankAccount1.cards[2] = cardData3;

    User user;
    user.isRegistered = true;
    strcpy(user.username, "test");
    strcpy(user.password, "test");
    strcpy(user.name, "test");
    user.age = 18;
    user.isAccompaniedByAdult = true;
    user.numberOfBankAccounts = 1;

    user.bankAccounts = (BankAccount *)malloc(sizeof(BankAccount) * user.numberOfBankAccounts);

    if(bankAccount1.cards == NULL) {
        printf("Error allocating memory for bank accounts!\n");
        exit(EXIT_FAILURE);
    }

    user.bankAccounts[0] = bankAccount1;
    
    Login(&user);
    UserAccessBankAccount(&user);
    

    free(user.bankAccounts);
    free(bankAccount1.cards);

    return 0;
}
