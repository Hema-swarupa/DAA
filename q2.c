#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
    int u;
    int v;
    int w;
};
int compare(const void* a,const void* b){
    struct node* a1=(struct node*)a;
    struct node* b1=(struct node*)b;
    return a1->w-b1->w;
}
int find(int u,int parent[],int n){
      if(parent[u]==u){
        return u;
      }
      return parent[u]=find(parent[u],parent,n);
}
void unionset(int u,int v,int parent[],int n,int rank[]){
    int pu=find(u,parent,n);
    int pv=find(v,parent,n);
    if(pu==pv){
        return;
    }
    else if(rank[pu]<rank[pv]){
        parent[pu]=pv;
    }
    else if(rank[pv] <rank[pu]){
        parent[pv]=pu;
    }
    else{
        parent[pu]=pv;
        rank[pv]++;
    }
}
void krushkal(struct node nodes[],int n,int e){
    int parent[n];
    int rank[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    qsort(nodes,e,sizeof(nodes[0]),compare);
    int c=0;
    int add=0;
    for(int i=0;i<e && add<n-1 ;i++){
        if(nodes[i].w==INT_MAX){
            continue;
        }
        int u=nodes[i].u;
        int v=nodes[i].v;
        if(find(u,parent,n)!=find(v,parent,n)){
             c+=nodes[i].w;
             add++;
             unionset(u,v,parent,n,rank);
        }
    }
    if(add==n-1){
    printf("%d",c);}
    else{
        printf("IMPOSSIBLE");
    }
}
int main(){
   int n, e;
   scanf("%d%d",&n,&e);
   struct node nodes[e];
   for(int i=0;i<e;i++){
    scanf("%d%d%d",&nodes[i].u,&nodes[i].v,&nodes[i].w);
   }
   int f;
   scanf("%d",&f);
   for(int i=0;i<f;i++){
    int ei;
    scanf("%d",&ei);
    nodes[ei-1].w=INT_MAX;
   }
   krushkal(nodes,n,e);
    return 0;
}