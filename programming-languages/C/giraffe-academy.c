#include <stdio.h>
#include <stdlib.h>

    //Return
double cube(double num){
    double result = num * num * num;
    return result;
}

    //If
int max(int num1, int num2, int num3){
    int result;
    if(num1 >= num2 && num1 >=3){
        result = num1;
    }else if(num2 >= num1 && num2 >= num3){
        result = num2;
    }else {
        result = num3;
    }
    return result;
}
    //Better Calculator
void betterCalculator(){
    double num1;
    double num2;
    char op;

    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter operator: ");
    scanf(" %c", &op);
    printf("Enter a second number: ");
    scanf("%lf", &num2);

    if(op == '+'){
        printf("%f", num1 + num2);
    } else if(op == '-'){
        printf("%f", num1 - num2);
    } else if(op == '*'){
        printf("%f", num1 * num2);
    } else if(op == '/'){
        printf("%f", num1 / num2);
    }else {
        printf("Invalid Operator");
    }
}
    //Structs
struct Student{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

    //Guessing Game
void guessingGame(){
    int secretNumber = 5;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;

    while(guess != secretNumber && outOfGuesses == 0){
        if(guessCount < guessLimit){
            printf("Enter a number: ");
            scanf("%d", &guess);
            guessCount++;
        }else {
            outOfGuesses = 1;
        }
    }
    if(outOfGuesses == 1){
        printf("Out of guesses");
    }else{
        printf("You Win!");
    }
}
int main()
{

    //Basics
    printf("Hello world!\n");
    printf("    /|\n");
    printf("   / |\n");
    printf("  /  |\n");
    printf(" /___|\n");

    char characterName[] = "Evrim";
    int characterAge = 67;
    printf("There once was a man named %s\n", characterName);
    printf("he was %d years old.\n", characterAge);
    characterAge = 30;
    printf("He really liked the name %s\n", characterName);
    printf("but did not like being %d.\n", characterAge);

    int age = 24;
    double gpa = 3.02;
    char grade = 'B';
    char phrase[] = "Bear in Giraffe Academy\n";

    float favNum = 6.0;
    printf("My favorite %s is %f\n", "number", favNum);

    printf("%f\n", 5.0 / 4.0);
    printf("%d\n", 5 / 4);
    printf("%f\n", pow(2, 3));
    printf("%f\n", ceil(36.356));
    printf("%f\n", floor(36.356));

    /* printf("Comments are fun"); */
    // printf("maybe not");

    const int NUM = 5;
    printf("%d\n", NUM);
    //NUM = 8;
    printf("%d\n", NUM);
    printf("%d\n", 90);

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);
    printf("Enter your gpa: ");
    scanf("%lf", &gpa);
    printf("Your gpa is %f\n", gpa);
    printf("Enter your grade: ");
    scanf(" %c", &grade);
    printf("Your grade is %c\n", grade);
    char name[20];
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Your name is %s\n", name);

    char surname[20];
    printf("Enter your surname:");
    fgets(surname, 20, stdin);
    printf("Your surname is %s\n", surname);

    //Basic Calculator
    double num1;
    double num2;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("Answer: %f", num1+ num2);

    //Mad Libs Game
    char color[20];
    char pluralNoun[20];
    char celebrityF[20];
    char celebrityL[20];

    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a plural noun: ");
    scanf("%s", pluralNoun);
    printf("Enter a celebrity: ");
    scanf("%s%s", celebrityF, celebrityL);

    printf("Roses are %s\n",color);
    printf("%s are blue\n", pluralNoun);
    printf("I love %s %s\n", celebrityF, celebrityL);

    //Arrays
    int luckyNumbers[] = {4, 8, 15, 16, 23 ,42};
    luckyNumbers[1] = 200;
    printf("%d \n", luckyNumbers[1]);

    int luckyNumbers1[20];
    luckyNumbers1[1] = 80;
    luckyNumbers1[0] = 90;
    printf("%d \n", luckyNumbers1[0]);

    //Functions
    printf("Top\n");
    sayHi("Mike", 40);
    sayHi("Evrim", 24);
    sayHi("Harry", 45);
    printf("Bottom \n");
    printf("Answer: %f \n", cube(3.0));

    //If
    printf("%d", max(4, 10, 6));
    if(3 > 2 || 2>5){
        printf("True");
    }
    if(3 != 2){
        printf("True");
    }
    if(!(3 <  2)){
        printf("True");
    }


    betterCalculator();

    //Switch
    char grade = 'A';

    switch(grade){
    case 'A' :
        printf("You did great! ");
        break;
    case 'B' :
        printf("You did alright! ");
        break;
    case 'C' :
        printf("You did poorly! ");
        break;
    case 'D' :
        printf("You did very bad! ");
        break;
    case 'F' :
        printf("You Failed! ");
        break;
    default:
        printf("Invalid Grade");
    }

    //Structs
    struct Student student1;
    student1.age = 24;
    student1.gpa = 3.03;
    strcpy(student1.name, "Evrim");
    strcpy(student1.major, "Computer Engineer");

    struct Student student2;
    student2.age = 24;
    student2.gpa = 3.0;
    strcpy(student2.name, "Jim");
    strcpy(student2.major, "Art");
    printf("%s", student2.name);

    //While
    int index = 6;
    while(index <= 5){
        printf("%d\n", index);
        index++;
    }

    do {
        printf("%d\n", index);
        index++;
    } while(index <= 5);


    guessingGame();

    //For Loops
    int i;
    for (i = 0; i <= 5; i++){
        printf("%d\n", luckyNumbers[i]);
    }

    //2D Arrays & Nested Loops
    int nums[3][2] = {
    {1,2},{3,4},{5,6}
    };
    printf("%d \n", nums[1][0]);
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
            printf("%d,", nums[i][j]);
        }
        printf("\n");
    }

    //Memory Addresses, Pointers
    int age = 30;
    int *pAge = &age;
    double gpa = 3.4;
    double *pGpa = &gpa;
    char grade = 'A';
    char *pGrade = &grade;

    printf("age: %p\npga: %p\ngrade: %p\n", &age, &gpa, &grade);
    printf("age's memory address: %p\n", &age);

    //Dereferencing Pointers
    printf("%d\n", *pAge);
    printf("%d", *&age);

    //Writing File
    FILE * fpointer = fopen("employesees.txt", "w");
    fprintf(fpointer, "Evrim, Computer Engineer\nJim, Salesman");
    FILE * fpointer = fopen("employesees.txt", "a");
    fprintf(fpointer, "\nKelly, Customer Service");

    //Reading File
    char line[255];
    FILE * fpointer = fopen("employesees.txt", "r");
    fgets(line, 255, fpointer);
    printf("%s", line);
    fclose(fpointer);

    return 0;
}

    //Functions
void sayHi(char nameF[], int ageF[]){
    printf("Hello %s, you are %d \n", nameF, ageF);
}

