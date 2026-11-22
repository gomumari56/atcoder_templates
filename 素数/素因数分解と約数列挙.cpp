//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll N=10000020;

    vector<ll> primes;
    vector<bool> is_prime(N+1,true);
    for(ll i=2;i<(ll)(is_prime.size());i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<(ll)(is_prime.size());j+=i){
                is_prime[j]=false;
            }
        }
    }

    //primesに素数が入っている

    //素因数分解し、各素因数をvectorに入れる
    auto fac1 = [&](ll X) -> vector<ll> {
        vector<ll> div;
        ll now=0;
        while(X>1){
            if(now>=(ll)(primes.size())){
                div.push_back(X);
                break;
            }
            if(primes[now]*primes[now]>X){
                div.push_back(X);
                break;
            }
            if(X%primes[now]==0){
                div.push_back(primes[now]);
                X/=primes[now];
            }
            else{
                now++;
            }
        }
        return div;
    };

    //素因数分解し、各素因数をmapに入れる
    auto fac2 = [&](ll X) -> map<ll,ll> {
        map<ll,ll> div;
        ll now=0;
        while(X>1){
            if(now>=(ll)(primes.size())){
                div[X]++;
                break;
            }
            if(primes[now]*primes[now]>X){
                div[X]++;
                break;
            }
            if(X%primes[now]==0){
                div[primes[now]]++;
                X/=primes[now];
            }
            else{
                now++;
            }
        }
        return div;
    };

    //約数列挙
    auto divisor_list = [&](map<ll,ll> div) -> vector<ll> {
        vector<ll> res;
        res.push_back(1);
        for(auto [d,c]:div){
            ll L=(ll)(res.size());
            for(ll i=0;i<c;i++){
                for(ll j=L*i;j<L*(i+1);j++){
                    res.push_back(res[j]*d);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    };

    //愚直約数列挙
    auto divisor_list2 = [&](ll X) -> vector<ll> {
        vector<ll> res;
        for(ll i=1;i*i<=X;i++){
            if(i*i==X){
                res.push_back(i);
            }
            else if(X%i==0){
                res.push_back(i);
                res.push_back(X/i);
            }
        }
        sort(res.begin(),res.end());
        return res;
    };

    ll X=414003;

    {
        auto div=fac1(X);
        for(auto d:div){
            cout << d << " ";
        }
        cout << endl;
    }

    {
        auto div=fac2(X);
        for(auto [d,c]:div){
            cout << d << "^" << c << " ";
        }
        cout << endl;
    }

    {
        auto div=divisor_list(fac2(X));
        for(auto d:div){
            cout << d << " ";
        }
        cout << endl;
    }

    {
        auto div=divisor_list2(X);
        for(auto d:div){
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}