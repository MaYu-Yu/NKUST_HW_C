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
	
	while(letter==0) //�P�_�O�_���r���A�p�G���O�r���^��1 
	{
		printf("�п�J�A���b���G"); 
		scanf("%s",password);	
		letter=1;	
		for(int i=0;i<strlen(password)-1;++i)
		{
			letter*=isalpha(password[i]);
		}
		if(letter==0)
		{
			printf("��J���~�A�ЦA��J�@��\n");
		}
		if(strlen(password)<=1)
		{
			letter=0;
			printf("��J���~�A�ЦA��J�@��\n");
		}
	}
		
	for(int i=0;i<strlen(password)-1;++i) //��CHAR�নINT 
	{
		password[i]=tolower(password[i]);
		password[i]=(int)password[i];	
	}
	
	printf("�z���K�X�O�G");
	
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

