#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int money,total,eat_o=0,eat_b=0;
	printf("�п�J�p��i�ϥΪ����B�G");
	scanf("%d",&money);
	
	while(money>=30)//�Y��L�B��L�B�½L���j�� 
{
	for(int i=1;i<=3;i++)
	{
		if(i==1&&money>=30)
		{
			money-=30;
			eat_o+=1;
			
		}
		if(i==2&&money>=30)
		{
			money-=30;
			eat_o+=1;
		}		
		if(i==3&&money>=40)
		{
			money-=40;
			eat_b+=1;
		}		
	}
}
	total=eat_o+eat_b;//�@�Y�X�L 
	for(int min=0;min<=total-1;min++)//�ɶ��j�� 
	{
			if(min%3!=2)
			{
			printf("��%d���� ��L\n",min*5);		
			}
			else
			{ 
			printf("��%d���� �½L\n",min*5);	
			} 
	}
	printf("�@�Y�F�G��L%d�� �½L�G%d�� �X�p�G%d�L �Ѿl���B�G%d\n", eat_o, eat_b, total, money);
}
