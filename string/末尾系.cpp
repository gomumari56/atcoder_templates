#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string S="abcde";

    //末尾の要素
    cout << *S.rbegin() << endl;

    //末尾の要素
    cout << S.back() << endl;

    //末尾の1要素を消去する
    S.pop_back();
    cout << S << endl;
    
    return 0;
}