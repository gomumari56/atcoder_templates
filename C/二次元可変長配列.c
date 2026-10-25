#include<stdio.h>
#include<stdlib.h>
int cmpnum(const void * n1, const void * n2);
int main(){
    int N;
    scanf("%d",&N);
    //縦n、横可変長(初期値1)の配列
    int **a;
    a = (int**) calloc (sizeof(int*), N+1);
    for(int i = 1; i <= N; i++) {
        a[i] = (int*) calloc (sizeof(int), 1);
    }
    //a[i][0]   ... a[i]の配列の長さが記録される
    //a[3][0]=5 ... a[3]の要素数が5、すなわち
    //              a[3][1]からa[3][5]まで配列が確保されている
    int M,A,B;
    scanf("%d",&M);
    for(int i=1;i<=M;i++){
        scanf("%d %d",&A,&B);
        //a[A]の配列の長さを1増やしてデータを追加する
        a[A][0]++;
        a[A] = (int*) realloc ( a[A] , sizeof(int)* (a[A][0]+1) );
        a[A][a[A][0]]=B;
        //a[B]の配列の長さを1増やしてデータを追加する
        a[B][0]++;
        a[B] = (int*) realloc ( a[B] , sizeof(int)* (a[B][0]+1) );
        a[B][a[B][0]]=A;
    }
    for(int i=1;i<=N;i++){
        qsort(a[i]+1,a[i][0],sizeof(int),cmpnum);
        printf("%d",a[i][0]);
        for(int j=1;j<=a[i][0];j++){
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int cmpnum(const void * n1, const void * n2){
	if (*(int*)n1 > *(int*)n2){return 1;}
	else if (*(int*)n1 < *(int*)n2){return -1;}
	else{return 0;}
}