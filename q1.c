#include<stdio.h>
#define max 100
#include<limits.h>
int mindistance(int dist[],int visit[],int n){
    int mini=-1;int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(visit[i]==0 && dist[i]<min){
            mini=i;
            min=dist[i];
        }
    }
    return mini;
}
void printpath(int parent[],int d){
      if(parent[d]==-1){
        printf("%d",d);
        return;
      }
    printpath(parent,parent[d]);
     printf("->%d",d);
}
void dijkstra(int g[max][max],int n,int s,int d){
    int dist[n];
    int vist[n];
    int parent[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        vist[i]=0;
        parent[i]=-1;
    }
    dist[s]=0;
    for(int i=0;i<n-1;i++){
        int u=mindistance(dist,vist,n);
        vist[u]=1;
        for(int v=0;v<n;v++){
            if(g[u][v]!=INT_MAX && vist[v]==0 && dist[u]!=INT_MAX && dist[v]>g[u][v]+dist[u] ){
                dist[v]=dist[u]+g[u][v];
                parent[v]=u;
            }
        }
    }
    
    printf("%d ",dist[d]);
    printpath(parent,d);
}


int main(){
int n,e;
scanf("%d%d",&n,&e);
int g[max][max];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j){
            g[i][j]=0;
        }
        else{
            g[i][j]=INT_MAX;
        }
}
}
for(int i=0;i<e;i++){
    int v1,u,w;
    scanf("%d%d%d",&u,&v1,&w);
    g[u][v1]=w;
    g[v1][u]=w;
}
int s;
scanf("%d",&s);
int d;
scanf("%d",&d);
dijkstra(g,n,s,d);
    return 0;
}