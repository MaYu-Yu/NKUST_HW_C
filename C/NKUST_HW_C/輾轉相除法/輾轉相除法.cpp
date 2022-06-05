#include<stdio.h>
#include<stdlib.h>
int judgment(int m,int n);

int main()
{
	int x=0,y=0,answer;
	
	while(x==0)
	{
		printf("請輸入第一個數字：");
		scanf("%d",&x);
		if(x<=0) //如果輸入非正整數的值就重新輸入 
		{
			x=0;
			printf("輸入錯誤，請再輸入一次\n");
		}
	}
	while(y==0)
	{
		printf("請輸入第二個數字：");
		scanf("%d",&y);	
		if(y<=0) //如果輸入非正整數的值就重新輸入 
		{
			y=0;
			printf("輸入錯誤，請再輸入一次\n");
		}		
	}
	answer=judgment(x,y);
	printf("最大公因數是%d\n",answer);
	system("PAUSE"); 
}

int judgment(int n,int m)
{
    if(m==0)
        return n;
    else
       return judgment(m,n%m);
}

