#include <iostream>
#include <vector>

template<class T> void chmax(T& a, T b)
{
    if(a < b) a = b;
}

int main()
{
    int N; long long W;
    std::cin >> N >> W;

    std::vector<long long> weight(N), value(N);
    for(int i=0; i<N; ++i) std::cin >> weight[i] >> value[i];

    std::vector<std::vector<long long>> dp(N+1, std::vector<long long>(W+1, 0) );

    for(int i=0; i<N; ++i){
        for(int j=0; j<=W; ++j){
            //選ぶとき
            if(j - weight[i] >= 0) chmax(dp[i+1][j], dp[i][j-weight[i]] + value[i]);
            //選ばないとき
            chmax(dp[i+1][j], dp[i][j]);
        }
    }

    std::cout << dp[N][W] << std::endl;
    for(int i=0; i<N+1; ++i){
        for(int j=0; j<W+1; ++j){
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
}