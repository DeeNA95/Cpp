#include <iostream>

double square(double x) {
    return x * x;
}

void print_square (double x) {
    std::cout<<"The square of " << x << " is " << square(x) <<"\n";
}//with void the program returns no value as such return is unneccesary

int main () {
    print_square(50.450399303);
    return 0;

}