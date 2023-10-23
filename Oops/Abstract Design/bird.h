#if !defined(BIRD_h)
#define BIRD_h
#include <iostream>
class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class sparrow : public Bird
{
public:
    void eat()
    {
        std::cout << "sparrow is eating\n";
    }
    void fly()
    {
        std::cout << "sparrow is flying\n";
    }
};

class eagle : public Bird
{
public:
    void eat()
    {
        std::cout << "eagle is eating\n";
    }
    void fly()
    {
        std::cout << "eagle is flying\n";
    }
};
class koyal : public Bird
{
public:
    void eat()
    {
        std::cout << "koyal is eating\n";
    }
    void fly()
    {
        std::cout << "koyal is flying\n";
    }
};
#endif // BIRD_h
