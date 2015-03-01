#include <iostream>
#include <cstdlib>
#include <cstring>
#include "String.h"
using namespace std;
int main()
{
    String s1;
    String s2("abcdefg");
    s1.copy("xyz");
    s2.append(s1);
    for(int i = 0; i < s2.length(); i++)
    {
        if(s2.char_at(i) >= 'a' && s2.char_at(i) <= 'z')
        {
            s2.char_at(i) = s2.char_at(i)-'a'+'A';
        }

    }
    if(s2.compare("ABCDEFGXYZ") == 0)
        {
            cout << "ok!" << endl;
        }
        cout << s1.get_str() << endl << s2.get_str() << endl;
    return 0;
}
