#include<stdio.h>
#include<stdlib.h>

void length_sort(int length[4]);

int main()
{
	int length[4],kind=0;

	printf("�п�J�|�Ӫ��u���סG");
	scanf("%d %d %d %d" ,&length[0],&length[1],&length[2],&length[3]);
	
	if(length[0]>0 && length[1]>0 && length[2]>0 && length[3]>0)
	{
		length_sort(length);
		if(length[3]>=(length[2]+length[1]+length[0]))
		{
			printf("�L�k�զ��|���\n");
			kind=0;	
		}
		if(length[3]<(length[2]+length[1]+length[0]))
		{	
			kind=1;
			if(length[0]==length[1]&&length[2]==length[3])
			{
				kind=2;
				if(length[0]==length[1] && length[1]==length[2] && length[2]==length[3] && length[3]==length[0])
				{
					printf("�����\n");
					kind=3;
				}
			}	
		}
		if(kind==1)printf("�|���\n");
		if(kind==2)printf("�����\n");
			
		system("pause");
	}	
}

void length_sort(int length[4])
{
	int empty;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(i!=j&&length[i]>length[j])
			{
				empty=length[i];
				length[i]=length[j];
				length[j]=empty;			
			}
		}			
	}
}
