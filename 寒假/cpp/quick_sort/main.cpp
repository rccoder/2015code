#include <iostream>
/*
*quick sort
*/
using namespace std;
const int N = 10;
//find the split_point
int split(int a[], int first, int last)
{
    int split_point, pivot;
    pivot = a[first];
    split_point = a[first];
    for(int unknown = first + 1; unknown <= last; unknown++)
    {
        if(a[unknown] < pivot)
        {
            split_point++;
            int tep = a[split_point];
            a[split_point] = a[unknown];
            a[unknown] = tep;
        }
    }
    a[first] = a[split_point];
    a[split_point] = pivot;
    return split_point;
}
void quick_sort(int a[], int first, int last)
{
    if(first < last)
    {
        int split_point = split(a, first, last);
        quick_sort(a, first, split_point-1);
        quick_sort(a, split_point+1, last);
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
    quick_sort(a, 0, N-1);
    print(a, N);
    return 0;
}
