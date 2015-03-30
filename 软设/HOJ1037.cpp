#include <iostream>
#include <cstdlib>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#define N 205
#define INF 999999
using namespace std;

int P, Q;
int R1, R2, C1, C2;
int Z[N][N];
int step[N][N];
int D[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//
bool visible(int tepx, int tepy, int X, int Y, bool judge)
{
    //同行同列
    if(tepx == X)
        return true;
    else if(tepx > X){
        swap(tepx, X);
        swap(tepy, Y);
    }
    int z1 = judge ? Z[tepx][tepy] : Z[tepy][tepx];
    int z2 = judge ? Z[X][Y] : Z[Y][X];
    int dx = X - tepx;
    int dy = Y - tepy;
    int dz = z2 - z1;
    int y = 2*dx*(tepy) + dy;
    int z = (2*z1+1)*dx + dz;
    int m = (dy > 0) ? 1 : 0;
    for(int k = tepx+1; k <= X; k++){
        int ry = (y+dx-m) / (2*dx);
        int ry2 = (y+dx+m-1) / (2*dx);
        if(judge){
            if(z < Z[k-1][ry]*2*dx || z < Z[k][ry2]*2*dx) return false;
        }
        else{
            if(z < Z[ry][k-1]*2*dx || z < Z[ry2][k]*2*dx){
               return false;
            }
        }
        z += 2*dz;
        y += 2*dy;
    }
    return true;
}

bool see(int tepx, int tepy, int X, int Y)
{
    //cout << 1 << endl;
    //true 和 false 分别代表××××××××××
    return visible(tepx, tepy, X, Y, true) && visible(tepy, tepx, Y, X, false);
}

bool go(int x, int y, int tepx, int tepy)
{
    //if(x == 3 && y == 0){
      //  cout << "来了" <<endl;
    //}
    //保证不超不回退
    if(tepx < 0 || tepx >= P || tepy < 0 || tepy >= Q || step[tepx][tepy] <= step[x][y]+1)
    {
        //cout << "tepx" << tepx << "tepy" << tepy << "step1" << step[tepx][tepy] << "step2" << step[x][y]+1 << endl;
        return false;
    }

    //保证能升能降
   // cout << 11 << endl;
    int height = Z[x][y] - Z[tepx][tepy];
    //if(x == 4 && y == 0){
      //  cout << "我真的来1了" << tepx << tepy  << x << y<<endl;
    //}
    //cout << "height:" << height << endl;
    if(height < -1 || height > 3){
      //   cout << "我真的来2了" << tepx << tepy <<endl;
        return false;
    }
    //判断挡不住
    else{
       // cout << "zhegeguol11111e" << tepx << tepy << endl;
        return see(tepx, tepy, R1, C1) || see(tepx, tepy, R2, C2);
    }

}


int main()
{
    int T;
    queue <int> QE;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> P >> Q;
        for(int j = 0; j < P; j++){
            for(int k = 0; k < Q; k++){
                cin >> Z[j][k];
            }
        }
        cin >> R1 >> C1 >> R2 >> C2;
        R1--;
        C1--;
        R2--;
        C2--;
        //输入数据完毕
        memset(step, 10000, sizeof(step));
        //特殊情况
       if(R1 == R2 && C1 == C2){
        cout << "The shortest path is 0 steps long." << endl;
       }
       else{
        //回归一维数组，转化过去
        QE.push(R1*N+C1);
        step[R1][C1] = 0;
        int flag = 0;
        while(!QE.empty()){
            int p = QE.front();
            QE.pop();
            //计算xy
            int x = p / N;
            int y = p % N;
            //走四条边
            for(int r = 0; r < 4; r++){
                //tep*下一个点，四个方向
                int tepx = x + D[r][0];
                int tepy = y + D[r][1];
                //cout << "tepx:" << tepx << endl;
                //go bool类型的函数，返回true false
                if(go(x, y, tepx, tepy)){
                        //cout << x << " " << y <<  "->" << tepx << " " << tepy << endl;
                    //转化为一维数组压队列
                    QE.push(tepx*N+tepy);
                    //继续走一步，step加1
                    step[tepx][tepy] = step[x][y]+1;
                    //cout << "走过的点(" << tepx << ", " << tepy << ")" << endl;
                    if(tepx == R2 && tepy == C2){
                        cout << "The shortest path is " << step[R2][C2] << " steps long." << endl;
                        flag = 1;
                        break;
                    }
                    //x = tepx;
                    //y = tepy;
                    //cout << "走" << endl;
                }
            }
        }
        if(!flag)
            cout << "Mission impossible!" << endl;
       }
       //清空队列
       while(!QE.empty()){
        QE.pop();
       }
    }
    return 0;
}
