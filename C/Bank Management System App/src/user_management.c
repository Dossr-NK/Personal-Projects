#include "user_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Login function is used to authenticate and login the user into the system.
Input: Pointer to the user object
Output: None
*/
void Login(User *user){
    if(!user->isRegistered){
        printf("\nYou are unregistered, please register first!\n");
        Register(user);
    }

    // Create temporary variables to check if the username and password are correct
    username tempUsername;
    password tempPassword;
    bool isUserLoggedIn = false;
    short loginAttempts = 0;

    do {

        printf("\nPlease login before accessing your bank data!\n");
        printf("Enter username: ");
        scanf("%s", tempUsername);
        printf("Enter password: ");
        scanf("%s", tempPassword);

        // Check if the username and password are correct
        if(strcmp(user->username, tempUsername) == 0 && strcmp(user->password, tempPassword) == 0){
            printf("Login successful!\n\n");
            isUserLoggedIn = true;
        } else {
            printf("Login failed!\n\n\n");
            loginAttempts++;
        }

    } while(loginAttempts < MAX_LOGIN_ATTEMPTS && !isUserLoggedIn);

    if(!isUserLoggedIn){
        printf("You have exceeded the maximum number of login attempts!\n");
        user->isLoggedIn = false;
    } else {
        user->isLoggedIn = true;
    }

}

/*
Register function is used to register the user into the system if they aren't already.
Input: Pointer to the user object
Output: Boolean value indicating if the user is registered or not
*/
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
        printf("\n\n--------------------------------------\n");
        printf("Welcome to the user management system!\n");
        printf("What would you like to do?\n");
        printf("1. Manage your bank accounts\n");
        printf("2. Change password\n");
        printf("3. Change username\n");
        printf("4. Logout\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                UserAccessBankAccount(user);
            case 2:
                ChangePassword(user);
            case 3:
                ChangeUsername(user);
            case 4:
                Logout(user);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(user->isLoggedIn);
}

/*
 * UserAccessBankAccount function is used to allow the user to access any of their bank accounts.
 * Input: Pointer to the user object.
 * Output: None.
 */
void UserAccessBankAccount(User *user) {
    printf("You have %d bank accounts.\n", sizeof(user->bankAccounts));
    printf("Which bank account would you like to access?\n");
    printf("Enter the name of the bank where your account is: ");

    char bankAccountName[20];
    scanf("%s", &bankAccountName);

    BankAccount bankAccount;
    for(int i = 0; i < sizeof(user->bankAccounts); i++) {
        if(strcmp(user->bankAccounts[i].bankName, bankAccountName) == 0) {
            bankAccount = *(&user->bankAccounts[i]);
        }
    }

    printf("Currently accessing bank account at %s.\n", bankAccount.bankName);
    printf("AccountID: %d\n", bankAccount.accountID);
    printf("Credit score: %d\n", bankAccount.creditScore);
    printf("Here is a list of your cards:\n");

    for(int i = 0; i < sizeof(bankAccount); i++) {
        CardData cardData = bankAccount.cards[i];
        printf("Card %d:\n", i + 1);
        printf("Type: %c\n", cardData.type);
    }

    printf("What would you like to do?\n");
    printf("1. Manage your Bank Account\n");
    printf("2. Manage each card\n");
    printf("3. Logout\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            UserBankAccountManagement(&bankAccount);
            break;
        case 2:
            UserBankAccountManagement(&bankAccount);
            break;
        case 3:
            Logout(user);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

/*
 * Logout function is used to logout the user from the system.
 * Input: Pointer to the user object.
 * Output: None.
 */
void Logout(User *user) {
    user->isLoggedIn = false;
    printf("You have been logged out! The program will now exit.\n");
    exit(0);
}

/*
ChangePassword function is used to allow the user to change the password of their login information if they wanted to.
Input: Pointer to the user object.
Output: Boolean value of whether the change for password was successful.
*/
bool ChangePassword(User *user) {

    password tempPassword;
    short changeAttempts = 0;

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
            strcpy(user->username, newPassword);
            printf("Password change successful!\n");
            break;
        }

    } while(changeAttempts < MAX_PASSWORD_CHANGE_ATTEMPTS);

    if(changeAttempts == MAX_PASSWORD_CHANGE_ATTEMPTS) {
        printf("You have run out of password change attempts, please try again later.");
        return false;
    }

    return true;
}

/*
ChangeUsername function is used to allow the user to change the username of their login information if they wanted to.
Input: Pointer to the user object.
Output: Boolean value of whether the change for username was successful.
*/
bool ChangeUsername(User *user) {

    username tempUsername;
    short changeAttempts = 0;

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
        printf("You have run out of username change attempts, please try again later.");
        return false;
    }

    return true;
}