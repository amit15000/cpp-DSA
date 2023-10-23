#include <bits/stdc++.h>
using namespace std;

//<-------------------- Yes, we can make constructor private----------------->
class Box
{
    friend class BoxFactory;
    friend void Show_Box(string name_of_box, const Box &a);

private:
    int width;
    static int borderWidth;
    int height; // height of all boxes--> same;
    // private constructor   ---it will be compiled without error
    // Box(int _val)
    // {
    //     width = _val;
    // }
    Box(int _val, int _h) : width(_val), height(_h){}; // initialization list.
public:
    void getWidth() const
    {
        cout << width << endl;
    }
    void setWidth(int _val)
    {
        width = _val;
    }

    // //not working
    //     void Box::setBorderWidth(int _val)
    //     {
    //         // Box::borderWidth = _val;
    //         Box::borderWidth = _val;
    //     }

    void getBorderWidth() const
    {
        cout << borderWidth << endl;
    }
    void Show_Box()
    {
        const type_info &info = typeid(this);
        cout << "\nName :" << info.name() << endl;
        printf("Width = %d\nHeight = %d\nBorder-Width = %d\n", width, height, borderWidth);
    }
};
int Box::borderWidth = 22;

class BoxFactory
{
    // height of all objects of this particular factory should be same.
public:
    int height;
    BoxFactory(int _h)
    {
        height = _h;
    }

    Box getABox(int _w)
    {

        // function of return type = ' class '
        Box b(_w, height);
        return b;
    }
};

int main()
{
    // Box box1; // error because--- only constructor  is  private.==> no default constructor exist.
    // so we have to make a friend class BoxFactory --- that would be friend of Box class --and it will initialize the instances of Box.

    // create box using box factory.

    // All boxes have same border width , so -->
    // int Box::void setBorderWidth(10);

    // working

    // Set border-width of all total boxes == 10

    // Box::setBorderWidth(22); //not working

    // Each factory produces all the boxes of same height
    //  eg --- factory1 all boxes ==> height =10
    //  eg --- factory2 all boxes ==> height =20
    BoxFactory factoryNumber1(15);
    BoxFactory factoryNumber2(51);

    // making boxes of factoryNumber1;
    //  width of all boxes are varying.
    Box BoxF1b1 = factoryNumber1.getABox(8);
    Box BoxF1b2 = factoryNumber1.getABox(88);
    Box BoxF1b3 = factoryNumber1.getABox(888);

    // making boxes of factoryNumber2;
    //  width of all boxes are varying.
    Box BoxF2b1 = factoryNumber2.getABox(8);
    Box BoxF2b2 = factoryNumber2.getABox(88);
    Box BoxF2b3 = factoryNumber2.getABox(888);

    // expected output--->
    // 3 boxes == = > having different width, same height, (all - total border - width = same)

    // Box *bn = NULL;

    // for (int i = 1; i < 4; i++)
    // {
    //     // string boxName = "BoxF" + i;       //error bcz it will return pointer of type const char* to the ith index of char;
    //     string boxName = "BoxF" + to_string(i) + 'b' + to_string(i);

    //     boxName.Show_Box();
    //     BoxF1b3.Show_Box();

    //     // cout << boxName << endl;
    // }
    BoxF1b1.Show_Box();
    BoxF1b2.Show_Box();
    BoxF2b1.Show_Box();
    BoxF2b2.Show_Box();
    return 0;
}