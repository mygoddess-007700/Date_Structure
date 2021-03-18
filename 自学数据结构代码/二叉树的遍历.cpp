# include <stdio.h>
# include <malloc.h>

struct BTNode
{
    char date;
    struct BTNode * pLchild;
    struct BTNode * pRchild;
};

struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int main(void)
{
    struct BTNode * pT = CreateBTree();

    PreTraverseBTree(pT);//先序遍历
    printf("\n");

    InTraverseBTree(pT);//中序遍历
    printf("\n");

    PostTraverseBTree(pT);//后序遍历
    printf("\n");

    return 0;
}

struct BTNode * CreateBTree(void)
{
    struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));

    pA->date = 'A';
    pB->date = 'B';
    pC->date = 'C';
    pD->date = 'D';
    pE->date = 'E';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pE->pRchild = NULL;

    return pA;
}

void PreTraverseBTree(struct BTNode * pT)
{
    if(NULL != pT)
    {
        printf("%c\n", pT->date);

        if(NULL != pT->pLchild)
        {
            PreTraverseBTree(pT->pLchild);
            //pT->pLchild可以代表整个左子树（递归）
        }

        if(NULL != pT->pRchild)
        {
            PreTraverseBTree(pT->pRchild);
        }
    }

}

void InTraverseBTree(struct BTNode * pT)
{
    if(NULL != pT)
    {

        if(NULL != pT->pLchild)
        {
            InTraverseBTree(pT->pLchild);
            //pT->pLchild可以代表整个左子树（递归）
        }

        printf("%c\n", pT->date);

        if(NULL != pT->pRchild)
        {
            InTraverseBTree(pT->pRchild);
        }
    }

}

void PostTraverseBTree(struct BTNode * pT)
{
    if(NULL != pT)
    {

        if(NULL != pT->pLchild)
        {
            PostTraverseBTree(pT->pLchild);
            //pT->pLchild可以代表整个左子树（递归）
        }

        if(NULL != pT->pRchild)
        {
            PostTraverseBTree(pT->pRchild);
        }

        printf("%c\n", pT->date);
    }

}
