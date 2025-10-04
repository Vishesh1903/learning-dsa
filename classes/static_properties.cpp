#include <iostream>

using namespace std;

class Student{
    public:
    int roll_num;
    int age;
    static int total_students;

    Student(){
        roll_num = 58;
        age = 45;
        total_students++;
    }
    Student(int roll_num, int age){
        this->roll_num = roll_num;
        this->age = age;
        total_students++;
    }

};

int Student::total_students = 0;


int main(){
    Student s1(20, 18);
    Student s2;

    cout << Student::total_students << endl;

    return 0;

}