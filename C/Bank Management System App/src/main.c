#include <stdio.h>
#include <string.h>

#include "user_management.h"

int main(int argc, char **argv){
    printf("\n\nHello to the Bank Management System App!\n");
    printf("----------------------------------------\n\n\n");
    
    User user;
    user.isRegistered = true;
    strcpy(user.username, "test");
    strcpy(user.password, "test");
    strcpy(user.name, "test");
    user.age = 18;
    
    Login(&user);
    bool changePasswordTest = ChangePassword(&user);
    bool changeUsernameTest = ChangeUsername(&user);
    if(user.isLoggedIn){
        printf("User is logged in!\n");
    } else {
        printf("User is not logged in!\n");
    }

    if(changePasswordTest) {
        printf("Password changed\n");
    } else {
        printf("Password change failed\n");
    }

    if(changeUsernameTest) {
        printf("Username changed");
    } else {
        printf("Username change failed");
    }

    return 0;
}
