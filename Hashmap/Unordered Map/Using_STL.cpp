#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    unordered_map<string, int> m;

    // insertion Methods

    pair<string, int> p = make_pair("Amit", 21);
    m.insert(p);

    pair<string, int> myPair("love", 143);
    m.insert(myPair);

    m.emplace("Shani", 22);

    // read

    cout << m.at("Amit") << endl;
    cout << m["Shani"] << endl;

    // Varsha key is not present
    //  cout << m.at("Varsha") << endl;

    // if ravi key --> not present ==> create ravi key--- > and assign 0 to it.
    cout << m["Ravi"] << endl;
    m["mona"] = 20;
    m["mona"] = 22;
    cout << m["mona"] << endl;
    cout << m.size() << endl;

    m.erase("mona");

    m.emplace("one", 1);
    m.emplace("two", 2);
    m.emplace("three", 3);
    m.emplace("four", 4);
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        // unorder--- > jis order mein insert kiya uuuse agar bhi aa sakta
        cout << it->first << " " << it->second << " ";
        it++;
    }
    cout << endl;
}