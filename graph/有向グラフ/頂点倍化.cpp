// https://atcoder.jp/contests/abc410/editorial/13208

// 頂点倍化 頂点倍加

#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
using namespace std;
int main(){
    ll N,M;
    cin >> N >> M;
    map<pair<ll,ll>,vector<pair<ll,ll>>> G2;
    for(ll i=1;i<=M;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        for(ll s=0;s<1024;s++){
            G2[{a,s}].push_back({b,s^w});
        }
    }
    bool vis[1030][1030]={};
    ll ans=LLONG_MAX;
    queue<pair<ll,ll>> Q;
    vis[1][0]=true;
    Q.push({1,0});
    while(!Q.empty()){
        auto [a,s]=Q.front();
        Q.pop();
        if(a==N){
            ans=min(ans,s);
        }
        for(auto [b,w]:G2[{a,s}]){
            if(vis[b][w]==false){
                Q.push({b,w});
                vis[b][w]=true;
            }
        }
    }
    if(ans==LLONG_MAX){
        cout << "-1" << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}