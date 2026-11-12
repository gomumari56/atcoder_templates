//reference: https://github.com/gomumari56/atcoder_templates

//参考: https://info.atcoder.jp/entry/algorithm_lectures/euler_tour_technique

//438 - F

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;

/////////////////////////////////////////////////
template<typename T>
void OUT(const T &X, ostream &os = cout){
    if constexpr(requires{X.begin();X.end();}){
        for(auto it=X.begin();it!=X.end();it++) OUT(*it, os);
        os << "\n";
    }else if constexpr(requires(T t){t.pop();t.size();}){
        T x=X;
        while(x.size()){
            if constexpr(requires{x.top();}){
                OUT(x.top(), os);
                x.pop();
            }else{
                OUT(x.front(), os);
                x.pop();
            }
        }
        os << "\n";
    }else{
        if constexpr(requires(T t){t.first;}){
            OUT(X.first, os);
            OUT(X.second, os);
            os << "\n";
        }else{
            os << X << " ";
        }
    }
}
#define debug(x) cerr << endl << #x << ":" << endl, OUT(x, cerr), cout << endl
/////////////////////////////////////////////////

//segtreeモノイドの定義
#define S pair<ll,ll>
S op(S a,S b){
    return min(a,b);
}
S e(){
    return {LLONG_MAX,0};
}

//segtreeモノイドの定義
#define S_p ll
ll op_p(ll a,ll b){
    return a+b;
}
ll e_p(){
    return 0LL;
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
    // ll Q;
    // cin >> Q;

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

    //Vは長さ2*N-1なので対応するsegtreeも長さ2*N-1にする
    segtree<S_p,op_p,e_p> seg_p(2*N-1);
    //初期値を1にする(入力で与えられる場合もある)
    for(ll i=0;i<N;i++){
        seg_p.set(in[i],1);
    }

    //頂点vの部分木に含まれる頂点の重みの総和
    auto v_count = [&](ll a) -> ll {
        return seg_p.prod(in[a],out[a]+1);
    };

    //頂点a,bのLCAを求める
    auto LCA = [&](ll a,ll b) -> ll {
        if(in[a]<in[b]){
            return seg.prod(in[a],in[b]+1).second;
        }
        else{
            return seg.prod(in[b],in[a]+1).second;
        }
    };

    //頂点a,bの距離を求める
    auto v_dist = [&](ll a,ll b) -> ll {
        return depth[in[a]]+depth[in[b]]-2*depth[in[LCA(a,b)]];
    };

    ll ans=N;

    { //0
        ans+=((N-1)*(N-2))/2;
        for(auto next:G[0]){
            ll c=v_count(next);
            ans-=(c*(c-1))/2;
        }
    }

    //debug(ans);

    ll first_child;
    {
        for(auto next:G[0]){
            if(v_dist(next,1)<v_dist(0,1)){
                first_child=next;
                break;
            }
        }
    }

    ll L=0,R=0;
    for(ll i=1;i<N;i++){
        if(v_dist(L,i)+v_dist(i,R)==v_dist(L,R)){
            //すでに内部にある
        }
        else if(v_dist(R,i)==v_dist(R,L)+v_dist(L,i)){
            L=i;
        }
        else if(v_dist(L,i)==v_dist(L,R)+v_dist(R,i)){
            R=i;
        }
        else{
            break;
        }
        if(R==0){
            ans+=(N-v_count(first_child))*v_count(L);
        }
        else{
            ans+=v_count(L)*v_count(R);
        }
    }

    cout << ans << endl;

    return 0;
}