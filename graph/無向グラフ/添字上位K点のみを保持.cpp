#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll K=10; //連結成分の添字が大きいK点の情報だけを持つ

ll R[200020]={};
vector<ll> L(200020,-1);
ll root(ll p);
int main(){
    map<ll,vector<ll>> M;
    ll N,Q;
    cin >> N >> Q;
    for(ll i=1;i<=N;i++){
        R[i]=i;
        M[i].push_back(i);
    }
    for(ll i=1;i<=Q;i++){
        ll t;
        cin >> t;
        if(t==1){
            ll u,v;
            cin >> u >> v;
            if(root(u)!=root(v)){
                ll rm=min(root(u),root(v));
                ll rM=max(root(u),root(v));
                R[rM]=rm;
                for(ll i=0;i<(ll)(M[rM].size());i++){
                    M[rm].push_back(M[rM][i]);
                }
                sort(M[rm].rbegin(),M[rm].rend());
                while((int)(M[rm].size())>K){
                    M[rm].pop_back();
                }
            }
        }
        if(t==2){
            ll v,k;
            cin >> v >> k;
            if((ll)(M[root(v)].size())<k){
                cout << -1 << endl;
            }
            else{
                cout << M[root(v)][k-1] << endl;
            }
        }
    }
    return 0;
}
ll root(ll p){
    if(R[p]==p){
        return p;
    }
    else{
        return root(R[p]);
    }
}