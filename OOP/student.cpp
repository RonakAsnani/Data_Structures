#include <iostream>
using namespace std;
#include "Oop.cpp"

int main()
{
    Student s1;
    Student s2, s3, s4;

    //s1.age = 24;
    s1.rollNumber = 101;
    // cout << s1.age << endl;

    s1.display();

    // dynamically
    Student *s5 = new Student;

    //(*s5).age = 23;
    (*s5).rollNumber = 90;

    //s5->age = 23;
    s5->rollNumber = 104;

    //(*s5).display();
    s5->display();

    cout << s1.getage() << " " << (*s5).getage();
    return 0;
}