#include <iostream>
/*
* The question of Josephus
*/
using namespace std;
const int N = 100, M = 5;
int main()
{
    bool in_circle[N];
    //init the is_circle
    for(int index = 0; index < N; index++)
    {
        in_circle[index] = true;
    }
    //the index of the child before the say
    int index = N - 1;
    //the number of child before of the say
    int num_of_circle = N;
    while(num_of_circle > 1)
    {
        //the success of say
        int count = 0;
        while(count < M)
        {
            index = (index + 1) % N;
            if(in_circle[index])
            {
                count ++;
            }
        }
        in_circle[index] = false;
        num_of_circle --;
    }
    for(index = 0; index < N; index++)
    {
        if(in_circle[index])
        {
            break;
        }
    }
    cout << "The winner is No." << index << endl;
    return 0;
}
