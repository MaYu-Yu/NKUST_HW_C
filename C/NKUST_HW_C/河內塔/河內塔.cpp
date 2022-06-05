#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 

void hanoi(int disk,char A,char B,char C) 
{ 
	if(disk == 1) //�̫�@���A�����������X���^
		printf("�Фl %d �q %c ���� %c \n",disk,A,C);  
	else //�[��W�߫�o�{�����M�J�N��ѥX�ӤF 
	{	 
		hanoi(disk-1, A, C, B); 
		printf("�Фl %d �q %c ���� %c\n",disk,A,C); 
		hanoi(disk-1, B, A, C);
	} 
}

int main() 

{ 
	int disk; 
	int times=1; 
	char A='A',B='B',C='C'; 

	printf("�п�J���X�ӺФl�G"); 
	scanf("%d",&disk); 
	
	hanoi(disk,A,B,C); 
	
	times=pow(2,disk)-1;
	printf("�ֲ̤��ʡG%d��\n",times-1); 
	system("pause"); 
	
	return 0; 
} 
