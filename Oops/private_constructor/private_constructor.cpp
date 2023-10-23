#include <bits/stdc++.h>
using namespace std;

//<-------------------- Yes, we can make constructor private----------------->
class Box
{
    friend class BoxFactory;

private:
    int width;
    // private constructor   ---it will be compiled without error
    // Box(int _val)
    // {
    //     width = _val;
    // }
    Box(int _val) : width(_val){}; // initialization list.
public:
    void getWidth() const
    {
        cout << width << endl;
    }
    void setWidth(int _val)
    {
        width = _val;
    }
};
class BoxFactory
{
    int count;

public:
    Box getABox(int _w)
    { // function of return type = ' class '
        Box b(_w);
        return b;
    }
};

int main()
{
    // Box box1; // error because--- only constructor  is  private.==> no default constructor exist.
    // so we have to make a friend class BoxFactory --- that would be friend of Box class --and it will initialize the instances of Box.

    // create box using box factory.

    BoxFactory factory1;
    Box box1 = factory1.getABox(12);
    box1.getWidth();
    return 0;
}