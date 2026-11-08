#include<bits/stdc++.h>
#define ll long long
using namespace std;

//整数nに対して、√nの整数部分を返す
ll isqrt(ll n){
    ll x = sqrt((long double)n);
    __int128_t xx = (__int128_t)x * x;
    __int128_t yy = (__int128_t)(x+1) * (x+1);
    if(xx > n) x--;
    else if(yy <= n) x++;
    return x;
}

int main(){
    ll u=77679264099999999;
    /////77679263542580001;
    cout << " sqrt(u) = " << (ll)sqrt(u) << endl;
    cout << "isqrt(u) = " << isqrt(u) << endl;
    //本来、√u = 278709999 のはずであるが、sqrtでは丸め誤差が生じる
    cout << 278709999LL*278709999LL << endl;
    cout << 278710000LL*278710000LL << endl;
    return 0;
}