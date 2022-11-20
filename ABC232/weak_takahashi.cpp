#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W; cin >> H >> W;
    vector<vector<int>> C(H+1, vector<int>(W+1,0));
    // vector<vector<int>> cost(H, vector<int>(W,0));
    for(int i=1; i<H+1; ++i){
        for(int j=1; j<W+1; ++j){
            char c; cin >> c;
            if(c == '.') C[i][j] = 0;
            else if(c == '#') C[i][j] = -1;
        }
    }

    for(int i=1; i<H+1; ++i){
        for(int j=1; j<W+1; ++j){
            if(i == 1 && j == 1){
                C[i][j] = 1;
                continue;
            }
            if(max(C[i-1][j], C[i][j-1]) == 0 || C[i][j] == -1) continue;
            C[i][j] = max(C[i-1][j], C[i][j-1]) + 1;
        }
    }

    int max = 0;
    for(int i=0; i<H+1; ++i){
        for(int j=0; j<W+1; ++j){
            if(C[i][j] > max) max = C[i][j];
            // cout << C[i][j] << " ";
        }
        // cout << endl;
    }

    // cout << endl;
    cout << max << endl;
    
}