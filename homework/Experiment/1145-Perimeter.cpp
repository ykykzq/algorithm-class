//注意，此题中所有使用的数组下标从1开始
#include<stdio.h>
char graph[100][100];
bool visited[100][100];//是否访问过
int Length;//周长
void search(int m,int n,int x,int y){
    if(false){

    }
    else{
        Length=Length+4;
        if(graph[x-1][y]=='X')
            Length--;
        if(graph[x+1][y]=='X')
            Length--;
        if(graph[x][y-1]=='X')
            Length--;
        if(graph[x][y+1]=='X')
            Length--;

        
        if(graph[x-1][y-1]=='X'&&visited[x-1][y-1]==0){
            visited[x-1][y-1]=1;
            search(m,n,x-1,y-1);
        }
        if(graph[x-1][y]=='X'&&visited[x-1][y]==0){
            visited[x-1][y]=1;
            search(m,n,x-1,y);
        }
        if(graph[x-1][y+1]=='X'&&visited[x-1][y+1]==0){
            visited[x-1][y+1]=1;
            search(m,n,x-1,y+1);
        }
        if(graph[x][y-1]=='X'&&visited[x][y-1]==0){
            visited[x][y-1]=1;
            search(m,n,x,y-1);
        }
        if(graph[x][y+1]=='X'&&visited[x][y+1]==0){
            visited[x][y+1]=1;
            search(m,n,x,y+1);
        }
        if(graph[x+1][y-1]=='X'&&visited[x+1][y-1]==0){
            visited[x+1][y-1]=1;
            search(m,n,x+1,y-1);
        }
        if(graph[x+1][y]=='X'&&visited[x+1][y]==0){
            visited[x+1][y]=1;
            search(m,n,x+1,y);
        }
        if(graph[x+1][y+1]=='X'&&visited[x+1][y+1]==0){
            visited[x+1][y+1]=1;
            search(m,n,x+1,y+1);
        }
    }
    return;
}

int main(){
    int m,n,x,y;

    //初始化graph数组
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            graph[i][j]='*';

    while(1){
        scanf("%d%d%d%d",&m,&n,&x,&y);
        if(m==0&&n==0&&x==0&&y==0)//终止条件
            break;
        getchar();//吃回车
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%c",&graph[i][j]);
                visited[i][j]=0;//顺便初始化visited
            }
            getchar();//吃回车
        }
        //初始化
        Length=0;

        visited[x][y]=1;
        search(m,n,x,y);
        
        //输出
        printf("%d\n",Length);
    }
    return 0;
}
