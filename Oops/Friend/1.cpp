#include <bits/stdc++.h>
using namespace std;

// parent class
class Animal
{
    friend class Human;           // class ko friend banaya.
    friend void print(Animal &a); // function ko friend banya.
private:
    int age;

public:
    string name;
    int weight;

    void setAge(int _val)
    {
        age = _val;
    }

    void eat()
    {
        -cout << "Eating" << endl;
    }
};

// child class

class Human
{
public:
    void getAge(const Animal &a)
    {
        cout << a.age << endl; // before making this Human class friend of  Animal(target) class , we can't access private member of the Animal class
    }
};
void print(Animal &a)
{
    cout << a.age << endl;
}

int main()
{
    Animal a;
    a.setAge(12);

    Human h;
    // h.getAge(a);

    print(a);
    return 0;
}