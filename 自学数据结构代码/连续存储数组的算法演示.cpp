# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

struct Arr
{
    int * pBase; //�洢���������һ��Ԫ�صĵ�ַ
    int len; //�����������ɵ����Ԫ�صĸ���
    int cnt; //��ǰ������ЧԪ�صĸ���
//    int increment; //�Զ���������
};

typedef Arr * z;

void init_arr(z, int length);
bool append_arr(z, int val); //׷�ӣ������������룩
bool insert_arr(z, int pos, int val); //pos��ֵ��1��ʼ����Ϊǰ����
bool delete_arr(z, int pos, int * pVal); //pos��ֵ��1��ʼ
int get(z, int pos);
bool is_empty(z);
bool is_full(z);
void sort_arr(z);
void show_arr(z);
void inversion_arr(z);

int main(void)
{
    Arr arr;
    int val;
    
    init_arr(&arr, 6);
    show_arr(&arr);
    append_arr(&arr, 1);
    append_arr(&arr, 10);
    append_arr(&arr, -3);
    append_arr(&arr, 6);
    append_arr(&arr, 88);
    append_arr(&arr, 11);

    if ( delete_arr(&arr, 4, &val) )
    {
        printf("ɾ���ɹ���\n");
        printf("��ɾ����Ԫ���ǣ�%d\n", val);
    }
    else
    {
        printf("ɾ��ʧ�ܣ�\n");
    }
    show_arr(&arr);
    
    
    // append_arr(&arr, 2);
    // append_arr(&arr, 3);
    // append_arr(&arr, 4);
    // append_arr(&arr, 5);
    // insert_arr(&arr, 1, 99);
    // show_arr(&arr);
    // append(&arr, 6);
    // append(&arr, 7);

   inversion_arr(&arr);
   printf("���ú�������ǣ�\n");
   show_arr(&arr);
   sort_arr(&arr);
    printf("�����������ǣ�\n");
   show_arr(&arr); 

    return 0;
}

void init_arr(z pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if (NULL == pArr->pBase)
    {
        printf("��̬�����ڴ�ʧ�ܣ�\n");
        exit(-1); //��ֹ��������
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
    
}

bool is_empty(z pArr)
{
    if(0 == pArr->cnt)
    {
        return true;
    }
    else

    {
        return false;
    }
    
}

void show_arr(z pArr)
{
    if ( is_empty(pArr) )
    {
        printf("����Ϊ�գ�\n");
    }
    else
    {
        for(int i=0; i<pArr->cnt; ++i)
        {
            printf("%d ", pArr->pBase[i]);
        }
            printf("\n");
    }

    return;
}

bool is_full(z pArr)
{
    if (pArr->cnt == pArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool append_arr(z pArr, int val)
{
    //���Ƿ���false
    if ( is_full(pArr) )
    {
        return false;
    }
    //������׷��
    else
    {
        pArr->pBase[pArr->cnt] = val;
        ++(pArr->cnt);
        return true;
    }
    
}

bool insert_arr(z pArr, int pos, int val)
{
    int i;

    if( is_full(pArr) )
    {
        return false;
    }

    if(pos<1 || pos>pArr->cnt+1)
    {
        return false;
    }

    for(i=pArr->cnt-1; i>=pos-1; --i)
    {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    ++(pArr->cnt);

    return true;
}

bool delete_arr(z pArr, int pos, int * pVal)
{
    int i;

    if( is_empty(pArr) )
    {
        return false;
    }
    if(pos<1 || pos>pArr->cnt)
    {
        return false;
    }

    *pVal = pArr->pBase[pos-1];
    for(i=pos; i<pArr->cnt; ++i)
    {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    --pArr->cnt;
    return true;
}

void inversion_arr(z pArr)
{
    int i = 0;
    int j = pArr->cnt-1;
    int t;

    while(i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
    return;
}

int get(z pArr, int pos)
{
    if( is_empty(pArr) )
    {
        return false;
    }
    if(pos<1 || pos>pArr->cnt)
    {
        return false;
    }
    
    return pArr->pBase[pos-1];
}

void sort_arr(z pArr)
{
    int i, j, t;

    for(i=0; i<pArr->cnt-1; ++i)
    {
        for(j=i+1; j<pArr->cnt; ++j)
        {
            if(pArr->pBase[i]>pArr->pBase[j])
            {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }

    return;
}
