#include <bits/stdc++.h>
using namespace std;

class Animal
{
private:
    int weight;

public:
    string name;
    int age;

    // default constructor

    Animal()
    {
        cout << "Default constructor called" << endl;
    }

    // parametrised constructor
    Animal(int weight)
    {
        cout << "Default constructor 2 called" << endl;
    }

    Animal(string name, int age, int weight)
    {
        this->age = age;
        this->name = name;
        this->weight = weight;
        cout << "Default constructor 3 called" << endl;
    }

    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->name = obj.name;
        this->weight = obj.weight;
    }
    // setter
    int setWeight(int weight)
    {
        // weight =w;

        // This will not work properly now
        //  weight = weight;

        // this is a pointer thats points to the current object.
        // this->weight or (*this)->weight it means that the-- - at the weight of "current object".

        this->weight = weight;
        // or
        // (*this).weight = weight;
    }

    // getter
    int getWeight()
    {
        return weight;
    }
    void print()
    {
        cout << "Name :" << this->name << endl
             << "Age :" << this->age << endl
             << "Weight :" << this->weight << endl;
    }
};

int main()
{

    // // static allocation
    // Animal amit;
    // Animal amit2();
    // Animal varsha(10);

    // // amit.name = "Dog";
    // // amit.setWeight(19);
    // // cout << "Name : " << amit.name << endl;
    // // cout << "Weight : " << amit.getWeight() << endl;

    // // dynamic allocation

    // Animal *sumit = new Animal;

    // Animal *sumit2 = new Animal(10, "Sumit");
    // // sumit->name = "Cat";
    // // (*sumit).age = 14;
    // // cout << sumit->name << endl;
    // // cout << (*sumit).age << endl;

    // // sumit->setWeight(25);
    // // cout << sumit->getWeight() << endl;

    // // copy of oject

    Animal a3("Amit", 19, 70);
    Animal b3(a3);
    // b3.print();
    a3.age = 10;

    cout << "a3 ->" << endl;
    a3.print();
    cout << "b3 ->" << endl;
    b3.print();

    return 0;
}