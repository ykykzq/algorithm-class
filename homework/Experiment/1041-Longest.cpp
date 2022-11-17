#include<stdio.h>
int answer[200][200];//填表

int FindLength(char *a,char*b,int aLength,int bLength){//注意a，b从1开始编号
    //初始化，令行标下标为0时值为0
    for(int i=0;i<200;i++) 
        answer[0][i]=answer[i][0]=0;

    for(int i=1;i<=aLength;i++){//行
        for(int j=1;j<=bLength;j++){
            //对于（i，j）处的值，利用递推公式求解
            if(a[i]==b[j])
                answer[i][j]=answer[i-1][j-1]+1;
            else{
                answer[i][j]=answer[i-1][j]>answer[i][j-1]?answer[i-1][j]:answer[i][j-1];
            }
        }
    }
    return answer[aLength][bLength];
}

int main(){
    char a[210],b[210];
    fgets(a+1,210,stdin);
    fgets(b+1,210,stdin);
    int aLen=0,bLen=0;
    for(int i=1;i<210;i++){
        if((aLen==0)&&(a[i]=='\n'||a[i]==0))
            aLen=i-1;
        if((bLen==0)&&(b[i]=='\n'||b[i]==0))
            bLen=i-1;
    }

    int ans=FindLength(a,b,aLen,bLen);
    printf("%d\n",ans);

    return 0;
}