#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream outFile;
    string first;
    string last;
    int age;
   
    // Prompt the user for their first name
    std::cout << " Enter your first name : " << std::endl;
    getline(cin, first);
   
    // Prompt the user for their last name
    std::cout << " Enter your last name : " << std::endl;
    getline(cin, last);
   
    // Prompt the user for their age
    std::cout << " Enter enter your age : " << std::endl;
    std::cin >> age;
   
   
    outFile.open("output_file.txt");
    outFile << " First name : " << "\t" << first << std::endl;
    outFile << " Last name : " << "\t" << last << std::endl;
    outFile << " Age : " << "\t" << age << std::endl;
   
    outFile.close();

    return 0;
}
