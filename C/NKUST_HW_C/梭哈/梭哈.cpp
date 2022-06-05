#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include <string.h>

void random(char card[][10],int *card_remaining,char draw_card[][10],int size);
void separade(int *drew_times,char drew_card[][10],int flower[],int number[]);
void bet_money_set(int *total_bet_money,int *money,int compete,int win,int *throw_card);
void game(char my_card[][10],char pc_card[][10],int total_bet_money,int money,int compete);
void sort(int flower[], int number[],int compete);
void compare(int my_flower[],int my_number[],int pc_flower[],int pc_number[],int compete,int my_kind,int pc_kind,int *win);
void judgment(int flower[],int number[],int *kind,int compete);

int main()
{
	char exit[10];
	int throw_card=0;
	int counter=0;	
	printf("輸入exit即可儲存並離開，輸入任意一個數就可以開始遊戲");  
	while(strcmp(gets(exit),"exit"))
	{
		system("cls");
		srand(time(NULL));	
		int money;
		int win=0;	
		int choice=0;
		int total_bet_money=0;
		int card_remaining=52;
		int my_kind=1;
		int pc_kind=1;
		char card[52][10] = 
		{
		"黑桃A","黑桃2","黑桃3","黑桃4","黑桃5","黑桃6","黑桃7","黑桃8","黑桃9","黑桃10","黑桃J","黑桃Q","黑桃K",
		"紅心A","紅心2","紅心3","紅心4","紅心5","紅心6","紅心7","紅心8","紅心9","紅心10","紅心J","紅心Q","紅心K",
		"方塊A","方塊2","方塊3","方塊4","方塊5","方塊6","方塊7","方塊8","方塊9","方塊10","方塊J","方塊Q","方塊K",
		"梅花A","梅花2","梅花3","梅花4","梅花5","梅花6","梅花7","梅花8","梅花9","梅花10","梅花J","梅花Q","梅花K"
		}; 	
		char my_card[5][10];
		char pc_card[5][10];
		int my_card_flower[5];
		int pc_card_flower[5];	
		int my_card_number[5];
		int pc_card_number[5];	
	
		for(int drew_times=0;drew_times<=4;drew_times++) //先把卡抽完&存入 
		{
			random(card,&card_remaining,my_card,drew_times); //我抽牌
			separade(&drew_times,my_card,my_card_flower,my_card_number); //把花色和數字分開&分配大小 		
		}
		for(int drew_times=0;drew_times<=4;drew_times++) //先把卡抽完&存入 
		{
			random(card,&card_remaining,pc_card,drew_times); //電腦抽牌
			separade(&drew_times,pc_card,pc_card_flower,pc_card_number); //把花色和數字分開&分配大小 		
		} 	

		FILE *fin;
		FILE *fout;
		fin=fopen("money.txt","r+");
		fscanf(fin,"%d",&money); //讀取現有金額 
		if(money<=0)
		{
			printf("您的皮包已經空了....\n");
			printf("回家吃土吧，還在這賭博\n"); 
			printf("但是我是好人，就施捨給你1000元吧\n"); 
			money+=1000;
			printf("你的金錢突然冒出了$1000\n");
			printf("你的金錢剩餘$%d\n",money);
		}
		
		printf("歡迎來到『梭哈』的世界\n");
		printf("開啟新遊戲請輸入1\n");
		if(counter==0&&money!=1000&&throw_card==0)
		{
			printf("繼續遊戲請輸入2\n");			
		}
		if(counter>0&&money==1000)
		{
			printf("繼續遊戲請輸入2\n");				
		}
		if(money!=1000&&throw_card==1)
		{
			printf("繼續遊戲請輸入2\n");			
		}
		
		while(choice>=3||choice<=0)
		{
			scanf("%d",&choice);
			if(money==1000)
			{
				if(choice==2)
				{
					printf("輸入錯誤，請再輸入一次\n");	
					choice=6;				
				}
			}			
			if((choice>=3||choice<=0)&&money!=1000)
			{
				printf("輸入錯誤，請再輸入一次\n");
			}
		}
		
		if(choice==1)
		{
			money=1000;
		}
		for(int compete=1;compete<=5;compete++)
		{
			throw_card=0;
			bet_money_set(&total_bet_money,&money,compete,win,&throw_card); //設置賭金 
			if(throw_card==1)
			{
				printf("棄牌了呢....\n");
				fout=fopen("money.txt","w+"); 
				fprintf(fout,"%d",money);//存檔 
				fclose(fout);		
				system("pause");		
				return main();
			}
			sort(my_card_flower,my_card_number,compete); //排列數字
			sort(pc_card_flower,pc_card_number,compete); //排列數字			  			
			judgment(my_card_flower,my_card_number,&my_kind,compete); //判斷牌種 
			judgment(pc_card_flower,pc_card_number,&pc_kind,compete); //判斷牌種  				
			compare(my_card_flower,my_card_number,pc_card_flower,pc_card_number,compete,my_kind,pc_kind,&win); //比較大小 
			game(my_card,pc_card,total_bet_money,money,compete);
		}

		if(win==1)
		{	
			printf("恭喜您贏得這場勝負了！！！\n");
			money+=total_bet_money*2;
			printf("您賺了；$%d\n",total_bet_money);
			printf("您的金錢剩餘；$%d\n",money);
		}
		else
		{
			printf("您輸給電腦...........\n");
			printf("您輸了；$%d\n",total_bet_money);
			printf("您的金錢剩餘；$%d\n",money);				
		}
		printf("輸入exit即可儲存並離開，輸入任意一個數就可以繼續玩遊戲"); 	
		fout=fopen("money.txt","w+"); 
		fprintf(fout,"%d",money);//存檔 
		fclose(fout);	
		system("pause");
		system("cls");	
		counter++;
	}
}

void random(char card[][10],int *card_remaining,char draw_card[][10],int size) //抽牌 
{
	int num;
	num=(rand()%*card_remaining); //產生的亂數
	*card_remaining-=1; 
	
	strcpy(draw_card[size],card[num]); //抽出的牌 
	
	for(int i=num;i<=*card_remaining;++i) //把抽走的牌移出，再把後面的牌移到前面的陣列 
	{
		strcpy(card[i],card[i+1]);
	}
} 

void separade(int *drew_times,char drew_card[][10],int flower[],int number[]) //把花色和數字分開
{			
	char number_1[10];
	char flower_1[10];	

 	strncpy(flower_1,drew_card[*drew_times],4); //拿出花色&分配大小 
	if(strcmp("黑桃",flower_1)==0)
	{
 		flower[*drew_times]=4;
	}
	if(strcmp("紅心",flower_1)==0)
	{
 		flower[*drew_times]=3;
	}	
	if(strcmp("方塊",flower_1)==0)
	{
 		flower[*drew_times]=2;
	}	
	if(strcmp("梅花",flower_1)==0)
	{
 		flower[*drew_times]=1;
	}
	
 	memcpy(number_1,&drew_card[*drew_times][4],3); //拿出數字 
 	if(strcmp("A",number_1)==0) //如果是英文轉換成數字來比對
 	{
 		number[*drew_times]=14; //A最大 
	}
	else if(strcmp("J",number_1)==0)
	{
 		number[*drew_times]=11;
	}
	else if(strcmp("Q",number_1)==0)
	{
 		number[*drew_times]=12;
	}
	else if(strcmp("K",number_1)==0)
	{
 		number[*drew_times]=13;
	}		
	else
	{
		number[*drew_times]=atoi(number_1); //char的數字轉int 
	}
}

void bet_money_set(int *total_bet_money,int *money,int compete,int win,int *throw_card) //設置賭金 
{
	system("cls"); //清除文字 
	int bet_money=0;
	int choice=0;	
	if(compete==1)
	{
		printf("您的金錢剩餘；$%d\n",*money);	
		printf("請輸入基本的注額：");			
		int a=0;
		while(a==0) 
		{
			scanf("%d",&bet_money);
			if(bet_money<=0||bet_money>=*money)
			{
				printf("輸入錯誤，請再輸入一次\n");
			}
			else
			{
				a=1;
			}
		}		
	}
	else if(win==1)
	{
		printf("目前您的牌比較大，由你來下注\n");
		while(choice>=4||choice<=1) 
		{
			printf("您的金錢剩餘；$%d\n",*money);
			if(compete==5)
			{
				printf("梭哈請輸入1，");	
			}
			printf("下注請輸入2，棄牌請輸入3 :");			
			scanf("%d",&choice);
			if(choice==1&&compete==5)
			{
				bet_money+=*money;
				break;			
			}
			else if(choice==2)
			{
				printf("請輸入下注金額：");	
				int a=0;
				while(a==0) 
				{
					scanf("%d",&bet_money);
					if(bet_money<=0||bet_money>=*money)
					{
						printf("輸入錯誤，請再輸入一次\n");
					}
					else
					{
						a=1;
					}
				}
			}
			else if(choice==3)
			{
				*throw_card=1; //棄牌重來
			}
			else
			{
				printf("輸入錯誤，請再輸入一次\n");
			}
		}
	}
	else 
	{			
		while(choice>=4||choice<=0) 
		{
		printf("目前電腦牌比較大，電腦下注$100\n");
		printf("您的金錢剩餘；$%d\n",*money);		
		printf("跟注請輸入1，棄牌請輸入2，加注請輸入3:");			
		scanf("%d",&choice);
			if(choice==1)
			{
				bet_money+=100;
			}
			else if(choice==2) 
			{
				*throw_card=1; //棄牌重來
			}
			else if(choice==3)
			{
				printf("請輸入跟加注金額(100+您輸入的金額)：");	
				int a=0;
				while(a==0) 
				{
					scanf("%d",&bet_money);
					if(bet_money<=0||bet_money+100>=*money)
					{
						printf("輸入錯誤，請再輸入一次\n");
					}
					else
					{
						bet_money+=100; 
						a=1;
					}
				}				
			}
			else
			{
				printf("輸入錯誤，請再輸入一次\n");				
			}
		}	
	}
	*total_bet_money+=bet_money; 
	*money-=bet_money;	
}

void game(char my_card[][10],char pc_card[][10],int total_bet_money,int money,int compete)  //顯示牌組 
{
	system("cls"); //清除文字
	printf("您的金錢剩餘；$%d\n",money);
	printf("目前您的賭金為$%d\n",total_bet_money);
	printf("目前電腦的賭金為$%d\n",total_bet_money);	
	printf("我的卡："); 	
	if(compete!=5)
	{
		printf("%s(暗牌) ",my_card[0]);	
		
		for(int i=1;i<=compete;i++)		
		{
			printf("%s ",my_card[i]);		
		}
		printf("\n");
		printf("電腦的卡：");
		printf("暗牌 ");		
		for(int i=1;i<=compete;i++)	
		{
			printf("%s ",pc_card[i]);		
		}
	}
	else
	{
		for(int i=0;i<=4;i++)		
		{
			printf("%s ",my_card[i]);		
		}
		printf("\n");
		printf("電腦的卡：");		
		for(int i=0;i<=4;i++)	
		{
			printf("%s ",pc_card[i]);		
		}		
	}
	printf("\n");	
	system("pause");
}
void sort(int flower[], int number[],int compete) //排列數字 
{
	int empty;
	if(compete!=5)
	{
		for(int i=1;i<=compete;i++) 
		{
			for(int j=i+1;j<=compete;j++)
			{
				if(number[i]<number[j])
				{
					empty=number[i];
					number[i]=number[j];
					number[j]=empty;
					empty=flower[i];
					flower[i]=flower[j];
					flower[j]=empty;							
				}
			}
		} 		
	}
	else
	{
		for(int i=0;i<=4;i++) 
		{
			for(int j=i+1;j<=4;j++)
			{
				if(number[i]<number[j])
				{
					empty=number[i];
					number[i]=number[j];
					number[j]=empty;
					empty=flower[i];
					flower[i]=flower[j];
					flower[j]=empty;							
				}
			}
		} 			
	}
}

void compare(int my_flower[],int my_number[],int pc_flower[],int pc_number[],int compete,int my_kind,int pc_kind,int *win)
{		
	*win=0; 
	if(my_kind==pc_kind) //總類相同進入比較 
	{
		if(my_kind==9||my_kind==6||my_kind==5) //同花順&同花&順子 
		{	
			if(my_number[0]>pc_number[0])
			{
				*win=1;
			}
			else if(my_number[0]==pc_number[0])
			{
				if(my_flower[0]>pc_flower[0])
				{
					*win=1;
				}			
			}
		}	
		else if(my_kind==8||my_kind==7||my_kind==3)//鐵支&葫蘆&三條 比數字大小就好
		{
			if(my_number[2]>pc_number[2])	
			{
				*win=1;
			}						
		}
		else if(my_kind==4) //兩對 先比大對 在比小對 都一樣就比單張	花色比最大對的 
		{
			if(compete==5)
			{ 
				if(my_number[1]>pc_number[1])
				{
					*win=1;
				}
				else if(my_number[3]>pc_number[3])
				{
					*win=1;
				}
				else if(my_number[1]==pc_number[1] && my_number[3]==pc_number[3])
				{
					if(my_number[0]==pc_number[1] && my_number[3]==pc_number[4])
					{
						if(my_number[2]>pc_number[2])
						{
							*win=1;						
						}
						else if(my_number[2]==pc_number[2])
						{
							if(my_flower[0]>pc_flower[0] || my_flower[0]>pc_flower[1])	
							{
								*win=1;
							}
							else if(my_flower[1]>pc_flower[0] || my_flower[1]>pc_flower[1])
							{
									*win=1;								
							}								
						}
					}
					else if((my_number[0]==my_number[1] && my_number[3]==my_number[4]) && my_number[1]==my_number[2])
					{
						if(my_number[2]>pc_number[0])
						{
							*win=1;						
						}
						else if(my_number[2]==pc_number[0])
						{
							if(my_flower[0]>pc_flower[1] || my_flower[0]>pc_flower[2])	
							{
								*win=1;
							}
							else if(my_flower[1]>pc_flower[1] || my_flower[1]>pc_flower[2])
							{
									*win=1;								
							}								
						}
					}
					else if((my_number[0]==my_number[1] && my_number[3]==my_number[4]) && my_number[0]==my_number[1])
					{
						if(my_number[2]>pc_number[4])
						{
							*win=1;						
						}
						else if(my_number[2]==pc_number[4])
						{
							if(my_flower[0]>pc_flower[0] || my_flower[0]>pc_flower[1])	
							{
								*win=1;
							}
							else if(my_flower[1]>pc_flower[0] || my_flower[1]>pc_flower[1])
							{
									*win=1;								
							}								
						}
					}
						
					else if(my_number[1]==my_number[2] && my_number[1]==my_number[2])
					{					
						if(my_number[0]>pc_number[0])
						{
							*win=1;						
						}
						else if(my_number[2]==pc_number[2])
						{
							if(my_flower[1]>pc_flower[1] || my_flower[1]>pc_flower[2])	
							{
								*win=1;
							}
							else if(my_flower[2]>pc_flower[1] || my_flower[2]>pc_flower[2])
							{
									*win=1;								
							}								
						}
					}
					else if(my_number[1]==my_number[2] && my_number[0]==my_number[1])
					{
						if(my_number[0]>pc_number[4])
						{
							*win=1;						
						}
						else if(my_number[0]==pc_number[4])
						{
							if(my_flower[1]>pc_flower[0] || my_flower[1]>pc_flower[1])	
							{
								*win=1;
							}
							else if(my_flower[2]>pc_flower[0] || my_flower[2]>pc_flower[1])
							{
									*win=1;								
							}								
						}
					}
					else if(my_number[1]==my_number[2] && (my_number[0]==my_number[1] && my_number[3]==my_number[4]))
					{
						if(my_number[0]>pc_number[2])
						{
							*win=1;						
						}
						else if(my_number[0]==pc_number[2])
						{
							if(my_flower[1]>pc_flower[0] || my_flower[1]>pc_flower[1])	
							{
								*win=1;
							}
							else if(my_flower[2]>pc_flower[0] || my_flower[2]>pc_flower[1])
							{
									*win=1;								
							}								
						}
					}	
					else if(my_number[0]==my_number[1] && my_number[0]==my_number[1])
					{
						if(my_number[4]>pc_number[4])
						{
							*win=1;						
						}
						else if(my_number[4]==pc_number[4])
						{
							if(my_flower[0]>pc_flower[0] || my_flower[0]>pc_flower[1])	
							{
								*win=1;
							}
							else if(my_flower[1]>pc_flower[0] || my_flower[1]>pc_flower[1])
							{
									*win=1;								
							}								
						}
					}
					else if(my_number[0]==my_number[1] && my_number[1]==my_number[2])
					{
						if(my_number[4]>pc_number[0])
						{
							*win=1;						
						}
						else if(my_number[4]==pc_number[0])
						{
							if(my_flower[0]>pc_flower[1] || my_flower[0]>pc_flower[2])	
							{
								*win=1;
							}
							else if(my_flower[1]>pc_flower[1] || my_flower[1]>pc_flower[2])
							{
									*win=1;								
							}								
						}
					}
					else if(my_number[0]==my_number[1] && (my_number[0]==my_number[1] && my_number[3]==my_number[4]))
					{
						if(my_number[4]>pc_number[2])
						{
							*win=1;						
						}
						else if(my_number[4]==pc_number[2])
						{
							if(my_flower[0]>pc_flower[0] || my_flower[0]>pc_flower[1])	
							{
								*win=1;
							}
							else if(my_flower[1]>pc_flower[0] || my_flower[1]>pc_flower[1])
							{
									*win=1;								
							}								
						}
					}		
				}										
			}
			else
			{
				if(my_number[1]>pc_number[1])
				{
					*win=1;
				}
				else if(my_number[3]>pc_number[3])
				{
					*win=1;
				}
				else if(my_number[1]==pc_number[1])
				{
					if(my_flower[1]>pc_flower[1] && my_flower[1]>pc_flower[2])	
					{
						*win=1;
					}													
				}
			}
		}		
		else if(my_kind==2) //一對 
		{
			int m,p;
			if(compete==5)
			{
				for(int i=0;i<=3;i++)
				{
					if(my_number[i]==my_number[i+1])
					{
						m=i;					
					}
					if(pc_number[i]==pc_number[i+1])
					{
						p=i;				
					}
				}				
			}
			else
			{
				for(int i=1;i<=compete;i++)
				{
					for(int j=i+1;i<=compete;i++)
					{
						if(my_number[i]==my_number[j])
						{
							m=i;					
						}
						if(pc_number[i]==pc_number[j])
						{
							p=i;				
						}						
					}
				}				
			}
			
			if(my_number[m]>pc_number[p])
			{
				*win=1;
			}
			else if(my_number[m]==pc_number[p])	
			{
				if(my_flower[m]>pc_flower[p] && my_flower[m]>pc_flower[p+1])
				{
					*win=1;				
				}	
				if(my_flower[m+1]>pc_flower[p] && my_flower[m+1]>pc_flower[p+1])
				{
					*win=1;				
				}
			}	
		}
		else if(my_kind==1)	//散牌
		{
			if(compete==5)
			{
				if(my_number[0]==pc_number[0])	
				{
					if(my_flower[0]>pc_flower[0])	
					{
						*win=1;
					}
				}
				else if(my_number[0]>pc_number[0])	
				{
					*win=1;
				}
			}
			else
			{
				if(my_number[1]==pc_number[1])	
				{
					if(my_flower[1]>pc_flower[1])	
					{
						*win=1;
					}
				}
				else if(my_number[1]>pc_number[1])	
				{
					*win=1;
				}										
			}
		}								
	}
	else //總類不同 
	{
		if(my_kind>pc_kind)
		{
			*win=1;
		}
	}		
}

void judgment(int flower[],int number[],int *kind,int compete) //判斷牌種 
{
	//同花順9,鐵支8,葫蘆7,同花6,順子5,兩對4,三條3,一對2,散牌1 	
	if(compete==2) 
	{
		if(number[1]==number[2]) //比較有幾個數字一樣
		{
			*kind=2; //一對 
		}	
	}			
	if(compete==3)  
	{
		if(number[1]==number[3])
		{
			*kind=3; //三條
		}
		else if(number[1]==number[2] || number[2]==number[3])
		{
			*kind=2; //一對 
		}		
	}		
	if(compete==4)  
	{
		if(number[1]==number[2] && number[3]==number[4])
		{
			*kind=4; //兩對 
		}
		else if(number[1]==number[2] || number[2]==number[3] || number[3]==number[4])
		{
			*kind=2; //一對 
		}
		else if(number[1]==number[3] || number[2]==number[4])
		{
			*kind=3; //三條 
		}
	}	
	if(compete==5)  												
	{
		int n=0;//有幾個一樣的數字 
		int f=0;//是否同花
		int s=0;//是否為順子		
			for(int i=0;i<=3;i++)
			{
				if(number[i]-1==number[i+1]) //確認是否順子 
				{
					s+=1;					
				}
				if(flower[i]==flower[i+1]) //確認是否同花
				{
					f+=1;
				}	
				if(number[i]==number[i+1]) //比較有幾個數字一樣
				{
					n+=1;
				}			
			}
		
		if(f==4)
		{	
			*kind=6; //同花
		}
		if(s==4) 
		{		
			*kind=5; //順子 
		}		
		if(f==4 && s==4) //同花+順子 
		{
			*kind=9; //同花順 
		}	
		if(n==0)
		{
			*kind=1; //散牌 
			if(number[0]==14 && s==3) 
			{
				*kind=5; //12345的順子 
				if(f==4)
				{
					*kind=5; //12345的同花順 				
				}	
			}
		}	
		if(n==1)
		{
			*kind=2; //一對 
		}	
		if(n==2) 
		{
			if(number[2]==number[0]|number[4] || number[1]==number[2]&&number[2]==number[3]&&number[2]==number[3])
			 {
				*kind=3; //三條		 	
			 }
			 else
			 {
				*kind=4; //兩對		 	
			 }
		} 	
		if(n==3)
		{
			if(number[0]==number[3] || number[4]==number[1])
			{
				*kind=8; //鐵支		
			}
			else	
			{
				*kind=7; //葫蘆			
			}		
		} 		
	}	
}
