#include<stdio.h>
int weight[10000]={},value[10000]={};
int MAX_VALUE=0;//最大的价值
int n,c;
void search(int i/*当前的元素*/,int wei/*当前的重量*/,int val){
    if(i==n){//是一个解，下判断是否为最大价值
        if(val>MAX_VALUE){
            MAX_VALUE=val;
        }
    }
    else {
        if(weight[i]+wei<=c)//左剪枝，当第i个元素放不进去，就不放，直接搜索下一个
            search(i+1,wei+weight[i],val+value[i]);
        search(i+1,wei,val);
    }
    return;
}
int main(){
    
    
    while(1){
        scanf("%d%d",&n,&c);
        if(n==0&&c==0)break;
        for(int i=0;i<n;i++){
            scanf("%d",&weight[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&value[i]);
        }
        search(0,0,0);
        printf("%d\n",MAX_VALUE);
        MAX_VALUE=0;
    }
    
    return 0;

}