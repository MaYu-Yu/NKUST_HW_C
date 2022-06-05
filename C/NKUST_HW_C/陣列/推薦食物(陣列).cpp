#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	char menu[10][20]={{"六扇門火鍋"},{"麥當勞"},{"肯德基"},{"丹丹漢堡"},{"LaCaSa"},{"灰熊咖哩"},{"牛魔王牛排"},{"無疆滷味"},{"水餃+鍋貼"},{"阿華蔥抓餅"}};
	char name[1][100];
	int num[3];
	int a=1;

	
	printf("請輸入您的名稱：");
	scanf("%s",&name[0]);  //輸入名稱 
	printf("\n你好啊！！！ %s\n",name[0]); //顯示名稱 
	printf("\n今天推薦吃");		
	
	srand(time(NULL));	
	
	num[0]=(rand()%10);
	while(a<=2) //產生不重複的亂數 
	{
		int find=0;

		num[a]=(rand()%10); //產生1~10的亂數 
		for(int i=1; i<=2; ++i)
		{

    		if(num[i]== num[i-1]) //有發現重複的 
			{ 
            	find=1;
                break;
            }
		}

     	if(find==0) //沒發現重複的 
		{     
           	++a;       
      	}		
	}
	
	for(int i=0; i<=2; ++i) //顯示推薦吃的 
	{	
		printf("%s ",menu[num[i]]);
	}
	printf("\n");
	system("PAUSE");
}
	

