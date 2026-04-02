#include<stdio.h>
#define max 100
#include<limits.h>
int mindistance(int dist[],int visited[],int v){
    int min=INT_MAX;
    int mini=-1;
    for(int i=0;i<v;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            mini=i;
        }
    }
    return mini;
}
void dijkstra(int g[max][max],int v,int s){
    int dist[v];
    int visited[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[s]=0;
    for(int i=0;i<v-1;i++){
        int u=mindistance(dist,visited,v);
        if(u==-1){break;}
        visited[u]=1;
        for(int i=0;i<v;i++){
            if(visited[i]==0 && g[u][i]!=INT_MAX && dist[u]!=INT_MAX && dist[u]+g[u][i] <dist[i]){
                dist[i]=dist[u]+g[u][i];
            }
        }
    }
    for(int i=0;i<v;i++){
        if(dist[i]!=INT_MAX){
        printf("%d ",dist[i]);}
        else{
            printf("INF ");
        }
    }
}
int main(){
   int v,e;
   scanf("%d%d",&v,&e);
   int g[max][max];
   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        if(i==j){
            g[i][j]=0;
        }
        else{
        g[i][j]=INT_MAX;}
    }
   }
   for(int i=0;i<e;i++){
       int u,v1,w;
       scanf("%d%d%d",&u,&v1,&w);
       g[u][v1]=w;
       g[v1][u]=w;
   }
   int s;
   scanf("%d",&s);
   dijkstra(g,v,s);
   return 0;
}