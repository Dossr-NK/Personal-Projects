#ifndef _account_management_h_
#define _account_management_h_

typedef struct {
    int balance;
    int creditDebt; // Optional value if the CardData holds 'C'
} BankAccountData;

typedef struct {
    char type; // Either 'D' for debit or 'C' for credit
    BankAccountData bankAccountData;
} CardData;

typedef struct {
    int accountID; // A bank and user specific ID
    char bankName[20];
    short creditScore; // Score of 0 - 850
    int numberOfCards;
    CardData cards[]; // User can have more than 1 card so the array size isn't initialized here
} BankAccount;

void UserBankAccountManagement(BankAccount *bankAccount);
void UserCardDataManagement(CardData *cardData);
void UserBankAccountDataManagement(BankAccountData *bankAccountData);

#endif // _account_management_h_