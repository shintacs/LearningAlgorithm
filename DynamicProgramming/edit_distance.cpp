#include <iostream>
#include <vector>
#include <string>

const int INF = 1LL << 29;

template<class T> void chmin(T& a, T b)
{
    if(a > b) a = b;
}

int main()
{
    std::string s, t;
    std::cout << "sを入力" << std::endl;
    std::cin >> s;
    std::cout << "tを入力" << std::endl;
    std::cin >> t;

    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(t.size() + 1, INF));

    for(int i=0; i<=s.size(); ++i){
        for(int j=0; j<=t.size(); ++j){
            if(i == 0 && j == 0) dp[0][0] = 0;
            //　変更の手順
            if (i>0 && j>0){
                // 変更前から文字が正しいとき
                if(s[i-1] == t[j-1]) chmin(dp[i][j], dp[i-1][j-1]);
                // そうでないとき
                else chmin(dp[i][j], dp[i-1][j-1] + 1);
            } 
            // 削除の手順
            if(i > 0) chmin(dp[i][j], dp[i-1][j] + 1);

            // 挿入
            if(j > 0) chmin(dp[i][j], dp[i][j-1] + 1);
        }
    }

    for(int i=0; i<=s.size(); ++i){
        for(int j=0; j<=t.size(); ++j){
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
}