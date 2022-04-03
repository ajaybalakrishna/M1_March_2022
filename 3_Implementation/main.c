#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct Employee
{
    char empID[15];
    char fname[20];
    char lname[20];
    int age;
    float bsal;
    char phone[10];
} Employee;
FILE *fp;
Employee emp;
char fileName[]="EMP.txt";
char tempFileName[]="temp.txt";

#include "Empolyee_operation.c"


int main()
{
	int choice;

	fp = fopen("data.txt", "rb+");

	if (fp == NULL) {
		
		fp = fopen("data.txt", "wb+");
		
		if (fp == NULL) {
			printf("\nCannot open file...");
			exit(1);
		}
	}

	while (1) 
	{
		system("cls");
		
		printf("\n1. Add Employee\n");
		
		printf("\n2. DELETE Employee\n");
		
        printf("\n3. List Employee\n");
	    
        printf("\n4. MODIFY Employee\n");
		
		printf("\n5. Search Employee\n");
		
		printf("\n6. EXIT\n");
		
		printf("\nENTER YOUR CHOICE - ");
		
		scanf("%d", &choice);
        fflush(stdin);
			switch (choice) 
			{
		    case 1:
		       AddEmployee();
			   break;

		    case 2:
			   DeleteEmployee();
			   break;

		    case 3:
               ListEmployee();
			   break;

		    case 4:

     			ModifyEmployee();
	    		break;
            case 5:
             
			   SearchEmployee();
               break; 
		    case 6:
			   fclose(fp);
			   exit(0);
			   break;

		     default:
			 printf("\nINVALID CHOICE...\n");
 			}
	}

	return 0;
}
