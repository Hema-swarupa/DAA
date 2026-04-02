#include<stdio.h>
int minkey(int mstset[],int key[],int n){
   int min=999;
   int minid;
   for(int i=0;i<n;i++){
    if(mstset[i]==0 && min>key[i]){
        min=key[i];
        minid=i;
    }
   }
   return minid;
}
int main(){
    int n;
    scanf("%d",&n);
    int g[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
    }
    }
    int parent[n];
    int mstset[n];
    int key[n];
    for(int i=0;i<n;i++){
        mstset[i]=0;
        key[i]=999;
    }
    parent[0]=-1;
    key[0]=0;
    for(int i=0;i<n-1;i++){
        int u=minkey(mstset,key,n);
        mstset[u]=1;
        for(int v=0;v<n;v++){
            if(g[u][v] !=0 && mstset[v]==0 && g[u][v]<key[v]){
                parent[v]=u;
                key[v]=g[u][v];
            }
        }
    }
    int t=0;
    for(int i=1;i<=n-1;i++){
         t+=g[i][parent[i]];
    }
    printf("%d",t);
    return 0;
}