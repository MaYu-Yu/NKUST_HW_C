#include <stdio.h>
int main()
{
	int num,i,j;
	while(1) 
	{
		printf("�п�J�A���Ʀr(�Ϊ̿�J888���})�G");
		scanf("%d",&num);
		
		if(num==888)//�����{�� 
		{
			break;
		}
		else
		{
			for(int i=1;i<=num;i++)  
			{
				for(j=0;j<num-i;j++)//�ϤT���Υi�H��� 
				{	 
					printf(" ");
				} 
				for(j=i;j>0;j--)//�T���Υ���Ѥj�ܤp 
				{
					printf("%d",j);
				}
				for(j=2;j<=i;j++)//�T���Υk��Ѥp�ܤj 
				{
					printf("%d",j);
				}
			printf("\n"); //���r�i�H��U�@�� 
			}
		}
	}
	return 0;	
}
