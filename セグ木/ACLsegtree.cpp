#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;

#define S set<ll>
S op(S a,S b){
    for(auto p:b){
        a.insert(p);
    }
    return a;
}
S e(){
    S E;
    return E;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<S> A(N);
    for(int i=0;i<N;i++){
        ll t;
        cin >> t;
        A[i].insert(t);
    }

    segtree<S,op,e> seg(A);

    ll ans=0;

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            ans+=(ll)(seg.prod(i,j+1).size());
        }
    }

    cout << ans << endl;

    return 0;
}