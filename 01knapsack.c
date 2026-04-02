#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
void knap(int w[],int p[],int c,int n){
     int dp[n+1][c+1];
     for(int i=0;i<=n;i++){
        for(int w1=0;w1<=c;w1++){
            if(i==0 || w1==0){
                dp[i][w1]=0;
            }
            else if(w[i-1]<=w1){
               dp[i][w1]=max(dp[i-1][w1],p[i-1]+dp[i-1][w1-w[i-1]]);
            }
            else{
                dp[i][w1]=dp[i-1][w1];
            }
        }
     }
     printf("%d",dp[n][c]);
}

void main(){
    int n;
    scanf("%d",&n);
    int c;
    scanf("%d",&c);
    int w[n];
    int p[n];
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        scanf("%d",&p[i]);
    }
    knap(w,p,c,n);
    return 0;
}