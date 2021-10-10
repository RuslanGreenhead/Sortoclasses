#include <iostream>
#include "generator.h"
#include "employee.cpp"


int main() {
    generate_csv("newsort.csv", 10);
    Employee* my_list = get_array_from_csv("newsort.csv", 10);
    return 0;
}