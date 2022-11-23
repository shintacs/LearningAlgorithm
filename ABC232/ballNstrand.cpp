#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> X(N,0);
    vector<int> Y(N,0);

    for(int i=0; i<M; ++i){
        int ai, bi; cin >> ai >> bi;
        X[ai-1]++; X[bi-1]++;
    }
    for(int i=0; i<M; ++i){
        int ci, di; cin >> ci >> di;
        Y[ci-1]++; Y[di-1]++;
    }

    int cnt = 0;
    do{
        for(int i=0; i<N; ++i){
            cout << Y[i] << " ";
        }
        cout << endl;
        for(int i=0; i<N; ++i){
            if(X[i] == Y[i]){
                if(i == N-1){
                    cout << "Yes" << endl;
                    return 0;
                }
                continue;
            }
            break;
        }
        cnt++;
    }while(next_permutation(Y.begin(), Y.end()));

    cout << cnt << endl;
    cout << "No" << endl;
    return 0;

}