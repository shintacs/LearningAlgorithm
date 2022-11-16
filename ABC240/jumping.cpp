// 1つのテストケースだけ通らなかった（理由はわかってない）
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, X; cin >> N >> X;
    int a_sum = 0;
    vector<int> b;

    for(int i=0; i<N; ++i){
        int ai, bi;
        cin >> ai >> bi;

        a_sum+=ai;
        b.push_back(bi - ai);
    }

    if(a_sum > X){
        cout << "No" << endl;
        return 0;
    }
    
    vector<vector<bool>> dp(N+1, vector<bool>(X-a_sum+1, false));
    
    for(int x=0; x<(X-a_sum)+1; ++x){
        for(int i=0; i<N; ++i){
            if(x == 0) dp[i][x] = true;
            else{
                if(x >= b[i]) dp[i+1][x] = dp[i+1][x] || dp[i][x-b[i]]; //b[i]を選ぶとき
                dp[i+1][x] = dp[i+1][x] || dp[i][x]; //b[i]を選ばない時
            } 
        }
    }
    

    /*for(int i=0; i<N+1; ++i){
        for(int j=0; j<X-a_sum+1; ++j){
            cout << dp[i][j];
        }
        cout << endl;
    }*/

    if(dp[N][X-a_sum]) cout << "Yes" << endl;
    else cout << "No" << endl;

}