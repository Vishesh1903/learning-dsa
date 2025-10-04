#include <iostream>

using namespace std;

class Student
{
public:
    int roll_num;
    char* name;

    Student(int roll_num, char* name)
    {
        this->roll_num = roll_num;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display(){
        cout << "Roll Number: " << roll_num << endl;
        cout << "Name: " << name << endl;
    }

    ~Student(){
        delete [] name;
    }
};

int main()
{
    char name[] = "Vishesh";
    Student* s1 = new Student(20, name);
    s1->display();

    Student* s2 = new Student(25, name);
    s2->name[0] = 'A';
    s2->display();
    s1->display();

    delete s1;
    delete s2;

    return 0;
}