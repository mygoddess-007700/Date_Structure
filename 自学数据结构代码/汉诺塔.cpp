/*
	�����һ������
		ֱ�ӽ�A�����ϵ����Ӵ�C�Ƶ�B
	����
		�Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
		ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
		���B�����ϵ�n-1�����ӽ���A�Ƶ�C 
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
        cout<<"���������µ�"<<n<<"��������"<<A<<"���Ӱ���"<<C<<"����"<<endl;
        times++;
    }
    else
    {
        hannuota(n-1, A, C, B);
        cout<<"���������µ�"<<n<<"��������"<<A<<"���Ӱ���"<<C<<"����"<<endl;
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
    cout<<"�����뺺ŵ������������"<<endl;
    cin>>n;
    times = hannuota(n, a, b, c);
    cout<<"���ƶ�"<<times<<"��"<<endl;

    return 0;
}
