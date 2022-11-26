#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_pair(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}

int main()
{
    long long H,W;
    int N;
    cin >> H >> W >> N;

    vector<pair<int, int>> A(N), B(N);
    for(int i=0; i<N; ++i){
        cin >> A[i].first >> B[i].first;
        A[i].second = i;
        B[i].second = i;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int cnt = 0;
    int num = 0;
    for(int i=0; i<N; ++i){
        if(A[i].first != num){
            cnt++;
            num = A[i].first;
            A[i].first = cnt;
        }
        else{
            A[i].first = cnt;
        }
    }

    cnt = 0;
    num = 0;
    for(int i=0; i<N; ++i){
        if(B[i].first != num){
            cnt++;
            num = B[i].first;
            B[i].first = cnt;
        }
        else{
            B[i].first = cnt;
        }
    }

    sort(A.begin(), A.end(), compare_pair);
    sort(B.begin(), B.end(), compare_pair);

    for(int i=0; i<N; ++i) cout << A[i].first << " " << B[i].first << endl;

}