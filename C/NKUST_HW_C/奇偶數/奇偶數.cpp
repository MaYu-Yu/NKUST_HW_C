#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main ()
{
	int word, word1, i=1, count=0;
	printf("��J�@�Ӿ�ơG");
	scanf("%d",&word);
	
	word1=word;//��X��Ʀ��X�� 
 	while(word1>=10)
	{
 	 count++;
 	 word1/=10;
	}
	int a = pow(10,count);
	
	for(a; a>0; a/=10)//�ѫe���P�_�_���� 
	{	
		if((word/a)%2==0) 
		{ 
			printf("���� ");
		} 
		else
		{
			printf("�_�� "); 
		}
	}
	printf("\n");
	system("pause");
	return 0;	
 }
 
 


	



