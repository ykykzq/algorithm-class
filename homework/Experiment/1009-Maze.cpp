#include<stdio.h>
char maze[20][20];

bool HaveWay=false;


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

void FindMaze(int now_x,int now_y,int end_x,int end_y){
    if(now_x==end_x&&now_y==end_y){
        HaveWay=true;
    }
    else if(maze[now_x][now_y]!='.'||now_x<0||now_y<0||now_x>19||now_y>19){

    }
    else{
        maze[now_x][now_y]='W';
         

        FindMaze(now_x,now_y+1,end_x,end_y);

        FindMaze(now_x+1,now_y,end_x,end_y);

        FindMaze(now_x,now_y-1,end_x,end_y);
        
        FindMaze(now_x-1,now_y,end_x,end_y);  
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(;n;n--){//执行n次迷宫问题
        int start_i,start_j,end_i,end_j;
        scanf("%d %d %d %d",&start_i,&start_j,&end_i,&end_j);
        getchar();//吃回车
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                scanf("%c",&maze[i][j]);
            }
            getchar();//吃回车
        }
            
        
        HaveWay=false;
        FindMaze(start_i,start_j,end_i,end_j);
        if(HaveWay)
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}