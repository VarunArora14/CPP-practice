Aim: Write a program to find the greatest of two given
numbers in two different classes using friend function.

Theory: A friend function of a class is defined outside that
class' scope but it has the right to access all private and
protected members of the class. Even though the
prototypes for friend functions appear in the class
definition, friends are not member functions.

A friend can be a function, function template, or member
function, or a class or class template, in which case the
entire class and all of its members are friends.

friend class <classname>;

Source Code :

#include <iostream>
    using namespace std;
class one;
class second;
class one
{
    int num;

public:
    friend int greatest(one num, second num1);
    void enter()
    {
        cout << "Enter 1st num" << endl;
        cin >> num;
    }
};
class second
{
    int num1;

public:
    friend int greatest(one num, second num1);
    void enter()
    {
        cout << "Enter 2nd num" << endl;
        cin >> num1;
    }
};
int greatest(one a, second b)
{
    if (a.num > b.num1)
        return a.num;
    else
        return b.num1;
}
int main()
{
    one num;
    num.enter();
    second num1;
    num1.enter();
    cout << "Maximum Number" << endl;
    cout << greatest(num, num1);
    return 0;
}