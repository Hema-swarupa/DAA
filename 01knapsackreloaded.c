#include<stdio.h>
struct item{
    int w;
    int p;
};
int max(int v,int u){
    return (v>u)?v:u;
}
int knapsack(struct item items[],int n,int w){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(items[i-1].w<=j){
                dp[i][j]=max(dp[i-1][j],items[i-1].p+dp[i-1][j-items[i-1].w]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
   int n;
   scanf("%d",&n);
   int w;
   scanf("%d",&w);
   struct item items[n];
   for(int i=0;i<n;i++){
    scanf("%d",&items[i].p);
   }
   for(int i=0;i<n;i++){
    scanf("%d",&items[i].w);
   }
   printf("%d",knapsack(items,n,w));
    return 0;
}