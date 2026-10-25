#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    
    //long long型をstring型にする
    ll X=12345;
    string strX=to_string(X);
    cout << "strX= " << strX << endl;

    //string型をlong long型にする
    string Y="54321";
    ll llY=stoll(Y);
    cout << "llY= " << llY << endl;

    return 0;
}