#include <iostream>

bool accept()
{
std::cout << "Do you want to proceed (y or n)?\n";// write question

char answer = 0;
std::cin >> answer;// read answer
switch (answer)
{
case 'y':
    return true;
case 'n':
    return false;

default:
    std::cout << "Selected No";
    return false;
}
}

int main(){
    accept();
    return 0;
}