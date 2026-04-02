#include<stdio.h>
#include<stdlib.h>
int max(int m,int n){
  return (m>n)?m:n;
}
int powernxt(int n){
  int p=1;
  while(p<n){
    p<<=1;
  }
  return p;
}
int* polynomialmul(int* a,int* b,int n){
       int* c=(int*)calloc(2*n,sizeof(int));
       if(n==1){
        c[0]=a[0]*b[0];
        return c;
       }
       int mid=n/2;
       int* p1=polynomialmul(a,b,mid);
       int* p2=polynomialmul(a+mid,b,mid);
       int* p3=polynomialmul(a,b+mid,mid);
       int* p4=polynomialmul(a+mid,b+mid,mid);

       for(int i=0;i<2*mid;i++){
        c[i]+=p1[i];
        c[i+mid]+=p2[i]+p3[i];
        c[i+2*mid]+=p4[i];
       }
    free(p1);
    free(p2);
    free(p3);
    free(p4);

    return c; }
    


int main(){
      int n;
      scanf("%d",&n);
      int p1[n];
      for(int i=0;i<n;i++){
        scanf("%d",&p1[i]);
      }
      int m;
      scanf("%d",&m);
      int p2[m];
      for(int i=0;i<m;i++){
        scanf("%d",&p2[i]);
      }
      int size=powernxt(max(n,m));
      int* a= (int*)calloc(size,sizeof(int));
      int* b=(int*)calloc(size,sizeof(int));
      for(int i=0;i<n;i++){
             a[i] =p1[i];
      }
      for(int j=0;j<m;j++){
        b[j]=p2[j];
      }
     int* c= polynomialmul(a,b,size);
     for(int i=0;i<n+m-1;i++){
      printf("%d ",c[i]);
     }
    return 0;
}