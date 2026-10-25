#include<stdio.h>
//一番根元を返す関数
int root(int *ar,int x);
void unite(int *ar,int a,int b);
int main(){
    int R[100010]={};
    int N,M;
    int a,b,a2,b2;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        R[i]=i;
    }
    for(int i=1;i<=M;i++){
        scanf("%d %d",&a,&b);
        unite(R,a,b);
    }
    for(int i=2;i<=N;i++){
        if(root(R,i)!=root(R,1)){
            printf("The graph is not connected.\n");
            return 0;
        }
    }
    printf("The graph is connected.\n");
    return 0;
}
//繋がっている点の中で最小の添え字の点の添え字を返す
int root(int *ar,int x){
    int y=x;
    if(ar[ar[y]]==ar[y]){
        return ar[y];
    }
    else{
        ar[y]=root(ar,ar[y]);
        return root(ar,ar[y]);
    }
}
void unite(int *ar,int a,int b){
    if(root(ar,a)!=root(ar,b)){
        //aとbの根本同士を繋げる
        if(root(ar,a)<root(ar,b)){
            ar[root(ar,b)]=root(ar,a);
            ar[b]=root(ar,a);
        }
        else{
            ar[root(ar,a)]=root(ar,b);
            ar[a]=root(ar,b);
        }
    }
}