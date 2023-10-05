#ifndef _account_management_h_
#define _account_management_h_

typedef struct {
    char type; // Either 'D' for debit or 'C' for credit
    int balance;
    int creditDebt; // Optional value if the CardData holds 'C'
} CardData;

typedef struct {
    int accountID; // A bank and user specific ID
    char bankName[20];
    short creditScore; // Score of 0 - 850
    // int numberOfCards; Initially a number to allow for dynamic allocation of the cards array, however, cause too much issues so it was removed
    CardData cards[5]; // User can have up to 5 cards
} BankAccount;

void CreateNewCard(BankAccount *bankAccount);
void DeleteCard(BankAccount *bankAccount);
void AccessCardData(CardData *cardData);
void UserBankAccountManagement(BankAccount *bankAccount);

#endif // _account_management_h_