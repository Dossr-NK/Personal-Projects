#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account_management.h"
#include "user_management.h"

// Define file location for the data file
const char* fileLocation =  "C:\\Users\\natha\\Desktop\\Personal-Projects\\C"
                            "\\Bank Management System App\\src\\txtfiles\\data.txt";

int main(int argc, char **argv){

    CardData cardData1 = {'D', 1000, 0};
    CardData cardData2 = {'C', 2000, 300};
    CardData cardData3 = {'C', 3000, 500};

    BankAccount bankAccount1;
    bankAccount1.accountID = 1;
    strcpy(bankAccount1.bankName, "Chase");
    bankAccount1.creditScore = 750;
    bankAccount1.cards[0] = cardData1;
    bankAccount1.cards[1] = cardData2;
    bankAccount1.cards[2] = cardData3;

    BankAccount bankAccount2;
    bankAccount2.accountID = 2;
    strcpy(bankAccount2.bankName, "Bank of America");
    bankAccount2.creditScore = 800;
    bankAccount2.cards[0] = cardData1;
    bankAccount2.cards[1] = cardData2;
    bankAccount2.cards[2] = cardData3;

    User user;
    user.isRegistered = true;
    strcpy(user.username, "test");
    strcpy(user.password, "test");
    strcpy(user.name, "test");
    user.age = 18;
    user.isAccompaniedByAdult = true;

    if(user.bankAccounts == NULL) {
        printf("Error allocating memory for bank accounts!\n");
        exit(EXIT_FAILURE);
    }

    user.bankAccounts[0] = bankAccount1;
    user.bankAccounts[1] = bankAccount2;

    FILE* file = fopen( fileLocation , "wb");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    int wrote = fwrite(&user, sizeof(User), 1, file);
    printf("Wrote %d bytes to file.\n", wrote);
    fclose(file);

    // First read the data from the file, if there is data, if not the user will be requested to register
    User initUser;
    // Read file and get data
    file = fopen( fileLocation , "rb");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    if(fread(&initUser, sizeof(User), 1, file) != 1) {
        printf("Error reading file!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fclose(file);

    printf("User data read from file!\n");
    printf("Username: %s\n", initUser.username);
    printf("Password: %s\n", initUser.password);
    printf("Name: %s\n", initUser.name);
    printf("Age: %d\n", initUser.age);
    printf("Is logged in: %d\n", initUser.isLoggedIn);
    printf("Is accompanied by adult: %d\n", initUser.isAccompaniedByAdult);
    printf("Bank account 1 ID: %d\n", initUser.bankAccounts[0].accountID);
    printf("Bank account 1 name: %s\n", initUser.bankAccounts[0].bankName);
    printf("Bank account 1 credit score: %d\n", initUser.bankAccounts[0].creditScore);
    printf("Bank account 1 card 1 type: %c\n", initUser.bankAccounts[0].cards[0].type);
    printf("Bank account 1 card 1 balance: %d\n", initUser.bankAccounts[0].cards[0].balance);
    printf("Bank account 1 card 1 credit debt: %d\n", initUser.bankAccounts[0].cards[0].creditDebt);
    printf("Bank account 1 card 2 type: %c\n", initUser.bankAccounts[0].cards[1].type);
    printf("Bank account 1 card 2 balance: %d\n", initUser.bankAccounts[0].cards[1].balance);
    printf("Bank account 1 card 2 credit debt: %d\n", initUser.bankAccounts[0].cards[1].creditDebt);
    printf("Bank account 1 card 3 type: %c\n", initUser.bankAccounts[0].cards[2].type);
    printf("Bank account 1 card 3 balance: %d\n", initUser.bankAccounts[0].cards[2].balance);
    printf("Bank account 1 card 3 credit debt: %d\n", initUser.bankAccounts[0].cards[2].creditDebt);
    printf("Bank account 2 ID: %d\n", initUser.bankAccounts[1].accountID);
    printf("Bank account 2 name: %s\n", initUser.bankAccounts[1].bankName);
    printf("Bank account 2 credit score: %d\n", initUser.bankAccounts[1].creditScore);
    printf("Bank account 2 card 1 type: %c\n", initUser.bankAccounts[1].cards[0].type);
    printf("Bank account 2 card 1 balance: %d\n", initUser.bankAccounts[1].cards[0].balance);
    printf("Bank account 2 card 1 credit debt: %d\n", initUser.bankAccounts[1].cards[0].creditDebt);    
    printf("Bank account 2 card 2 type: %c\n", initUser.bankAccounts[1].cards[1].type);
    printf("Bank account 2 card 2 balance: %d\n", initUser.bankAccounts[1].cards[1].balance);
    printf("Bank account 2 card 2 credit debt: %d\n", initUser.bankAccounts[1].cards[1].creditDebt);
    printf("Bank account 2 card 3 type: %c\n", initUser.bankAccounts[1].cards[2].type);
    printf("Bank account 2 card 3 balance: %d\n", initUser.bankAccounts[1].cards[2].balance);
    printf("Bank account 2 card 3 credit debt: %d\n", initUser.bankAccounts[1].cards[2].creditDebt);

    // Clears the terminal for easier readability
    // system("clear");

    // Start of program
    printf("Hello to the Bank Management System App!\n");
    printf("----------------------------------------\n\n\n");

    return 0;
}
