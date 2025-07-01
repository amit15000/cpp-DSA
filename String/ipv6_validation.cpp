#include <bits/stdc++.h>
using namespace std;

bool isValidSegment(string &s)
{
    int n = s.length();

    // Length must be between 1 and 4
    if (n == 0 || n > 4)
        return false;

    // Check if all characters are valid hexadecimal digits
    for (char c : s)
    {
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
            return false;
    }

    return true;
}

// Function to check if a given string is a valid IPv6 address
bool isValid(string &ip)
{
    int colonCount = 0;
    int len = ip.length();

    // Count the number of colons
    for (char c : ip)
    {
        if (c == ':')
            colonCount++;
    }

    // An IPv6 address must have exactly 7 colons
    if (colonCount != 7)
        return false;

    // Split manually by ':'
    string segment;
    int segmentCount = 0;

    for (int i = 0; i < len; i++)
    {
        if (ip[i] == ':')
        {
            if (!isValidSegment(segment))
                return false;
            segment.clear();
            segmentCount++;
        }
        else
        {
            segment += ip[i];
        }
    }

    if (!isValidSegment(segment))
        return false;

    return segmentCount == 7;
}

int main()
{
    string ip1 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    string ip2 = "fe80::1";
    string ip3 = "2001:db8:85a3::8a2e:370:7334";
    string ip4 = "2001:0db8:85a3:xyz:0000:8a2e:0370:7334";

    cout << (isValid(ip1) ? "Valid\n" : "Not valid\n");
    cout << (isValid(ip2) ? "Valid\n" : "Not valid\n");
    cout << (isValid(ip3) ? "Valid\n" : "Not valid\n");
    cout << (isValid(ip4) ? "Valid\n" : "Not valid\n");

    return 0;
}