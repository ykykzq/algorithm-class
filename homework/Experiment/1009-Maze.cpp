#include<stdio.h>
char maze[20][20];

bool HaveWay=false;

bool CanPlace(int x,int y){
    if(x<0||x>19||y<0||y>19)//越界不能通行
        return false;
    if(maze[x][y]=='X')//是墙不能通行
        return false;
    if(maze[x][y]=='W')//走过的地方不能通行
        return false;
    return true;
}

// int flag_display=0;
// void display(){//用于debug
//     printf("%d:\n",flag_display++);
//     for(int i=0;i<20;i++){
//         for(int j=0;j<20;j++)
//             printf("%c",maze[i][j]);
//         printf("\n");
//     }
        
//     printf("\n");
//     return;
// }

// bool NoWay(int x,int y){//走入了死胡同
//     if(!CanPlace(x,y-1))//上
//         if(!CanPlace(x,y+1))//下
//             if(!CanPlace(x-1,y))//左
//                 if(!CanPlace(x+1,y))//右
//                     return true;
//     return false;
// }

void FindMaze(int now_x,int now_y,int end_x,int end_y){
    if(now_x==end_x&&now_y==end_y){
        HaveWay=true;
    }
    else{
        if(CanPlace(now_x,now_y-1)){
            maze[now_x][now_y-1]='W';
            // display();
            FindMaze(now_x,now_y-1,end_x,end_y);
            // printf("退回\n");
            maze[now_x][now_y-1]='.';
        }
        if(CanPlace(now_x,now_y+1)){
            maze[now_x][now_y+1]='W';
            // display();
            FindMaze(now_x,now_y+1,end_x,end_y);
            // printf("退回\n");
            maze[now_x][now_y+1]='.';
        }
        if(CanPlace(now_x-1,now_y)){
            maze[now_x-1][now_y]='W';
            // display();
            FindMaze(now_x-1,now_y,end_x,end_y);
            // printf("退回\n");
            maze[now_x-1][now_y]='.';
        }
        if(CanPlace(now_x+1,now_y)){
            maze[now_x+1][now_y]='W';
            // display();
            FindMaze(now_x+1,now_y,end_x,end_y);
            // printf("退回\n");
            maze[now_x+1][now_y]='.';
        }
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(;n;n--){//执行n次迷宫问题
        int start_i,start_j,end_i,end_j;
        scanf("%d%d%d%d",&start_i,&start_j,&end_i,&end_j);
        getchar();//吃回车
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++)
                scanf("%c",&maze[i][j]);
            getchar();//吃回车
        }
            
        
        HaveWay=false;
        if(CanPlace(start_i,start_j))
            maze[start_i][start_j]='W';
        FindMaze(start_i,start_j,end_i,end_j);
        if(HaveWay)
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}