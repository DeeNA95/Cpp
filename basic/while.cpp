#include <iostream>

bool answer(){
    int tries = 0;
    while (tries < 3)
    {
       std::cout << "What is your answer ( y or n)\n";
       char answer = 0;
       std::cin >> answer;

       switch (answer)
       {
       case 'y':
        return true;
    
       case 'n':
        return false;
       
       default:
        ++tries;
        std::cout << "Defaulted to NO\n";
        
       }
    }
    std::cout<< "Taken Value as NO\n";
}

int main(){
    answer();
    return 0;
}