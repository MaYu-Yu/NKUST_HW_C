#include<stdio.h>
#include <stdlib.h> 
int main(void) 
{ 
	int num, sum, dividend, divisor; 

	while(num<6)
{
	printf("块俱计―赣计ず┮ΤЧ计(程蔼8128): "); 
	scanf("%d", &num); 
	if(num<1)//絋粄计琌Τ 
	{	
		printf("计ぃ0┪璽计\n");
	}	
	if(num<6&&num>0)//6琌程Ч计
	{
		printf("俱计ぇい⊿ΤЧ计\n");
	} 
}

	for(dividend=1; dividend<=num; dividend++)//琵计1~num常浪代 
{ 
	sum=0; 
	for(divisor=1; divisor<dividend; divisor++)//琵埃计1~num 
{ 
	if(dividend%divisor==0) //緇计0碞琌计 
	{
		sum+=divisor; 
	}
} 
	if(sum == dividend) //絋粄琌ぃ琌Ч计 
	{
	int factor;
		printf(" %d=", dividend); 
		
		for(factor=1; factor<dividend; factor++)//琵埃计1~Ч计 
	{
		if(dividend%factor==0)//―计 
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
