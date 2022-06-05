#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int money,total,eat_o=0,eat_b=0;
	printf("請輸入小花可使用的金額：");
	scanf("%d",&money);
	
	while(money>=30)//吃橘盤、橘盤、黑盤的迴圈 
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
	total=eat_o+eat_b;//共吃幾盤 
	for(int min=0;min<=total-1;min++)//時間迴圈 
	{
			if(min%3!=2)
			{
			printf("第%d分鐘 橘盤\n",min*5);		
			}
			else
			{ 
			printf("第%d分鐘 黑盤\n",min*5);	
			} 
	}
	printf("共吃了：橘盤%d個 黑盤：%d個 合計：%d盤 剩餘金額：%d\n", eat_o, eat_b, total, money);
}
