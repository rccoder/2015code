#include <iostream>
/*
*sel_sort
*/
using namespace std;
const int N = 10;
int max(int a[], int n)
{
    int j = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[j])
        {
            j = i;
        }
    }
    return j;
}
void sel_sort(int a[], int n)
{
    int j;
    for(int i = n; i > 1; i--)
    {
        //the max number called j which is in a from 0 to i
        j = max(a, i);
        //swap the i-1 and j
        int tep = a[j];
        a[j] = a[i-1];
        a[i-1] = tep;
    }
}
void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sel_sort(a, N);
    print(a, N);
    return 0;
}
