#include<stdio.h>
#include<stdlib.h>

int max(int n,int m){
    return (n>m)?n:m;
}
int powernxt(int n){
    int p=1;
    while(p<n){
        p<<=1;
    }
    return p;
}

int* add(int* a,int size){
    int* res=(int*)calloc(size,sizeof(int));
    for(int i=0;i<size;i++){
        res[i]=a[i]+a[i+size];
    }
    return res;
}
int* poly(int* a,int* b,int n){
    int*c=(int*)calloc(2*n,sizeof(int));
    if(n==1){
        c[0]=a[0]*b[0];
        return c;
    }
    int mid=n/2;
    int* p1=poly(a,b,mid);
    int* a0a1=add(a,mid);
    int* b0b1=add(b,mid);
    // int* p2=poly(a+mid,b,mid);
    // int* p3=poly(a,b+mid,mid);
    int* p3=poly(a0a1,b0b1,mid);
    int* p4=poly(a+mid,b+mid,mid);

    for(int i=0;i<2*mid;i++){
        c[i]+=p1[i];
        c[i+mid]+=p3[i]-p1[i]-p4[i];
        c[i+2*mid]+=p4[i];
    }
    free(p1);
    //free(p2);
    free(p3);
    free(p3);
    return c;

}
int main(){

int n,m;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
scanf("%d",&m);
int b[m];
for(int i=0;i<m;i++){
    scanf("%d",&b[i]);
}
int size=powernxt(max(m,n));
int* p1=(int*)calloc(size,sizeof(int));
int* p2=(int*)calloc(size,sizeof(int));
for(int i=0;i<n;i++){
    p1[i]=a[i];
}
for(int i=0;i<m;i++){
    p2[i]=b[i];
}

int* res=poly(p1,p2,size);
for(int i=0;i<n+m-1;i++){
    printf("%d ",res[i]);
}
free(res);
free(p1);
free(p2);
return 0;
}