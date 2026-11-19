//reference: https://github.com/gomumari56/atcoder_templates

//参考: https://info.atcoder.jp/entry/algorithm_lectures/euler_tour_technique

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void et(ll now,ll prev,vector<vector<ll>>& G,vector<ll>& V,vector<ll>& in,vector<ll>& out){
    in[now]=(ll)(V.size());
    V.push_back(now);
    for(auto next:G[now]){
        if(next!=prev){
            et(next,now,G,V,in,out);
            V.push_back(now);
        }
    }
    out[now]=(ll)(V.size())-1;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<vector<ll>> G(N);
    for(ll i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //Vがオイラーツアー(通った頂点列)
    vector<ll> V,in(N),out(N);
    et(0,-1,G,V,in,out);

    //V,in,outの出力
    for(auto v:V){cout << v << " ";}cout << endl;
    for(auto v:in){cout << v << " ";}cout << endl;
    for(auto v:out){cout << v << " ";}cout << endl;

    return 0;
}