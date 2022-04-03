#include "unity/unity.h"
#include "Empolyee_operation.h"

#define PROJECT_NAME "EMPLOYEE_MANAGE_"

extern void AddEmployee();
extern void DeleteEmployee();
extern void SearchEmployee();
extern void ListEmployee();
extern void ModifyEmployee();
void setUp()
 {

 }

void tearDown()
 {

 }

int main()
{
   UNITY_BEGIN();

    RUN_TEST(AddEmployee);
    RUN_TEST(ListEmployee);
    RUN_TEST(ModifyEmployee);
    RUN_TEST(SearchEmployee);
    RUN_TEST(DeleteEmployee);
  return (UNITY_END());
}
