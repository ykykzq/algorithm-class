#include<stdio.h>
int answer[12][12];
typedef struct Matrix
{
    int x,y;
}Matrix;
Matrix input[11];

int Find(int n){
    //初始化
    for(int i=1;i<12;i++){
        answer[i][i]=0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            int min=~(1<<31);
            int x=j,y=i+j-1;
            for(int c=x;c<y;c++){//分割
                if(min>answer[x][c]+answer[c+1][y]+input[x].x*input[c].y*input[y].y)
                    min=answer[x][c]+answer[c+1][y]+input[x].x*input[c].y*input[y].y;
            }
            answer[x][y]=min;
        }
    }
    return answer[1][n];
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&(input[i].x),&(input[i].y));
    }
    int ans=Find(n);
    printf("%d\n",ans);
    return 0;
}
