#include<stdio.h>

int judgment(int m,int n);

int main()
{
	int x,y,answer;
	printf("請輸入第一個數字：");
	scanf("%d",&x);
	printf("請輸入第二個數字：");
	scanf("%d",&y);
	answer=judgment(x,y);
	printf("最大公因數是%d",answer);
}

int judgment(int n,int m)
{
    if(m==0)
        return n;
    else
       return judgment(m,n%m);
}

