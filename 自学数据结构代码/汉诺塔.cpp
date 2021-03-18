/*
	如果是一个盘子
		直接将A柱子上的盘子从C移到B
	否则
		先将A柱子上的n-1个盘子借助C移到B
		直接将A柱子上的盘子从A移到C
		最后将B柱子上的n-1个盘子借助A移到C 
*/ 
# include <iostream>
using std::cout;
using std::cin;
using std::endl;

int hannuota(int n, char A, char B, char C)
{
    static int times = 0;
    if(1 == n)
    {
        cout<<"将从上往下第"<<n<<"个盘子由"<<A<<"柱子搬向"<<C<<"柱子"<<endl;
        times++;
    }
    else
    {
        hannuota(n-1, A, C, B);
        cout<<"将从上往下第"<<n<<"个盘子由"<<A<<"柱子搬向"<<C<<"柱子"<<endl;
        times++;
        hannuota(n-1, B, A, C);
    }

    return times;
}

int main(void)
{
    char a = 'A';
    char b = 'B';
    char c = 'C';
    int n;
    int times;
    cout<<"请输入汉诺塔的盘子数量"<<endl;
    cin>>n;
    times = hannuota(n, a, b, c);
    cout<<"共移动"<<times<<"次"<<endl;

    return 0;
}
