#include<stdio.h>
int weight[10000]={};
int n,c1,c2;
int MaxWeight;//第一艘船的最大重量
void search(int i/*当前的元素*/,int wei){
    if(i==n){//是一个解，下判断
        if(wei>MaxWeight)
            MaxWeight=wei;
    }
    else {
        if(weight[i]+wei<=c1)//左剪枝，当第i个元素放不进去，就不放，直接搜索下一个(转到右枝)
            search(i+1,wei+weight[i]);
        search(i+1,wei);//右枝，此箱子不放入船1
    }
    return ;//返回船1目前装载的重量
}
int main(){
    
    
    while(1){
        scanf("%d%d%d",&c1,&c2,&n);
        if(n==0&&c1==0&&c2==0)break;
        for(int i=0;i<n;i++){
            scanf("%d",&weight[i]);
        }

        MaxWeight=0;
        search(0,0);

        int sum=0;//所有集装箱的总重量
        for(int i=0;i<n;i++)
            sum+=weight[i];
            
        if(sum-MaxWeight>c2)  
            printf("No\n");
        else 
            printf("Yes\n");
    }
    
    return 0;

}