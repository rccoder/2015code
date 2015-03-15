#include <iostream>
#include <string.h>
#define MAX 101
#define N 28
using namespace std;

int S[N][N];
int visited[N], lowcost[N];

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;
        //初始化
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                S[i][j] = MAX;
                S[j][i] = MAX;
            }
        }
        //遍历输入，寻找每个点
        for(int i = 1; i <= n-1; i++){
            //两个点
            char first, second;
            //点的所有支的数目和与某一节点之间的长度
            int num, edge;
            cin >> first >> num;
            for(int j = 1; j <= num; j++){
                cin >> second >> edge;
                //从1开始计数
                S[first-'A'+1][second-'A'+1] = edge;
                S[second-'A'+1][first-'A'+1] = edge;
            }

        }
        //cout << "输入完毕！" << endl;
        //prim算法


        int result = 0;
        memset(visited, 0, sizeof(visited));
        memset(lowcost, MAX, sizeof(lowcost));
        //标记低一个节点已经被访问
        visited[1] = 1;
        //pos是标记
        int pos = 1;
        for(int i = 1; i <= n; i++){
            if(i != pos){
                lowcost[i] = S[pos][i];
            }
        }
        for(int i = 1; i <= n; i++){
            int min = MAX+1;
            //遍历每个节点找最短的
            for(int j = 1; j <= n; j++){
                if(!visited[j] && min > lowcost[j]){
                    min = lowcost[j];
                    //标记下访问的位置
                    pos = j;
                }
            }
            //防止最后一次把min算进来
            if(min != MAX+1)
                result += min;
           // cout << min << endl;
            //标记已经被访问
            visited[pos] = 1;
            //重新生权树
            for(int j = 1; j <= n; j++){
                if(!visited[j] && lowcost[j] > S[pos][j]){
                    lowcost[j] = S[pos][j];
                }
            }
        }
        cout << result << endl;
    }
}

