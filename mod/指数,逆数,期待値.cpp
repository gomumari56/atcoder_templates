#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll powmod(ll x,ll p); //x^p %MOD
ll psmod(ll a,ll r,ll n); //初項a,公比r,項数nの等比級数の和 %MOD
ll modinv(ll a); //aの逆元
ll expect_mod(ll p,ll q); //期待値 有理数p/qに対するmod (Rの値)
int main(){
    ll k=powmod(2,7); //2の7乗 をMODで割ったあまり
    ll x=psmod(1,2,5); //初項1、公比2、項数5の等比数列の和 をMODで割ったあまり
    cout << k << " " << x << endl;
    return 0;
}
ll powmod(ll x,ll p){
    ll ans=1;
    while(p){
        if(p&1){
            ans=ans*x%MOD;
        }
        x=x*x%MOD;
        p>>=1;
    }
    return ans;
}
ll psmod(ll a,ll r,ll n){
    if(n==1){
        return a%MOD;
    }
    ll x=psmod(a,r,n/2);
    ll ret=(x+powmod(r,n/2)*x)%MOD;
    if(n&1){
        ret=(a+r*ret)%MOD;
    }
    return ret;
}
ll modinv(ll a){
	ll b=MOD,u=1,v=0;
	while(b){
		ll t=a/b;
		a-=t*b; swap(a,b);
		u-=t*v; swap(u,v);
	}
	u%=MOD;
	if(u<0){
        u+=MOD;
    }
	return u;
}
ll expect_mod(ll p,ll q){
    return (p*modinv(q))%MOD;
}