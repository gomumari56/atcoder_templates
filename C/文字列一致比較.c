#include<stdio.h>
#include<string.h>
int main(){
    char s1[10]="abcdefghij";
    char s2[10]="bacdefghij";
    char s3[10]="abcdefghij";
    int ans=strncmp(s1+2,s2+2,2);
    printf("ans=%d",ans);
    return 0;
}