#include <iostream>

using namespace std;


class Student{
    int roll_num;
    int* age;

    public: 
    Student(){
        roll_num = 58;
        *age = 45;
    }
    Student(int roll_num, int age) {
        this->roll_num = roll_num;
        this->age = new int;
        *(this->age) = age;
    }

    Student(const Student &s){
        roll_num = s.roll_num;
        age = s.age; // shallow copy
    }

    void setAge(int age){
        *(this->age) = age;
    }

    void show(){
        cout << "Roll Number: " << roll_num << endl;
        cout << "Age: " << *age << endl;
    }
    ~Student(){
        delete age;
    }
};

int main(){

    Student s1(20, 18);
    Student s2(s1); // copy constructor called
    s2.show();
    s2.setAge(25);
    s1.show(); // age of s1 also changes due to shallow copy
    s2.show(); 
    return 0;
}