#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Struct and TypeDef Examples
struct Player {
    char name[50];
    int highScore;
};

typedef char user[25]; // user is now a type that is the same as char[25]

struct User {
    user name;
    char password[12];
    int id;
};

typedef struct {
    user name;
    char password[12];
    int id;
} UserStruct;

struct Student {
    char name[12];
    float gpa;
};

// Enum Examples
enum Day{Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7};

// Functions and Function Prototype Examples
void birthday() {
    printf("Happy Birthday!\n");
}

void birthdayWithParameters(int age, char name[]) {
    printf("Happy Birthday %s! You are %d years old!\n", name, age);
}

double square(double num) {
    return num * num;
}

int findMax(int x, int y) {
    // Using a ternary operator
    return (x > y) ? x : y;
}

void functionPrototype(); // Function prototype example

void sort(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            } 
        }
    }
    printf("Sorted Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    /*
        escape sequence = character combination consisting of a backslash (\) followed by a letter or by a combination of digits.
        They specigy actions to be performed rather than characters to be printed.
        ex:
            \n = newline
            \t = horizontal tab
            \b = backspace
            \" = double quote
            \' = single quote
            \\ = backslash
    */
    printf("Hello World!\n");
    printf("Skrrrrrt\n");

    /*
        Variables = named memory location that may take on different values.
        Refer to a variabls's name to access the stored value.
        The variable behaves as if it was the value it containts.
        BUT we need to declare what type of data we are storing in the variable.
    */
   int x; // Declaring a variable
   x = 123; // Assigning a value to the variable
   int y = 456; // Declaring and assigning a value to the variable

   int age = 19; // Integer
   float gpa = 3.68; // Floating point number
   char grade = 'A'; // Stores a single character
   char name[] = "Nate"; // Array of characters, emulates a string

    printf("My name is %s and I am %d years old.\n", name, age); // %s = string, %d = integer are called format specifiers
    printf("My average grade is: %c\n", grade); // %c = character
    printf("My GPA is: %f\n", gpa); // %f = floating point number

    /*
        Data Types:                                                            Format Specifier:                                        Size:                                 
            char = single character                                                     %c                                              1 byte
            char[] = array of characters (string)                                       %s                                              1 byte per character
            float = floating point number                                               %f                                              4 bytes
            int = integer                                                               %d                                              4 bytes
            double = double precision floating point (8 byes)                           %lf                                             8 bytes
            bool = boolean (true or false) (1 byte)                                     %d                                              1 byte 
            char = numeric value representing a character (1 byte) (-128 - +127)        %c or %d                                        1 byte
            Keywords = reserved words that have a special meaning to the compiler
                unsigned = positive value only (0 - +255 for unsigned char for example)
                    to display an unsigned int use %u
                signed = positive and negative values (-128 - +127 for signed char for example)
                short = half the size of an int (2 bytes)
                    doesn't require the use of int keyword
                long = twice the size of an int (4 bytes)
                    doesn't require the use of int keyword if only using long
                    long long int = 8 bytes
                    use %lld or %llu to display long long int
                    not used often
    */

    // Examples
    unsigned int a = 123;
    signed int b = -123;
    short int c = 1231;
    long int d = 1231413;
    long long int e = 1212321413;
    char f = 'a';
    char g[] = "Hello World!";
    float h = 123.456;
    double i = 123.45612321451123;
    bool j = true;

    printf("unsigned int: %u\n", a);
    printf("signed int: %d\n", b);
    printf("short int: %d\n", c);
    printf("long int: %ld\n", d);
    printf("long long int: %lld\n", e);
    printf("char: %c\n", f);
    printf("char[]: %s\n", g);
    printf("float: %f\n", h);
    printf("double: %lf\n", i);
    printf("bool: %d\n", j);

    
   /*
        Format Specifiers % = defines and formats a type of data to be displayed
            %c = character
            %s = string (array of characters)
            %f = floating point number
            %lf = double precision floating point number
            %d = integer

            %.1 = decimal precision
            %1 = minimum field width
            %- = left align
   */

    // Examples
    float item1 = 5.99;
    float item2 = 12.99;
    float item3 = 100.99;

    // Prints all the items using 2 decimal point precision
    printf("Item 1: $%-8.2f\n", item1); // - = left align, 8 = minimum field width, .2 = decimal precision
    printf("Item 2: $%10.2f\n", item2); // 10 = minimum field width, .2 = decimal precision
    printf("Item 3: $%-5.2f\n", item3); // - = left align, 5 = minimum field width, .2 = decimal precision

    // Constant = fixed value that may not be altered during program execution
    float pi = 3.14159; // Normal variable that can be changed
    printf("Pi: %f\n", pi);

    const float PI = 3.14159; // const keyword makes the variable a constant
    printf("Constant Pi: %f\n", PI);

    /*
        Arithmetic Operators
            + = addition
            - = subtraction
            * = multiplication
            / = division
            % = modulus (remainder)
            ++ = increment
            -- = decrement
    */

    // Examples
    int num1 = 10;
    int num2 = 3;

    int num3 = num1 + num2; // 10 + 3 = 13
    printf("num1 + num2 = %d\n", num3);

    // Typecasting = converting one data type to another
    float num4 = (float)num1 / num2; // (float)num1 = typecasting num1 to a float
    printf("num1 / num2 = %f\n", num4);

    /*
        Augmented Assignment Operators = used to replace a statement where an operator takes a variable as one of its arguments
                                         and then assigns the result back to the same variables.
                                         x = x+1 
                                         x += 1
    */

    // Examples
    int num5 = 10;
    num5 += 5; // num5 = num5 + 5
    printf("num5: %d\n", num5);

    /*
        User Input
            scanf() = used to read input from the user
            scanf() = scanf("format specifier", &variable);
            & = address of operator
    */

    // Example
    int age_input;
    printf("Enter your age: ");
    scanf("%d", &age_input);
    printf("You are %d years old.\n", age_input);

    char name_input[20]; // 20 = maximum number of characters that can be stored in the array
    printf("Enter your name: ");
    scanf("%s", name_input);
    /*
        For strings that have spaces in them use fgets() instead of scanf()
        fgets(name_input, 20, stdin); 20 = maximum number of characters that can be stored in the array, stdin = standard input
        fgets() also stores the newline character (\n) in the array
        To remove the newline character use the following code
        name_input[strlen(name_input) - 1] = '\0';
    */
    printf("Your name is %s.\n", name_input);

    // Math Functions using the math.h library
    double A = sqrt(9); // sqrt() = square root
    printf("A: %lf\n", A);
    double B = pow(2, 4); // pow() = power
    printf("B: %lf\n", B);
    int C = round(3.14); // round() = round to the nearest integer
    printf("C: %d\n", C);
    int D = ceil(3.14); // ceil() = round up
    printf("D: %d\n", D);
    int E = floor(3.14); // floor() = round down
    printf("E: %d\n", E);
    double F = fabs(-100); // fabs() = absolute value
    printf("F: %lf\n", F);
    double G = log(3); // log() = natural logarithm
    printf("G: %lf\n", G);
    double H = sin(45); // sin() = sine
    printf("H: %lf\n", H);
    double I = cos(45); // cos() = cosine
    printf("I: %lf\n", I);
    double J = tan(45); // tan() = tangent
    printf("J: %lf\n", J);

    // Simple Program to calculate the circumference and area of a circle
    // PI is declared above as a constant
    double radius_input;
    double circumference;
    double area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius_input);
    circumference = 2 * PI * radius_input;
    area = PI * pow(radius_input, 2); // pow() = power or could be PI * radius_input * radius_input instead if math isn't included
    printf("The circumference of the circle is: %lf\n", circumference);
    printf("The area of the circle is: %lf\n", area);

    // Simple Program to Calculate the Hypotenuse of a Right Triangle
    double side1;
    double side2;
    double hypotenuse;

    printf("Enter Side 1: ");
    scanf("%lf", &side1);
    printf("Enter Side 2: ");
    scanf("%lf", &side2);

    hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));
    printf("The hypotenuse is: %lf\n", hypotenuse);

    // If Statement Practice in C
    age = 0;
    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18) {
        printf("You are an adult.\n");
    } else if(age >= 13) {
        printf("You are a teenager.\n");
    } else {
        printf("You are a child.\n");
    }

    // Switch Statement Practice in C
    printf("Enter your grade: ");
    scanf(" %c", &grade);
    switch(grade) {
        case 'A':
            printf("You did great!\n");
            break;
        case 'B':
            printf("You did alright!\n");
            break;
        case 'C':
            printf("You did poorly!\n");
            break;
        case 'D':
            printf("You did very bad!\n");
            break;
        case 'F':
            printf("You failed!\n");
            break;
        default:
            printf("Invalid Grade!\n");
    }

    // Simple Temperature Conversion Program
    double temp_input;
    char unit_input;

    printf("Enter the temperature: ");
    scanf("%lf", &temp_input);
    printf("Enter the unit (F or C): ");
    scanf(" %c", &unit_input);
     unit_input = toupper(unit_input); // toupper() = converts a character to uppercase

    if(unit_input == 'C') {
        printf("The temperature is currently in Celsius.\n");
        printf("The temperature in Fahrenheit is: %.1lf\n", (temp_input * 9/5) + 32);
    } else if(unit_input == 'F') {
        printf("The temperature is currently in Fahrenheit.\n");
        printf("The temperature in Celsius is: %.1lf\n", (temp_input - 32) * 5/9);
    } else {
        printf("%c is and invalid unit!\n", unit_input);
    }

    // Access calculator function
    char operator_input;
    double num1_input;
    double num2_input;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator_input);
    printf("Enter the first number: ");
    scanf("%lf", &num1_input);
    printf("Enter the second number: ");
    scanf("%lf", &num2_input);
    switch(operator_input) {
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", num1_input, num2_input, num1_input + num2_input);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", num1_input, num2_input, num1_input - num2_input);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", num1_input, num2_input, num1_input * num2_input);
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf\n", num1_input, num2_input, num1_input / num2_input);
            break;
        default:
            printf("Invalid Operator!\n");
    }

    /*
        Logical Operators:
            && = AND        checks if BOTH conditions are true
            || = OR         checks if ONE of the conditions are true
            ! = NOT         checks if the condition is NOT true
    */

    // Examples
    if(age >= 18 && age <= 60) {
        printf("You are an adult.\n");
    }

    if(age < 18 || age > 60) {
        printf("You are not an adult.\n");
    }

    if(!(age < 18)) {
        printf("You are an adult.\n");
    }

    // Practicing calling a funtion
    birthday();
    birthday();
    birthday();

    // Practicing calling a function with parameters
    char name_input2[] = "Nate";
    birthdayWithParameters(19, name_input2);

    // Practicing calling a function with a return value
    printf("The square of 2 is: %lf\n", square(2));

    /*
        Ternary Operator = shortcut for if else statement that returns a value
            (condition) ? value_if_true : value_if_false
    */

    // Examples
    printf("The maximum number is: %d\n", findMax(2, 5));

    /*
        Function Prototypes
            What is it?
                Function declaration, without a body, before main()
                Ensures that calls to a fucntion are made with the correct arguments and return type
    */

    // Example
    functionPrototype(); // If the function is called with incorrect argument types or return type then the compiler will throw an error

    /*
        String functions, include <string.h>
            strlwr      =    converts a string to lowercase
            strupr      =    converts a string to uppercase
            strlen      =    returns the length of a string
            strcat      =    concatenates two strings
            strcpy      =    copies one string to another
            strcmp      =    compares two strings
            strncat     =   concatenates two strings up to a specified number of characters
            strncpy     =   copies one string to another up to a specified number of characters
            stricmp     =   compares two strings without case sensitivity
            strnicmp    =  compares two strings without case sensitivity up to a specified number of characters
            strchr      =    returns a pointer to the first occurrence of a character in a string
            strrchr     =   returns a pointer to the last occurrence of a character in a string
            strset      =    sets all of the characters in a string to a specified character
            strnset     =   sets a specified number of characters in a string to a specified character
            strrev      =    reverses a string
    */

    // Examples
    char string1[] = "Hello";
    char string2[] = "World";

    strlwr(string1);
    printf("string1: %s\n", string1);
    strupr(string1);
    printf("string1: %s\n", string1);
    strcat(string1, string2);
    printf("string1: %s\n", string1);
    strncat(string1, string2, 2);
    printf("string1: %s\n", string1);
    strcpy(string1, string2);
    printf("string1: %s\n", string1);
    strncpy(string1, string2, 2);
    printf("string1: %s\n", string1);

    int result = strcmp(string1, string2);
    if(result = 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    // Practicing For Loops
    for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    /*
        While loop = repeats a section of code while a condition is true
            WHILE some condition remains true
            a while loop might not run at all if the condition is false
    */

    // Example
    char name_test[25];

    printf("Enter your name: ");
    fgets(name_test, 25, stdin);
    name_test[strlen(name_test) - 1] = '\0';
    
    while(strlen(name_test) == 0) {
        printf("No name was entered.\n");
        printf("Enter your name: ");
        fgets(name_test, 25, stdin);
        name_test[strlen(name_test) - 1] = '\0';
    }

    printf("Hello %s!\n", name_test);

    /*
        Do While Loop = repeats a section of code while a condition is true
            DO some code
            WHILE some condition remains true
            a do while loop will always run at least once
    */

    // Example
    int number = 0;
    int sum = 0;
    do{
        printf("Enter a number: ");
        scanf("%d", &number);
        if(number > 0) {
            sum += number;
        }
    } while(number > 0);
    printf("The sum is: %d\n", sum);

    // Nested Loop = loop inside another loop
    int rows, columns;
    char symbol;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    scanf("%c"); // scanf() leaves a newline character in the buffer so we need to use scanf() again to get rid of it
    printf("Enter the symbol to be used: ");
    scanf("%c", &symbol);

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }

    /*
        Break Statement = used to exit a loop
        Continue Statement = used to skip the current iteration of a loop
    */

    /*
        Arrays = a data structure that stores a collection of variables that are all the same type
        Arrays are stored in contiguous memory locations
        Arrays are zero indexed
        Arrays are fixed in size
        Arrays are declared as follows: type name[size];
        Arrays are initialized as follows: type name[size] = {value1, value2, value3, ...};
    */

    // Examples
    double prices[] = {1.99, 2.99, 3.99, 4.99};
    printf("The first price is: $%.2lf\n", prices[0]);

    // Print all the prices in the array with a for loop
    printf("All the prices in the array:\n");
    printf("%d bytes\n", sizeof(prices)); // sizeof() = returns the size of the array in bytes
    for(int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++) { // sizeof(prices)/sizeof(prices[0]) = returns the number of elements in the array
        printf("Price %d: $%.2lf\n", i + 1, prices[i]);
    }

    /*
        2D Arrays = an array of arrays, where each element is an array
                    useful if you need a matrix, grid, or table of data
    */

    // Examples
    int numbers[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("The number in row 1, column 2 is: %d\n", numbers[0][1]);
    printf("Print entire 2D array:\n");
    int rows1 = sizeof(numbers)/sizeof(numbers[0]);
    int columns1 = sizeof(numbers[0])/sizeof(numbers[0][0]);
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < columns1; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    // Array of strings
    char cars[][10] = {"Mustang", "Corvette", "Camaro"};
    // Cannot directly change the value of a string in an array of strings, ex cannot do cars[0] = "Ferrari"

    strcpy(cars[0], "Tesla"); // strcpy() = copies one string to another

    for(int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++) {
        printf("%s\n", cars[i]);
    }

    // Swap values between two variables (for sorting algorithms)
    char x100 = 'X';
    char y100 = 'Y';
    printf("Before swap: x = %c, y = %c\n", x100, y100);

    char temp = x100;
    x100 = y100;
    y100 = temp;
    printf("After swap: x = %c, y = %c\n", x100, y100);

    // Thing to note about strings, if they are not the same size then the string will not be copied properly, so initialize the string to the same size
    char water[15] = "water";
    char lemonade[15] = "lemonade";
    char temp2[15];
    printf("Before swap: water = %s, lemonade = %s\n", water, lemonade);

    strcpy(temp2, water);
    strcpy(water, lemonade);
    strcpy(lemonade, temp2);
    printf("After swap: water = %s, lemonade = %s\n", water, lemonade);

    // Sort an arry
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, size);

    /*
        Struct = collection of related members ("variables") that can be different types
            listed under one name in a block of memory
            VERY SIMILAR to classes in other languages (but no methods)
            struct declared above main()
    */

    // Example
    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Nate");
    player1.highScore = 100;

    strcpy(player2.name, "Bob");
    player2.highScore = 50;

    printf("Player 1: %s, %d\n", player1.name, player1.highScore);
    printf("Player 2: %s, %d\n", player2.name, player2.highScore);

    // TypeDef = used to create a new type, reserved keyword that gives an existing datatype a "nickname"

    // Example
    char user1[25] = "Nate";
    user user2 = "Bob";
    struct User user3 = {"Nate", "password", 1};
    UserStruct user4 = {"Bob", "password", 2};
    printf("User 1: %s\n", user1);
    printf("User 2: %s\n", user2);
    printf("User 3: %s, %s, %d\n", user3.name, user3.password, user3.id);
    printf("User 4: %s, %s, %d\n", user4.name, user4.password, user4.id);

    // Creating an array of structs
    struct Student student1 = {"Nate", 3.68};
    struct Student student2 = {"Bob", 3.99};
    struct Student student3 = {"John", 2.99};
    struct Student student4 = {"Jane", 3.99};

    struct Student students[] = {student1, student2, student3, student4};
    for(int i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        printf("Student %-12d: %s, %.2f\n", i + 1, students[i].name, students[i].gpa);
    }

    /*
        Enums = a user defined type of named integer identifiers
                helps to make a program more readable
    */

    // Example
    enum Day today = Mon;
    printf("Today is day %d\n", today);

    if(today == Sun || today == Sat) {
        printf("It's the weekend!\n");
    } else {
        printf("It's a weekday!\n");
    }

    /*
        Pseudo random numbers = A set of values or elements that are statistically random
                                (Don't use these for any sort of cryptographic security)
                                Include <stdlib.h> and <time.h>
                                srand() = seeds the random number generator
    */

    // Example
    srand(time(0)); // time(0) = returns the current time in seconds

    int number2 = (rand() % 6) + 1; // rand() = returns a random number, % 6 = returns a number between 0 and 5, + 1 = returns a number between 1 and 6
    printf("The random number is: %d\n", number2);

    // Creating a simple random number guessing game
    const int MIN = 1;
    const int MAX = 10;
    int guess;
    int guesses;
    int answer;
    answer = (rand() % MAX) + MIN;

    do {
        printf("Guess a number between %d and %d: ", MIN, MAX);
        scanf("%d", &guess);
        if(guess > answer) {
            printf("Too high!\n");
        } else if(guess < answer) {
            printf("Too low!\n");
        } else {
            printf("You got it!\n");
        }
        guesses++;
    } while(guess != answer);

    printf("It took you %d guesses to get %d answer.\n", guesses, answer);

    // Simple Quiz Game
    char questions[][100] = {"1. What is the capital of the United States?",
                             "2. What is the capital of Canada?",
                             "3. What is the capital of Mexico?"};

    char options[][100] = {"A. New York\nB. Washington D.C.\nC. Los Angeles\nD. Chicago\n",
                           "A. Toronto\nB. Vancouver\nC. Ottawa\nD. Montreal\n",
                           "A. Mexico City\nB. Guadalajara\nC. Monterrey\nD. Tijuana\n"};

    char answers[] = {'B', 'C', 'A'};
    int numQuestions = sizeof(questions)/sizeof(questions[0]);

    char guess1;
    int score;

    printf("Welcome to the Quiz Game!\n");

    for(int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i]);
        for(int j = (i * 4); j < (i * 4); j++) {
            printf("%s", options[j]);
        }
        printf("Enter your answer: ");
        scanf(" %c", &guess1);
        scanf("%c"); // scanf() leaves a newline character in the buffer so we need to use scanf() again to get rid of it

        guess1 = toupper(guess1);

        if(guess1 == answers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect!\n");
        }
    }

    printf("You got %d out of %d questions correct!\n", score, numQuestions);

    /*
        Bitwise Operators = special operators that work on bits
            & = AND
            | = OR
            ^ = XOR
            << = left shift
            >> = right shift
    */

    // Examples
    int x1 = 6; //  6   = 00000110
    int y1 = 12; // 12  = 00001100
    int z1 = 0; //  0   = 00000000

    z1 = x1 & y1; // 4 = 00000100
    printf("x1 AND y1 = z1 which is: %d\n", z1);

    z1 = x1 | y1; // 14 = 00001110
    printf("x1 OR y1 = z1 which is: %d\n", z1);

    z1 = x1 ^ y1; // 10 = 00001010
    printf("x1 XOR y1 = z1 which is: %d\n", z1);

    z1 = x1 << 2; // 24 = 00011000
    printf("x1 left shift 2 = z1 which is: %d\n", z1);

    z1 = x1 >> 2; // 1 = 00000001
    printf("x1 right shift 2 = z1 which is: %d\n", z1);

    /*
        Memory addresses
            memory = an array of byes within RAM (street)
            memory block = a group of bytes (house)
            memory address = the location of a byte within memory (house address)
    */

    // Example
    char a1 = 'X';
    char b1 = 'Y';
    char c1 = 'Z';

    printf("%d bytes\n", sizeof(a1));
    printf("%d bytes\n", sizeof(b1));
    printf("%d bytes\n", sizeof(c1));

    printf("a1 is stored at %p\n", &a1); // & = address of operator
    printf("b1 is stored at %p\n", &b1);
    printf("c1 is stored at %p\n", &c1);

    /*
        Pointers = a variable that stores the address of another variable
        Dereference Operator = * = used to access the value of a pointer
    */

    // Example
    age = 21;
    int *pAge = &age; // * = pointer variable
    printf("age is stored at address of %p\n", &age);
    printf("pAge stores the address of %p\n", pAge);
    printf("value of age is %d\n", age);
    printf("value of age is %d\n", *pAge); // * = dereference operator

    // Writing to files
    FILE *pF = fopen("test.txt", "w"); // fopen() = opens a file, "w" = write mode, can also write file path instead of just file name

    fprintf(pF, "Spongebob Squarepants\n");

    fclose(pF);

    /*
        if(remove("test.txt") == 0) { // remove() = deletes a file
            printf("File deleted successfully.\n");
        } else {
            printf("Error deleting file.\n");
        }
    */

   FILE *pF1 = fopen("oof.txt", "r"); // "r" = read mode
    char buffer[255];

    if(pF1 == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    fgets(buffer, 255, pF1);
    printf("%s\n", buffer);

    /*
        To read whole file:
            while(fgets(buffer, 255, pF1) != NULL) {
                printf("%s", buffer);
            }
    */

    fclose(pF1);

    return 0;
}

void functionPrototype() {
    printf("This is a function prototype.\n");
}
