#include<bits/stdc++.h>
#define ll long long
using namespace std;

//https://atcoder.jp/contests/APG4b/tasks/APG4b_ac

int main(){

    ll N1=25;
    bitset<7> B1(N1); //long longを2進数に変換
    cout << "B1=" << B1 << endl;

    bitset<7> B2("1010110"); //stringを2進数に変換
    cout << "B2=" << B2 << endl;

    bitset<7> B3=B1; //コピー可能
    cout << "B3=" << B3 << endl;

    if(B1==B3){ //全体で比較可能
        cout << "B1=B3" << endl;
    }

    bitset<7> B4=B1&B2; //AND 両方が1の桁だけ1になる
    cout << "B4=" << B4 << endl;

    const ll bn=20;
    for (ll tmp = 0; tmp < (1LL << bn); tmp++) {
    bitset<bn> s(tmp);
    // (ビット列sに対する処理)
    }

    cout << B4[4] << endl;

    return 0;
}