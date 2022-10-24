#include<stdio.h>
#include<queue>
using namespace std;

typedef struct node
{
    int PeopleX,PeopleY;
    int BoxX,BoxY;
    int step;
}node;

//全局变量
queue <node> q1;
char maze[10][10];
bool used[10][10][10][10];//PeopleX,PeopleY,BoxX,BoxY

bool Check(node NewNode){
    if(NewNode.PeopleX<0||NewNode.PeopleY<0||NewNode.PeopleX>9||NewNode.PeopleY>9)//人越界
        return false;
    if(NewNode.BoxX<0||NewNode.BoxY<0||NewNode.BoxX>9||NewNode.BoxY>9)//箱子越界
        return false;
    if(maze[NewNode.PeopleX][NewNode.PeopleY]=='1')//人遇墙
        return false;
    if(maze[NewNode.BoxX][NewNode.BoxY]=='1')//箱子遇墙
        return false;
    if(used[NewNode.PeopleX][NewNode.PeopleY][NewNode.BoxX][NewNode.BoxY])//判重
        return false;
    return true;
}

node MakeNewNode(node NowNode,int i){//只进行人的移动，之后看箱子如何移动
    node NewNode=NowNode;
    NewNode.step++;
    if(i==1){//人往上走
        NewNode.PeopleX--;
        if(NewNode.PeopleX==NewNode.BoxX&&NewNode.PeopleY==NewNode.BoxY)//位置重合了
            NewNode.BoxX--;//则箱子被向上推动
    }
    if(i==2){//人往下走
        NewNode.PeopleX++;
        if(NewNode.PeopleX==NewNode.BoxX&&NewNode.PeopleY==NewNode.BoxY)//位置重合了
            NewNode.BoxX++;//则箱子被向下推动
    }
    if(i==3){//人往左走
        NewNode.PeopleY--;
        if(NewNode.PeopleX==NewNode.BoxX&&NewNode.PeopleY==NewNode.BoxY)//位置重合了
            NewNode.BoxY--;//则箱子被向左推动
    }
    if(i==4){//人往右走
        NewNode.PeopleY++;
        if(NewNode.PeopleX==NewNode.BoxX&&NewNode.PeopleY==NewNode.BoxY)//位置重合了
            NewNode.BoxY++;//则箱子被向右推动
    }
    return NewNode;
}

int search(node start,node end){
    used[start.PeopleX][start.PeopleY][end.BoxX][end.BoxY]=true;
    q1.push(start);
    while (!q1.empty())
    {
        node NowNode=q1.front();q1.pop();

        node NewNode;
        for(int i=1;i<=4;i++){
            NewNode=MakeNewNode(NowNode,i);
            if(Check(NewNode)){
                used[NewNode.PeopleX][NewNode.PeopleY][NewNode.BoxX][NewNode.BoxY]=true;
                if(NewNode.BoxX==end.BoxX&&NewNode.BoxY==end.BoxY){
                    return NewNode.step;
                }
                q1.push(NewNode);
            }
        }
    }//endWhile
    return -1;
}

int main(){
    node start,end;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char x;
            scanf("%c",&x);
            if(x=='2'){//箱子
                start.BoxX=i;
                start.BoxY=j;
                maze[i][j]='0';
            }
            else if (x=='3')//目标位置
            {
                end.BoxX=i;
                end.BoxY=j;
                maze[i][j]='0';
            }
            else if (x=='4')//人
            {
                start.PeopleX=i;
                start.PeopleY=j;
                maze[i][j]='0';
            }
            else
                maze[i][j]=x;
        }
        getchar();//吃回车
    }//end i for

    //初始化
    start.step=0;
    int answer=search(start,end);

    printf("%d\n",answer);

    return 0;
}//end main