// Inlcude ALL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Clear C4996 (scanf may be unsafe)
#pragma warning(disable:4996)

// Clear C4716 (return value)
#pragma warning(disable:4716)

// Clear C6385 (Reading invalid data : readable 12, but 16 be read)
#pragma warning(disable:6385)

// Clear C6386 (Buffer overrun)
#pragma warning(disable:6386)

// Clear C6031 (Return scanf)
#pragma warning(disable:6031)

// Clear C4013
int LoginAdmin();
int AdminPage();
int NewStudent();
int InputStudent();
int EditStudent();
void header();
int calculator();
int CheckStudents();
int FoundCheckStudents();
int StudentPage();


// See Assignment student number
#define MaxStudents 5000 

// Number of student
int No_Student = 0; // set student as 0

// Information of student
char Name_Student[MaxStudents][51];                                 // String "Name" as "Array Data" and have "50" data base
char ID_Student[MaxStudents][11];                                   // String "ID" as "Array Data" and have "11" data base

// Class 1 Code with hours in sem
char Course_Code1[MaxStudents][3][11];                              // String "Course Code 1" as "Array" But have "3 sem"
int Hour_code1[MaxStudents][3]; // sem 1 to 3                       // Number in hours in [Course 1] having "3 sem" as "Array"

// Class 2 Code with hours in sem
char Course_Code2[MaxStudents][3][11];                              // String "Course Code 2" as "Array" but have "3 sem"
int Hour_code2[MaxStudents][3]; // sem 1 top 3                      // Number in hours in [Course 2] having "3 sem" as "Array"

// Grade[A,A-,B+,B,B-,C+,C,F]
char GradeCode1[MaxStudents][3][3]; // Sem 1 to 3                   // String "Grade Course Code 1" as "Array" and make it can fill in "A , A-, B+, B ..."
char GradeCode2[MaxStudents][3][3]; // Sem 1 to 3                   // String "Grade Course Code 2" as "Array" and make it can fill in "A , A-, B+, B ..."

// Find GPA
float GPA[MaxStudents][3]; // Sem 1 to 3                            // Float "GPA" as "Array" and have "3 sem"
float GradePointInSemOnly[MaxStudents][3][2]; // 3 Sem, 2 Course    // Float "Grade In Point" as "Array" and ot have "3 Sem" and "2 Course", can fill in "4.00, 3.75, 3.50..."
float TotalCredithours[MaxStudents][3]; // Sem 1 to 3               // Float "Total Credit Hours" in "Sem 1 to 3"
                                                                    //     *This only for 3 GPA, Like "Course 1 Credit Hours + Course 2 Credit Hours"* 

// Find CGPA
float CGPA[MaxStudents];                                            // Float "CGPA" as "Array"
float TotalQualityPoint[MaxStudents][2]; // 2 course                // Float "Total Quality Point" in "Sem 1 to 3" and it have "2 Course"
float TotalCreditHoursALL[MaxStudents][2]; // 2 course              // Float "Total Credit Hours" in "Course 1 and 2"
                                                                    //     *This only for CGPA, like "Credit Hours in Course 1 and Course 2"*

// To found student
int StudentFound;

// To Set Student Mode Show information or not
int InfoShow = 0;

// Makes Editor easy to set up header in all page
void header() {
    system("cls");
    // Header with text ( Kolej Pasar )
    printf("-----------------------------------------------------------------------\n");
    printf("  _  __          _            _     ____                               \n");
    printf(" | |/ /   ___   | |   ___    (_)   |  _ \\    __ _   ___    __ _   _ __ \n");
    printf(" | ' /   / _ \\  | |  / _ \\   | |   | |_) |  / _` | / __|  / _` | | '__|\n");
    printf(" | . \\  | (_) | | | |  __/   | |   |  __/  | (_| | \\__ \\ | (_| | | |   \n");
    printf(" |_|\\_\\  \\___/  |_|  \\___|  _/ |   |_|      \\__,_| |___/  \\__,_| |_|   \n");
    printf("                           |__/                                        \n");
    printf("-----------------------------------------------------------------------\n");
}

// The Main that User can see in the first time
int main() {
    header(); // Run Header function

    // Welcome & Questions
    printf("Welcome to Kolej Pasar System! \n");
    printf("What can I help you? \n");

    // Choice
    printf("<1> Enter Staff Administrator Mode \n");
    printf("<2> Enter Student Mode \n");
    printf("<3> Exit \n");
    printf("\n> ");

    // Answer
    int AS_Main = 0; // Make Answer as 0 as default
    scanf("%d", &AS_Main);
    rewind(stdin);
    switch (AS_Main) // Swtich case
    {
    case 1: // Enter Staff
        system("cls");
        LoginAdmin();
        break;

    case 2: // Enter Student
        system("cls");
        StudentPage();
        break;

    case 3: // Exit
        printf("Thank you, have a nice day.\n\n");
        system("pause");
        exit(0);

    default: // No case find
        printf("Please check your answer.\n");
        system("pause");
        system("cls");
        main();
        break;
    }
}

// Staff Login Mode 
int LoginAdmin() {
    header();

    // Welcome Page
    printf("Welcome to Staff Administrator Mode! \n");

    // Choice
    printf("<1> Login Admin \n");
    printf("<2> Back \n");
    printf("\n> ");

    // Answer
    int AS_LoginAdmin = 0;
    scanf("%d", &AS_LoginAdmin);
    rewind(stdin);
    switch (AS_LoginAdmin)
    {
    case 1:
        // Check ID Admin
        printf("-----------------------------------------------------------------------\n");
        printf("Please enter your admin id and password \n");

        // Admin Data set as 0 as default
        char id_staff[15] = { 0 };
        char pass_staff[12] = { 0 };

        // ID Enter
        printf("\nPlease enter your id        > ");
        scanf("%14s", id_staff);
        rewind(stdin);

        // Password Enter
        printf("Please enter your password  > ");
        scanf("%11s", pass_staff);
        rewind(stdin);

        // Check ID
        if (strcmp(id_staff, "Admin") == 0 && strcmp(pass_staff, "123") == 0)
        {
            // If True
            system("cls");
            AdminPage();
        }
        else {
            // If Fail
            printf("Login failed! Please try again.\n");
            system("pause");
            system("cls");
            LoginAdmin();
        }
        break;

    case 2: // Go Back To Main
        system("cls");
        main();
        break;

    default: // No answer find
        printf("Please check you answer.\n");
        system("pause");
        system("cls");
        LoginAdmin();
        break;
    }
}

// Staff Page after login
int AdminPage() {
    header();

    // Welcome Page
    printf("Welcome, Admin. \n");

    // Choice
    printf("<1> Input new student\n");
    printf("<2> Edit Student details\n");
    printf("<3> Check Student Information\n");

    // Is the information show in student mode?
    if (InfoShow == 0)
    {
        // No
        printf("<4> Show Information in Student Mode\n");
    }
    else
    {
        // Yes
        printf("<4> Hide Information in Student Mode\n");
    }

    printf("<5> Log out\n");
    printf("\n> ");

    // Answer data
    int AS_AdminPage = 0;
    scanf("%d", &AS_AdminPage);
    rewind(stdin);
    switch (AS_AdminPage)
    {
    case 1:
        // New Students
        // Confirm enter?
        printf("-----------------------------------------------------------------------\n");
        printf("Confirm to Enter a New Student?\n");
        printf("Note:Can't exit during enter a new student's information\n");
        printf("<1> Confirm\n");
        printf("<2> No\n");
        printf("\n> ");
        int ConfirmNew = 0;
        scanf("%d", &ConfirmNew);
        rewind(stdin);
        if (ConfirmNew == 1)
        {
            // Yes
            system("cls");
            NewStudent();
        }
        else if (ConfirmNew == 2)
        {
            // No
            system("cls");
            AdminPage();
        }
        else
        {
            // Input Error
            printf("Please check your answer.\n");
            system("pause");
            system("cls");
            AdminPage();
        }
        break;

    case 2:
        // Student detail
        system("cls");
        InputStudent();
        break;

    case 3:
        // Check Information
        system("cls");
        FoundCheckStudents();
        break;

    case 4:
        // Show or Hide Student information
        printf("-----------------------------------------------------------------------\n");
        printf("Confirm?\n");
        printf("<1> Yes\n");
        printf("<2> No\n\n");
        printf("> ");
        int ConfirmInfo = 0;
        scanf("%d", &ConfirmInfo);
        rewind(stdin);

        // Confirm or not
        if (ConfirmInfo == 1)
        {
            if (InfoShow == 1)
            {
                // Hide
                InfoShow = 0;
                printf("\nSuccess Hide!\n");
            }
            else
            {
                // Show
                InfoShow = 1;
                printf("\nSuccess Show!\n");
            }
            system("pause");
            system("cls");
            AdminPage();
        }
        else
        {
            system("cls");
            AdminPage();
        }

        break;

    case 5:
        // Logout
        system("cls");
        main();
        break;

    default:
        // Default
        printf("Please check your answer.\n");
        system("pause");
        system("cls");
        AdminPage();
        break;
    }
}

// New Student Input Menu
int NewStudent() {
    header();

    printf("Please enter student's information: \n");

    // Name
    printf("Student Name               > ");
    scanf("%49[^\n]", Name_Student[No_Student]);
    rewind(stdin);

    // ID (KPKL?????)
    printf("ID                         > KPKL");
    scanf("%5s", ID_Student[No_Student]);
    rewind(stdin);

    // Student Number start from 0, and ++ to add student number
    No_Student++;

    // To tell user success connect
    printf("-----------------------------------------------------------------------\n");
    printf("Data Saved. Now we have %d students.\n", No_Student);

    system("pause");
    system("cls");

    // Go back to admin page
    AdminPage();
}


// Page to found which students
int InputStudent() {
    header();

    StudentFound = -1; // Set defaut

    // Show all Students 
    printf("Students List:\n");
    for (int i = 0; i < No_Student; i++)
    {
        printf("KPKL%-5s | %-10s\n", ID_Student[i], Name_Student[i]);
    }

    // Ask user which student user want to edit
    printf("\nWhich Student you want to edit details?\n");
    printf("Student ID > KPKL");
    char DetialEdit[10] = { 0 };

    scanf("%5s", DetialEdit);
    rewind(stdin);

    // Check the ID
    for (int i = 0; i < No_Student; i++)
    {
        if (strcmp(DetialEdit, ID_Student[i]) == 0) // if detailedit same with ID = 0
        {
            StudentFound = i; // save number to data
            break;
        }
    }

    if (StudentFound == -1) // If not found data
    {
        // Tell user can't find the data
        printf("404 Not Found.\n");
        system("pause");
        system("cls");
        AdminPage();
    }
    else // Have founded data
    {
        system("cls");
        header();

        // Confirm Student Information
        printf("Student Information:\n");
        printf("Student Name     : %s\n", Name_Student[StudentFound]);
        printf("Student ID       : KPKL%s\n\n", ID_Student[StudentFound]);

        // Question
        printf("Did you sure you want to edit this student's details?\n");
        printf("<1> Yes\n");
        printf("<2> No\n");
        printf("\n> ");

        int ConfirmInputStudent = 0;
        scanf("%d", &ConfirmInputStudent);
        rewind(stdin);

        switch (ConfirmInputStudent)
        {
        case 1:
            // Confirm
            system("cls");
            EditStudent();
            break;

        case 2:
            // Back
            system("cls");
            AdminPage();
            break;

        default:
            // Double check key in
            printf("Please check your answer.\n");
            system("pause");
            system("cls");
            AdminPage();
            break;
        }
    }
}


// Page to edit the students that you found
int EditStudent() {
    header();

    // Student Information
    printf("Student's Information:\n");

    printf("Student Name                      : %s\n", Name_Student[StudentFound]);
    printf("Student ID                        : KPKL%s\n\n", ID_Student[StudentFound]);

    printf("Course 1 Code in Sem 1            : %s\n", Course_Code1[StudentFound][1]);
    printf("Credit Hours Course 1 in Sem 1    : %d hours\n", Hour_code1[StudentFound][1]);
    printf("Grade Course 1 in Sem 1           : %s\n", GradeCode1[StudentFound][1]);

    printf("\n");

    printf("Course 2 Code in Sem 1            : %s\n", Course_Code2[StudentFound][1]);
    printf("Credit Hours Course 2 in Sem 1    : %d hours\n", Hour_code2[StudentFound][1]);
    printf("Grade Course 2 in Sem 1           : %s\n", GradeCode2[StudentFound][1]);

    printf("\n");

    printf("Course 1 Code in Sem 2            : %s\n", Course_Code1[StudentFound][2]);
    printf("Credit Hours Course 1 in Sem 2    : %d hours\n", Hour_code1[StudentFound][2]);
    printf("Grade Course 1 in Sem 2           : %s\n", GradeCode1[StudentFound][2]);

    printf("\n");

    printf("Course 2 Code in Sem 2            : %s\n", Course_Code2[StudentFound][2]);
    printf("Credit Hours Course 2 in Sem 2    : %d hours\n", Hour_code2[StudentFound][2]);
    printf("Grade Course 2 in Sem 2           : %s\n", GradeCode2[StudentFound][2]);

    printf("\n");

    printf("Course 1 Code in Sem 3            : %s\n", Course_Code1[StudentFound][3]);
    printf("Credit Hours Course 1 in Sem 3    : %d hours\n", Hour_code1[StudentFound][3]);
    printf("Grade Course 1 in Sem 3           : %s\n", GradeCode1[StudentFound][3]);

    printf("\n");

    printf("Course 2 Code in Sem 3            : %s\n", Course_Code2[StudentFound][3]);
    printf("Credit Hours Course 2 in Sem 3    : %d hours\n", Hour_code2[StudentFound][3]);
    printf("Grade Course 2 in Sem 3           : %s\n", GradeCode2[StudentFound][3]);

    printf("\n");

    // Question
    printf("Which you want to edit?\n");
    printf("<1> ALL\n");                                    // Edit All in one time
    printf("<2> Name\n");                                   // Edit Name
    printf("<3> ID\n");                                     // Edit ID
    printf("<4> Course Code\n");                            // Edit Course Code 1&2 all sem
    printf("<5> Credit Hours Course Code\n");               // Edit Credit Hours Course Code
    printf("<6> Grade Course Code in sem 1 to 3\n");        // Edit Grade Course in Sem 1 to 3
    printf("<7> Exit\n");                                  // Exit to Admin Page

    printf("\n> ");
    int AS_EditStudent = 0;

    scanf("%d", &AS_EditStudent);
    rewind(stdin);

    int ConfirmAllEdit = 0;

    switch (AS_EditStudent)
    {
    case 1:
        // Take a confirm
        printf("\nConfirm want to edit all of the information?\n");
        printf("<1> Yes\n");
        printf("<2> No\n");
        printf("\n> ");
        scanf("%d", &ConfirmAllEdit);
        rewind(stdin);

        if (ConfirmAllEdit == 1)
        {
            system("cls");
            header();

            // 2
            printf("Student Name  : %s\n", Name_Student[StudentFound]);
            printf("Change to?\n");
            printf("\n> ");
            scanf("%49[^\n]", Name_Student[StudentFound]);
            rewind(stdin);

            printf("-----------------------------------------------------------------------\n");

            // 3
            printf("Student ID    : KPKL%s\n", ID_Student[StudentFound]);
            printf("Change to?\n");
            printf("\n> KPKL");
            scanf("%5s", ID_Student[StudentFound]);
            rewind(stdin);

            printf("-----------------------------------------------------------------------\n");

            // 4
            // Sem 1
            printf("Course 1 Code In Sem 1 : %s\n", Course_Code1[StudentFound][1]);
            printf("Course 2 Code In Sem 1 : %s\n", Course_Code2[StudentFound][1]);

            printf("Course 1 Code In Sem 2 : %s\n", Course_Code1[StudentFound][2]);
            printf("Course 2 Code In Sem 2 : %s\n", Course_Code2[StudentFound][2]);

            printf("Course 1 Code In Sem 3 : %s\n", Course_Code1[StudentFound][3]);
            printf("Course 2 Code In Sem 3 : %s\n", Course_Code2[StudentFound][3]);

            printf("Change to?\n");
            printf("\nCourse Code 1 In Sem 1 > ");
            scanf("%s", Course_Code1[StudentFound][1]);
            rewind(stdin);

            printf("Course Code 2 In Sem 1 > ");
            scanf("%s", Course_Code2[StudentFound][1]);
            rewind(stdin);

            // Sem 2
            printf("\nCourse Code 1 In Sem 2 > ");
            scanf("%s", Course_Code1[StudentFound][2]);
            rewind(stdin);

            printf("Course Code 2 In Sem 2 > ");
            scanf("%s", Course_Code2[StudentFound][2]);
            rewind(stdin);

            // Sem 3
            printf("\nCourse Code 1 In Sem 3 > ");
            scanf("%s", Course_Code1[StudentFound][3]);
            rewind(stdin);

            printf("Course Code 2 In Sem 3 > ");
            scanf("%s", Course_Code2[StudentFound][3]);
            rewind(stdin);

            printf("-----------------------------------------------------------------------\n");

            // 5
            printf("Credit Hours Course 1 in sem 1 : %d hours\n", Hour_code1[StudentFound][1]);
            printf("Credit Hours Course 2 in sem 1 : %d hours\n", Hour_code2[StudentFound][1]);

            printf("Credit Hours Course 1 in sem 2 : %d hours\n", Hour_code1[StudentFound][2]);
            printf("Credit Hours Course 2 in sem 2 : %d hours\n", Hour_code2[StudentFound][2]);

            printf("Credit Hours Course 1 in sem 3 : %d hours\n", Hour_code1[StudentFound][3]);
            printf("Credit Hours Course 2 in sem 3 : %d hours\n", Hour_code2[StudentFound][3]);

            printf("Change to?\n");
            // Sem 1
            printf("\nCourse 1 In Sem 1 > ");
            scanf("%d", &Hour_code1[StudentFound][1]);
            rewind(stdin);
            printf("Course 2 In Sem 1 > ");
            scanf("%d", &Hour_code2[StudentFound][1]);
            rewind(stdin);

            // Sem 2
            printf("\nCourse 1 In Sem 2 > ");
            scanf("%d", &Hour_code1[StudentFound][2]);
            rewind(stdin);
            printf("Course 2 In Sem 2 > ");
            scanf("%d", &Hour_code2[StudentFound][2]);
            rewind(stdin);

            // Sem 3
            printf("\nCourse 1 In Sem 3 > ");
            scanf("%d", &Hour_code1[StudentFound][3]);
            rewind(stdin);
            printf("Course 2 In Sem 3 > ");
            scanf("%d", &Hour_code2[StudentFound][3]);
            rewind(stdin);

            printf("-----------------------------------------------------------------------\n");

            // 6
            printf("Grade Course 1 in sem 1 : %s\n", GradeCode1[StudentFound][1]);
            printf("Grade Course 2 in sem 1 : %s\n", GradeCode2[StudentFound][1]);

            printf("Grade Course 1 in sem 2 : %s\n", GradeCode1[StudentFound][2]);
            printf("Grade Course 2 in sem 2 : %s\n", GradeCode2[StudentFound][2]);

            printf("Grade Course 1 in sem 3 : %s\n", GradeCode1[StudentFound][3]);
            printf("Grade Course 2 in sem 3 : %s\n\n", GradeCode2[StudentFound][3]);

            printf("Grade     Grade Point\n");
            printf("---------------------\n");
            printf("A         4.00       \n");
            printf("A-        3.75       \n");
            printf("B+        3.50       \n");
            printf("B         3.00       \n");
            printf("B-        2.75       \n");
            printf("C+        2.50       \n");
            printf("C         2.00       \n");
            printf("F         0.00       \n");

            printf("-----------------------------------------------------------------------\n");

            printf("Enter Grade as letter (A,A-,B+...) \n");
            printf("Change to?\n");

            // Reset as 0
            TotalQualityPoint[StudentFound][1] = 0.00;

            // Set GPA as 0
            // Sem 1
            GradePointInSemOnly[StudentFound][1][1] = 0.00;
            GradePointInSemOnly[StudentFound][2][1] = 0.00;
            GradePointInSemOnly[StudentFound][3][1] = 0.00;

            GradePointInSemOnly[StudentFound][1][2] = 0.00;
            GradePointInSemOnly[StudentFound][2][2] = 0.00;
            GradePointInSemOnly[StudentFound][3][2] = 0.00;

            printf("\nCourse 1 in Sem 1 > ");
            scanf("%s", GradeCode1[StudentFound][1]);
            rewind(stdin);

            if (strcmp(GradeCode1[StudentFound][1], "A") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 4.00;
                GradePointInSemOnly[StudentFound][1][1] += 4.00;
            }
            else if (strcmp(GradeCode1[StudentFound][1], "A-") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.75;
                GradePointInSemOnly[StudentFound][1][1] += 3.75;
            }
            else if (strcmp(GradeCode1[StudentFound][1], "B+") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.50;
                GradePointInSemOnly[StudentFound][1][1] += 3.50;
            }
            else if (strcmp(GradeCode1[StudentFound][1], "B") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.00;
                GradePointInSemOnly[StudentFound][1][1] += 3.00;
            }
            else if (strcmp(GradeCode1[StudentFound][1], "B-") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.75;
                GradePointInSemOnly[StudentFound][1][1] += 2.75;
            }
            else if (strcmp(GradeCode1[StudentFound][1], "C+") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.50;
                GradePointInSemOnly[StudentFound][1][1] += 2.50;
            }
            else if (strcmp(GradeCode1[StudentFound][1], "C") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.00;
                GradePointInSemOnly[StudentFound][1][1] += 2.00;
            }
            else // if no data, or F
            {
                TotalQualityPoint[StudentFound][1] += 0.00;
                GradePointInSemOnly[StudentFound][1][1] += 0.00;
                // Set to F
                strcpy(GradeCode1[StudentFound][1], "F");
            }

            printf("Course 2 in Sem 1 > ");
            scanf("%s", GradeCode2[StudentFound][1]);
            rewind(stdin);

            // Reset as 0
            TotalQualityPoint[StudentFound][2] = 0.00;

            if (strcmp(GradeCode2[StudentFound][1], "A") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 4.00;
                GradePointInSemOnly[StudentFound][1][2] += 4.00;
            }
            else if (strcmp(GradeCode2[StudentFound][1], "A-") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.75;
                GradePointInSemOnly[StudentFound][1][2] += 3.75;
            }
            else if (strcmp(GradeCode2[StudentFound][1], "B+") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.50;
                GradePointInSemOnly[StudentFound][1][2] += 3.50;
            }
            else if (strcmp(GradeCode2[StudentFound][1], "B") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.00;
                GradePointInSemOnly[StudentFound][1][2] += 3.00;
            }
            else if (strcmp(GradeCode2[StudentFound][1], "B-") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.75;
                GradePointInSemOnly[StudentFound][1][2] += 2.75;
            }
            else if (strcmp(GradeCode2[StudentFound][1], "C+") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.50;
                GradePointInSemOnly[StudentFound][1][2] += 2.50;
            }
            else if (strcmp(GradeCode2[StudentFound][1], "C") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.00;
                GradePointInSemOnly[StudentFound][1][2] += 2.00;
            }
            else // if no data, or F
            {
                TotalQualityPoint[StudentFound][2] += 0.00;
                GradePointInSemOnly[StudentFound][1][2] += 0.00;
                // Set to F
                strcpy(GradeCode2[StudentFound][1], "F");
            }


            printf("\nCourse 1 in Sem 2 > ");
            scanf("%s", GradeCode1[StudentFound][2]);
            rewind(stdin);

            if (strcmp(GradeCode1[StudentFound][2], "A") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 4.00;
                GradePointInSemOnly[StudentFound][2][1] += 4.00;
            }
            else if (strcmp(GradeCode1[StudentFound][2], "A-") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.75;
                GradePointInSemOnly[StudentFound][2][1] += 3.75;
            }
            else if (strcmp(GradeCode1[StudentFound][2], "B+") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.50;
                GradePointInSemOnly[StudentFound][2][1] += 3.50;
            }
            else if (strcmp(GradeCode1[StudentFound][2], "B") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.00;
                GradePointInSemOnly[StudentFound][2][1] += 3.00;
            }
            else if (strcmp(GradeCode1[StudentFound][2], "B-") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.75;
                GradePointInSemOnly[StudentFound][2][1] += 2.75;
            }
            else if (strcmp(GradeCode1[StudentFound][2], "C+") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.50;
                GradePointInSemOnly[StudentFound][2][1] += 2.50;
            }
            else if (strcmp(GradeCode1[StudentFound][2], "C") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.00;
                GradePointInSemOnly[StudentFound][2][1] += 2.00;
            }
            else // if no data, or F
            {
                TotalQualityPoint[StudentFound][1] += 0.00;
                GradePointInSemOnly[StudentFound][2][1] += 0.00;
                // Set to F
                strcpy(GradeCode1[StudentFound][2], "F");
            }

            printf("Course 2 in Sem 2 > ");
            scanf("%s", GradeCode2[StudentFound][2]);
            rewind(stdin);

            if (strcmp(GradeCode2[StudentFound][2], "A") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 4.00;
                GradePointInSemOnly[StudentFound][2][2] += 4.00;
            }
            else if (strcmp(GradeCode2[StudentFound][2], "A-") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.75;
                GradePointInSemOnly[StudentFound][2][2] += 3.75;
            }
            else if (strcmp(GradeCode2[StudentFound][2], "B+") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.50;
                GradePointInSemOnly[StudentFound][2][2] += 3.50;
            }
            else if (strcmp(GradeCode2[StudentFound][2], "B") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.00;
                GradePointInSemOnly[StudentFound][2][2] += 3.00;
            }
            else if (strcmp(GradeCode2[StudentFound][2], "B-") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.75;
                GradePointInSemOnly[StudentFound][2][2] += 2.75;
            }
            else if (strcmp(GradeCode2[StudentFound][2], "C+") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.50;
                GradePointInSemOnly[StudentFound][2][2] += 2.50;
            }
            else if (strcmp(GradeCode2[StudentFound][2], "C") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.00;
                GradePointInSemOnly[StudentFound][2][2] += 2.00;
            }
            else // if no data, or F
            {
                TotalQualityPoint[StudentFound][2] += 0.00;
                GradePointInSemOnly[StudentFound][2][2] += 0.00;
                // Set to F
                strcpy(GradeCode2[StudentFound][2], "F");
            }

            printf("\nCourse 1 in Sem 3 > ");
            scanf("%s", GradeCode1[StudentFound][3]);
            rewind(stdin);

            if (strcmp(GradeCode1[StudentFound][3], "A") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 4.00;
                GradePointInSemOnly[StudentFound][3][1] += 4.00;
            }
            else if (strcmp(GradeCode1[StudentFound][3], "A-") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.75;
                GradePointInSemOnly[StudentFound][3][1] += 3.75;
            }
            else if (strcmp(GradeCode1[StudentFound][3], "B+") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.50;
                GradePointInSemOnly[StudentFound][3][1] += 3.50;
            }
            else if (strcmp(GradeCode1[StudentFound][3], "B") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 3.00;
                GradePointInSemOnly[StudentFound][3][1] += 3.00;
            }
            else if (strcmp(GradeCode1[StudentFound][3], "B-") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.75;
                GradePointInSemOnly[StudentFound][3][1] += 2.75;
            }
            else if (strcmp(GradeCode1[StudentFound][3], "C+") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.50;
                GradePointInSemOnly[StudentFound][3][1] += 2.50;
            }
            else if (strcmp(GradeCode1[StudentFound][3], "C") == 0)
            {
                TotalQualityPoint[StudentFound][1] += 2.00;
                GradePointInSemOnly[StudentFound][3][1] += 2.00;
            }
            else // if no data, or F
            {
                TotalQualityPoint[StudentFound][1] += 0.00;
                GradePointInSemOnly[StudentFound][3][1] += 0.00;
                // Set to F
                strcpy(GradeCode1[StudentFound][3], "F");
            }

            printf("Course 2 in Sem 3 > ");
            scanf("%s", GradeCode2[StudentFound][3]);
            rewind(stdin);

            if (strcmp(GradeCode2[StudentFound][3], "A") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 4.00;
                GradePointInSemOnly[StudentFound][3][2] += 4.00;
            }
            else if (strcmp(GradeCode2[StudentFound][3], "A-") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.75;
                GradePointInSemOnly[StudentFound][3][2] += 3.75;
            }
            else if (strcmp(GradeCode2[StudentFound][3], "B+") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.50;
                GradePointInSemOnly[StudentFound][3][2] += 3.50;
            }
            else if (strcmp(GradeCode2[StudentFound][3], "B") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 3.00;
                GradePointInSemOnly[StudentFound][3][2] += 3.00;
            }
            else if (strcmp(GradeCode2[StudentFound][3], "B-") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.75;
                GradePointInSemOnly[StudentFound][3][2] += 2.75;
            }
            else if (strcmp(GradeCode2[StudentFound][3], "C+") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.50;
                GradePointInSemOnly[StudentFound][3][2] += 2.50;
            }
            else if (strcmp(GradeCode2[StudentFound][3], "C") == 0)
            {
                TotalQualityPoint[StudentFound][2] += 2.00;
                GradePointInSemOnly[StudentFound][3][2] += 2.00;
            }
            else // if no data, or F
            {
                TotalQualityPoint[StudentFound][2] += 0.00;
                GradePointInSemOnly[StudentFound][3][2] += 0.00;
                // Set to F
                strcpy(GradeCode2[StudentFound][3], "F");
            }

            printf("-----------------------------------------------------------------------\n");

            calculator();

            // Done Saved it
            printf("\nSaved!\n");
            system("pause");
            system("cls");
            EditStudent();
            break;

        }
        else if (ConfirmAllEdit == 2)
        {
            system("cls");
            EditStudent();
        }
        else
        {
            printf("Please check your answer.\n");
            system("pause");
            system("cls");
            EditStudent();
        }
        break;

    case 2:
        system("cls");
        header();
        printf("Student Name  : %s\n", Name_Student[StudentFound]);
        printf("Change to?\n");
        printf("\n> ");
        scanf("%49[^\n]", Name_Student[StudentFound]);
        rewind(stdin);
        printf("\nSaved!\n");
        system("pause");
        system("cls");
        EditStudent();
        break;

    case 3:
        system("cls");
        header();
        printf("Student ID    : KPKL%s\n", ID_Student[StudentFound]);
        printf("Change to?\n");
        printf("\n> KPKL");
        scanf("%5s", ID_Student[StudentFound]);
        rewind(stdin);
        printf("\nSaved!\n");
        system("pause");
        system("cls");
        EditStudent();
        break;

    case 4:
        system("cls");
        header();
        // Sem 1
        printf("Course 1 Code In Sem 1 : %s\n", Course_Code1[StudentFound][1]);
        printf("Course 2 Code In Sem 1 : %s\n", Course_Code2[StudentFound][1]);

        printf("Course 1 Code In Sem 2 : %s\n", Course_Code1[StudentFound][2]);
        printf("Course 2 Code In Sem 2 : %s\n", Course_Code2[StudentFound][2]);

        printf("Course 1 Code In Sem 3 : %s\n", Course_Code1[StudentFound][3]);
        printf("Course 2 Code In Sem 3 : %s\n", Course_Code2[StudentFound][3]);

        printf("Change to?\n");
        printf("\nCourse Code 1 In Sem 1 > ");
        scanf("%s", Course_Code1[StudentFound][1]);
        rewind(stdin);

        printf("Course Code 2 In Sem 1 > ");
        scanf("%s", Course_Code2[StudentFound][1]);
        rewind(stdin);

        // Sem 2
        printf("\nCourse Code 1 In Sem 2 > ");
        scanf("%s", Course_Code1[StudentFound][2]);
        rewind(stdin);

        printf("Course Code 2 In Sem 2 > ");
        scanf("%s", Course_Code2[StudentFound][2]);
        rewind(stdin);

        // Sem 3
        printf("\nCourse Code 1 In Sem 3 > ");
        scanf("%s", Course_Code1[StudentFound][3]);
        rewind(stdin);

        printf("Course Code 2 In Sem 3 > ");
        scanf("%s", Course_Code2[StudentFound][3]);
        rewind(stdin);

        printf("\nSaved!\n");
        system("pause");
        system("cls");
        EditStudent();
        break;

    case 5:
        system("cls");
        header();
        printf("Credit Hours Course 1 in sem 1 : %d hours\n", Hour_code1[StudentFound][1]);
        printf("Credit Hours Course 2 in sem 1 : %d hours\n", Hour_code2[StudentFound][1]);

        printf("Credit Hours Course 1 in sem 2 : %d hours\n", Hour_code1[StudentFound][2]);
        printf("Credit Hours Course 2 in sem 2 : %d hours\n", Hour_code2[StudentFound][2]);

        printf("Credit Hours Course 1 in sem 3 : %d hours\n", Hour_code1[StudentFound][3]);
        printf("Credit Hours Course 2 in sem 3 : %d hours\n", Hour_code2[StudentFound][3]);

        printf("Change to?\n");
        // Sem 1
        printf("\nCourse 1 In Sem 1 > ");
        scanf("%d", &Hour_code1[StudentFound][1]);
        rewind(stdin);
        printf("Course 2 In Sem 1 > ");
        scanf("%d", &Hour_code2[StudentFound][1]);
        rewind(stdin);

        // Sem 2
        printf("\nCourse 1 In Sem 2 > ");
        scanf("%d", &Hour_code1[StudentFound][2]);
        rewind(stdin);
        printf("Course 2 In Sem 2 > ");
        scanf("%d", &Hour_code2[StudentFound][2]);
        rewind(stdin);

        // Sem 3
        printf("\nCourse 1 In Sem 3 > ");
        scanf("%d", &Hour_code1[StudentFound][3]);
        rewind(stdin);
        printf("Course 2 In Sem 3 > ");
        scanf("%d", &Hour_code2[StudentFound][3]);
        rewind(stdin);

        calculator();

        printf("\nSaved!\n");
        system("pause");
        system("cls");
        EditStudent();
        break;

    case 6:
        system("cls");
        header();

        printf("Grade Course 1 in sem 1 : %s\n", GradeCode1[StudentFound][1]);
        printf("Grade Course 2 in sem 1 : %s\n", GradeCode2[StudentFound][1]);

        printf("Grade Course 1 in sem 2 : %s\n", GradeCode1[StudentFound][2]);
        printf("Grade Course 2 in sem 2 : %s\n", GradeCode2[StudentFound][2]);

        printf("Grade Course 1 in sem 3 : %s\n", GradeCode1[StudentFound][3]);
        printf("Grade Course 2 in sem 3 : %s\n\n", GradeCode2[StudentFound][3]);

        printf("Grade     Grade Point\n");
        printf("---------------------\n");
        printf("A         4.00       \n");
        printf("A-        3.75       \n");
        printf("B+        3.50       \n");
        printf("B         3.00       \n");
        printf("B-        2.75       \n");
        printf("C+        2.50       \n");
        printf("C         2.00       \n");
        printf("F         0.00       \n");

        printf("-----------------------------------------------------------------------\n");

        printf("Enter Grade as letter (A,A-,B+...) \n");
        printf("Change to?\n");

        // Reset as 0
        TotalQualityPoint[StudentFound][1] = 0.00;

        // Set GPA as 0
        // Sem 1
        GradePointInSemOnly[StudentFound][1][1] = 0.00;
        GradePointInSemOnly[StudentFound][2][1] = 0.00;
        GradePointInSemOnly[StudentFound][3][1] = 0.00;

        GradePointInSemOnly[StudentFound][1][2] = 0.00;
        GradePointInSemOnly[StudentFound][2][2] = 0.00;
        GradePointInSemOnly[StudentFound][3][2] = 0.00;

        printf("\nCourse 1 in Sem 1 > ");
        scanf("%s", GradeCode1[StudentFound][1]);
        rewind(stdin);

        if (strcmp(GradeCode1[StudentFound][1], "A") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 4.00;
            GradePointInSemOnly[StudentFound][1][1] += 4.00;
        }
        else if (strcmp(GradeCode1[StudentFound][1], "A-") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.75;
            GradePointInSemOnly[StudentFound][1][1] += 3.75;
        }
        else if (strcmp(GradeCode1[StudentFound][1], "B+") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.50;
            GradePointInSemOnly[StudentFound][1][1] += 3.50;
        }
        else if (strcmp(GradeCode1[StudentFound][1], "B") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.00;
            GradePointInSemOnly[StudentFound][1][1] += 3.00;
        }
        else if (strcmp(GradeCode1[StudentFound][1], "B-") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.75;
            GradePointInSemOnly[StudentFound][1][1] += 2.75;
        }
        else if (strcmp(GradeCode1[StudentFound][1], "C+") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.50;
            GradePointInSemOnly[StudentFound][1][1] += 2.50;
        }
        else if (strcmp(GradeCode1[StudentFound][1], "C") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.00;
            GradePointInSemOnly[StudentFound][1][1] += 2.00;
        }
        else // if no data, or F
        {
            TotalQualityPoint[StudentFound][1] += 0.00;
            GradePointInSemOnly[StudentFound][1][1] += 0.00;
            // Set to F
            strcpy(GradeCode1[StudentFound][1], "F");
        }

        printf("Course 2 in Sem 1 > ");
        scanf("%s", GradeCode2[StudentFound][1]);
        rewind(stdin);

        // Reset as 0
        TotalQualityPoint[StudentFound][2] = 0.00;

        if (strcmp(GradeCode2[StudentFound][1], "A") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 4.00;
            GradePointInSemOnly[StudentFound][1][2] += 4.00;
        }
        else if (strcmp(GradeCode2[StudentFound][1], "A-") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.75;
            GradePointInSemOnly[StudentFound][1][2] += 3.75;
        }
        else if (strcmp(GradeCode2[StudentFound][1], "B+") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.50;
            GradePointInSemOnly[StudentFound][1][2] += 3.50;
        }
        else if (strcmp(GradeCode2[StudentFound][1], "B") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.00;
            GradePointInSemOnly[StudentFound][1][2] += 3.00;
        }
        else if (strcmp(GradeCode2[StudentFound][1], "B-") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.75;
            GradePointInSemOnly[StudentFound][1][2] += 2.75;
        }
        else if (strcmp(GradeCode2[StudentFound][1], "C+") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.50;
            GradePointInSemOnly[StudentFound][1][2] += 2.50;
        }
        else if (strcmp(GradeCode2[StudentFound][1], "C") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.00;
            GradePointInSemOnly[StudentFound][1][2] += 2.00;
        }
        else // if no data, or F
        {
            TotalQualityPoint[StudentFound][2] += 0.00;
            GradePointInSemOnly[StudentFound][1][2] += 0.00;
            // Set to F
            strcpy(GradeCode2[StudentFound][1], "F");
        }


        printf("\nCourse 1 in Sem 2 > ");
        scanf("%s", GradeCode1[StudentFound][2]);
        rewind(stdin);

        if (strcmp(GradeCode1[StudentFound][2], "A") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 4.00;
            GradePointInSemOnly[StudentFound][2][1] += 4.00;
        }
        else if (strcmp(GradeCode1[StudentFound][2], "A-") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.75;
            GradePointInSemOnly[StudentFound][2][1] += 3.75;
        }
        else if (strcmp(GradeCode1[StudentFound][2], "B+") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.50;
            GradePointInSemOnly[StudentFound][2][1] += 3.50;
        }
        else if (strcmp(GradeCode1[StudentFound][2], "B") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.00;
            GradePointInSemOnly[StudentFound][2][1] += 3.00;
        }
        else if (strcmp(GradeCode1[StudentFound][2], "B-") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.75;
            GradePointInSemOnly[StudentFound][2][1] += 2.75;
        }
        else if (strcmp(GradeCode1[StudentFound][2], "C+") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.50;
            GradePointInSemOnly[StudentFound][2][1] += 2.50;
        }
        else if (strcmp(GradeCode1[StudentFound][2], "C") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.00;
            GradePointInSemOnly[StudentFound][2][1] += 2.00;
        }
        else // if no data, or F
        {
            TotalQualityPoint[StudentFound][1] += 0.00;
            GradePointInSemOnly[StudentFound][2][1] += 0.00;
            // Set to F
            strcpy(GradeCode1[StudentFound][2], "F");
        }

        printf("Course 2 in Sem 2 > ");
        scanf("%s", GradeCode2[StudentFound][2]);
        rewind(stdin);

        if (strcmp(GradeCode2[StudentFound][2], "A") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 4.00;
            GradePointInSemOnly[StudentFound][2][2] += 4.00;
        }
        else if (strcmp(GradeCode2[StudentFound][2], "A-") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.75;
            GradePointInSemOnly[StudentFound][2][2] += 3.75;
        }
        else if (strcmp(GradeCode2[StudentFound][2], "B+") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.50;
            GradePointInSemOnly[StudentFound][2][2] += 3.50;
        }
        else if (strcmp(GradeCode2[StudentFound][2], "B") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.00;
            GradePointInSemOnly[StudentFound][2][2] += 3.00;
        }
        else if (strcmp(GradeCode2[StudentFound][2], "B-") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.75;
            GradePointInSemOnly[StudentFound][2][2] += 2.75;
        }
        else if (strcmp(GradeCode2[StudentFound][2], "C+") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.50;
            GradePointInSemOnly[StudentFound][2][2] += 2.50;
        }
        else if (strcmp(GradeCode2[StudentFound][2], "C") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.00;
            GradePointInSemOnly[StudentFound][2][2] += 2.00;
        }
        else // if no data, or F
        {
            TotalQualityPoint[StudentFound][2] += 0.00;
            GradePointInSemOnly[StudentFound][2][2] += 0.00;
            // Set to F
            strcpy(GradeCode2[StudentFound][2], "F");
        }

        printf("\nCourse 1 in Sem 3 > ");
        scanf("%s", GradeCode1[StudentFound][3]);
        rewind(stdin);

        if (strcmp(GradeCode1[StudentFound][3], "A") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 4.00;
            GradePointInSemOnly[StudentFound][3][1] += 4.00;
        }
        else if (strcmp(GradeCode1[StudentFound][3], "A-") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.75;
            GradePointInSemOnly[StudentFound][3][1] += 3.75;
        }
        else if (strcmp(GradeCode1[StudentFound][3], "B+") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.50;
            GradePointInSemOnly[StudentFound][3][1] += 3.50;
        }
        else if (strcmp(GradeCode1[StudentFound][3], "B") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 3.00;
            GradePointInSemOnly[StudentFound][3][1] += 3.00;
        }
        else if (strcmp(GradeCode1[StudentFound][3], "B-") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.75;
            GradePointInSemOnly[StudentFound][3][1] += 2.75;
        }
        else if (strcmp(GradeCode1[StudentFound][3], "C+") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.50;
            GradePointInSemOnly[StudentFound][3][1] += 2.50;
        }
        else if (strcmp(GradeCode1[StudentFound][3], "C") == 0)
        {
            TotalQualityPoint[StudentFound][1] += 2.00;
            GradePointInSemOnly[StudentFound][3][1] += 2.00;
        }
        else // if no data, or F
        {
            TotalQualityPoint[StudentFound][1] += 0.00;
            GradePointInSemOnly[StudentFound][3][1] += 0.00;
            // Set to F
            strcpy(GradeCode1[StudentFound][3], "F");
        }

        printf("Course 2 in Sem 3 > ");
        scanf("%s", GradeCode2[StudentFound][3]);
        rewind(stdin);

        if (strcmp(GradeCode2[StudentFound][3], "A") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 4.00;
            GradePointInSemOnly[StudentFound][3][2] += 4.00;
        }
        else if (strcmp(GradeCode2[StudentFound][3], "A-") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.75;
            GradePointInSemOnly[StudentFound][3][2] += 3.75;
        }
        else if (strcmp(GradeCode2[StudentFound][3], "B+") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.50;
            GradePointInSemOnly[StudentFound][3][2] += 3.50;
        }
        else if (strcmp(GradeCode2[StudentFound][3], "B") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 3.00;
            GradePointInSemOnly[StudentFound][3][2] += 3.00;
        }
        else if (strcmp(GradeCode2[StudentFound][3], "B-") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.75;
            GradePointInSemOnly[StudentFound][3][2] += 2.75;
        }
        else if (strcmp(GradeCode2[StudentFound][3], "C+") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.50;
            GradePointInSemOnly[StudentFound][3][2] += 2.50;
        }
        else if (strcmp(GradeCode2[StudentFound][3], "C") == 0)
        {
            TotalQualityPoint[StudentFound][2] += 2.00;
            GradePointInSemOnly[StudentFound][3][2] += 2.00;
        }
        else // if no data, or F
        {
            TotalQualityPoint[StudentFound][2] += 0.00;
            GradePointInSemOnly[StudentFound][3][2] += 0.00;
            // Set to F
            strcpy(GradeCode2[StudentFound][3], "F");
        }

        calculator();

        printf("\nSaved!\n");
        system("pause");
        system("cls");
        EditStudent();
        break;

    case 7:
        system("cls");
        AdminPage();
        break;

    default:
        printf("Please check your answer.\n");
        system("pause");
        system("cls");
        EditStudent();
        break;
    }


}


// System only
int calculator() {
    // Total Credit
    // Sem 1
    TotalCredithours[StudentFound][1] = (float)Hour_code1[StudentFound][1] + (float)Hour_code2[StudentFound][1];
    // Sem 2
    TotalCredithours[StudentFound][2] = (float)Hour_code1[StudentFound][2] + (float)Hour_code2[StudentFound][2];
    // Sem 3
    TotalCredithours[StudentFound][3] = (float)Hour_code1[StudentFound][3] + (float)Hour_code2[StudentFound][3];

    // Credit Hours = 0
    if (TotalCredithours[StudentFound][1] == 0 || TotalCredithours[StudentFound][2] == 0 || TotalCredithours[StudentFound][3] == 0)
    {
        // Set all to 0
        GPA[StudentFound][1] = 0;
        GPA[StudentFound][2] = 0;
        GPA[StudentFound][3] = 0;
        CGPA[StudentFound] = 0;
    }
    else {
        // GPA sem 1                         // Grade in sem 1 course 1         *   // Hours in sem 1 course 1 +       // Grade in sem 1 course 1         *   // Hours in sem 1 course 1  /      // Credit hours sem 1
        GPA[StudentFound][1] = (float)((GradePointInSemOnly[StudentFound][1][1] * Hour_code1[StudentFound][1]) + (GradePointInSemOnly[StudentFound][1][2] * Hour_code2[StudentFound][1])) / TotalCredithours[StudentFound][1];

        // GPA sem 2                         // Grade in sem 2 course 1         *   // Hours in sem 2 course 1 +       // Grade in sem 2 course 1         *   // Hours in sem 2 course 1  /      // Credit hours sem 2
        GPA[StudentFound][2] = (float)((GradePointInSemOnly[StudentFound][2][1] * Hour_code1[StudentFound][2]) + (GradePointInSemOnly[StudentFound][2][2] * Hour_code2[StudentFound][2])) / TotalCredithours[StudentFound][2];

        // GPA sem 3                         // Grade in sem 3 course 1         *   // Hours in sem 3 course 1 +       // Grade in sem 3 course 1         *   // Hours in sem 3 course 1  /      // Credit hours sem 3
        GPA[StudentFound][3] = (float)((GradePointInSemOnly[StudentFound][3][1] * Hour_code1[StudentFound][3]) + (GradePointInSemOnly[StudentFound][3][2] * Hour_code2[StudentFound][3])) / TotalCredithours[StudentFound][3];

        // CGPA
        CGPA[StudentFound] = (GPA[StudentFound][1] + GPA[StudentFound][2] + GPA[StudentFound][3]) / 3;
    }
}


// Found Check Information
int FoundCheckStudents() {
    header();

    StudentFound = -1; // Set defaut

    // Student list
    printf("Students List:\n");
    for (int i = 0; i < No_Student; i++)
    {
        printf("KPKL%-5s | %-10s\n", ID_Student[i], Name_Student[i]);
    }

    // Question
    printf("\nWhich Student you want to check?\n");
    printf("Student ID > KPKL");
    char CheckStudent[10] = { 0 };

    scanf("%5s", CheckStudent);
    rewind(stdin);

    // Check the ID
    for (int i = 0; i < No_Student; i++)
    {
        if (strcmp(CheckStudent, ID_Student[i]) == 0) // if detailedit same with ID
        {
            StudentFound = i; // save number to data
            break;
        }
    }

    if (StudentFound == -1) // If not found
    {
        printf("404 Not Found.\n");
        system("pause");
        system("cls");
        AdminPage();
    }
    else
    {
        system("cls");
        CheckStudents();
    }
}


// Check Information
int CheckStudents() {
    header();
    printf("Student's Information:\n");

    printf("Student Name                      : %s\n", Name_Student[StudentFound]);
    printf("Student ID                        : KPKL%s\n\n", ID_Student[StudentFound]);

    printf("Course 1 Code in Sem 1            : %s\n", Course_Code1[StudentFound][1]);
    printf("Credit Hours Course 1 in Sem 1    : %d hours\n", Hour_code1[StudentFound][1]);
    printf("Grade Course 1 in Sem 1           : %s\n", GradeCode1[StudentFound][1]);

    printf("\n");

    printf("Course 2 Code in Sem 1            : %s\n", Course_Code2[StudentFound][1]);
    printf("Credit Hours Course 2 in Sem 1    : %d hours\n", Hour_code2[StudentFound][1]);
    printf("Grade Course 2 in Sem 1           : %s\n", GradeCode2[StudentFound][1]);

    printf("\n");

    printf("Course 1 Code in Sem 2            : %s\n", Course_Code1[StudentFound][2]);
    printf("Credit Hours Course 1 in Sem 2    : %d hours\n", Hour_code1[StudentFound][2]);
    printf("Grade Course 1 in Sem 2           : %s\n", GradeCode1[StudentFound][2]);

    printf("\n");

    printf("Course 2 Code in Sem 2            : %s\n", Course_Code2[StudentFound][2]);
    printf("Credit Hours Course 2 in Sem 2    : %d hours\n", Hour_code2[StudentFound][2]);
    printf("Grade Course 2 in Sem 2           : %s\n", GradeCode2[StudentFound][2]);

    printf("\n");

    printf("Course 1 Code in Sem 3            : %s\n", Course_Code1[StudentFound][3]);
    printf("Credit Hours Course 1 in Sem 3    : %d hours\n", Hour_code1[StudentFound][3]);
    printf("Grade Course 1 in Sem 3           : %s\n", GradeCode1[StudentFound][3]);

    printf("\n");

    printf("Course 2 Code in Sem 3            : %s\n", Course_Code2[StudentFound][3]);
    printf("Credit Hours Course 2 in Sem 3    : %d hours\n", Hour_code2[StudentFound][3]);
    printf("Grade Course 2 in Sem 3           : %s\n", GradeCode2[StudentFound][3]);

    printf("\n");

    printf("GPA in sem 1                      : %.2f \n", GPA[StudentFound][1]);
    printf("GPA in sem 2                      : %.2f \n", GPA[StudentFound][2]);
    printf("GPA in sem 3                      : %.2f \n\n", GPA[StudentFound][3]);

    printf("CGPA                              : %.2f \n\n", CGPA[StudentFound]);

    printf("Click any button to exit.\n");
    system("pause");
    AdminPage();
}


// Student Page
int StudentPage() {
    header();

    // Welcome Page
    printf("Welcome to Student Mode! \n");

    // Choice
    printf("<1> Login Student \n");
    printf("<2> Contact Us\n");
    printf("<3> Back \n");
    printf("\n> ");

    // Answer
    int AS_StudentPage = 0;
    scanf("%d", &AS_StudentPage);
    rewind(stdin);
    switch (AS_StudentPage)
    {
    case 1:
        printf("-----------------------------------------------------------------------\n");

        // Student ID Enter
        char ID_StudentPage[11] = { 0 };

        // ID Enter
        printf("\nPlease enter your id        > KPKL");
        scanf("%14s", ID_StudentPage);
        rewind(stdin);

        // Process Found
        StudentFound = -1; // Set defaut

        for (int i = 0; i < No_Student; i++)
        {
            if (strcmp(ID_StudentPage, ID_Student[i]) == 0) // if detailedit same with ID
            {
                StudentFound = i; // save number to data
                break;
            }
        }

        if (StudentFound == -1) // If not found
        {
            printf("404 Not Found.\n");
            system("pause");
            system("cls");
            main();
        }
        else
        {
            system("cls");
            header();
            printf("Student's Information:\n");

            printf("Student Name                      : %s\n", Name_Student[StudentFound]);
            printf("Student ID                        : KPKL%s\n\n", ID_Student[StudentFound]);

            if (InfoShow == 1)
            {
                printf("Course 1 Code in Sem 1            : %s\n", Course_Code1[StudentFound][1]);
                printf("Credit Hours Course 1 in Sem 1    : %d hours\n", Hour_code1[StudentFound][1]);
                printf("Grade Course 1 in Sem 1           : %s\n", GradeCode1[StudentFound][1]);

                printf("\n");

                printf("Course 2 Code in Sem 1            : %s\n", Course_Code2[StudentFound][1]);
                printf("Credit Hours Course 2 in Sem 1    : %d hours\n", Hour_code2[StudentFound][1]);
                printf("Grade Course 2 in Sem 1           : %s\n", GradeCode2[StudentFound][1]);

                printf("\n");

                printf("Course 1 Code in Sem 2            : %s\n", Course_Code1[StudentFound][2]);
                printf("Credit Hours Course 1 in Sem 2    : %d hours\n", Hour_code1[StudentFound][2]);
                printf("Grade Course 1 in Sem 2           : %s\n", GradeCode1[StudentFound][2]);

                printf("\n");

                printf("Course 2 Code in Sem 2            : %s\n", Course_Code2[StudentFound][2]);
                printf("Credit Hours Course 2 in Sem 2    : %d hours\n", Hour_code2[StudentFound][2]);
                printf("Grade Course 2 in Sem 2           : %s\n", GradeCode2[StudentFound][2]);

                printf("\n");

                printf("Course 1 Code in Sem 3            : %s\n", Course_Code1[StudentFound][3]);
                printf("Credit Hours Course 1 in Sem 3    : %d hours\n", Hour_code1[StudentFound][3]);
                printf("Grade Course 1 in Sem 3           : %s\n", GradeCode1[StudentFound][3]);

                printf("\n");

                printf("Course 2 Code in Sem 3            : %s\n", Course_Code2[StudentFound][3]);
                printf("Credit Hours Course 2 in Sem 3    : %d hours\n", Hour_code2[StudentFound][3]);
                printf("Grade Course 2 in Sem 3           : %s\n\n", GradeCode2[StudentFound][3]);

                printf("GPA in sem 1                      : %.2f \n", GPA[StudentFound][1]);
                printf("GPA in sem 2                      : %.2f \n", GPA[StudentFound][2]);
                printf("GPA in sem 3                      : %.2f \n\n", GPA[StudentFound][3]);

                printf("CGPA                              : %.2f \n\n", CGPA[StudentFound]);
            }
            else {
                printf("Information not done by admin or not yet shared!\n\n");
            }
            printf("Please confirm the information that show don't have any mistake!\n\n");

            printf("If there have any mistake, please contact us.\n\n");
            system("pause");
            system("cls");
            main();
        }

    case 2:
        system("cls");
        header();
        printf("Office Open Time : 07:30 - 12:00\n");
        printf("                 : 14:00 - 18:30\n");
        printf("--------------------------------------------------\n");
        printf("Phone Number     : 03-1122 0227 (Mr On)\n");
        printf("                 : 03-3344 1231 (Mr Yap)\n");
        printf("--------------------------------------------------\n");
        printf("Gmail            : kolejpasar001@gmail.com\n");
        printf("--------------------------------------------------\n");
        printf("Address          : 27, Lorong Lembah Permai Tiga, \n");
        printf("                   11200 Tanjong Bungah,\n");
        printf("                   Pulau Pinang, Malaysia\n");
        printf("--------------------------------------------------\n\n");
        printf("Click any button to exit.\n");

        system("pause");
        system("cls");
        StudentPage();
        break;

    case 3:
        system("cls");
        main();
        break;

    default:
        printf("Please check you answer.\n");
        system("pause");
        system("cls");
        StudentPage();
        break;
    }
}
