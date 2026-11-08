#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
using namespace std;
int main(){
    ll N;
    cin >> N;
    if(N>10000020){
        N=10000020;
    }

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

    for(auto p:primes){
        cout << p << " ";
    }
    cout << endl;
    cout << (ll)(primes.size()) << " primes found" << endl;

    return 0;
}