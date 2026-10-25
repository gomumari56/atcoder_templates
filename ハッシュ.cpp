// 367 - F

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll MOD=(2LL<<61)-1; //巨大な素数
int main(){
    mt19937_64 rng((ull)chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N,Q;
    cin >> N >> Q;   

    vector<ll> r(N); //0~N-1の整数にそれぞれランダムな値を割り当てる
    for(ll i=0;i<N;i++){
        r[i]=rng()%MOD;
    }

    vector<ll> sa(N),sb(N);
    for(ll i=0;i<N;i++){
        ll t;
        cin >> t;
        t--;
        sa[i]=r[t];
        if(i>0){
            sa[i]+=sa[i-1];
            sa[i]%=MOD;
        }
    }
    for(ll i=0;i<N;i++){
        ll t;
        cin >> t;
        t--;
        sb[i]=r[t];
        if(i>0){
            sb[i]+=sb[i-1];
            sb[i]%=MOD;
        }
    }

    //多重集合が一致しているかを高速に判定することができる
    while(Q--){
        ll l,r,L,R;
        cin >> l >> r >> L >> R;
        l--;r--;L--;R--;
        if(r-l!=R-L){
            cout << "No" << endl;
            continue;
        }
        ll cnt1=0;
        cnt1+=sa[r];
        if(l>0){
            cnt1-=sa[l-1];
            cnt1+=MOD;
            cnt1%=MOD;
        }
        ll cnt2=0;
        cnt2+=sb[R];
        if(L>0){
            cnt2-=sb[L-1];
            cnt2+=MOD;
            cnt2%=MOD;
        }
        if(cnt1==cnt2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}