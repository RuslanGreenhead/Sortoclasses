#include <iostream>
#include <fstream>
#include "employee.h"
#include "iomanip"

bool Employee::operator > (const Employee &object) {
    if(m_score > object.m_score){
        return true;
    }else if(m_score < object.m_score){
        return false;
    }else{
        return (m_surname + m_name) > (object.m_surname + object.m_name);
    }
}

bool Employee::operator < (const Employee &object) {
    if(m_score < object.m_score){
        return true;
    }else if(m_score > object.m_score){
        return false;
    }else{
        return (m_surname + m_name) < (object.m_surname + object.m_name);
    }
}

bool Employee::operator >= (const Employee &object){
    return !(*this < object);
}

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

// Print n_of_items first items of the list to the console
void PrintList(Employee* list, int num_of_items){
    for(int i = 0; i < 89; i++){
        std::cout << "-";
    }
    std::cout << std::endl;

    std::cout << std::setw(15) << std::left << "NAME" << " | ";
    std::cout << std::setw(15) << std::left << "SURNAME" << " | ";
    std::cout << std::setw(20) << std::left << "FACULTY" << " | ";
    std::cout << std::setw(15) << std::left << "SPECIALTY" << " | ";
    std::cout << std::setw(15) << std::left << "SCORE" << " | ";
    std::cout << std::endl;

    for (int i = 0; i < num_of_items; i++) {
        for(int i = 0; i < 94; i++){
            std::cout << "-";
        }
        std::cout << std::endl;

        std::cout << std::setw(15) << std::left << list[i].m_name << " | ";
        std::cout << std::setw(15) << std::left << list[i].m_surname << " | ";
        std::cout << std::setw(20) << std::left << list[i].m_faculty << " | ";
        std::cout << std::setw(15) << std::left << list[i].m_specialty << " | ";
        std::cout << std::setw(15) << std::left << list[i].m_score << " | ";
        std::cout << std::endl;
    }

    for(int i = 0; i < 94; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}