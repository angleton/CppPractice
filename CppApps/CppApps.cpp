// CppApps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int arr[] = { 10, 20, 30, 40 };

    // Printing elements of an array using
    // foreach loop
    // Here, int is the data type, x is the variable name
    // and arr is the array for which we want to iterate foreach
    std::cout << "Traversing the array with foreach using array's data type: ";
    for (int x : arr)
        std::cout << x << " ";

    // data type of x is set as int
    std::cout << "\nTraversing the array with foreach using auto keyword     : ";
    for (auto x : arr)
        std::cout << x << " ";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
