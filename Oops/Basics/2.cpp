#include <iostream>
using namespace std;

class Car
{
private:
    int srn;
    int weight;
    int maxSpeed;
    int speed;

public:
    Car(int x)
    {
        this->srn = x;
    }

    void setSpeed(int s)
    {
        this->speed = s;
    }

    void run()
    {
        cout << "Car is running at speed " << this->speed;
    }
};

int main()
{

    Car *XUV = new Car(576);
    XUV->setSpeed(14);
    XUV->run();

    Car xr340(44);
    xr340.setSpeed(12);
    xr340.run();
}
