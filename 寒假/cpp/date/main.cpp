#include <iostream>
using namespace std;
#include "date.h"
int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    date some_day;
    some_day.set(y, m, d);
    some_day.print();
    if(some_day.is_leap_year())
    {
        cout << "Is leap year!" << endl;
    }
    else
    {
        cout << "Isn't leap year!" << endl;
    }
    return 0;
}
