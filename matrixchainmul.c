#include<stdio.h>
#include<limits.h>
int matrix(int a[],int n){
    int dp[n][n];
    for(int i=1;i<n;i++){
        dp[i][i]=0;
    }
    for(int size=2;size<n;size++){
        for(int i=1;i<n-size+1;i++){
            int j=size+i-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<dp[i][j]){
                    dp[i][j]=q;
                }
            }
        }
    }
    return dp[1][n-1];
}


int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",matrix(a,n));
    return 0;
}