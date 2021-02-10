/*Code : Stack Using LL
You need to implement a Stack class using linked list.
The data members should be private.
Implement the following public functions :
1. Constructor -
Initialises the data member (i.e. head to null).
2. push :
This function should take one argument of type T and has return type void. This function should insert an element in the stack. Time complexity should be O(1).
3. pop :
This function takes no input arguments and has return type T. This should removes the last element which is entered and return that element as an answer. Time complexity should be O(1).
4. top :
This function takes no input arguments and has return type T. This should return the last element which is entered and return that element as an answer. Time complexity should be O(1).
5. size :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
6. isEmpty :
Checks if the stack is empty or not. Return true or false.
	*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class StackWithLL
{
private:
    Node<T> *head;
    int size;

public:
    StackWithLL()
    {
        head = NULL;
        size = 0;
    }

    void push(T data)
    {
        Node<T> *newno = new Node<T>(data);

        newno->next = head;
        head = newno;
        size++;
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head->next;
        delete head;
        head = temp;

        size--;
        return ans;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

// int main()
// {
//     StackWithLL<char> s;
//     s.push(100);
//     s.push(101);
//     s.push(102);
//     s.push(103);
//     s.push(104);

//     cout << s.top() << endl;
//     cout << s.pop() << endl;
//     cout << s.pop() << endl;

//     cout << s.pop() << endl;

//     cout << s.getSize() << endl;
//     cout << s.isEmpty() << endl;
// }
