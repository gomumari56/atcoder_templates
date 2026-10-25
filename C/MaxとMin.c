#include<stdio.h>
int max(int a,int b){if(a>b){return a;}else{return b;}}
int min(int a,int b){if(a>b){return b;}else{return a;}}
int Max(int a,int b){return a>b?a:b;};
int Min(int a,int b){return a>b?b:a;};
long long llMax(long long a,long long b){return a>b?a:b;};
long long llMin(long long a,long long b){return a>b?b:a;};
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)
int main(){
    int a=3,b=5;
    long long c=20,d=50;
    printf("%d %d\n",max(a,b),min(a,b));
    printf("%d %d\n",Max(a,b),Min(a,b));
    printf("%d %d\n",MAX(a,b),MIN(a,b));
    printf("%lld %lld\n",MAX(c,d),MIN(c,d));
    printf("%lld %lld\n",MAX(a,c),MIN(c,a));
    return 0;
}