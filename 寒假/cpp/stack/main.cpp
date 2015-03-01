/*
*过程
*/
#include <iostream>
using namespace std;
const int STACK_SIZE = 100;
struct Stack
{
    int top;
    int buffer[STACK_SIZE];
};
void init(Stack &S)
{
    S.top = -1;
}
bool push(Stack S, int i)
{
    if(S.top == STACK_SIZE - 1)
    {
        cout << "Stack is overflow!" << endl;
        return false;
    }
    else
    {
        S.top ++;
        S.buffer[S.top] = i;
        return true;
    }
}
bool pop(Stack &S)
{
    if(S.top == -1)
    {
        cout << "The stack is empty";
        return false;
    }
    else
    {
        int i = S.buffer[S.top];
        S.top--;
        return true;
    }
}
int peek(Stack &S)
{
    if(S.top == -1)
    {
        cout << "The stack is empty!";
    }
    else
    {
        return S.buffer[S.top];
    }
}



/*
*Object Stack
*/
#include <iostream>
using namespace std;
const int STACK_SIZE = 100;
class Stack
{
    int top;
    int buffer[STACK_SIZE];
    public:
        Stack()
        {
            top = -1;
        }
        bool push(int i)
        {
            if(top == STACK_SIZE - 1)
            {
                cout << "The Stack is overflow!";
                return false;
            }
            else
            {
                top++;
                buffer[top]  = i;
                return true;
            }
        }
        bool pop(int &i)
        {
            if(top == -1)
            {
                cout << "The stack is empty!";
                return false;
            }
            else
            {
                i = buffer[top];
                top--;
                return true;
            }
        }
        int peek(int i)
        {
            if(top == -1)
            {
                cout << "The stack is empty!";
            }
            else
            {
                i = buffer[top];
            }
        }
};
/*
*using
*/
Stack st;
int x;
st.push(12);
st.pop(x);

st.top++;//error_category
st.buffer[st.top] = 12; //Error
