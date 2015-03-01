#include <iostream>
#include <cstdlib>
#include "Vector.h"
#include "Matrix.h"
using namespace std;
/*
*the cpp can become more quick by friendly function
*drect***** get the private
*english is pool*****
*………………
class Vector
{
    friend void multiply(Matrix &m, Vector &v, Vector &r);
};

class Matrix
{
    friend void multiply(Matrix &m, Vector &v, Vector &r);
};

void multiply(Matrix &m, Vector &v, Vector &r)
{
    if(m.col != v.num || m.row != r.num)
    {
        cout << "The data is error!" << endl;
        exit(-1);
    }
    int *p_m = m.p_data, *p_v =v.p_data, *p_r;
    for(int i = 0; i < m.row; i++)
    {
        *p_r = 0;
        p_v = v.p_data;
        for(int j = 0; j < m.col; j++)
        {
            *p_r += (*p_m)*(*p_v);
            p_m++;
            p_v++;
        }
        p_r++;
    }
}

*/
void multiply(Matrix &m, Vector &v, Vector &r)
{
    if(m.get_col() != v.get() || m.get_row() != r.get())
    {
        cout << "The data is error!" << endl;
        exit(-1);
    }
    int row = m.get_row(), col = m.get_col();
    for(int i = 0; i < row; i++)
    {
        r.element(i) = 0;
        for(int j = 0; j < col; j++)
        {
            r.element(i) = m.element(i, j) * v.element(j);
        }
    }
}
int main()
{
    int row, column;
    cout << "Please input the row and column about the Matrix" << endl;
    cin >> row >> column;
    Matrix m(row, column);
    Vector v(column);
    Vector r(row);
    cout << "Please input the data of the Matrix:" << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cin >> m.element(i, j);
        }
    }
    cout << "Please input the data of the Vector:" << endl;
    for(int i = 0; i < column; i++)
    {
        cin >> v.element(i);
    }
    multiply(m, v, r);
    cout << "Matrix:" << endl;
    m.display();
    cout << "Vector:" << endl;
    v.display();
    cout << "Multiply:" << endl;
    r.display();
    return 0;
}
