#include <iostream>

struct Vector {
    int sz;         // Number of elements
    double* elem;   // Pointer to elements
};

// Initialize vector
void vector_init(Vector& v, int s) {
    v.elem = new double[s];  // Allocate an array of s doubles
    v.sz = s;
}

// Function to read elements into the vector and calculate the sum
double read_and_sum(int s) {
    Vector v;
    vector_init(v, s);   // Initialize vector with size s

    std::cout << "Enter " << s << " numbers:" << std::endl;
    for (int i = 0; i < v.sz; ++i) {
        std::cin >> v.elem[i];  // Read elements into the vector
    }

    double sum = 0;
    for (int i = 0; i < v.sz; ++i) {
        sum += v.elem[i];  // Sum up the elements
    }

    delete[] v.elem;  // Clean up memory
    return sum;
}
// use . to access the struct member through name and reference
// -> to access through pointer
void f(Vector v, Vector& rv, Vector* pv){
    int i = v.sz;
    int o = rv.sz;
    int p = pv->sz;
}

int main() {
    std::cout << "Sum: " << read_and_sum(5) << std::endl;  // Example usage
    
    return 0;
}