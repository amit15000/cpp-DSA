#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    // string line;

    // //    getline(input,output,delimeter)
    // getline(cin, line);

    // cout << line << endl;

    // // custom delimeter  by default " "

    // string amit = "12,43,534,5634r6";
    // stringstream ass(amit);
    // string str;

    // while (getline(ass, str, ','))
    // {
    //     cout << str << " ";
    // }


    string input = "12,45,566,4,67,89,00";
    stringstream mid(input);
    string res;
    string temp;

    while(getline(mid,temp,',')){
        res += temp + 'a';
        cout<<temp;
    }
    cout<<res;
}
