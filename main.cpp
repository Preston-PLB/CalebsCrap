// File: homework 5.cpp
// Author: Caleb Angell
// Date: 2/7/21
// This program reads a file to output the min, max, and mean of the contents.
#include<fstream>      // Used to read the .txt file
#include <iostream>    // Provides cin and cout
#include <cassert>     // Provides assert function

using namespace std;   // Allows all standard library items to be used

// Precondition: Requires an array of integers A[] as well as m, the size of the array
// Postcondition: Will error check to prevent overflows, and will output the size of the integers that were read
int getNumbers(long long *p,int m) {
    string  fileLine    =           ""; // Temp entry to hold lines in
    int     i           =            0; // Counter for the loop
    long long n         =            0; // Place Holder for the entries found

    while(cin >> n){               // Loop to load up the data
        cout << i << ": " << n << std::endl;    //mean output
        assert(i<100);	// No longer needed due to using a pointer
	p[i] = n;
	m++;
        i++;
    }
    cout << m << " is the number of integers in the array" << std::endl;
    return i;
}

// Precondition: Requires an array of integers A[] as well as m, the size of the array
// Postcondition: Will output min, max and sum
void examineNumbers(long long *p,int n) {
    int     min         =            0; // Place Holder for the min value found
    int     max         =            0; // Place Holder for the max value found
    int     sum         =            0; // Place Holder for the sum value found

    for (int i=0;i<=n;i++){             // Loop to find min, max, and sum
        if(p[i]<min){
            min=p[i];
        }
        else if(p[i]>max){
            max=p[i];
        }
        sum+=p[i];
    }
    cout << "The minimum value is: " << min << std::endl;   //Min output
    cout << "The maximum value is: " << max << std::endl;   //max output
    cout << "The mean value is: " << sum/n << std::endl;    //mean output
}

//Precondition: A list of numbers with a max of 100 integers can be input, negative or positive
//Postcondition: The Program will output the quantity of integers in the list, the min, max, and mean
int main( ) {
    long long     p[100]                  ; // Array of the input data
    int     m           =            0; // Entry for the size of the input
    int     n           =            0; // Entry for the size of the input
    ifstream in("./hw5list.txt");     //input .txt file

    cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt

    n=getNumbers(p,m);
    examineNumbers(p,n);
    cout << "99" << ": " << p[99] << std::endl;    //mean output

    return EXIT_SUCCESS;
}
