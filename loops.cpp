#include <iostream>

bool accept()
{
std::cout << "Do you want to proceed (y or n)?\n";// write question

char answer = 0;
std::cin >> answer;// read answer

if (answer == 'y') return true;
return false;
}

int main(){
    accept();
    return 0;
}
