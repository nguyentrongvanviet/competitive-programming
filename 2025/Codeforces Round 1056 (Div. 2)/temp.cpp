#include <stdio.h>
#include <math.h>

int check(int A[], long long l, long long r){
    for (int j = l+1; j<r; j++){
        for (int i =l; i<j; i++){
            for (int k = j+1; k<= r; k++){
                if (2*A[j] == A[i]+ A[k]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


void hehehe(int A[], int n){
    // đếm số lượng mảng con không chứa i,j,k thỏa mãn đề rồi 
    //lấy tổng số lượng mảng con của cả mảng trừ đi là ra
    long long l=0, r=0;
    long long count =0;
    for (;r<n;r++){
        while (check(A,l,r)) l++;
        count+=r-l+1;
    }
    printf("%lld",1ll*n*(n+1)/2-count);
}

int main(){
    
    int n;
    scanf("%i",&n);
    int A[n];
    int i=0;
    for (;i<n;i++) scanf("%i",&A[i]);
    hehehe(A,n);
    
    return 0;
}