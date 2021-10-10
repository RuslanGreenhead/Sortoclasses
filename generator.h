#pragma once
#include <string>
#include <fstream>
#include <ctime>


using namespace std;

const string digits[]= {"0","1","2","3","4","5","6","7","8","9"};

const string surnames [101] = {"Molokanov", "Adams", "Allen", "Armstrong", "Atkinson", "Bailey", "Baker", "Ball",\
"Bell", "Brown", "Burton", "Carter", "Clarke", "Cole", "Collins", "Davidson", "Davies", "Dawson", "Dixon", "Edwards",\
"Elliot", "Evans", "Fisher", "Fletcher", "Ford", "Foster", "Fox", "Gibson", "Graham", "Grant", "Gray", "Green",\
"Griffiths", "Hall", "Hamilton", "Harris", "Harvey", "Hill", "Jackson", "James", "Jenkins", "Johnson", "Jones",\
"Kelly", "Kennedy", "King", "Knight", "Lawrence", "Lee", "Lewis", "Lloyd", "Marshall", "Martin", "Mason", "McDonald",\
"Murphy", "Natt", "Nelson", "Nightingale", "Nixon", "Nutter", "O’Dell", "Osborne", "Owen", "Oxley", "Page", "Painter",\
"Palmer", "Pastor", "Peterson", "Quill", "Quimby", "Quintrell", "Ramsey", "Ratliff", "Richards", "Roberts", "Robinson",\
"Scott", "Simpson", "Smith", "Stewart", "Taylor", "Thomas", "Thompson", "Turner", "Walsh", "Ward", "Webb", "West",\
"White", "Yalden", "Yarbury", "Yardley", "Yarrow", "Yates", "Young", "Zachary", "Zelly", "Zinc", "Zouch"};
const int surnames_number = 101;

const string names [99]= {"Wade","Dave","Seth","Ivan","Riley","Gilbert","Jorge","Dan","Brian","Roberto",\
"Ramon","Miles","Liam","Nathaniel","Ethan","Lewis","Milton","Claude","Joshua","Glen","Harvey","Blake",\
"Antonio","Connor","Julian","Aidan","Harold","Conner","Peter","Hunter","Eli","Alberto","Carlos","Shane",\
"Aaron","Marlin","Paul","Ricardo","Hector","Alexis","Adrian","Kingston","Douglas","Gerald","Joey","Johnny",\
"Charlie","Scott","Martin","Tristin","Troy","Tommy","Rick","Victor","Jessie","Neil","Ted","Nick","Wiley",\
"Morris","Clark","Stuart","Orlando","Keith","Marion","Marshall","Noel","Everett","Romeo","Sebastian",\
"Stefan","Robin","Clarence","Sandy","Ernest","Samuel","Benjamin","Luka","Fred","Albert","Greyson","Terry",\
"Cedric","Joe","Paul","George","Bruce","Christopher","Mark","Ron","Craig","Philip","Jimmy","Arthur",\
"Jaime","Perry","Harold","Jerry","Shawn"};
const int names_number = 99;

const string  faculties[10] = {"Electronics", "Mathematics", "Psychology", "Philisophy", "Biology", "Media and design",\
"History", "Geography", "Computer science", "Cryptography"};
const int faculties_number = 10;

const string  specialties[5] = {"A", "B", "C", "D", "E"};
const int specialties_number = 5;

const int email_domens_amount = 3;
string email_domens[] = {"yandex.ru", "gmail.com", "yahoo.com"};

// Generate phone number
string  get_phone(){
    string tel = "+7";
    for (int i =0; i < 10; i ++){
        tel += digits[ rand() % 10 ];
    }
    return tel;
}

// Generate email
string get_email(string name, string surname){
    string email = name + "_" + surname + "@" + email_domens[rand() % email_domens_amount];
    return email;
}

// Generate CSV data in the current folder
void generate_csv(const string filename, int num_of_items){
    std::ofstream sorting_data_stream;
    sorting_data_stream.open(filename, std::ios::out);

    srand(time(NULL));

    string name, surname;

    for (int index =0; index < num_of_items; index ++){

        name = names[rand() % names_number];
        surname = surnames[rand() % surnames_number];

        sorting_data_stream << name << ',' << surname << ',' << faculties[rand() % faculties_number] \
        << ',' << specialties[rand() % specialties_number] << ',' << rand() % 301 << endl;
    }

    sorting_data_stream.close();
}