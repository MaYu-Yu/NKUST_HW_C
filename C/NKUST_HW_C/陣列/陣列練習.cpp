#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int target[5];
	int yours[5];
	int counter=0;
	int n=0;
	int a=0;
	int num=0;
	
	srand(time(NULL));		
	while(a<=4) //���ͤ����ƪ��ü� 
	{
		int find=0;
	
		num=(rand()%25)+1; //����1~25���ü� 	
			
		for(int i=0; i<=4; ++i)
		{

    		if(target[i]== num) //���o�{���ƪ� 
			{ 
            	find=1;
                break;
            }
		}
     	if(find==0) //�S�o�{���ƪ� 
		{     
         	target[a]=num; 
           	++a;       
      	}		
	}
	
	while(counter<=4) //��J�A�n���ֳz���X 
	{
		printf("�п�J�A���ֳz���X(1~25)�G");
		scanf("%d",&yours[counter]);
	
		int a=0;
		if(yours[counter]<=0 || yours[counter]>25)  //�T�{���X�O�_�W�X�d��
		{
			printf("��J�����X�W�X�d��,�ЦA��J�@��\n");
	        a=1; //fault
		}	
		for(int i=0; i<counter; i++)//�T�{���X�_������ 
		{		
			if(yours[counter]==yours[i])
			{
				printf("��J���ƪ����X,�ЦA��J�@��\n");
     	        a=1; //fault
			}
		}	
    	if(a==0)
    	{
     		counter++;    
     	}
	}
	
	
	printf("\n�z��J�����X�O�G"); //��ܩҦ������X 
	for(int i=0; i<=4; ++i)
	{
		printf("%d ",yours[i]);
	}	
	
	for(int i=0; i<=4; ++i) //�T�{���X�ӼƦr�O�P�������X�۵��� 
	{
		if(target[i]==yours[i])
		{
			++n;
		}
	}
	
	printf("\n�ֳz�������X�O�G");
	for(int i=0; i<=4; ++i)
	{
		printf("%d ",target[i]); //��ֳܼz�������X 
	}
	printf("\n���߱z���F%d�Ӹ��X\n",n);
	switch(n) //�T�{�O�o����Ӽ� 
	{
		case 5: 
			printf("��o�F�@��~\n)");
			break;
		case 4:	
			printf("��o�F�G��~\n");
			break;
		case 3:	
			printf("��o�F�w����~\n");
			break;
		case 2:
		case 1:
		case 0:	
			printf("�A���A�F~\n");
			break;
	}
	system("PAUSE");
}
