//reference: https://github.com/gomumari56/atcoder_templates

//参考: https://info.atcoder.jp/entry/algorithm_lectures/euler_tour_technique

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;

//segtreeモノイドの定義
#define S pair<ll,ll>
S op(S a,S b){
    return min(a,b);
}
S e(){
    return {LLONG_MAX,0};
}

void et(ll now,ll prev,ll d,vector<vector<ll>>& G,vector<ll>& V,vector<ll>& in,vector<ll>& out,vector<ll>& depth){
    in[now]=(ll)(V.size());
    V.push_back(now);
    depth.push_back(d);
    for(auto next:G[now]){
        if(next!=prev){
            et(next,now,d+1,G,V,in,out,depth);
            V.push_back(now);
            depth.push_back(d);
        }
    }
    out[now]=(ll)(V.size())-1;
}


////////////////
// 添え字が1から始まるならtrue
const bool index1 = false;
////////////////

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    ll Q;
    cin >> Q;

    vector<vector<ll>> G(N);
    for(ll i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        if(index1){
            a--;
            b--;
        }
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //Vがオイラーツアー(通った頂点列)
    vector<ll> V,depth,in(N),out(N);
    et(0,-1,0,G,V,in,out,depth);

    //Vは長さ2*N-1なので対応するsegtreeも長さ2*N-1にする
    segtree<S,op,e> seg(2*N-1);
    for(ll i=0;i<2*N-1;i++){
        seg.set(i,{depth[i],V[i]});
    }

    //頂点a,bのLCAを求める
    auto LCA = [&](ll a,ll b) -> ll {
        if(in[a]<in[b]){
            return seg.prod(in[a],in[b]+1).second;
        }
        else{
            return seg.prod(in[b],in[a]+1).second;
        }
    };

    while(Q--){
        ll a,b;
        cin >> a >> b;
        if(index1){
            a--;
            b--;
        }
        cout << LCA(a,b)+(index1) << endl;
    }

    return 0;
}