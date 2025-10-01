#include <iostream>

using namespace std;

class Student
{
public:
    int roll_num;
    int age;

    Student(){
        roll_num = 58;
        age = 45;
    }
    Student(int roll_num){
        this->roll_num = roll_num;
    }
    Student(int roll_num, int age)
    {
        this->roll_num = roll_num;
        this->age = age;
    }

    void show()
    {
        cout << "Roll Number: " << roll_num << endl;
        cout << "Age: " << age << endl;
    }

    void setAge(int age){
        this->age = age;
    }
    void setRollnum(int roll_num){
        this->roll_num = roll_num;
    }
    int getAge(){
        return age;
    }
    int getRollnum(){
        return roll_num;
    }
};

int main()
{
    Student *s1 = new Student(20, 18);
    Student s2;
    s1->show();

    s2.setAge(s1->getAge());
    s2.setRollnum(s1->getRollnum());
    s2.show();
    return 0;
}