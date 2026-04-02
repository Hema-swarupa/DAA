#include<stdio.h>
#include<stdlib.h>
struct item{
int weight;
int profit;
float ratio;
};
void merge(struct item a[],int s,int mid,int e){
    struct item* p=(struct item*)malloc(sizeof(struct item)*(e-s+1));
    int k=0;
    int i=s,j=mid+1;
    while(i<=mid && j<=e){
       if(a[i].ratio>a[j].ratio){
        p[k]=a[i];
        k++;
        i++;
       }
       else{
        p[k++]=a[j++];
       }

    }
    while(i<=mid ){
        p[k]=a[i];
        k++;
        i++;
    }
     while( j<=e){
        p[k++]=a[j++];
     }
       k=0;
       for(int i=s;i<=e;i++){
        a[i]=p[k++];
       }

   free(p);
   return;
}

void mergesort(struct item a[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}

int main(){
     int n;
     scanf("%d",&n);
     int weight;
     scanf("%d",&weight);
    struct item items[n];
     for(int i=0;i<n;i++){
        scanf("%d",&items[i].weight);
    }
     for(int i=0;i<n;i++){
        scanf("%d",&items[i].profit);
    }
    for(int i=0;i<n;i++){
        items[i].ratio=(float)items[i].profit/items[i].weight;
    }
    mergesort(items,0,n-1);
    // for(int i=0;i<n;i++){
    //     printf("%.2f ",items[i].ratio);
    // }
    int temp=0;
    int profit=0;
    for(int i=0;i<n;i++){
        if(temp+items[i].weight<=weight){
            profit +=items[i].profit;
            temp +=items[i].weight;
        }
    }
    printf("%d",profit);

    return 0;
}