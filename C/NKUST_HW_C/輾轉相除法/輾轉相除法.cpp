#include<stdio.h>
#include<stdlib.h>
int judgment(int m,int n);

int main()
{
	int x=0,y=0,answer;
	
	while(x==0)
	{
		printf("�п�J�Ĥ@�ӼƦr�G");
		scanf("%d",&x);
		if(x<=0) //�p�G��J�D����ƪ��ȴN���s��J 
		{
			x=0;
			printf("��J���~�A�ЦA��J�@��\n");
		}
	}
	while(y==0)
	{
		printf("�п�J�ĤG�ӼƦr�G");
		scanf("%d",&y);	
		if(y<=0) //�p�G��J�D����ƪ��ȴN���s��J 
		{
			y=0;
			printf("��J���~�A�ЦA��J�@��\n");
		}		
	}
	answer=judgment(x,y);
	printf("�̤j���]�ƬO%d\n",answer);
	system("PAUSE"); 
}

int judgment(int n,int m)
{
    if(m==0)
        return n;
    else
       return judgment(m,n%m);
}

