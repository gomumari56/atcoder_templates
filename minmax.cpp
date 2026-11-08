#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a=20,b=10;
    long long c;
    cin >> c;
    auto [s,t]=minmax(a,c);
    // cout << s << " " << t << endl;
    a=t;
    auto [s2,t2]=minmax(s,b);
    // cout << s2 << " " << t2 << endl;
    b=t2;
    cout << a << " " << b << endl;
    return 0;
}