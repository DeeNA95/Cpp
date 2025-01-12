#include<iostream>

class Vector {
    public:
        Vector( int s) :elem{new double[s]}, sz{s} {}
        double& operator[] (int i) { return elem[i];}
        int size() { return sz;}
    
    private:
        double* elem;
        int sz;
};

int main(){
    Vector d(6);
    std::cout << d.size() << "\n";
    std::cout << d.operator[](0) << "\n";
    return 0;
}