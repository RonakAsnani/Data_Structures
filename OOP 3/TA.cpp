#include <bits/stdc++.h>
using namespace std;
#include "teacher.cpp"
#include "student.cpp"

class TA : public Teacher, public Student
{
public:
    void print()
    {
        cout << "TA" << endl;
    }
};
