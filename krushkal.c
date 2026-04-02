#include<stdio.h>
#include<stdlib.h>
#define max 100
int g[max][max];
int parent[max];
int rank[max];
struct node{
   int u;
   int v;
   int w;
};
struct node nodes[max];
int compare(const void* a,const void* b){
    struct node* a1=(struct node*)a;
    struct node* b1=(struct node*)b;
    return a1->w-b1->w;
}
int find(int x){
    if(parent[x]==x){
        return parent[x];
    }
    return parent[x]=find(parent[x]);
}
void unionset(int u,int v){
    int pu =find(u);
    int pv=find(v);
    if(pu==pv){
        return;
    }
    if(rank[pu]<rank[pv]){
        parent[pu]=pv;
    }
    else if(rank[pv]<rank[pu]){
        parent[pv]=pu;
    }
    else{
        parent[pu]=pv;
        rank[pv]++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int ec=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
            if(i<j && g[i][j]!=0){
                nodes[ec].u=i;
                nodes[ec].v=j;
                nodes[ec].w=g[i][j];
                ec++;
            }
        }
    }
    qsort(nodes,ec,sizeof(struct node),compare);
    for(int i=0;i<n;i++){
        rank[i]=0;
        parent[i]=i;
    }
    int tc=0;
    int c=0;
    for(int i=0;i<ec && c< n-1;i++){
        int u=nodes[i].u;
        int v=nodes[i].v;
        if(find(u)!=find(v)){
            tc+=nodes[i].w;
            c++;
            unionset(u,v);
        }
    }
    printf("%d",tc);
    return 0;
}