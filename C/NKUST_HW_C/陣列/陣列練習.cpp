#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int target[5];
	int yours[5];
	int counter=0;
	int n=0;
	int a=0;
	int num=0;
	
	srand(time(NULL));		
	while(a<=4) //產生不重複的亂數 
	{
		int find=0;
	
		num=(rand()%25)+1; //產生1~25的亂數 	
			
		for(int i=0; i<=4; ++i)
		{

    		if(target[i]== num) //有發現重複的 
			{ 
            	find=1;
                break;
            }
		}
     	if(find==0) //沒發現重複的 
		{     
         	target[a]=num; 
           	++a;       
      	}		
	}
	
	while(counter<=4) //輸入你要的樂透號碼 
	{
		printf("請輸入你的樂透號碼(1~25)：");
		scanf("%d",&yours[counter]);
	
		int a=0;
		if(yours[counter]<=0 || yours[counter]>25)  //確認號碼是否超出範圍
		{
			printf("輸入的號碼超出範圍,請再輸入一次\n");
	        a=1; //fault
		}	
		for(int i=0; i<counter; i++)//確認號碼否有重複 
		{		
			if(yours[counter]==yours[i])
			{
				printf("輸入重複的號碼,請再輸入一次\n");
     	        a=1; //fault
			}
		}	
    	if(a==0)
    	{
     		counter++;    
     	}
	}
	
	
	printf("\n您輸入的號碼是："); //顯示所有的號碼 
	for(int i=0; i<=4; ++i)
	{
		printf("%d ",yours[i]);
	}	
	
	for(int i=0; i<=4; ++i) //確認有幾個數字是與中獎號碼相等的 
	{
		if(target[i]==yours[i])
		{
			++n;
		}
	}
	
	printf("\n樂透中獎號碼是：");
	for(int i=0; i<=4; ++i)
	{
		printf("%d ",target[i]); //顯示樂透中獎號碼 
	}
	printf("\n恭喜您中了%d個號碼\n",n);
	switch(n) //確認是得到哪個獎 
	{
		case 5: 
			printf("獲得了一獎~\n)");
			break;
		case 4:	
			printf("獲得了二獎~\n");
			break;
		case 3:	
			printf("獲得了安慰獎~\n");
			break;
		case 2:
		case 1:
		case 0:	
			printf("再接再厲~\n");
			break;
	}
	system("PAUSE");
}
