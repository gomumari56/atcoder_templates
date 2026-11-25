//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //__popcountで立っているbit数を数えることができる
    //unsigned型にする必要がある
    
    for(ll i=0;i<=16;i++){
        ll c=__popcount((unsigned)i);
        cout << i << " " << c << endl;
    }

    return 0;
}