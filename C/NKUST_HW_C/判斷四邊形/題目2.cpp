#include<stdio.h> 
#include<ctype.h> 
#include<stdlib.h> 
int main()
{
	int num;
	int answer;
	printf("��J0���}\n");	
	while(1)
	{
		printf("�п�J�_�ơG");			
		if(scanf("%d",&num)==EOF||num==0)
		{
			system("pause");
			break;
		}	
		if(num<=2||num%2==0) //1��2�ΰ��Ƭ���J���~ 
		{
			printf("��J���~�A�ЦA��J�@��\n");
			return main(); //���s��J&�P�_ 
		}					
		
		answer=(num*(num+1)/2+(num+1)/2-3)*3;
		printf("\n��X���G%d\n",answer);	
	
	}
}
