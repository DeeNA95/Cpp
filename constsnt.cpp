#include <iostream>

constexpr double double_it (double x){
    return 2 * x;
}

int main(){

    // constant wont be changed no matter what
    const double d = 17;
    std::cout<< d << "\n";
    // ++d; wont work
    constexpr int c = 8;
    // requires the function to be declared constexpr
    constexpr double v = 1.5 * double_it(c);
    std::cout << v;


    return 0;
}