#pragma once

using namespace std;

class Employee{
public:
    Employee() = default;
    friend Employee* get_array_from_csv(const std::string filename, int num_of_items);

private:
    string m_name;
    string m_surname;
    string m_faculty;
    string m_specialty;

    int m_score;
};