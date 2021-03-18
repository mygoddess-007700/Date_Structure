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
    init(&S); //Ŀ�������һ����ջ
    push(&S, 1); //ѹջ(��ջ)
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S); //�������

    if( pop(&S, &val) ) //��ջ
    {
        printf("��ջ�ɹ�����ջ��Ԫ����%d\n", val);
    }
    else
    {
        printf("��ջʧ�ܣ�\n");
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
        printf("��̬�ڴ����ʧ�ܣ�\n");
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
//��pS��ָ���ջ��ջһ�Σ����ѳ�ջ��Ԫ�ش���pVal�β���ָ��ı����У������ջʧ�ܷ���false�����򷵻�true
bool pop(PSTACK pS, int * pVal)
{
    if( empty(pS) )
    {
        return false;
    }
    else //ɾ������Ҫ��ָ�����ƶ��һ�Ҫ�ͷſռ�
    {
        PNODE r = pS->pTop;
        *pVal = r->date;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }
}

//���
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
