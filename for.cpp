#include <iostream>
#include <initializer_list>

void print(){
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for(auto x : v) // for each x in v
        std::cout << x << "\n";
    for (auto x : {10.1,21.4,32.6})
        std::cout << x << "\n";
}

// also follows the normal c for loop

// can also use & reference
void decrement (){
    double v[] =  {0,1,2,3,4,5,6,7,8,9};
    // & means with reference to
    for(auto& x:v)
        std::cout << x--<< "\t"<< x << "\n";
}

int main(){
    print();
    decrement();
    return 0;
}
