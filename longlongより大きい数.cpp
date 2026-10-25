#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll X=20000000000000;
    ll Y=30000000000000;
    ll Z=15000000000000;
    
    ll W=X*Y;
    W/=Z;
    cout << "W= " << W << endl;
    //X*Yがlong longを超えているのでバグる

    __int128_t V=X*Y;
    V/=Z;
    cout << (ll)V << endl;
    return 0;
}