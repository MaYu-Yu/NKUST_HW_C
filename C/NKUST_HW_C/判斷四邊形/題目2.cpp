#include<stdio.h> 
#include<ctype.h> 
#include<stdlib.h> 
int main()
{
	int num;
	int answer;
	printf("輸入0離開\n");	
	while(1)
	{
		printf("請輸入奇數：");			
		if(scanf("%d",&num)==EOF||num==0)
		{
			system("pause");
			break;
		}	
		if(num<=2||num%2==0) //1或2或偶數為輸入錯誤 
		{
			printf("輸入錯誤，請再輸入一次\n");
			return main(); //重新輸入&判斷 
		}					
		
		answer=(num*(num+1)/2+(num+1)/2-3)*3;
		printf("\n輸出為：%d\n",answer);	
	
	}
}
