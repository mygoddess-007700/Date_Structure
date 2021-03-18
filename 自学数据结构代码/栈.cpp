# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
    int date;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottem;
}STACK, * PSTACK;


void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool empty(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK);

int main(void)
{
    STACK S;
    int val;
    init(&S); //目的是造出一个空栈
    push(&S, 1); //压栈(入栈)
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S); //遍历输出

    if( pop(&S, &val) ) //出栈
    {
        printf("出栈成功，出栈的元素是%d\n", val);
    }
    else
    {
        printf("出栈失败！\n");
    }
    traverse(&S);

    clear(&S);
    traverse(&S);
    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    else
    {
        pS->pBottem = pS->pTop;
        pS->pTop->pNext = NULL; //pS->Bottom->pNext = NULL;
    }
    
    return;
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->date = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;

    return;
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;

    while(p != pS->pBottem)
    {
        printf("%d ", p->date);
        p = p->pNext;
    }
    printf("\n");

    return;
}

bool empty(PSTACK pS)
{
    if(pS->pTop == pS->pBottem)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败返回false，否则返回true
bool pop(PSTACK pS, int * pVal)
{
    if( empty(pS) )
    {
        return false;
    }
    else //删除不仅要把指针下移而且还要释放空间
    {
        PNODE r = pS->pTop;
        *pVal = r->date;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }
}

//清空
void clear(PSTACK pS)
{
    if( empty(pS) )
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while(p != pS->pBottem)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
    }
    pS->pTop = pS->pBottem;


}
