#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 

void hanoi(int disk,char A,char B,char C) 
{ 
	if(disk == 1) //最後一次，做完直接跳出遞回
		printf("碟子 %d 從 %c 移到 %c \n",disk,A,C);  
	else //觀察規律後發現公式套入就對解出來了 
	{	 
		hanoi(disk-1, A, C, B); 
		printf("碟子 %d 從 %c 移到 %c\n",disk,A,C); 
		hanoi(disk-1, B, A, C);
	} 
}

int main() 

{ 
	int disk; 
	int times=1; 
	char A='A',B='B',C='C'; 

	printf("請輸入有幾個碟子："); 
	scanf("%d",&disk); 
	
	hanoi(disk,A,B,C); 
	
	times=pow(2,disk)-1;
	printf("最少移動：%d次\n",times-1); 
	system("pause"); 
	
	return 0; 
} 
