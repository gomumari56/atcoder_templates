//reference: https://github.com/gomumari56/atcoder_templates

//ABC 390 D

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> A(15);
unordered_set<ll> S;
vector<ll> G(15,-1);
vector<ll> sum(15,0);

//N個の要素をグループ分けする方法はB(N)通り存在する(ベル数)
//dfsで全探索可能
//b(d,k)...d-1までをkグループに分けている状況で, 
//dをどのグループに入れるかを考える

void b(ll d,ll k){
    if(d==N){
        //各グループの和のXORをとる
        ll cnt=0;
        for(ll i=0;i<k;i++){
            cnt^=sum[i];
        }
        S.insert(cnt);
    }
    else{
        //dをグループ0~kに入れる
        for(ll i=0;i<k;i++){
            G[d]=i;
            sum[i]+=A[d];
            b(d+1,k);
            sum[i]-=A[d];
        }
        G[d]=k;
        sum[k]+=A[d];
        b(d+1,k+1);
        sum[k]-=A[d];
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    for(ll i=0;i<N;i++){
        cin >> A[i];
    }

    b(0,0);

    cout << (ll)(S.size()) << endl;

    return 0;
}