#include <iostream>
#include <string>

int main (){
    // usual equal sign
    int r = 4;
    // curly braces assignment 
    // int p {5};
    // std::cout << r << "\n" << p;
    // double u {0.2};
    // int i2 {7};
    // std::vector<int> v ={1,2,3};
    // the type does not have to be explicitly called can be decided using the auto
    auto b = true;
    // std::cout << typedef(b);

    // operators
    int x = 50;
    std::cout<< x << -x << "\n";
    int new_val = --x;
    std::cout << new_val<< "\n";


    return 0;
}