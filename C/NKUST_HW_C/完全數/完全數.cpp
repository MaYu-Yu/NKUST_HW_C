#include<stdio.h>
#include <stdlib.h> 
int main(void) 
{ 
	int num, sum, dividend, divisor; 

	while(num<6)
{
	printf("��J�@��ơA�D�ӼƦr�H���Ҧ���������(�̰���8128): "); 
	scanf("%d", &num); 
	if(num<1)//�T�{�Ʀr�O�_���� 
	{	
		printf("�Ʀr���ର0�έt��\n");
	}	
	if(num<6&&num>0)//6�O�̤p��������
	{
		printf("����Ƥ����S��������\n");
	} 
}

	for(dividend=1; dividend<=num; dividend++)//���Ʀr1~num�����˴��� 
{ 
	sum=0; 
	for(divisor=1; divisor<dividend; divisor++)//�����Ƭ�1~num 
{ 
	if(dividend%divisor==0) //�l�Ƭ�0�N�O�]�� 
	{
		sum+=divisor; 
	}
} 
	if(sum == dividend) //�T�{�O���O������ 
	{
	int factor;
		printf(" %d=", dividend); 
		
		for(factor=1; factor<dividend; factor++)//�����Ƭ�1~������ 
	{
		if(dividend%factor==0)//�D�]�� 
		{
		if(factor!=(dividend/2))
		{
			printf("%d+",factor);
		}
			else
		{
			printf("%d\n",factor);
		} 
		}
	}
		
		
	}
} 

	system("pause"); 
	return 0 ; 
} 
