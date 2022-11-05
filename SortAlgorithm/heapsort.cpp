#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int> &a, int i, int N){
    int child1 = i*2 + 1; //左の子供
    if(child1 >= N) return; //子供がないときは終わり

    //子供同士の比較
    if(child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;

    if(a[child1] <= a[i]) return; //逆転がなかったら終了

    //swap
    swap(a[i], a[child1]);

    //再帰的に繰り返す
    Heapify(a, child1, N);
}

void HeapSort(vector<int> &a){
    int N = (int)a.size();

    // ステップ 1: a 全体をヒープにするフェーズ
    for(int i= N / 2 -1; i>=0; --i){
        Heapify(a, i, N);
    }

    // ステップ2: ヒープから1個1個最大値を pop するフェーズ
    for(int i=N-1; i>0; --i){
        swap(a[0], a[i]); //ヒープの最大値を左詰め
        Heapify(a, 0, i); //ヒープサイズは i に
    }
}

int main(){
    int N; cin >> N; //要素数
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    //ヒープソート
    HeapSort(a);
    for(int i=0; i<N; ++i) cout << a[i] << endl;
}