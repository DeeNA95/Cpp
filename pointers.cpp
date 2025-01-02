#include <iostream>

int main(){
    // array of character elements
    char name[6] = "Derek"; // usual null pointer taking up one array space like C
    std::cout << name << "\n";

    // pointer
    // to a character can be declared like this
    char* p = &name[0];
    // prints out everything from index 0 to the end 
    std::cout << p << "\n";

    char c = *p;
    // only prints out what p is pointed to
    std::cout << c << "\n";


    return 0;
}