#include <stdio.h>
void merge(int A[], int B[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = 0;
    int l;
    while (i < mid && j < right) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    if (i == mid) { /* i側のAをBに移動し尽くしたので、j側も順番にBに入れていく */
        while (j < right) {
            B[k++] = A[j++];
        }
    } else {
        while (i < mid) { /* j側のAをBに移動し尽くしたので、i側も順番にBに入れていく */
            B[k++] = A[i++];
        }
    }
    for (l = 0; l < k; l++) {
        A[left + l] = B[l];
    }
}
void merge_sort(int A[], int B[], int left, int right) {
    int mid;
    if (left == right || left == right - 1) { return; }
    mid = (left + right) / 2;
    merge_sort(A, B, left, mid);
    merge_sort(A, B, mid, right);
    merge(A, B, left, mid, right);
}
int main(void) {
    int a[10] = {8,4,7,2,1,3,5,6,9,10};
    int b[10] = {0};
    const int n = 10;
    int i;
    merge_sort(a, b, 0, n);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}