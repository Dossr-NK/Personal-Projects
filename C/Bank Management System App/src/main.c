#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_management.h"
#include "account_management.h"

// Define file location for the data file
const char* fileLocation =  "";

int main(int argc, char **argv){   
    // First read the data from the file, if there is data, if not the user will be requested to register
    User initUser;
    // // // Read file and get data
    FILE* file = fopen(fileLocation , "rb");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    if(fread(&initUser, sizeof(User), 1, file) != 1) {
        printf("Error reading file! No user saved.\n");
        fclose(file);
        initUser = InitializeDefaultUser();
    }
    fclose(file);

    // Clears the terminal for easier readability
    system("clear");

    // Start of program
    printf("Hello to the Bank Management System App!\n");
    printf("----------------------------------------\n");

    // Initialize user object
    User user;

    // Checks if the user read from file is registered, if it is set it to the active user, else set it as a default user
    if(initUser.isRegistered == true) {
        user = initUser;
    } else {
        user = InitializeDefaultUser();
    }

    Login(&user);

    
    // Reopen file to write data for saving
    file = fopen(fileLocation , "wb");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    if(fwrite(&user, sizeof(User), 1, file) != 1) {
        printf("Error writing to file!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    return 0;
}