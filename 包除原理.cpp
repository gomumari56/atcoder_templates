//abc246 - F

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;
using mint = atcoder::modint998244353;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N,L;
    cin >> N >> L;
    vector<string> S(N);
    for(ll i=0;i<N;i++){
        cin >> S[i];
    }
    mint ans=(mint)0;
    for(ll t=1;t<(1LL<<N);t++){
        ll K=popcount(uint64_t(t));
        mint ord=(mint)0;
        if((K%2)==1){
            ord+=(mint)1;
        }
        else{
            ord-=(mint)1;
        }
        vector<ll> used(26,0);
        for(ll i=0;i<N;i++){
            if((t&(1LL<<i))==(1LL<<i)){
                for(auto c:S[i]){
                    used[c-'a']++;
                }
            }
        }
        mint c=(mint)0;
        for(ll i=0;i<26;i++){
            if(used[i]==K){
                c++;
            }
        }
        ans+=ord*(c.pow(L));
    }
    cout << ans.val() << endl;
    return 0;
}