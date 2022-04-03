#include "Empolyee_details.h"

void AddEmployee()
{
    char another,ch;
    do
    {
        system("cls");

        fseek(fp,0,SEEK_END);

        another='Y';

        printf("\n\nADD EMPLOYEE RECORD\n\n");
        printf("  1. ENTER EMPLOYEE ID: ");
        gets(emp.empID);
        printf("\n  2. ENTER FIRST NAME OF EMPLOYEE: ");
        gets(emp.fname);
        printf("\n  3. ENTER LAST NAME OF EMPLOYEE: ");
        gets(emp.lname);
        printf("\n  4. ENTER AGE OF EMPLOYEE: ");
        scanf("%d",&emp.age);
        printf("\n  5. ENTER SALARY OF EMPLOYEE: ");
        scanf("%f",&emp.bsal);
        printf("\n  6. ENTER PHONE OF EMPLOYEE:");
        scanf("%s",emp.phone);
        printf("\nSAVE CHANGE (y/n)? - ");
        ch=getch();
        if(ch=='y'||ch=='Y')
        {
            fwrite(&emp,sizeof(emp),1,fp);
            fflush(stdin);
        }

        printf("\n\nADD ANOTHER EMPLOYEE(Y/N)? - ");

        another=getch();
        fflush(stdin);
    }
    while(another=='Y'|| another=='y');
}

void SearchEmployee()
{
    int i,datafound=0;
    char employeeId[15];
    char another,ch;
    do
    {
        fseek(fp,0,SEEK_SET);

        printf("\n\nSEARCH EMPLOYEE RECORD\n\n");

        printf("ENTER EMPLOYEE ID: ");
        gets(employeeId);
        while(fread(&emp,sizeof(emp),1,fp)==1)
        {
            if(strcmp(emp.empID,employeeId)==0)
        {
        datafound=1;
        break;
        }
        }
        if(datafound==1)
        {
            printf("\n\nRECORD OF EMPLOYEE");

            //printf("——————–");

            printf("\n\nEMPLOYEE ID :");
            printf("%s",emp.empID);

            printf("\n\nFIRST NAME :");
            printf("%s",emp.fname);

            printf("\n\nLAST NAME :");
            printf("%s",emp.lname);

            printf("\n\nAGE :");
            printf("%d",emp.age);

            printf("\n\nBASIC SALARY :");
            printf("%.2f",emp.bsal);

            printf("\n\nPHONE :");
            printf("%s",emp.phone);
        }
        else
        {
            printf("\n\nEMPLOYEE NOT FOUND!!!!!");
        }

        printf("\n\nSEARCH ANOTHER EMPLOYEE(Y/N)? ");
        fflush(stdin);
        another=getch();
        fflush(stdin);
    }
    while(another=='Y'|| another=='y');
}

void ModifyEmployee()
{
    system("cls");
  int i, datafound=0,recordNo=0;
    char employeeId[15];
    char another,ch;
    do
    {

        fseek(fp,0,SEEK_SET);
        rewind(fp);

        printf("\n\nMODIFY EMPLOYEE RECORD\n\n");

        printf("ENTER EMPLOYEE ID TO BE MODIFIED - ");
        gets(employeeId);
        while(fread(&emp,sizeof(emp),1,fp)==1)
        {
            //printf("\n%s-",emp.empID);
            emp.empID[strcspn(emp.empID, "\n")] = 0;
            if(strcmp(emp.empID,employeeId)==0)
            {
                datafound=1;
                break;
            }
            recordNo++;
        }
        if(datafound==1)
        {
            printf("\nOLD RECORD FOUND\n\n");

            printf("EMPLOYEE ID : ");
            printf("%s",emp.empID);

            printf("\n\nFIRST NAME : ");
            printf("%s",emp.fname);

            printf("\n\nLAST NAME : ");
            printf("%s",emp.lname);

            printf("\n\nAGE : ");
            printf("%d",emp.age);

            printf("\n\nBASIC SALARY : ");
            printf("%.2f",emp.bsal);

            printf("\n\nPHONE :");
            printf("%s",emp.phone);

            printf("\n\nENTER NEW EMPLOYEE DETAILS");
            printf("\n\nEMPLOYEE ID:");
            gets(emp.empID);

            printf("\nFIRST NAME :");
            gets(emp.fname);

            printf("\nLAST NAME :");
            gets(emp.lname);

            printf("\nAGE :");
            scanf("%d",&emp.age);

            printf("\nBASIC SALARY :");
            scanf("%f",&emp.bsal);

            printf("\nPHONE :");
            scanf("%s",emp.phone);
            fseek(fp,sizeof(emp)*(recordNo),SEEK_SET);

            if(fwrite(&emp,sizeof(emp),1,fp)==1)
              printf("\nTHE RECORD HAS BEEN MODIFIED!!!!!");
            else
              printf("\nEROR DURING MODIFICATION!!!!!");
        }
        else
        {
            printf("\n\nEMPLOYEE NOT FOUND!!!!!");
        }

        printf("\n\nMODIFY ANOTHER EMPLOYEE(Y/N)?");
        fflush(stdin);
        another=getch();
        fflush(stdin);

    }
          while(another=='Y'||another=='y');
}


void DeleteEmployee()
{
    int i,datafound=0;
    char employeeId[15];
    FILE *fpTemp;
    char another,ch;
    do
    {
        fseek(fp,0,SEEK_SET);
        rewind(fp);

        printf("\n\nDELETE EMPLOYEE RECORD\n\n");

        printf("ENTER EMPLOYEE ID TO BE DELETED - ");
        gets(employeeId);
        while(fread(&emp,sizeof(emp),1,fp)==1)
        {
            if(strcmp(emp.empID,employeeId)==0)
            {
                datafound=1;
                break;
            }
        }
        if(datafound==1)
        {
            fpTemp=fopen(tempFileName,"wb");
            rewind(fp);
            while(fread(&emp,sizeof(emp),1,fp)==1)
            {
                if(strcmp(emp.empID,employeeId)!=0)
                    fwrite(&emp,sizeof(emp),1,fpTemp);
            }
            fclose(fp);
            fclose(fpTemp);
            remove(fileName);
            rename(tempFileName,fileName);
            fp=fopen(fileName,"rb+");

            printf("\nSUCCESSFULLY DELETED!!!!!");
        }
        else
        {
            printf("\nEMPLOYEE NOT FOUND!!!!!");
        }
        printf("\n\nDELETE ANOTHER EMPLOYEE(Y/N)?");
        fflush(stdin);
        another=getch();
        fflush(stdin);

    } while(another=='Y'|| another=='y');
}
void ListEmployee()
{
    //system("cls");

    fseek(fp,0,SEEK_SET);

    printf("\n\nLIST OF EMPLOYEE RECORD\n\n");

    printf("EMP ID        ");

    printf("FIRST NAME    ");

    printf("LAST NAME     ");

    printf("AGE           ");

    printf("PHONE         ");

    printf("SALARY        \n");
    int i;
    for(i=1;i<=80;i++)
    {
        printf("-");
    }
    i=5;
    while(fread(&emp,sizeof(emp),1,fp)==1)
    {
        printf("\n%s",emp.empID);
        for(int i=0;i<14-strlen(emp.empID);i++)
        {printf(" ");}

        printf("%s",emp.fname);
        for(int i=14;i<28-strlen(emp.fname);i++)
        {printf(" ");}

        printf("%s",emp.lname);
        for(int i=28;i<42-strlen(emp.lname);i++)
        {printf(" ");}

        printf("%d",emp.age);
        for(int i=42;i<56-2;i++)
        {printf(" ");}

        printf("%s",emp.phone);
        for(int i=56;i<70-10;i++)
        {printf(" ");}

        printf("%.2f",emp.bsal);
        i++;
    }
    getch();
}
