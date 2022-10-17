#include<stdio.h>
typedef struct Stack{
    char stack[200];
    char ptr=-1;
}Stack,*pStack;

void Push(pStack p,char i){
    p->ptr++;
    p->stack[p->ptr]=i;
    return;
}

char Pop(pStack p){
    if(p->ptr<0)return -1;
    return p->stack[p->ptr];
    p->ptr--;
}

char now_op[200];//当前的操作顺序

char letter[200];//原序列
int ptr_le;//指向原序列

char goal[200];//目标序列
int ptr_goa;//指向目标序列

Stack s;


void dfs(int i,int NofLetter){//i是第几次操作,从0开始
    if(ptr_goa==NofLetter){
        for(int j=0;j<NofLetter;j++)
            printf("%c ",now_op[j]);
    }
    else {
        //入栈
        if(ptr_le<NofLetter){
            Push(&s,letter[ptr_le]);
            ptr_le++;
            now_op[i]='i';
            dfs(i+1,NofLetter);
            Pop(&s);
            ptr_le--;
        }
        
        //出栈（栈里有元素）
        if(s.ptr>=0&&s.stack[s.ptr]==letter[ptr_le]){
            char temp=Pop(&s);
            ptr_goa++;
            now_op[i]='o';
            dfs(i+1,NofLetter);
            ptr_goa--;
            Push(&s,temp);
        }        
    }
}