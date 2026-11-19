//reference: https://github.com/gomumari56/atcoder_templates
//参考: https://betrue12.hateblo.jp/entry/2020/09/23/005940

//477 - F
//平面走査
//遅延セグ木 lazy_segtree
//区間加算・区間和

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;
#define pos pair<ll,ll>

//遅延セグ木の定義
struct S {
    ll value;
    ll size;
};
#define F ll
S op(S a,S b){ return {a.value+b.value,a.size+b.size}; }
S e(){ return {0,0}; }
S mapping(F f,S x){ return {x.value+f*x.size,x.size}; }
F composition(F f,F g){ return f+g; }
F id(){ return 0; }

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N,M,Q;
    cin >> N >> M >> Q;

    vector<ll> L(N),R(N);
    for(ll i=0;i<N;i++){
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }

    priority_queue<pos,vector<pos>,greater<pos>> pq;

    vector<tuple<ll,ll,ll,ll>> query(Q);
    for(ll i=0;i<Q;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        query[i]={a,b,c,d};
        pq.push({b,d});
        pq.push({b,c-1});
        pq.push({a-1,d});
        pq.push({a-1,c-1});
    }

    //構造体で初期化(値0,長さ1)
    vector<S> v(M, {0, 1});
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(v);

    map<pos,ll> C;

    ll xnow=0,ynow=-1;
    while(!pq.empty()){
        auto [x,y]=pq.top();
        pq.pop();
        if(x==-1||y==-1){
            C[{x,y}]=0;
            continue;
        }
        while(xnow<x){
            //xnowのynow+1からN-1までを埋める
            ll cmin=max(ynow+1,L[xnow]);
            ll cmax=min(M-1,R[xnow]);
            if(cmin<=cmax){
                seg.apply(cmin,cmax+1,1);
            }
            xnow++;
            ynow=-1;
        }
        {
            if(ynow<y){
                //xnowのynow+1からyまでを埋める
                ll cmin=max(ynow+1,L[xnow]);
                ll cmax=min(y,R[xnow]);
                if(cmin<=cmax){
                    seg.apply(cmin,cmax+1,1);
                }
                ynow=y;
            }
        }
        C[{x,y}]=seg.prod(0,y+1).value;
    }

    for(ll i=0;i<Q;i++){
        auto [a,b,c,d]=query[i];
        cout << (C[{b,d}]-C[{b,c-1}]-C[{a-1,d}]+C[{a-1,c-1}]) << endl;
    }

    return 0;
}