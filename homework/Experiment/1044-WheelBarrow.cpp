//需要注意的是，每一个点都有5*4（颜色*方向）种状态
//因此不能像之前一样，直接用maze存储状态并判重
//另开一个bool数组（line19），用于记录有过的状态，进而判重
#include<stdio.h>
#include<queue>
using namespace std;

//定义数据结构
typedef struct node{
    int x,y;
    int color;//颜色
    int direction;//方向
    int step;//表示几步——此题中为花费的时间
}node;

//全局变量
queue <node> q1;
char maze[20][20];
bool used[20][20][5][4];
//函数部分

//转化方向为int
int TransColor(char color){
    if(color=='R')
        return 0;
    if(color=='Y')
        return 1;
    if(color=='B')
        return 2;
    if(color=='W')
        return 3;
    if(color=='G')
        return 4;  
    return -1;  
}

//转化方向为int
int TransDir(char direction){
    if(direction=='E')
        return 0;
    if(direction=='S')
        return 1;
    if(direction=='W')
        return 2;
    if(direction=='N')
        return 3;
    return -1;
}

//扩展节点
node MakeNewNode(node NowNode,int i){
    node NewNode=NowNode;
    NewNode.step++;
    if(i==1){//直走
        NewNode.color=(NewNode.color+1)%5;
        if(NewNode.direction==0)//东
            NewNode.y++;
        else if(NewNode.direction==1)//南
            NewNode.x++;
        else if(NewNode.direction==2)//西
            NewNode.y--;
        else if(NewNode.direction==3)//北
            NewNode.x--;
    }
    else if(i==2){//转向-
        NewNode.direction=(NewNode.direction+1)%4;
    }
    else if(i==3){//转向-
        NewNode.direction=(NewNode.direction-1+4)%4;
    }
    return NewNode;
}

//判断是否可扩展
bool Check(node NewNode){
    if(NewNode.x<0||NewNode.y<0||NewNode.x>19||NewNode.y>19)//越界
        return false;
    if(maze[NewNode.x][NewNode.y]=='X')//墙
        return false;
    if(used[NewNode.x][NewNode.y][NewNode.color][NewNode.direction]==1)//此节点的此方向已出现过
        return false;
    return true;
}

void display(){
    printf("\n");
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(maze[i][j]=='X'||maze[i][j]=='.')
                printf("%3c",maze[i][j]);
            else printf("%3d",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return ;
}
//解决问题的函数
int search(node start,node end){
    used[start.x][start.y][start.color][start.direction]=1;
    maze[start.x][start.y]=1;
    q1.push(start);
    while(!q1.empty()){
        node NowNode=q1.front();q1.pop();

        node NewNode;
        for(int i=1;i<=3;i++){
            NewNode=MakeNewNode(NowNode,i);
            if(Check(NewNode)){
                used[NewNode.x][NewNode.y][NewNode.color][NewNode.direction]=1;
                maze[NewNode.x][NewNode.y]=1;
                //debug
                // if(maze[NewNode.x][NewNode.y]>NewNode.step||maze[NewNode.x][NewNode.y]=='.')
                //     maze[NewNode.x][NewNode.y]=NewNode.step;
                // display();

                if(NewNode.x==end.x&&NewNode.y==end.y&&NewNode.color==end.color){//到达终点
                    return NewNode.step;
                }
                q1.push(NewNode);
            }//endIf
        }//endFor
    }//endWhile
    return -1;
}//endFuction

int main(){
    node start,end;
    char color,direction;

    scanf("%d%d",&start.x,&start.y);
    getchar();
    color=getchar();
    getchar();
    direction=getchar();
    //修正、转化
    start.x--;
    start.y--;
    start.color=TransColor(color);
    start.direction=TransDir(direction);

    scanf("%d%d",&end.x,&end.y);
    getchar();
    color=getchar();
    //修正、转化
    end.x--;
    end.y--;
    end.color=TransColor(color);

    getchar();//吃回车
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++)
            scanf("%c",&maze[i][j]);
        getchar();
    }

    //初始化
    start.step=0;
    int answer=search(start,end);
    printf("%d\n",answer);
    return 0;
}