#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main()
{
    vector<int> v;
    int x;
    cin >> x;
    while(x > 0){
        v.push_back(x);
        cin >> x;
    }
    vector<int> :: iterator it1 = v.begin();
    vector<int> :: iterator it2 = v.end();

    cout << "MAX:" << *max_element(it1, it2) << endl;


    cout << "SUM:" << accumulate(it1, it2, 0) <<endl;


    sort(it1, it2);
    cout << "Sorted:" << endl;
    while(it1 != it2){
        cout << *it1 << " ";
        it1++;
    }
    cout << endl;

    return 0;
}
