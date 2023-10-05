#include "account_management.h"

#include <stdio.h>

/*
 * CreateNewCard is a function to create a new card for the user.
 * Input: bankAccount is a pointer to the bank account of the user
 * Output: None
*/
void CreateNewCard(BankAccount *bankAccount) {
    // Create a new card
}

/*
 * DeleteCard is a function to delete a card for the user.
 * Input: bankAccount is a pointer to the bank account of the user
 * Output: None
*/
void DeleteCard(BankAccount *bankAccount) {
    // Delete a card
}

void AccessCardData(CardData *cardData) {
    // Access card data
}

/*
 * UserBankAccountManagement is a function to allow the user to create, delete, and modify their bank accounts, mainly the number of cards as well as access each cards' data.
 * Input: bankAccount is a pointer to the bank account of the user
 * Output: None   
 */
void UserBankAccountManagement(BankAccount *bankAccount) {
    printf("You have %d cards.\n", sizeof(bankAccount->cards));
    printf("What would you like to do?\n");
    printf("1. Create a new card\n");
    printf("2. Delete a card\n");
    printf("3. Access card data\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            // Create a new card
            break;
        case 2:
            // Delete a card
            break;
        case 3:
            // Modify a card
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}