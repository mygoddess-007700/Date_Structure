# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int date; //数据域
	struct Node * pNext; //指针域 
}NODE, *PNODE; //NODE等价于struct node   PNODE等价于struct Node *

//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);


int main(void)
{
	PNODE pHead = NULL; //等价于struct Node * pHead = NULL;
	int val;

	pHead = create_list(); //创建一个非循环链表，并将该链表的首地址赋给pHead

	if( is_empty(pHead) )
	{
		printf("链表为空!\n");
	}
	else
	{
		printf("链表不空!\n");
	}

	traverse_list(pHead);

	insert_list(pHead, 3, 33);
	if( delete_list(pHead, 4, &val) )
	{
		printf("删除成功，您删除的元素是：%d\n", val);
	}
	else
	{
		printf("删除失败！您删除的元素不存在！\n");
	}
	
	traverse_list(pHead);
	int len = length_list(pHead);
	printf("链表的长度是%d\n", len);

	sort_list(pHead);
	traverse_list(pHead);

	return 0;	
} 

PNODE create_list(void)
{
	int len; //用来存放有效节点的个数
	int i;
	int val; //用来临时存放用户输入的结点的值

	//分配了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); //动态分配一个空间，大小为NODE，相当于动态分配了NODE
	                                           //再自动分配一个指针指向这个空间
	if(NULL == pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您需要生成的链表结点的个数：len = ");
	scanf("%d", &len);

	for(i=0; i<len; ++i)
	{
		printf("请输入第%d个结点的值：", i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->date = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while(NULL != p)
	{
		printf("%d ", p->date);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while(NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE pHead)
{
	int t;
	PNODE p, q;
	for(p=pHead->pNext; p!=NULL; p=p->pNext)
	{
		for(q=p->pNext; q!=NULL; q=q->pNext)
		{
			if(p->date > q->date)
			{
				t = p->date;
				p->date = q->date;
				q->date = t;
			}
		}
	}
	return;
}

//在pHead所指向的第pos个节点的前面插入一个结点，该节点的值是val
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if(i>pos-1 || NULL==p)
	{
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	pNew->date = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if(i>pos-1 || NULL==p->pNext)
	{
		return false;
	}

	PNODE q = p->pNext;
	*pVal = q->date;

	//删除p节点后的结点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}
