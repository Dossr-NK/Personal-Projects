#ifndef _user_management_h
#define _user_management_h

#include <stdbool.h>
#include "account_management.h"

#define MAX_LOGIN_ATTEMPTS 5
#define MAX_PASSWORD_CHANGE_ATTEMPTS 3
#define MAX_USERNAME_CHANGE_ATTEMPTS 3

typedef char username[20];
typedef char password[20];
typedef char name[20];

typedef struct {
    bool isRegistered;
    username username;
    password password;
    name name;
    unsigned int age;
    bool isLoggedIn;
    bool isAccompaniedByAdult;
    int numberOfBankAccounts;
    BankAccount bankAccounts[]; // This holds the bank accounts of the user for various banks 
} User;

void Login(User *user);
void Register(User *user);
void UserManagement(User *user);
void UserAccessBankAccount(User *user);
void Logout(User *user);
bool ChangePassword(User *user);
bool ChangeUsername(User *user);

#endif /* user_management_h */