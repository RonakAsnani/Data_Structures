#include <bits/stdc++.h>
using namespace std;
#include "Studentsdata.cpp"
int main()
{
    // Student s1(101, 20);
    //s1.age = 20;
    //s1.rollNumber = 101;

    Student s1;

    // cout << s1.rollNumber << " " << s1.age << endl;
    // cout << Student ::totalStudents << endl;

    // s1.totalStudents = 20;

    // Student s2;
    // cout << Student::totalStudents << endl;

    cout << Student::gettotal() << endl;
    return 0;
}