#include <iostream>
/*
*INSERCTION SORT
*/
using namespace std;
const int N = 10;
void inserction_sort(int a[], int n)
{
    for(int j = 1; j < n; j++)
    {
        int key = a[j];
        //insert a[j] into the sorted sequeue a[0, j]
        int i = j - 1;
        while(i >= 0 && a[i] > key)
        {
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
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
    inserction_sort(a, N);
    print(a, N);
    return 0;
}
