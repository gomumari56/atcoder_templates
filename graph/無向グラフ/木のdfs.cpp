#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)
#define pll pair<ll,ll>
#define vel vector<ll>
using namespace std;
ll ans=0;
vector<bool> vis(100050,false);
vector<vector<pair<ll,ll>>> G(100050);
vector<ll> X(100050);
void dfs(ll edge);
int main(){
    ll N;
    cin >> N;
    for(ll i=1;i<=N;i++){
        cin >> X.at(i);
    }
    for(ll i=1;i<=N-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    //頂点1を根に設定してDFS
    dfs(1);

    cout << ans << endl;

    return 0;
}
void dfs(ll edge){
    for(ll i=0;i<(ll)(G.at(edge).size());i++){
        if(vis.at(G.at(edge).at(i).first)==false){
            vis.at(G.at(edge).at(i).first)=true;
            dfs(G.at(edge).at(i).first);
            X.at(edge)+=X.at(G.at(edge).at(i).first);
            ans+=abs(X.at(G.at(edge).at(i).first))*G.at(edge).at(i).second;
        }
    }
}