# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int date; //������
	struct Node * pNext; //ָ���� 
}NODE, *PNODE; //NODE�ȼ���struct node   PNODE�ȼ���struct Node *

//��������
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);


int main(void)
{
	PNODE pHead = NULL; //�ȼ���struct Node * pHead = NULL;
	int val;

	pHead = create_list(); //����һ����ѭ������������������׵�ַ����pHead

	if( is_empty(pHead) )
	{
		printf("����Ϊ��!\n");
	}
	else
	{
		printf("������!\n");
	}

	traverse_list(pHead);

	insert_list(pHead, 3, 33);
	if( delete_list(pHead, 4, &val) )
	{
		printf("ɾ���ɹ�����ɾ����Ԫ���ǣ�%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ���ɾ����Ԫ�ز����ڣ�\n");
	}
	
	traverse_list(pHead);
	int len = length_list(pHead);
	printf("����ĳ�����%d\n", len);

	sort_list(pHead);
	traverse_list(pHead);

	return 0;	
} 

PNODE create_list(void)
{
	int len; //���������Ч�ڵ�ĸ���
	int i;
	int val; //������ʱ����û�����Ľ���ֵ

	//������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); //��̬����һ���ռ䣬��СΪNODE���൱�ڶ�̬������NODE
	                                           //���Զ�����һ��ָ��ָ������ռ�
	if(NULL == pHead)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("����������Ҫ���ɵ�������ĸ�����len = ");
	scanf("%d", &len);

	for(i=0; i<len; ++i)
	{
		printf("�������%d������ֵ��", i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("����ʧ�ܣ�������ֹ��\n");
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

//��pHead��ָ��ĵ�pos���ڵ��ǰ�����һ����㣬�ýڵ��ֵ��val
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
		printf("��̬�ڴ����ʧ�ܣ�\n");
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

	//ɾ��p�ڵ��Ľ��
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}
