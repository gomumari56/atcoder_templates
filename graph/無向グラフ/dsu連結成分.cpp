#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    dsu d(100);
    d.merge(5,7);
    cout << d.leader(5) << endl;
    cout << d.leader(7) << endl;
    cout << d.leader(10) << endl;
    return 0;
}