#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Max(int v1,int v2){
    if(v1>v2){
        return v1;
    }
    return v2;
}
void lcs(char a[],char b[]){
    int n=strlen(a);
    int m=strlen(b);
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=Max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int index=dp[n][m];
    char res[index+1];
    res[index]='\0';
    int i=n;int j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            res[index-1]=a[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        
    }
}
printf("%s",res);
}

void main(){
    char a[100];
    char b[100];
    scanf("%s",a);
    scanf("%s",b);
    lcs(a,b);
}