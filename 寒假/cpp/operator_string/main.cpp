#include <iostream>
#include <cstring>
#include <cstdlib>
#include "String.h"
using namespace std;
bool operator == (const String &s1, const String &s2)
{
    return (strcmp(s1.str, s2.str) == 0);
}
bool operator == (const String &s, const char * p)
{
    return (strcmp(s.str, p) == 0);
}
bool operator == (const char *p, const String &s)
{
    return (strcmp(p, s.str) == 0);
}
String operator + (const String &s1, const String &s2)
{
    String temp(s1);
    temp += s2;
    return temp;
}
String operator + (const String &s, const char *p)
{
    String temp(s);
    temp += p;
    return temp;
}
String operator + (const char *p, const String &s)
{
    String temp(p);
    temp += s;
    return temp;
}

int main()
{
    String s1;
    String s2("abcdefg");
    String s3;
    s1 = "xyz";
    s2 += s1;
    s3 = s1 + s2;
    for(int i = 0; i < s2.length(); i++)
    {
        if(s2[i] >= 'a' && s2[i] <= 'z')
            s2[i] = s2[i] - 'a' + 'A';
    }
    if(s2 == "ABCDEFGXYZ")
        cout << "OK" << endl;
    cout << s1 << endl << s2 << endl << s3 << endl;
    return 0;
}
