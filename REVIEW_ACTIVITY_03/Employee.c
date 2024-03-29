#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

HourlyEmployee newEmployee(int id, String name, String gender, float hours) {
    HourlyEmployee he;
    
    he.idNumber = id;
    strcpy(he.name, name);
    strcpy(he.gender, gender);
    he.totalHoursWorked = hours;

    return he;
}
void displayEmployee(HourlyEmployee he) {
    printf("ID: %d\n", he.idNumber );
    printf("NAME: %s\n", he.name );
    printf("GENDER: %s\n", he.gender );
    printf("HOURS WORKED: %.2f\n", he.totalHoursWorked );
}

void initList(List *list) {
    list->max = 2;
    list->employees = malloc(sizeof(HourlyEmployee) * list->max);
    list->count=0;
}
void addEmployee(List *list, HourlyEmployee emp) {
    if(list->count==list->max){
	        list->max *= 2;
	        
	        HourlyEmployee *newEmp = (HourlyEmployee*)realloc(list->employees, sizeof(HourlyEmployee) * list->max);
	        if (newEmp == NULL) {
	            printf("Memory allocation error!\n");
	            return;
	        }
	        
	        list->employees = newEmp;
	    }
	    list->employees[list->count++] = emp;
	}
void displayEmployeeList(List list){
    int i;
    printf("%10s | %30s | %10s\n", "ID", "NAME", "GENDER");
    for( i = 0; i<list.count; ++i){
        printf("%10d | %30s | %10s\n", list.employees[i].idNumber, list.employees[i].name, list.employees[i].gender);
    }
    printf("\n");
}
List getFemaleEmployees(List list) {
    int i,ctr;
    List females;
    initList(&females);
    for( i=0; i<list.max; i++) {
        if(!strcmp(list.employees[i].gender, "female")){
            addEmployee(&females,list.employees[i]);
        }
    }
    return females;
}