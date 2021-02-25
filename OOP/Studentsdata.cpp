#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    static int totalStudents;

public:
    int age;
    int rollNumber;

    Student()
    {
        totalStudents++;
    }

    int getroll()
    {
        return rollNumber;
    }
    static int gettotal()
    {
        return totalStudents;
    }
    //int &x;

    // Student(int r, int age) : rollNumber(r), age(age), x(this->age)
    // {
    //     // rollNumber = r;
    // }
};
int Student ::totalStudents = 0; // initialize static data members