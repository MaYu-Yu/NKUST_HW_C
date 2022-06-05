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
	printf("��Jexit�Y�i�x�s�����}�A��J���N�@�ӼƴN�i�H�}�l�C��");  
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
		"�®�A","�®�2","�®�3","�®�4","�®�5","�®�6","�®�7","�®�8","�®�9","�®�10","�®�J","�®�Q","�®�K",
		"����A","����2","����3","����4","����5","����6","����7","����8","����9","����10","����J","����Q","����K",
		"���A","���2","���3","���4","���5","���6","���7","���8","���9","���10","���J","���Q","���K",
		"����A","����2","����3","����4","����5","����6","����7","����8","����9","����10","����J","����Q","����K"
		}; 	
		char my_card[5][10];
		char pc_card[5][10];
		int my_card_flower[5];
		int pc_card_flower[5];	
		int my_card_number[5];
		int pc_card_number[5];	
	
		for(int drew_times=0;drew_times<=4;drew_times++) //����d�⧹&�s�J 
		{
			random(card,&card_remaining,my_card,drew_times); //�ک�P
			separade(&drew_times,my_card,my_card_flower,my_card_number); //����M�Ʀr���}&���t�j�p 		
		}
		for(int drew_times=0;drew_times<=4;drew_times++) //����d�⧹&�s�J 
		{
			random(card,&card_remaining,pc_card,drew_times); //�q����P
			separade(&drew_times,pc_card,pc_card_flower,pc_card_number); //����M�Ʀr���}&���t�j�p 		
		} 	

		FILE *fin;
		FILE *fout;
		fin=fopen("money.txt","r+");
		fscanf(fin,"%d",&money); //Ū���{�����B 
		if(money<=0)
		{
			printf("�z���֥]�w�g�ŤF....\n");
			printf("�^�a�Y�g�a�A�٦b�o���\n"); 
			printf("���O�ڬO�n�H�A�N�I�˵��A1000���a\n"); 
			money+=1000;
			printf("�A��������M�_�X�F$1000\n");
			printf("�A�������Ѿl$%d\n",money);
		}
		
		printf("�w��Ө�y�����z���@��\n");
		printf("�}�ҷs�C���п�J1\n");
		if(counter==0&&money!=1000&&throw_card==0)
		{
			printf("�~��C���п�J2\n");			
		}
		if(counter>0&&money==1000)
		{
			printf("�~��C���п�J2\n");				
		}
		if(money!=1000&&throw_card==1)
		{
			printf("�~��C���п�J2\n");			
		}
		
		while(choice>=3||choice<=0)
		{
			scanf("%d",&choice);
			if(money==1000)
			{
				if(choice==2)
				{
					printf("��J���~�A�ЦA��J�@��\n");	
					choice=6;				
				}
			}			
			if((choice>=3||choice<=0)&&money!=1000)
			{
				printf("��J���~�A�ЦA��J�@��\n");
			}
		}
		
		if(choice==1)
		{
			money=1000;
		}
		for(int compete=1;compete<=5;compete++)
		{
			throw_card=0;
			bet_money_set(&total_bet_money,&money,compete,win,&throw_card); //�]�m��� 
			if(throw_card==1)
			{
				printf("��P�F�O....\n");
				fout=fopen("money.txt","w+"); 
				fprintf(fout,"%d",money);//�s�� 
				fclose(fout);		
				system("pause");		
				return main();
			}
			sort(my_card_flower,my_card_number,compete); //�ƦC�Ʀr
			sort(pc_card_flower,pc_card_number,compete); //�ƦC�Ʀr			  			
			judgment(my_card_flower,my_card_number,&my_kind,compete); //�P�_�P�� 
			judgment(pc_card_flower,pc_card_number,&pc_kind,compete); //�P�_�P��  				
			compare(my_card_flower,my_card_number,pc_card_flower,pc_card_number,compete,my_kind,pc_kind,&win); //����j�p 
			game(my_card,pc_card,total_bet_money,money,compete);
		}

		if(win==1)
		{	
			printf("���߱zĹ�o�o���ӭt�F�I�I�I\n");
			money+=total_bet_money*2;
			printf("�z�ȤF�F$%d\n",total_bet_money);
			printf("�z�������Ѿl�F$%d\n",money);
		}
		else
		{
			printf("�z�鵹�q��...........\n");
			printf("�z��F�F$%d\n",total_bet_money);
			printf("�z�������Ѿl�F$%d\n",money);				
		}
		printf("��Jexit�Y�i�x�s�����}�A��J���N�@�ӼƴN�i�H�~�򪱹C��"); 	
		fout=fopen("money.txt","w+"); 
		fprintf(fout,"%d",money);//�s�� 
		fclose(fout);	
		system("pause");
		system("cls");	
		counter++;
	}
}

void random(char card[][10],int *card_remaining,char draw_card[][10],int size) //��P 
{
	int num;
	num=(rand()%*card_remaining); //���ͪ��ü�
	*card_remaining-=1; 
	
	strcpy(draw_card[size],card[num]); //��X���P 
	
	for(int i=num;i<=*card_remaining;++i) //��⨫���P���X�A�A��᭱���P����e�����}�C 
	{
		strcpy(card[i],card[i+1]);
	}
} 

void separade(int *drew_times,char drew_card[][10],int flower[],int number[]) //����M�Ʀr���}
{			
	char number_1[10];
	char flower_1[10];	

 	strncpy(flower_1,drew_card[*drew_times],4); //���X���&���t�j�p 
	if(strcmp("�®�",flower_1)==0)
	{
 		flower[*drew_times]=4;
	}
	if(strcmp("����",flower_1)==0)
	{
 		flower[*drew_times]=3;
	}	
	if(strcmp("���",flower_1)==0)
	{
 		flower[*drew_times]=2;
	}	
	if(strcmp("����",flower_1)==0)
	{
 		flower[*drew_times]=1;
	}
	
 	memcpy(number_1,&drew_card[*drew_times][4],3); //���X�Ʀr 
 	if(strcmp("A",number_1)==0) //�p�G�O�^���ഫ���Ʀr�Ӥ��
 	{
 		number[*drew_times]=14; //A�̤j 
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
		number[*drew_times]=atoi(number_1); //char���Ʀr��int 
	}
}

void bet_money_set(int *total_bet_money,int *money,int compete,int win,int *throw_card) //�]�m��� 
{
	system("cls"); //�M����r 
	int bet_money=0;
	int choice=0;	
	if(compete==1)
	{
		printf("�z�������Ѿl�F$%d\n",*money);	
		printf("�п�J�򥻪��`�B�G");			
		int a=0;
		while(a==0) 
		{
			scanf("%d",&bet_money);
			if(bet_money<=0||bet_money>=*money)
			{
				printf("��J���~�A�ЦA��J�@��\n");
			}
			else
			{
				a=1;
			}
		}		
	}
	else if(win==1)
	{
		printf("�ثe�z���P����j�A�ѧA�ӤU�`\n");
		while(choice>=4||choice<=1) 
		{
			printf("�z�������Ѿl�F$%d\n",*money);
			if(compete==5)
			{
				printf("�����п�J1�A");	
			}
			printf("�U�`�п�J2�A��P�п�J3 :");			
			scanf("%d",&choice);
			if(choice==1&&compete==5)
			{
				bet_money+=*money;
				break;			
			}
			else if(choice==2)
			{
				printf("�п�J�U�`���B�G");	
				int a=0;
				while(a==0) 
				{
					scanf("%d",&bet_money);
					if(bet_money<=0||bet_money>=*money)
					{
						printf("��J���~�A�ЦA��J�@��\n");
					}
					else
					{
						a=1;
					}
				}
			}
			else if(choice==3)
			{
				*throw_card=1; //��P����
			}
			else
			{
				printf("��J���~�A�ЦA��J�@��\n");
			}
		}
	}
	else 
	{			
		while(choice>=4||choice<=0) 
		{
		printf("�ثe�q���P����j�A�q���U�`$100\n");
		printf("�z�������Ѿl�F$%d\n",*money);		
		printf("��`�п�J1�A��P�п�J2�A�[�`�п�J3:");			
		scanf("%d",&choice);
			if(choice==1)
			{
				bet_money+=100;
			}
			else if(choice==2) 
			{
				*throw_card=1; //��P����
			}
			else if(choice==3)
			{
				printf("�п�J��[�`���B(100+�z��J�����B)�G");	
				int a=0;
				while(a==0) 
				{
					scanf("%d",&bet_money);
					if(bet_money<=0||bet_money+100>=*money)
					{
						printf("��J���~�A�ЦA��J�@��\n");
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
				printf("��J���~�A�ЦA��J�@��\n");				
			}
		}	
	}
	*total_bet_money+=bet_money; 
	*money-=bet_money;	
}

void game(char my_card[][10],char pc_card[][10],int total_bet_money,int money,int compete)  //��ܵP�� 
{
	system("cls"); //�M����r
	printf("�z�������Ѿl�F$%d\n",money);
	printf("�ثe�z�������$%d\n",total_bet_money);
	printf("�ثe�q���������$%d\n",total_bet_money);	
	printf("�ڪ��d�G"); 	
	if(compete!=5)
	{
		printf("%s(�t�P) ",my_card[0]);	
		
		for(int i=1;i<=compete;i++)		
		{
			printf("%s ",my_card[i]);		
		}
		printf("\n");
		printf("�q�����d�G");
		printf("�t�P ");		
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
		printf("�q�����d�G");		
		for(int i=0;i<=4;i++)	
		{
			printf("%s ",pc_card[i]);		
		}		
	}
	printf("\n");	
	system("pause");
}
void sort(int flower[], int number[],int compete) //�ƦC�Ʀr 
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
	if(my_kind==pc_kind) //�`���ۦP�i�J��� 
	{
		if(my_kind==9||my_kind==6||my_kind==5) //�P�ᶶ&�P��&���l 
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
		else if(my_kind==8||my_kind==7||my_kind==3)//�K��&��Ī&�T�� ��Ʀr�j�p�N�n
		{
			if(my_number[2]>pc_number[2])	
			{
				*win=1;
			}						
		}
		else if(my_kind==4) //��� ����j�� �b��p�� ���@�˴N���i	����̤j�諸 
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
		else if(my_kind==2) //�@�� 
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
		else if(my_kind==1)	//���P
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
	else //�`�����P 
	{
		if(my_kind>pc_kind)
		{
			*win=1;
		}
	}		
}

void judgment(int flower[],int number[],int *kind,int compete) //�P�_�P�� 
{
	//�P�ᶶ9,�K��8,��Ī7,�P��6,���l5,���4,�T��3,�@��2,���P1 	
	if(compete==2) 
	{
		if(number[1]==number[2]) //������X�ӼƦr�@��
		{
			*kind=2; //�@�� 
		}	
	}			
	if(compete==3)  
	{
		if(number[1]==number[3])
		{
			*kind=3; //�T��
		}
		else if(number[1]==number[2] || number[2]==number[3])
		{
			*kind=2; //�@�� 
		}		
	}		
	if(compete==4)  
	{
		if(number[1]==number[2] && number[3]==number[4])
		{
			*kind=4; //��� 
		}
		else if(number[1]==number[2] || number[2]==number[3] || number[3]==number[4])
		{
			*kind=2; //�@�� 
		}
		else if(number[1]==number[3] || number[2]==number[4])
		{
			*kind=3; //�T�� 
		}
	}	
	if(compete==5)  												
	{
		int n=0;//���X�Ӥ@�˪��Ʀr 
		int f=0;//�O�_�P��
		int s=0;//�O�_�����l		
			for(int i=0;i<=3;i++)
			{
				if(number[i]-1==number[i+1]) //�T�{�O�_���l 
				{
					s+=1;					
				}
				if(flower[i]==flower[i+1]) //�T�{�O�_�P��
				{
					f+=1;
				}	
				if(number[i]==number[i+1]) //������X�ӼƦr�@��
				{
					n+=1;
				}			
			}
		
		if(f==4)
		{	
			*kind=6; //�P��
		}
		if(s==4) 
		{		
			*kind=5; //���l 
		}		
		if(f==4 && s==4) //�P��+���l 
		{
			*kind=9; //�P�ᶶ 
		}	
		if(n==0)
		{
			*kind=1; //���P 
			if(number[0]==14 && s==3) 
			{
				*kind=5; //12345�����l 
				if(f==4)
				{
					*kind=5; //12345���P�ᶶ 				
				}	
			}
		}	
		if(n==1)
		{
			*kind=2; //�@�� 
		}	
		if(n==2) 
		{
			if(number[2]==number[0]|number[4] || number[1]==number[2]&&number[2]==number[3]&&number[2]==number[3])
			 {
				*kind=3; //�T��		 	
			 }
			 else
			 {
				*kind=4; //���		 	
			 }
		} 	
		if(n==3)
		{
			if(number[0]==number[3] || number[4]==number[1])
			{
				*kind=8; //�K��		
			}
			else	
			{
				*kind=7; //��Ī			
			}		
		} 		
	}	
}
