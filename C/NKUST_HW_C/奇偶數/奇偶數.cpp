#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main ()
{
	int word, word1, i=1, count=0;
	printf("块俱计");
	scanf("%d",&word);
	
	word1=word;//т俱计Τ碭 
 	while(word1>=10)
	{
 	 count++;
 	 word1/=10;
	}
	int a = pow(10,count);
	
	for(a; a>0; a/=10)//パ玡耞案计 
	{	
		if((word/a)%2==0) 
		{ 
			printf("案计 ");
		} 
		else
		{
			printf("计 "); 
		}
	}
	printf("\n");
	system("pause");
	return 0;	
 }
 
 


	



