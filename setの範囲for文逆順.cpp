#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    multiset<ll> MS;
    MS.insert(1);
    MS.insert(2);
    MS.insert(3);
    MS.insert(3);
    MS.insert(4);

    for(auto it=MS.rbegin();it!=MS.rend();++it){
        cout << (ll)(*it) << " ";
    }
    cout << endl;
    return 0;
}