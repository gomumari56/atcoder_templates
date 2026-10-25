#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
using namespace std;
int main(){
    multiset<ll> V;
    V.insert(2);
    V.insert(5);
    V.insert(5);
    V.insert(5);
    V.insert(4);
    V.insert(4);
   
    //要素を1個だけ消したい場合は、イテレータを用いる
    auto itr=V.find(5);
    if(itr!=V.end()){
        V.erase(itr);
    }

    //通常のeraseはその値の要素を全て消してしまう
    V.erase(4);

    for(auto p:V){
        cout << p << " ";
    }
    cout << endl;

    cout << (ll)(V.size()) << endl;

    return 0;
}
//17:43