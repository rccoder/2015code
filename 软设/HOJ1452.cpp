#include <iostream>
#include <string>
using namespace std;
//找到root在中缀中的位置并且对节点进行打印，第一位置是0
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
 *用于递归的函数，在递归的同时打印节点
 *@parme
 *
 */
bool toPost(const string &pre, const string &ino)
{
    //递归结束的情况
    if(pre.size() == 0)
    {
        return false;
    }
    //只有一个节点的情况
    if(pre.size() == 1)
    {
        cout << pre;
        return true;
    }
    else
    {
        int k = findRoot(pre[0], ino);
        //递归进行
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
