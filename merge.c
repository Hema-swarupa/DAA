#include <stdio.h>
#include<stdlib.h>
void merge(int a[],int s,int mid,int n){
  int* res=(int*)malloc(sizeof(int)*(n-s+1));
  int k=0;
  int i=s,j=mid+1;
  while(i<=mid && j<=n){
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
  while(j<=n){
      res[k++]=a[j++];
  }
  k=0;
  for(int i=s;i<=n;i++){
    a[i]=res[k++];
  }

  free(res);
  return;
}
void msort(int a[],int s,int n){
   if(s>=n){
    return;
   }
   int mid= s+(n-s)/2;
   msort(a,s,mid);
   msort(a,mid+1,n);
   merge(a,s,mid,n);
    
}
int main(){
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
  scanf("%d",&a[i]);
}

 msort(a,0,n-1);
 for(int i=0;i<n;i++){
 printf("%d ",a[i]); }

}