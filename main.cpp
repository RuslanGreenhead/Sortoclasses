#include <iostream>
#include "generator.h"
#include "employee.cpp"


void BubbleSort(Employee* list, int num_of_items){};
//...
void ShuffleSort(Employee* list, int num_of_items){};

int main() {
    generate_csv("newsort.csv", 10);
    Employee* my_list = get_array_from_csv("newsort.csv", 10);
    PrintList(my_list, 10);
    return 0;
}