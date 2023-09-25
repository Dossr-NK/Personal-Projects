#ifndef _user_management_h
#define _user_management_h

#include <stdbool.h>

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
    bool isAccompaniedByAdult;
} User;

bool Login(User *user);
void Register(User *user);
bool ChangePassword(User *user);
bool ChangeUsername(User *user);

#endif /* user_management_h */