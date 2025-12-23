#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
	char password[50];
	int new_password[50];
	int letter=0;
	
	while(letter==0) //判斷是否為字母，如果都是字母回傳1 
	{
		printf("請輸入你的帳號："); 
		scanf("%s",password);	
		letter=1;	
		for(int i=0;i<strlen(password)-1;++i)
		{
			letter*=isalpha(password[i]);
		}
		if(letter==0)
		{
			printf("輸入錯誤，請再輸入一次\n");
		}
		if(strlen(password)<=1)
		{
			letter=0;
			printf("輸入錯誤，請再輸入一次\n");
		}
	}
		
	for(int i=0;i<strlen(password)-1;++i) //把CHAR轉成INT 
	{
		password[i]=tolower(password[i]);
		password[i]=(int)password[i];	
	}
	
	printf("您的密碼是：");
	
	for(int i=0;i<strlen(password)-1;++i)
	{
		new_password[i]=password[i]-password[i+1];
		new_password[i]=abs(new_password[i]);
		if(i<strlen(password))
		{
			printf("%d",new_password[i]);				
		}
	}
	system("PAUSE");
}

