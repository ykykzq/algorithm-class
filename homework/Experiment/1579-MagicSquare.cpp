//值得注意的点是通过一个数字i表示一个二维的坐标，即51,52行
#include<stdio.h>
int square[3][3];//幻方

bool CanPlace(int x,int y,int value){
    for(int i=0;i<3*x+y;i++){
        if(value==square[i/3][i%3]){//与前述元素有重复
            return false;
        }
    }
    if(x==0&&y==2){
        if(square[0][0]+square[0][1]+value!=15)//1，上横
            return false;
    }
    else if(x==1&&y==2){
        if(square[1][0]+square[1][1]+value!=15)//2，中横
            return false;
    }
    else if(x==2&&y==0){
        if(square[0][0]+square[1][0]+value!=15)//3，左竖
            return false;
        if(value+square[1][1]+square[0][2]!=15)//4，左下对角线
            return false;
    }
    else if(x==2&&y==1){
        if(square[0][1]+square[1][1]+value!=15)//5，中竖
            return false;
    }
    else if(x==2&&y==2){
        if(square[0][0]+square[1][1]+value!=15)//6，右下对角线
            return false;
        if(value+square[1][2]+square[0][2]!=15)//7，右竖
            return false;
        if(square[2][0]+square[2][1]+value!=15)//8，下横
            return false;
    }
    return true;
}

void search(int i){
    if(i==9){
        for(int x=0;x<3;x++){
            for(int y=0;y<2;y++){
                printf("%d ",square[x][y]);
            }
            printf("%d",square[x][2]);
            printf("\n");
        }
        printf("\n");
    }
    else{
        int x=i/3;
        int y=i%3;
        for(int val=1;val<=9;val++){
            if(CanPlace(x,y,val)){
                square[x][y]=val;
                search(i+1);
            }
        }
    }
    return ;
}
int main(){
    search(0);
    return 0;
}