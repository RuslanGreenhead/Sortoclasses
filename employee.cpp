#include <iostream>
#include <fstream>
#include "employee.h"

// Read strings from CSV into objects + aggregate them into array
Employee* get_array_from_csv(const std::string filename, int num_of_items){
    std::ifstream sorting_data_stream;
    sorting_data_stream.open(filename, std::ios::in);

    auto* list = new Employee[num_of_items];
    int i = 0;

    for(std::string str; std::getline(sorting_data_stream, str); ){

        Employee item = Employee();
        size_t position = 0;
        std::string delimiter = ",";
        std::string token;

        position = str.find(delimiter);
        token = str.substr(0, position);
        item.m_name = token;
        str.erase(0, position + delimiter.length());

        position = str.find(delimiter);
        token = str.substr(0, position);
        item.m_surname = token;
        str.erase(0, position + delimiter.length());

        position = str.find(delimiter);
        token = str.substr(0, position);
        item.m_faculty = token;
        str.erase(0, position + delimiter.length());

        position = str.find(delimiter);
        token = str.substr(0, position);
        item.m_specialty = token;
        str.erase(0, position + delimiter.length());

        position = str.find(delimiter);
        token = str.substr(0, position);
        item.m_score = std::stoi(token);
        str.erase(0, position + delimiter.length());

        list[i] = item;
        i++;
    }
    return list;
}