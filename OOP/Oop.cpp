class Student
{
public:
    int rollNumber;

private:
    int age;

public:
    ~Student()
    {
        cout << "destructor" << endl;
    }

    Student()
    {
        cout << "called" << endl;
    }
    Student(int rollNumer)
    {
        cout << " second call" << endl;
        rollNumber = rollNumber;
    }
    Student(int a, int r)
    {
        cout << "trice" << endl;
        age = a;
        rollNumber = r;
    }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }
    int getage()
    {
        return age;
    }
    void setage(int a)
    {
        age = a;
    }
};
