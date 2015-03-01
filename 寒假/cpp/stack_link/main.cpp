#include <iostream>
using namespace std;
class Stack
{
    public:
        Stack()
        {
            top = NULL;
        }
        bool push(int i);
        bool pop(int &i);
    private:
        struct Node
        {
            int content;
            Node *next;
        } *top;
};
bool Stack::push(int i)
{
    Node *p = new Node;
    //can't get the adress
    if(p == NULL)
    {
        cout << "The stack is overflow!" << endl;
        return false;
    }
    else
    {
        p->content = i;
        p->next = top;
        top = p;
        return true;
    }
}
bool Stack::pop(int &i)
{
    if(top == NULL)
    {
        cout << "Stack is empty!" << endl;
        return false;
    }
    else
    {
        Node *p = top;
        top = p->next;
        i = p->content;
        delete p;
        return true;
    }
}
