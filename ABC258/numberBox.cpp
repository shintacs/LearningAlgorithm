#include <iostream>

using namespace std;

int main()
{
    int N; cin >> N;
    int Nums[N][N];
    int max = 0;
    int max_i, max_j;

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            char x; 
            cin >> x;
            Nums[i][j] = x - '0';
        }
    }

    // 方向の定義をしてやるといい
    int p[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int q[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    long long ans = 0;

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            for(int cnt=0; cnt<8; cnt++){
                long long num = 0;
                int x = i;
                int y = j;
                for(int k=0; k<N; ++k){
                    num *= 10;
                    num += Nums[x][y];
                    x = (x+p[cnt] + N) % N;
                    y = (y+q[cnt] + N) % N;
                }
                if(ans < num) ans = num;
            }
        }
    }

    cout << ans << endl;
}