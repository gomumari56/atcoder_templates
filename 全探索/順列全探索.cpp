#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll N;
    cin >> N;

    /////入力

    vector<ll> P(N); //0~N-1までの順列
    ll R=1; //場合の数
    for(ll i=0;i<N;i++){
        P[i]=i;
        R*=i+1;
    }

    while(R>0){
        /////処理

        R--;
        next_permutation(P.begin(),P.end());
    }

    /////結論

    return 0;
}