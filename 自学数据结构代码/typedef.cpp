# include <stdio.h>

typedef int ZHANGSAN; //Ϊint�ٶ�ȡһ�����֣�ZHANGSAN�ȼ���int

typedef struct Student
{
    int sid;
    char name[100];
    char sex;
}* PST, ST; //PST�ȼ���Student *, STd������student
 

int main(void)
{
    //int i = 0; //�ȼ��� ZHANGSAN i = 10;
    //ZHANGSAN i = 20;
    //printf("%d\n", j);

    Student st; //�ȼ��� ST st��
    PST ps = &st; //�ȼ���ST * ps��
    ps->sid = 99;
    printf("%d", ps->sid);

    return 0;
}
