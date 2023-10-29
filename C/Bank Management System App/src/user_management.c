#include "user_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Login(User *user){
    if(!user->isRegistered){
        printf("\nYou are unregistered, please register first!\n");
        Register(user);
    }
    // Create temporary variables to check if the username and password are correct
    username tempUsername;
    password tempPassword;
    bool isUserLoggedIn = false;
    short loginAttempts = 1;

    do {

        printf("\nPlease login before accessing your bank data!\n");
        printf("Enter username: ");
        scanf("%s", tempUsername);
        printf("Enter password: ");
        scanf("%s", tempPassword);

        // Check if the username and password are correct
        if(strcmp(user->username, tempUsername) == 0 && strcmp(user->password, tempPassword) == 0){
            printf("Login successful!\n");
            isUserLoggedIn = true;
        } else {
            printf("Login failed!\n");
            printf("----------------------------------------\n");
            loginAttempts++;
        }

    } while(loginAttempts < MAX_LOGIN_ATTEMPTS && !isUserLoggedIn);

    if(!isUserLoggedIn){
        printf("You have exceeded the maximum number of login attempts!\n");
        user->isLoggedIn = false;
    } else {
        user->isLoggedIn = true;
        UserManagement(user);
    }

}

void Register(User *user) {
    printf("\n------------------------------------------------\n");
    printf("\nPlease register before accessing your bank data!\n");
    printf("Firstly, what is your age?");
    scanf("%d", &user->age);

    if(user->age < 18){
        printf("You must be accompanied by an adult in order to register.\n");
        printf("Is there an adult with you? (y/n)");

        char answer;
        scanf("%c", &answer);

        if(answer == 'y'){
            user->isAccompaniedByAdult = true;
        } else {
            user->isAccompaniedByAdult = false;
        }
    } else {
        user->isAccompaniedByAdult = true;
    } 

    printf("Great, now we will ask about your registration information:\n");
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    printf("Enter name: ");
    scanf("%s", user->name);

    user->isRegistered = true;

    printf("Registration successful!\n");
}

void UserManagement(User *user) {

    do{
        printf("\n--------------------------------------\n");
        printf("Welcome to the user management system!\n");
        printf("What would you like to do?\n");
        printf("1. Manage your bank accounts\n");
        printf("2. Change password\n");
        printf("3. Change username\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                UserAccessBankAccount(user);
                break;
            case 2:
                ChangePassword(user);
                break;
            case 3:
                ChangeUsername(user);
                break;
            case 4:
                Logout(user);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(user->isLoggedIn);
}

void UserAccessBankAccount(User *user) {
    printf("\n--------------------------------------\n");
    printf("You have %d bank accounts.\n", sizeof(user->bankAccounts)/sizeof(user->bankAccounts[0]));
    for(int i = 0; i < sizeof(user->bankAccounts)/sizeof(user->bankAccounts[0]); i++) {
        printf("Bank account %d's name: %s\n", i + 1, user->bankAccounts[i].bankName);
    }
    printf("Which bank account would you like to access?\n");
    printf("Enter the name of the bank where your account is: ");

    char bankAccountName[20];
    scanf("%s", &bankAccountName);

    BankAccount bankAccount;
    for(int i = 0; i < sizeof(user->bankAccounts)/sizeof(user->bankAccounts[0]); i++) {
        if(strcmp(user->bankAccounts[i].bankName, bankAccountName) == 0) {
            bankAccount = user->bankAccounts[i];
        }
    }

    printf("\n--------------------------------------\n");
    printf("Currently accessing bank account at %s.\n", bankAccount.bankName);
    printf("AccountID: %d\n", bankAccount.accountID);
    printf("Credit score: %d\n", bankAccount.creditScore);
    printf("Savings account balance: %d\n", bankAccount.savingsAccountBalance);
    printf("Here is a list of your cards:\n\n");

    for(int i = 0; i < sizeof(bankAccount.cards)/sizeof(bankAccount.cards[0]); i++) {
        CardData cardData = bankAccount.cards[i];
        printf("Card %d:\n", i + 1);
        printf("Type: %c\n", cardData.type);
        printf("Balance: %d\n", cardData.balance);
        printf("Credit debt: %d\n\n", cardData.creditDebt);
    }

    do{
        printf("What would you like to do?\n");
        printf("1. Manage your Bank Account\n");
        printf("2. Logout\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                UserBankAccountManagement(&bankAccount);
                break;
            case 2:
                Logout(user);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(user->isLoggedIn);
}

void Logout(User *user) {
    user->isLoggedIn = false;
    printf("You have been logged out! The program will now exit.\n");
    exit(0);
}

bool ChangePassword(User *user) {

    password tempPassword;
    short changeAttempts = 0;

    printf("\n--------------------------------------\n");
    printf("You will now be changing your password.\n");
    
    do {

        printf("Please enter previous password: ");
        scanf("%s", tempPassword);
    
        if(strcmp(tempPassword, user->password) != 0) {
            printf("Incorrect password, please try again.\n");
            changeAttempts++;
        } else {
            password newPassword;
            printf("Enter new password: ");
            scanf("%s", newPassword);
            strcpy(user->password, newPassword);
            printf("Password change successful!\n");
            break;
        }

    } while(changeAttempts < MAX_PASSWORD_CHANGE_ATTEMPTS);

    if(changeAttempts == MAX_PASSWORD_CHANGE_ATTEMPTS) {
        printf("You have run out of password change attempts, please try again later\n");
        return false;
    }

    return true;
}

bool ChangeUsername(User *user) {

    username tempUsername;
    short changeAttempts = 0;

    printf("\n--------------------------------------\n");
    printf("You will now be changing your username.\n");
    
    do {

        printf("Please enter previous username: ");
        scanf("%s", tempUsername);
    
        if(strcmp(tempUsername, user->username) != 0) {
            printf("Incorrect username, please try again.\n");
            changeAttempts++;
        } else {
            username newUsername;
            printf("Enter new username: ");
            scanf("%s", newUsername);
            strcpy(user->username, newUsername);
            printf("Username change successful! Your new username is %s.\n", newUsername);
            break;
        }

    } while(changeAttempts < MAX_USERNAME_CHANGE_ATTEMPTS);

    if(changeAttempts == MAX_USERNAME_CHANGE_ATTEMPTS) {
        printf("You have run out of username change attempts, please try again later.\n");
        return false;
    }

    return true;
}

User InitializeDefaultUser() {
    // Define default user
    User default_user = {
        .isRegistered = false,
        .age = 0,
        .isLoggedIn = false,
        .isAccompaniedByAdult = false,
    };
    
    // Copy default values to strings
    strcpy(default_user.username, "");
    strcpy(default_user.password, "");
    strcpy(default_user.name, "");
    
    // Initialize bank accounts
    for (int i = 0; i < 3; i++) {
        default_user.bankAccounts[i].isValid = false;
        default_user.bankAccounts[i].accountID = 0;
        strcpy(default_user.bankAccounts[i].bankName, "");
        default_user.bankAccounts[i].creditScore = 0;
        default_user.bankAccounts[i].savingsAccountBalance = 0;
        
        for (int j = 0; j < 5; j++) {
            default_user.bankAccounts[i].cards[j].isValid = false;
            default_user.bankAccounts[i].cards[j].type = 'D';
            default_user.bankAccounts[i].cards[j].balance = 0;
            default_user.bankAccounts[i].cards[j].creditDebt = 0;
        }
    }

    return default_user;
}