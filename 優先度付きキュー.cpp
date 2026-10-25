#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    priority_queue<ll,vector<ll>,greater<ll>> Q;

    //greater ... 小さいやつから取り出す
    //less ... 大きいやつから取り出す

    Q.push(3);
    Q.push(5);
    Q.push(1);
    Q.push(9);
    Q.push(7);

    //追加順だと3,5,1,9,7
    //greaterを使ってるので、1,3,5,7,9の順で取り出される

    while(!Q.empty()){
        cout << Q.top() << endl;
        Q.pop();
    }
    
    return 0;
}