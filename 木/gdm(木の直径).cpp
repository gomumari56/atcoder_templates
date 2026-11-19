#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll,ll>> G[200020]; //{繋がっている頂点,そこまでの重み}
pair<ll,ll> G_dist_max(ll t); //{頂点tから最も遠い点,そこまでの距離}
ll G_diameter(); //木の直径(最も離れている2点間の距離)

//グラフは木である必要がある

int main(){
    ll N;
    cin >> N;
    ll ans=0;
    for(ll i=1;i<=N-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        ans+=(2*c);
    }
    ans-=G_diameter();
    cout << ans << endl;
    return 0;
}
pair<ll,ll> G_dist_max(ll t){
    pair<ll,ll> gdm={0,0};
    queue<pair<ll,ll>> Q;
    set<ll> add;
    Q.push({t,0});
    add.insert(t);
    while(!Q.empty()){
        auto x=Q.front();
        Q.pop();
        for(auto y:G[x.first]){
            if(!add.count(y.first)){
                ll r=x.second+y.second;
                Q.push({y.first,r});
                add.insert(y.first);
                if(r>gdm.second){
                    gdm={y.first,r};
                }
            }
        }
    }
    return gdm;
}
ll G_diameter(){
    auto dist1=G_dist_max(1);
    auto dist2=G_dist_max(dist1.first);
    return dist2.second;
}