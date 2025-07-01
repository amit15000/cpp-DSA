#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string line;

    //    getline(input,output,delimeter)
    getline(cin, line);

    cout << line << endl;

    // custom delimeter  by default " "

    string amit = "12,43,534,5634r6";
    stringstream ass(amit);
    string str;

    while (getline(ass, str, ','))
    {
        cout << str << " ";
    }
}
