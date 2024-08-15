#include <iostream>
#include <string>

int main()
{
    std::string s1 = "example"; // Replace with your actual string
    int i = 5;                  // Replace with your desired end position

    for (int x = 0; x <= i; ++x)
    {
        if (x <= i && x >= 0)
        { // Ensure x is within valid range
            std::string substring = s1.substr(x, i - x + 1);
            std::cout << "Substring from position " << x << " to " << i << " is: " << substring << std::endl;
        }
    }

    return 0;
}
