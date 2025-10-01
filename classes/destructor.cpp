#include <iostream>

using namespace std;

class Student
{
public:
    int roll_num;
    int age;

    Student()
    {
        roll_num = 58;
        age = 45;
    }
    Student(int roll_num)
    {
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

    void setAge(int age)
    {
        this->age = age;
    }
    void setRollnum(int roll_num)
    {
        this->roll_num = roll_num;
    }
    int getAge()
    {
        return age;
    }
    int getRollnum()
    {
        return roll_num;
    }

    ~Student(){
        cout << "Destructor called" << endl;
    }
};

int main()
{
    Student *s1 = new Student(20, 18);
    Student *s2 = new Student(*s1);
    s2->show();
    
    Student s3(*s1);
    s3.show();
    
    Student s5(50, 50);
    Student s4(90, 100);
    delete s1;
    delete s2;


    return 0;
}