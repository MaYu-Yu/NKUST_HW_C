#include<stdio.h>

int judgment(int m,int n);

int main()
{
	int x,y,answer;
	printf("�п�J�Ĥ@�ӼƦr�G");
	scanf("%d",&x);
	printf("�п�J�ĤG�ӼƦr�G");
	scanf("%d",&y);
	answer=judgment(x,y);
	printf("�̤j���]�ƬO%d",answer);
}

int judgment(int n,int m)
{
    if(m==0)
        return n;
    else
       return judgment(m,n%m);
}

