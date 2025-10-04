#include <iostream>

using namespace std;

class Student
{
public:
    int roll_num;
    const int age;

    Student() : roll_num(58), age(45) {};

    Student(int roll_num, int age): roll_num(roll_num), age(age){};

    void display() {
        cout << "Roll Number: " << roll_num << endl;
        cout << "Age: " << age << endl;
    }


};

int main()
{

    Student s1(20, 18);

    s1.display();

    return 0;
}