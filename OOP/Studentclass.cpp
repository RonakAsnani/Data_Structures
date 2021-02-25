#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        // shallow copy
        //this->name = name;

        // deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Student(Student const &s)
    {
        this->age = s.age;
        //this ->name = s.name; // shallow copy

        //deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};