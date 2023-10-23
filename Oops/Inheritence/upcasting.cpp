
#include <bits/stdc++.h>
using namespace std;

class Bird
{
public:
    // virtual void eat() = 0;
    // virtual void fly() = 0;
    void eat()
    {
        cout << "Parent eating";
    };
    virtual void fly()
    {
        cout << "Parent flying" << endl;
    };
    // virtual void jump() = 0;
};
class sparrow : public Bird
{
public:
    void eat()
    {
        std::cout << "sparrow is eating\n";
    }
    // void fly()
    // {
    //     std::cout << "child is eating\n";
    // }
};
int main()
{
    // upcasting    ==> pointer --parent class      --> object--child class
    Bird *amit = new sparrow();
    // amit->eat();
    amit->fly();

    return 0;
}