#include<stdio.h>
#include<algorithm>


void BubbleSort(int *a,int n){//使之递增
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]>a[j+1]){
                a[j]=a[j]^a[j+1];
                a[j+1]=a[j]^a[j+1];
                a[j]=a[j]^a[j+1];
            }
        }
    }
    return ;
}
int FindWin(int *tHorse,int *qHorse,int HorseNum){
    int win=0;
    int qFast=HorseNum,qLow=1,tFast=HorseNum,tLow=1;
    for(int i=1;i<=HorseNum;i++){
        if(tHorse[tFast]>qHorse[qFast]){
            win++;
            tFast--;
            qFast--;
        }
        else if(tHorse[tLow]>qHorse[qLow]){
            win++;
            tLow++;
            qLow++;
        }
        else{
            if(tHorse[tLow]<qHorse[qFast]){
                win--;
                tLow++;
                qFast--;
            }
        }
    }
    return win;
}
int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        
        int qHorse[100],tHorse[100];
        for(int i=1;i<=n;i++)
            scanf("%d",&tHorse[i]);
        for(int j=1;j<=n;j++)
            scanf("%d",&qHorse[j]);

        BubbleSort(qHorse,n);
        BubbleSort(tHorse,n);

        int ans=FindWin(tHorse,qHorse,n);
        printf("%d\n",ans);
    }
    return 0;
}