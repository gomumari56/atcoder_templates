#include<stdio.h>
#include<stdlib.h>
int llcmpnum(const void * n1, const void * n2);
int main(){
	long long num[] = { 60, 10, 50, 30, 80, 40 ,20, 90, 70 , 0};
	int i;
	//	quicksortによる並べ替え
	qsort(num,sizeof(num)/sizeof(num[0]),sizeof(long long),llcmpnum);
    // 結果表示
    for(i=0;i<sizeof(num)/sizeof(num[0]);i++){
        printf("%ld ",num[i]);
    }
	return 0;
}
int llcmpnum(const void * n1, const void * n2){
	if (*(long long*)n1 > *(long long*)n2){
		return 1;
	}
	else if (*(long long*)n1 < *(long long*)n2){
		return -1;
	}
	else{
		return 0;
	}
}