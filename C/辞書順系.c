#include<stdio.h>
void get(int a[], int n);
void dis(int a[], int n);
//swap(&a,&b);みたいに使う
void swap(int *a,int *b);
//x番目からy番目を逆順にする
void reverse(int a[], int x, int y);
void plus_permutation(int a[],int l);
void minus_permutation(int a[],int l);

int main(){
    int a[10]={0,1,2,3,4,9,8,7,6,5};
    int l=sizeof(a)/sizeof(int);
    plus_permutation(a,l);
    //minus_permutation(a,l);
    dis(a,10);
    return 0;
}

void get(int a[],int n){
  if(n>=1){
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
  }
}
void dis(int a[],int n){
    if(n>=1){
        for(int i=0;i<n-1;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
    }
}
void swap(int *a,int *b){
    int z;
    z=*a;
    *a=*b;
    *b=z;
}
void reverse(int a[], int x, int y){
    for(int i=0;x+i<y-i;i++){
        swap(&a[x+i],&a[y-i]);
    }
}
void plus_permutation(int a[],int l){
    int min;
    for(int i=l-1;i>0;i--){
        if(a[i-1]<a[i]){
            min=i;
            for(int k=i+1;k<l;k++){
                if(a[i-1]<a[k] && a[min]>a[k]){
                    min=k;
                }
            }
            swap(&a[i-1],&a[min]);
            reverse(a,i,l-1);
            break;
        }
    }
}
void minus_permutation(int a[],int l){
    int max;
    for(int i=l-1;i>0;i--){
        if(a[i-1]>a[i]){
            max=i;
            for(int k=i+1;k<l;k++){
                if(a[i-1]>a[k] && a[max]<a[k]){
                    max=k;
                }
            }
            swap(&a[i-1],&a[max]);
            reverse(a,i,l-1);
            break;
        }
    }
}