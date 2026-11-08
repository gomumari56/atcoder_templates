#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<pair<ll,ll>> A(N);
    for(ll i=0;i<N;i++){
        cin >> A[i].first >> A[i].second;
    }

    //[0°,360°)でソートする場合
    auto arg_cmp = [](pair<ll,ll> p,pair<ll,ll> q) -> bool {
        auto [a,b]=p;
        auto [s,t]=q;
        //上側かどうかの判定
        bool u1=((b>0)||(b==0 && a>0));
        bool u2=((t>0)||(t==0 && s>0));
        if(u1==u2){
            return (a*t-s*b>0);
        }
        return u1;
    };

    sort(A.begin(),A.end(),arg_cmp);

    for(ll i=0;i<N;i++){
        cout << A[i].first << " " << A[i].second << endl;
    }

    return 0;
}