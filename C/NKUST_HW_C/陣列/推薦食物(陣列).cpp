#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	char menu[10][20]={{"����������"},{"�����"},{"�ּw��"},{"�����~��"},{"LaCaSa"},{"�Ǻ��@��"},{"���]������"},{"�Læ����"},{"����+��K"},{"���ؽ����"}};
	char name[1][100];
	int num[3];
	int a=1;

	
	printf("�п�J�z���W�١G");
	scanf("%s",&name[0]);  //��J�W�� 
	printf("\n�A�n�ڡI�I�I %s\n",name[0]); //��ܦW�� 
	printf("\n���ѱ��˦Y");		
	
	srand(time(NULL));	
	
	num[0]=(rand()%10);
	while(a<=2) //���ͤ����ƪ��ü� 
	{
		int find=0;

		num[a]=(rand()%10); //����1~10���ü� 
		for(int i=1; i<=2; ++i)
		{

    		if(num[i]== num[i-1]) //���o�{���ƪ� 
			{ 
            	find=1;
                break;
            }
		}

     	if(find==0) //�S�o�{���ƪ� 
		{     
           	++a;       
      	}		
	}
	
	for(int i=0; i<=2; ++i) //��ܱ��˦Y�� 
	{	
		printf("%s ",menu[num[i]]);
	}
	printf("\n");
	system("PAUSE");
}
	

