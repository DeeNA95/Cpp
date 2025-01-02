#include "stdio.h"
#include "iostream" 
#include <string>
#include <list>
//we can avoid using std:: before each call by making the namespsace global
using namespace std; // generally not preferred

void f(int ppp)
    {
        cout<< ppp * 2<<"\n\n";
    }

int main()
{
    int integer_variable = 50; // initialises and integer variable
    int declared_int; // declares the integer variable without assigning a value
    printf("this is an integer variable %d\n\n", integer_variable + 1);
    declared_int = integer_variable * 5;
    printf("This is the new value of declared_int %d\n\n", declared_int);
    //the printf in from the stdio.h and is c code
    //c ++ uses the iostream and std::cout to print
    std::cout<<"This is a print out using std::out\n\n";
    //the namespace for the the standard c++ library
    // the headers string and list are also standard and allow for implementation of lists and strings
    std::string s="Four legs Good;two legs Baaad!"; 
    std::list<std::string> slogans;
    // eg after making the namespace global
    string g="mama oohooh\n\n";
    std::cout<<s;
    float decimal = 5.99;
    double decimal2 = 5.7744999;
    float rem = decimal / decimal2;
    printf("\n\nthis is the rem to 2 dp %.2f\n\n", rem);

    float bep = integer_variable / decimal2;
    printf("this is bep %f\n\n", bep);


    bool A = false;
    printf("%d\n", A);

    int pp = 5;
        cout<<"val of pp is ";
        cout<<pp;
        cout<<"\n\n";
    
    //alternatively
    cout<<"the val of pp is "<<pp<<"\n\n";

    //the string type
    string s1 = "laadeedaadeedaa";
    string s2 = "slob on me knob";
    // allows for concatenation
    string s3 = s1+" " +s2 + "\n\n";
    cout<<s3;
    s3+="top five\n\n";//adds top five to the end of s3
    cout<<s3;

    f(pp);
    
    //more functions in string header
    string name = "Derek Nsoh Amuna";
    //subsetting
    string sub = name.substr(6,10);
    cout<< sub << "\n\n";

    return 0;
}

