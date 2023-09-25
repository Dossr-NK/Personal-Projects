#include "user_management.h"

#include <stdio.h>
#include <string.h>

/*
Login function is used to authenticate and login the user into the system.
Input: Pointer to the user object
Output: Boolean value indicating if the user is logged in or not
*/
bool Login(User *user){
    if(!user->isRegistered){
        printf("You are unregistered, please register first!\n");
        Register(user);
    }

    // Create temporary variables to check if the username and password are correct
    username tempUsername;
    password tempPassword;
    bool isUserLoggedIn = false;
    short loginAttempts = 0;

    do {

        printf("Please login before accessing your bank data!\n");
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
            loginAttempts++;
        }

    } while(loginAttempts < MAX_LOGIN_ATTEMPTS && !isUserLoggedIn);

    if(!isUserLoggedIn){
        printf("You have exceeded the maximum number of login attempts!\n");
        return false;
    }
    return true;
}

/*
Register function is used to register the user into the system if they aren't already.
Input: Pointer to the user object
Output: Boolean value indicating if the user is registered or not
*/
void Register(User *user) {
    printf("Please register before accessing your bank data!\n");
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
            printf("Incorrect password, please try again.");
            changeAttempts++;
        } else {
            strcpy(user->password, tempPassword);
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
            printf("Incorrect username, please try again.");
            changeAttempts++;
        } else {
            strcpy(user->username, tempUsername);
            printf("Username change successful!\n");
            break;
        }

    } while(changeAttempts < MAX_USERNAME_CHANGE_ATTEMPTS);

    if(changeAttempts == MAX_USERNAME_CHANGE_ATTEMPTS) {
        printf("You have run out of username change attempts, please try again later.");
        return false;
    }

    return true;
}