#include <stdio.h>
int main()
{
	int num,i,j;
	while(1) 
	{
		printf("請輸入你的數字(或者輸入888離開)：");
		scanf("%d",&num);
		
		if(num==888)//結束程式 
		{
			break;
		}
		else
		{
			for(int i=1;i<=num;i++)  
			{
				for(j=0;j<num-i;j++)//使三角形可以對稱 
				{	 
					printf(" ");
				} 
				for(j=i;j>0;j--)//三角形左邊由大至小 
				{
					printf("%d",j);
				}
				for(j=2;j<=i;j++)//三角形右邊由小至大 
				{
					printf("%d",j);
				}
			printf("\n"); //讓字可以到下一行 
			}
		}
	}
	return 0;	
}
