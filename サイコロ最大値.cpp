
//これはABC 411-E です

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
using namespace std;
using namespace atcoder;
using mint = atcoder::modint998244353;
int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(100010,vector<ll>(6,0));
    vector<ll> list;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<6;j++){
            cin >> A[i][j];
            list.push_back(A[i][j]);
        }
    }
    for(ll i=1;i<=N;i++){
        sort(A[i].begin(),A[i].end());
    }
    sort(list.begin(),list.end());
    //uniqueはlistの重複を詰めて、その次のイテレータを返すらしい
    list.erase(unique(list.begin(),list.end()),list.end());

    //listにMaxとしてあり得る数が並んでいる
    //dは、list[d]になって個数が増えるindexのまとめ
    ll M=(ll)(list.size());
    vvll d(M);
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<6;j++){
            ll index=lower_bound(list.begin(),list.end(),A[i][j])-list.begin();
            d[index].push_back(i);
        }
    }

    mint ans=0;
    //Bは各サイコロの目の数がlist_k以下である個数を保存する
    vector<ll> B(N+10,0);
    //B_iの総積
    mint prod=1;
    //B_i=0となっている個数
    ll c0=N;
    for(ll i=0;i<M-1;i++){
        ll t=list[i+1]-list[i];
        for(auto k:d[i]){
            if(B[k]==0){
                c0--;
                B[k]++;
            }
            else{
                prod/=B[k];
                B[k]++;
                prod*=B[k];
            }
        }
        if(c0==0){
            ans-=t*prod/mint(6).pow(N);
        }
    }
    ans+=list[M-1];
    cout << ans.val() << endl;
    return 0;
}