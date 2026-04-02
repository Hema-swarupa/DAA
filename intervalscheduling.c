#include<stdio.h>
struct interval{
    int s;
    int f;
};
int main(){


    int n;
    scanf("%d",&n);
    struct interval act[n];
    int num=1;
    for(int i=0;i<n;i++){
        scanf("%d",&act[i].s);
        scanf("%d",&act[i].f);
    }
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
          if(act[j].f<act[min].f){
            min=j;
          }
        }
        struct interval temp=act[i];
        act[i]=act[min];
        act[min]=temp;
    }
    int last=act[0].f;
    for(int i=1;i<n;i++){
        if(act[i].s>=last){
            num++;
            last=act[i].f;
        }
    }
    printf("%d",num);
    return 0;
}