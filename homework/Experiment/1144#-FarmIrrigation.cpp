// 用回溯法比较困难。我的思路是决策树的每一个分叉为每一个方格是否放置井，并且利用剪枝剪掉
// 不能使每一块地都被灌溉的枝（即左、上的块不能使他有水，并且右、下都不联通，必须有井）。
// 困难在于，把上方与左侧的所有块是否被灌溉都维护好。

//因此直接暴力比较简单，本质上是判断有几条相互独立的通路
#include<stdio.h>
char Farm[50][50];
int Water[50][50];//每块地都有水与否
int NofWell;


void search(int x,int y,int m,int n){
    Water[x][y]=1;
    if(x!=0)//不是第一行，上面有地块
        if(Farm[x-1][y]=='C'||Farm[x-1][y]=='D'||Farm[x-1][y]=='E'||Farm[x-1][y]=='H'||Farm[x-1][y]=='I'||Farm[x-1][y]=='J'||Farm[x-1][y]=='K')
        //上if表示上块与此块有联通水渠
            if(Farm[x][y]=='A'||Farm[x][y]=='B'||Farm[x][y]=='E'||Farm[x][y]=='G'||Farm[x][y]=='H'||Farm[x][y]=='J'||Farm[x][y]=='K')
            //上if表示此块有与上块联通的水渠
                if(Water[x-1][y]==0)
                    search(x-1,y,m,n);
    
    if(y!=0)//不是第一列，左侧有地块
        if(Farm[x][y-1]=='B'||Farm[x][y-1]=='D'||Farm[x][y-1]=='F'||Farm[x][y-1]=='G'||Farm[x][y-1]=='I'||Farm[x][y-1]=='J'||Farm[x][y-1]=='K')
        //上if表示左块与此块有联通水渠
            if(Farm[x][y]=='A'||Farm[x][y]=='C'||Farm[x][y]=='F'||Farm[x][y]=='G'||Farm[x][y]=='H'||Farm[x][y]=='I'||Farm[x][y]=='K')
            //上if表示此块与左块有联通水渠
                if(Water[x][y-1]==0)
                    search(x,y-1,m,n);
    if(x<m-1)
        if(Farm[x][y]=='C'||Farm[x][y]=='D'||Farm[x][y]=='E'||Farm[x][y]=='H'||Farm[x][y]=='I'||Farm[x][y]=='J'||Farm[x][y]=='K')
        //上if表示此块与下块有联通水渠
            if(Farm[x+1][y]=='A'||Farm[x+1][y]=='B'||Farm[x+1][y]=='E'||Farm[x+1][y]=='G'||Farm[x+1][y]=='H'||Farm[x+1][y]=='J'||Farm[x+1][y]=='K')
            //上if表示下块有与此块联通的水渠
                if(Water[x+1][y]==0)
                    search(x+1,y,m,n);
    if(y<n-1)
        if(Farm[x][y]=='B'||Farm[x][y]=='D'||Farm[x][y]=='F'||Farm[x][y]=='G'||Farm[x][y]=='I'||Farm[x][y]=='J'||Farm[x][y]=='K')
        //上if表示此块与右块有联通水渠
            if(Farm[x][y+1]=='A'||Farm[x][y+1]=='C'||Farm[x][y+1]=='F'||Farm[x][y+1]=='G'||Farm[x][y+1]=='H'||Farm[x][y+1]=='I'||Farm[x][y+1]=='K')
            //上if表示右块与此块有联通水渠
                if(Water[x][y+1]==0)
                    search(x,y+1,m,n);

    return ;
}

int main(){
    while(1){
        int m,n;
        scanf("%d %d",&m,&n);
        if(m==-1&&n==-1)//终止条件
            break;
        
        getchar();//吃掉回车
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%c",&Farm[i][j]);
            }
            getchar();//吃掉回车
        }

        NofWell=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                Water[i][j]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(Water[i][j]!=1){
                    search(i,j,m,n);
                    NofWell++;
                }
            }
        }

        printf("%d\n",NofWell);
    }
    return 0;
}