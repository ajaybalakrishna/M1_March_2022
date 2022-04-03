/**
 * @file Empolyee_details.h
 * @author Ajay B (ajaybalakrishna2001m@gmail.com)
 * @brief Header file for Empolyee details
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _EMPLOYEE_MANAGE_OPERATIONS_
#define _EMPLOYEE_MANAGE_OPERATIONS_


/**
 * @brief Add one new Empolyee details to the databae file 
 */
void AddEmployee();


/**
 * @brief lists all the Empolyee details present in database file
 */
void ListEmployee();


/**
 * @brief delete the user entered employee details 
 */
void DeleteEmployee();


/**
 * @brief Modify the user entered Employee details 
 */
void ModifyEmployee();


/**
 * @brief search and list the user entered Employee details 
 */
void SearchEmployee();

#endif /* #define _EMPLOYEE_MANAGE_OPERATIONS_ */
