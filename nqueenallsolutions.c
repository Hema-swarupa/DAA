#include<stdio.h>
#define max 20
int count=0;
int found=0;
void printboard(int board[max][max],int n){
   count++;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(board[i][j]){
            printf("Q ");
        }
        else{
            printf(". ");
        }
    }
    printf("\n");
   }
   printf("\n");
}

int issafe(int board[max][max],int r,int c,int n){
    for(int i=0;i<r;i++){
        if(board[i][c])return 0;
    }
    for(int i=r-1, j=c-1;i>=0 && j>=0;i--,j--){
        if(board[i][j])return 0;
    }
    for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
        if(board[i][j])return 0;
    }
    return 1;
}
void solve(int board[max][max],int row,int n){
    if(row==n){
        found=1;
        printboard(board,n);
        return;
    }
    if(found==1){
        return;
    }
    for(int c=0;c<n;c++){
        if(issafe(board,row,c,n)){
            board[row][c]=1;
            solve(board,row+1,n);
            board[row][c]=0;
        }
    }
}

int main(){
   int n;
   scanf("%d",&n);
   int board[max][max]={0};
   solve(board,0,n);
   printf("%d",count);
    return 0;
}