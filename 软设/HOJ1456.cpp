#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>
#include <queue>


#define R 1000002
#define T 1002


using namespace std;


int v[R];
bool flag[T];
queue <int> q[T], m;
int main()
{
    int s, L, U, count = 0;
//S代表有几组数据
    cin >> s;
    string Judge = "";
    int tep;
    memset(flag, true, T);
    memset(v, 0, R);
    while(s != 0)
    {
        count++;
        cout << "Scenario #" << count << "\n";
        for(int i = 1; i <= s; i++)
        {
//L代表每组有多少人
            cin >> L;
            for(int j = 1; j <= L; j++)
            {
                cin >> tep;
                v[tep] = i;
            }
        }
        cin >> Judge;
        while(Judge[0] != 'S')
        {


            if(Judge[0] == 'E')
            {
                cin >> tep;
                U = v[tep];
                q[U].push(tep);
                if(flag[U])
                {
                    m.push(U);
                    flag[U] = false;
                }
            }
            if(Judge[0] == 'D')
            {
                U = m.front();
                while(q[U].empty())
                {
                    m.pop();
                    flag[U] = true;
                    U = m.front();
                }
                cout << q[U].front() << "\n";
                q[U].pop();
            }
            cin >> Judge;
        }
        for(int i = 1; i <= L; i++)
        {
            while(!q[i].empty())
            {
                q[i].pop();
            }
        }
        while(!m.empty())
        {
            m.pop();
        }
        cout << "\n";
        cin >> s;
        memset(flag, true, T);
        memset(v, 0, R);
    }
}
