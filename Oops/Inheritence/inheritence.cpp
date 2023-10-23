#include <bits/stdc++.h>
using namespace std;

// parent class
class Animal
{
private:
    int age;

public:
    string name;
    int weight;

    string sound;
    // all the data memebers are in private, so it is 100% encapsulation.

    // parametrised constructor
    // Animal(string name, int wt, int age, string sound)
    // {
    //     this->name = name;
    //     this->weight = wt;
    //     this->age = age;
    //     this->sound = sound;
    // }
    void eat()
    {
        cout << "Eating" << endl;
    }
};

// child class

class Dog : public Animal // method of inheritance = public.
{
};

int main()
{
    Dog amit;
    amit.name = "Amit";
    amit.weight = 70;
    // amit.age = 12;    age private hai --- wo inherit nahi hoga--- if mode of inheritance is PUBLIC
    amit.sound = "bark";
    amit.eat();
    return 0;
}