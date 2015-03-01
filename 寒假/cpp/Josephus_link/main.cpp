#include <iostream>
using namespace std;
struct Node
{
    int no;
    Node *next;
};
int main()
{
    int n, m;
    cout << "Please input the number of the children:";
    cin >> n;
    cout << "Please input the number which was said:";
    cin >> m;
    Node *first, *last;
    first  = last = new Node;
    first->no = 0;
    for(int i = 0; i < n; i++)
    {
        Node *p = new Node;
        p->no = 0;
        last->next = p;
        last = p;
    }
    last->next = first;
    Node *previous  = last;
    while(n > 1)
    {
        for(int count = 1; count < m; count ++)
        {
            previous = previous->next;
        }
        Node *p = previous->next;
        previous->next = p->next;
        delete p;
        n--;
    }
    cout << "The winner is No" << previous->no << endl;
    delete previous;
    return 0;
}
