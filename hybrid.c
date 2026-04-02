#include<stdio.h>
int partition(int a[],int s,int n){
int pivot=a[n];
int i=s-1;
int j=s;
for(j;j<n;j++){
    if(a[j]<pivot){
        i++;
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
i++;
int temp=a[i];
a[i]=a[n];
a[n]=temp;
return i;

}
void selection(int a[],int s,int n){
    for(int i=s;i<n;i++){
        int mini=i;
        for(int j=i+1;j<=n;j++){
            if(a[mini]>a[j]){
                mini=j;
            }
        }
        int temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
    }
    }


void quick(int a[],int s,int n,int k){
    if(n-s+1 <=k){
        selection(a,s,n);
        return;
    }
    if(s<n){
    int pi=partition(a,s,n);
    quick(a,s,pi-1,k);
    quick(a,pi+1,n,k);}
}
int main(){
     int n;
     scanf("%d",&n);
     int k;
     scanf("%d",&k);
     int a[n];
     for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     quick(a,0,n-1,k);
     for(int i=0;i<n;i++){
        printf("%d ",a[i]);
     }
    return 0;
}