#include <iostream>
#include <string>
using namespace std;
//�ҵ�root����׺�е�λ�ò��ҶԽڵ���д�ӡ����һλ����0
int findRoot(char p, const string &str)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if(p == str[i])
            return i;
    }
    return -1;
}
/*
 *���ڵݹ�ĺ������ڵݹ��ͬʱ��ӡ�ڵ�
 *@parme
 *
 */
bool toPost(const string &pre, const string &ino)
{
    //�ݹ���������
    if(pre.size() == 0)
    {
        return false;
    }
    //ֻ��һ���ڵ�����
    if(pre.size() == 1)
    {
        cout << pre;
        return true;
    }
    else
    {
        int k = findRoot(pre[0], ino);
        //�ݹ����
        string pretep = pre.substr(1, k);
        string inotep = ino.substr(0, k);
        toPost(pretep, inotep);

        pretep = pre.substr(k+1, pre.size()-k-1);
        inotep = ino.substr(k+1, ino.size()-k-1);
        toPost(pretep, inotep);
        cout << pre[0];
    }
}
int main()
{
    string pre, ino, str;
    while(getline(cin, str))
    {
        int num = str.length()/2;
        pre = str.substr(0, num);
        ino = str.substr(num+1, num);
        toPost(pre, ino);
        cout << endl;
    }
    return 0;
}
