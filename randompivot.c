#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int s,int n){
    int p=s+rand()%(n-s+1);
    int pivot=a[p];
    int temp=a[n];
        a[n]=a[p];
        a[p]=temp;
     int i=s-1;
    for(int j=s;j<n;j++){
       if(a[j]<pivot){
        i++;
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
       }
    }
    i++;
     temp=a[i];
        a[i]=a[n];
        a[n]=temp;
        return i;
}

void quick(int a[],int s,int n){
    if(s<n){
    int pi=partition(a,s,n);
    quick(a,s,pi-1);
    quick(a,pi+1,n);}
}
int main(){
     int n;
     scanf("%d",&n);
     int a[n];
     for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     quick(a,0,n-1);
     for(int i=0;i<n;i++){
        printf("%d ",a[i]);
     }
    return 0;
}