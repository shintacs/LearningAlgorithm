#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long N, A, B;
    cin >> N >> A >> B;
    long long P, Q, R, S;
    cin >> P >> Q >> R >> S;

    for(long long i=P-1; i<Q; ++i){
        for(long long j=R-1; j<S; ++j){
            if(abs(i-(A-1)) == abs(j-(B-1))) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
}