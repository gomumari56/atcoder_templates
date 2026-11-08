#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
using namespace std;
const ll m14=100000000000000; //10^14
int main(){
    vector<ll> primes;
    vector<bool> is_prime(10000020,true);
    for(ll i=2;i<(ll)(is_prime.size());i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<(ll)(is_prime.size());j+=i){
                is_prime[j]=false;
            }
        }
    }

    ll L,R;
    cin >> L >> R;
    R=min(R,m14);
    L=min(L,R);
    // cout << L << " " << R << endl;

    vector<bool> vis(R-L,true);//vis[i]...i+L+1が素数かどうか
    vector<ll> lr_primes;

    for(auto p:primes){
        ll s=L+1;
        if(s%p!=0){
            s+=p-(L+1)%p;
        }
        if(s==p){
            s+=p;
        }
        for(ll x=s;x<=R;x+=p){
            if(vis[x-(L+1)]){
                vis[x-(L+1)]=false;
            }
        }
    }
    for(ll i=0;i<(ll)(vis.size());i++){
        if(vis[i]){
            lr_primes.push_back(i+L+1);
        }
    }

    for(auto p:lr_primes){
        cout << p << " ";
    }
    cout << endl;
    cout << "(" << L << "," << R << "]" << endl;
    cout << (ll)(lr_primes.size()) << " primes found" << endl;

    return 0;
}