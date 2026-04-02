#include<stdio.h>
#include<limits.h>
void matrix(int a[],int n){
    int ap[n][n];
    for(int i=1;i<n;i++){
        ap[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            ap[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int cost=ap[i][k]+ap[k+1][j]+a[i-1]*a[k]*a[j];
                if(cost<ap[i][j]){
                    ap[i][j]=cost;
                }
            }
        }
    }
    printf("%d",ap[1][n-1]);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    matrix(a,n);

    return 0;
}