#include<stdio.h>
int sche[129][129];

void arrange(int n,int x,int y){
    if(n==1)
        return;
    arrange(n/2,x,y);
    for(int i=x;i<x+n/2;i++){
        for(int j=y;j<y+n/2;j++){
            sche[i+n/2][j+n/2]=sche[i][j];
        }
    }
    arrange(n/2,x+n/2,y);
    for(int i=x;i<x+n/2;i++){
        for(int j=y;j<y+n/2;j++){
            sche[i][j+n/2]=sche[i+n/2][j];
        }
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    n=1<<n;
    for(int i=1;i<=n;i++){
        sche[i][1]=i;
    }

    arrange(n,1,1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",sche[i][j]);
            if(j!=n)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}