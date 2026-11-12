#include<bits/stdc++.h>
using namespace std;
vector<long long> segtree(400040);
int N,C=1;
void update(int i,long long x);
long long query(int a,int b);
long long query_sub(int a,int b,int k,int l,int r);

int main(){
    int Q,i;
    cin >> N >> Q ;
    //葉(最下層)のノード数はC(C-1から2*C-2)
    //segtreeのノード数は2*C-1(0から2*C-2)
    while(C<N){
        C*=2;
    }
    //クエリ
    int j,pos,l,r;
    long long x;
    for(i=1;i<=Q;i++){
        cin >> j;
        if(j==1){
            //データの更新
            cin >> pos >> x;
            update(pos-1,x);
        }
        else{
            //区間の最大値
            cin >> l >> r;
            cout << query(l-1,r-1) << endl;
        }
    }
    return 0;
}
//i番目をxに変更する
void update(int i,long long x){
    i+=C-1;
    segtree.at(i)=x;
    while(i>0){
        i=(i-1)/2;
        segtree.at(i)=max(segtree.at(i*2+1),segtree.at(i*2+2));
    }
}
//区間[a,b)の最大値
long long query(int a,int b){
    return query_sub(a,b,0,0,C); 
}
long long query_sub(int a,int b,int k,int l,int r){
    if(r<=a || b<=l){
        return -__INT_MAX__;
    }
    else if(a<=l && r<=b){
        return segtree.at(k);
    }
    else{
        int ql=query_sub(a,b,k*2+1,   l   ,(l+r)/2);
        int qr=query_sub(a,b,k*2+2,(l+r)/2,   r   );
        return max(ql,qr);
    }
}