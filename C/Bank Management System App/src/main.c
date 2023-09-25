#include <stdio.h>
#include <string.h>

#include "user_management.h"

int main(int argc, char **argv){
    printf("Hello, from Bank Management System App!\n");
    
    User user;
    user.isRegistered = true;
    strcpy(user.username, "test");
    strcpy(user.password, "test");
    strcpy(user.name, "test");
    user.age = 18;
    
    bool isUserLoggedIn = Login(&user);
    if(isUserLoggedIn){
        printf("User is logged in!\n");
    } else {
        printf("User is not logged in!\n");
    }

    return 0;
}
