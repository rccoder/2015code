#include <iostream>
#define M 101
#define INF 999999
using namespace std;
int MAP[M][M];
int main()
{
    int n, v, e;
    int v1, v2, length;
    //输入test的组
    cin >> n;
    for(int i = 0; i < n; i++){
        //点和边的个数
        cin >> v >> e;
        //初始化
        for(int k = 0; k < v; k++){
            for(int j = 0; j < v; j++){
            if(k ==j) MAP[k][j] = 0;
            //设置无穷大路径
            else MAP[k][j] = INF;
            }
        }
        //储存节点距离
        for(int j = 0;  j < e; j++){
            cin >> v1 >> v2 >> length;
            MAP[v1][v2] = length;
            MAP[v2][v1] = length;
        }
        //floyd,找最短路径
        for(int k = 0; k < v; k++){
            for(int j = 0; j < v; j++){
                for(int l = 0; l < v; l++){
                    if(MAP[j][l] > MAP[j][k]+MAP[k][l]){
                        MAP[j][l] = MAP[j][k]+MAP[k][l];
                    }
                }
            }
        }
        //get the sum
        int tep = INF;
        //a表示开始的节点
        int a, sum;
        for(int k = 0; k < v; k++){
            sum = 0;
            for(int j = 0; j < v; j++){
                sum += MAP[k][j];
            }
            //找最小的一个
            if(tep > sum){
                tep = sum;
                a = k;
            }
        }
        cout << a << " " << tep << endl;

    }
    return 0;
}

