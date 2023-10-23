#include <bits/stdc++.h>
using namespace std;

class Animal
{

public:
    // by defalut
    void cooking()
    {
        cout << " I'm parent class ---> cooking " << endl;
    }

    // ab compiler parent class jiska pointer hai use call karega -- Animal---- to Dog ke speak() ko call karega ab ;

    // void speak()
    // {
    //     cout << " I'm parent class ---> speaking" << endl;
    // }

    // ab compiler actual object ke funtion ko call karega -- new Dog ---- to Dog ke speak() ko call karega ab ;
    virtual void speak()
    {
        cout << " I'm parent class ---> speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    // function speak is being overridden ---- it's runtime polymorphism
    void speak()
    {
        cout << "I'm child class --->barking" << endl;
    }
};

int main()
{
    // Varsha v1;
    // Amit a1;
    // Amit a2;

    // a2.cooking();
    // a2.speak();

    // dynamic allocation

    // upcasting     =======     pointer jise banaya hai ---- us class ka function call hoga.
    Animal *a = new Dog;
    a->speak();
    // downcasting     =======     pointer jise banaya hai ---- us class ka function call hoga.
    // Dog *b = new Animal;      it is giving error

    // explicitly typecasting to Dog pointer type

    // downcasting
    Dog *b = (Dog *)new Animal;
    // (Dog *): This is a typecast. It's trying to convert the pointer to an Animal object into a pointer to a Dog object. This is called a downcasting. Downcasting is when you try to cast a pointer from a base class (in this case, Animal) to a pointer of a derived class (Dog). This operation can be dangerous if the object being pointed to is not actually of the derived class type.

    // speaking of the child class
    b->speak();

    // cooking of the parent class
    b->cooking();
    // v1.speak();
    // a1.speak();

    return 0;
}
