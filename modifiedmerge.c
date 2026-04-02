#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int s,int mid,int e){
    int* res=(int*)malloc(sizeof(int)*(e-s+1));
    int k=0;
    int i=s,j=mid+1;
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            res[k++]=a[i++];
        }
        else{
            res[k++]=a[j++];
        }
    }
    while(i<=mid){
         res[k++]=a[i++];
    }
    while(j<=e){
          res[k++]=a[j++];
    }
    int r=0;
    for(int i=s;i<=e;i++){
        a[i]=res[r++];
    }
 return;
}
void modif(int a[],int s,int e){
     if(s<e){
        int mid=s+(e-s)/3;
        modif(a,s,mid);
        modif(a,mid+1,e);
        merge(a,s,mid,e);
     }
}

int main(){
     int n;
     scanf("%d",&n);
     int a[n];
     for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     modif(a,0,n-1);
     for(int i=0;i<n;i++){
        printf("%d ",a[i]);
     }
    return 0;
}