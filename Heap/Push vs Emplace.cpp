#include <iostream>
#include <queue>

class MyElement
{
public:
    int value;

    // Constructor
    MyElement(int val) : value(val)
    {
        std::cout << "Constructing MyElement with value: " << value << std::endl;
    }
};

int main()
{
    std::priority_queue<MyElement> myQueue;

    // Using push to insert elements
    myQueue.push(MyElement(10));
    myQueue.push(MyElement(5));

    // Using emplace to directly construct and insert elements
    myQueue.emplace(15);
    myQueue.emplace(7);

    // No explicit constructor call needed when using emplace
    myQueue.emplace(25);

    // Print the elements in descending order (since it's a max heap)
    while (!myQueue.empty())
    {
        std::cout << myQueue.top().value << " ";
        myQueue.pop();
    }

    return 0;
}
