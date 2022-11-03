#include <iostream>
#include <vector>

template<class T> void chmax(T& a, T b)
{
    if(a < b) a = b;
}

int main()
{
    int N; 
    std::cin >> N;
    std::vector<int>a(N),b(N),c(N);
    a[0] = b[0] = c[0] = 0;
    for(int i=1; i<=N; ++i) std::cin >> a[i] >> b[i] >> c[i];

    std::vector<std::vector<int>> dp(N+1, std::vector<int>(3, 0));

    for(int i=1; i<=N; ++i)
    {
        // 前回がaでない場合
        chmax(dp[i][0], dp[i-1][1] + a[i]);
        chmax(dp[i][0], dp[i-1][2] + a[i]);
        // 前回がbでない場合
        chmax(dp[i][1], dp[i-1][0] + b[i]);
        chmax(dp[i][1], dp[i-1][2] + b[i]);
        // 前回がcでない場合
        chmax(dp[i][2], dp[i-1][0] + c[i]);
        chmax(dp[i][2], dp[i-1][1] + c[i]);
    }

    int maxval = 0;
    maxval = std::max(dp[N][0], std::max(dp[N][1], dp[N][2]));
    std::cout << maxval << std::endl;
}