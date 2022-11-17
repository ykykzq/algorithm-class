#include<stdio.h>
int answer[100];//answer[i]表示以第i个导弹结束的最大递减序列长度
int FindLen(int *missile,int mLength){
    //初始化
    for(int i=0;i<100;i++)
        answer[i]=1;//一定至少能拦截一个
    
    for(int i=1;i<=mLength;i++){
        for(int j=1;j<i;j++){
            if(missile[j]>=missile[i])//这个导弹比当前导弹高
                if(answer[j]+1>answer[i])//且可构建更长的序列
                    answer[i]=answer[j]+1;
            //else do nothing
        }
    }
    int ans=0;
    for(int i=1;i<=mLength;i++)
        if(answer[i]>ans)
            ans=answer[i];
    
    return ans;
}
int main(){
    while(1){
        int n;
        scanf("%d",&n);

        if(n==0)//终止条件
            break;

        int missile[100];
        for(int i=1;i<=n;i++)
            scanf("%d",&missile[i]);
        int ans=FindLen(missile,n);
        printf("%d\n",ans);
    }
    return 0;
}