# include <stdio.h>

typedef int ZHANGSAN; //为int再多取一个名字，ZHANGSAN等价于int

typedef struct Student
{
    int sid;
    char name[100];
    char sex;
}* PST, ST; //PST等价于Student *, STd代表了student
 

int main(void)
{
    //int i = 0; //等价于 ZHANGSAN i = 10;
    //ZHANGSAN i = 20;
    //printf("%d\n", j);

    Student st; //等价于 ST st；
    PST ps = &st; //等价于ST * ps；
    ps->sid = 99;
    printf("%d", ps->sid);

    return 0;
}
