#include <iostream>
using namespace std;

int length (char string_arr[]){
    int count = 0;
    while(string_arr[count] != '\0'){
        count++;
    }
    return count;
}

int main() {
    char str[15] = "Hello, World!";
    // char arr[10] works differently we do not have to initialize every value of arr instead we can just assign a string using cin and output works the same by assigning it to cout
    //once we give the input using cin last index will automatically be assigned to null character
    // we can also use string class from string header file
    // we can use length() function to get the length of the string 
    // but if we self assign a string to char arr then we have to manually assign null character at the end
    cout << "Length of the string: " << length(str) << endl;
    return 0;
}