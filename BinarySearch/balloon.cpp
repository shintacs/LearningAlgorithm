// 途中までやって眠くなったので一旦中止．教科書でいう30行目の意味が理解できてない
#include <iostream>
#include <vector>
#include <algorithm>

const long long INF=1LL << 60;

int main()
{
    int N;
    std::cin >> N;
    std::vector<long long> H(N), S(N);
    for(int i=0; i<N; ++i) std::cin >> H[i] >> S[i];

    std::vector<long long> t(N, 0);

    long long left = 0;
    long long right = INF;
    while(right - left > 1)
    {
        bool res = true;
        long long mid = (left + right)/2; //無限遠？
        for(int i=0; i<N; ++i)
        {
            if(mid < H[i]) res = false;
            else t[i] = (mid - H[i]) / S[i]; // 無限遠までの距離を計算
        }

        sort(t.begin(), t.end()); // 差し迫ってる順に並び替える
        for(int i=0; i<N; ++i){
            if(t[i] < i) res = false; // i秒後にi個目の風船を撃っても間に合うのか調べる
        }

        if(res) right = mid;
        else left = mid;
    }

    std::cout << right << std::endl;

}