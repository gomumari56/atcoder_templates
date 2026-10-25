#include<stdio.h>
void get(int a[200001], int n);
void dis(int a[200001], int n);

int main(){
  int n,a[20];
  scanf("%d",&n);
  get(a,n);
  dis(a,5);
  dis(a,5);
  return 0;
}
void get(int a[200001],int n){
  if(n>=1){
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
  }
}
void dis(int a[200001],int n){
  if(n>=1){
    for(int i=0;i<n;i++){
      printf("%d ",a[i]);
    }
  }
}