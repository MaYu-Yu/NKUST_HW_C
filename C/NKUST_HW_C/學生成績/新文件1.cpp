#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct student
{
	char name[100][10];
	int	chinese[100];
	int english[100];
	int math[100];
};

int main()
{	
	int choice;
	int times=0;
	FILE *fin;
	FILE *fout;
	struct student people;	
	
	while(1)
	{
		fin=fopen("txt.txt","r+");
		fout=fopen("txt.txt","a+");
		printf("輸入1新增，2修改，3查詢，4列表，5離開\n");
		printf("請輸入你的選擇：");
		scanf("%d",&choice);	
		printf("\n");
		if(choice==1)//新增 
		{		
			printf("學生姓名\n");
			scanf("%s",&people.name[times]);
			printf("國文成績\n");	
			scanf("%d",&people.chinese[times]);	
			printf("英文成績\n");
			scanf("%d",&people.english[times]);
			printf("數學成績\n");
			scanf("%d",&people.math[times]);
			fprintf(fout,"%s\t%d\t%d\t%d\n",people.name[times],people.chinese[times],people.english[times],people.math[times]);
			times++;
			fclose(fin);
 			fclose(fout);	
		}
		
		if(choice==2)//修改
		{
			char word[4][100]={"","","",""}; 
			for(int i=0;i<=100;i++)
			{
				people.chinese[i]=0;
				people.english[i]=0;
				people.math[i]=0;
			}
			for(int i=0; i<=3; ++i ) //儲存數值
			{
				fscanf(fin,"%s",&word[i] );	 
			}
			fscanf(fin,"%s",&people.name[0]);
			fscanf(fin,"%d",&people.chinese[0]);
			fscanf(fin,"%d",&people.english[0]);
			fscanf(fin,"%d",&people.math[0]);			
			fscanf(fin,"%s",&people.name[1]);
			fscanf(fin,"%d",&people.chinese[1]);
			fscanf(fin,"%d",&people.english[1]);
			fscanf(fin,"%d",&people.math[1]);			
			fout=fopen("txt.txt","w+");
			fprintf(fout,"姓名	國文	英文	數學\n");

			printf("請選擇您要修改的學生編號：\n");
			if(!strcmp("",people.name[0])==0)
			{
				printf("%s 請輸入1\n",people.name[0]);	
			}
			if(!strcmp("",people.name[1])==0)
			{
				printf("%s 請輸入2\n",people.name[1]);	
			}
	
			int choice_student=0;
			while(1) //選擇要更改哪位同學 
			{
				scanf("%d",&choice_student);
				if(choice_student==1) 
				{
					printf("更改後學生姓名\n");
					scanf("%s",&people.name[0]);
					printf("更改後國文成績\n");	
					scanf("%d",&people.chinese[0]);	
					printf("更改後英文成績\n");
					scanf("%d",&people.english[0]);
					printf("更改後數學成績\n");
					scanf("%d",&people.math[0]);
					fprintf(fout,"%s\t%d\t%d\t%d\n",people.name[0],people.chinese[0],people.english[0],people.math[0]);	
					if(!strcmp("",people.name[1])==0)
					{
						fprintf(fout,"%s\t%d\t%d\t%d\n",people.name[1],people.chinese[1],people.english[1],people.math[1]);	
					}	
					break;
				}
				
				if(choice_student==2)
				{
					printf("更改後學生姓名\n");
					scanf("%s",&people.name[1]);
					printf("更改後國文成績\n");	
					scanf("%d",&people.chinese[1]);	
					printf("更改後英文成績\n");
					scanf("%d",&people.english[1]);
					printf("更改後數學成績\n");
					scanf("%d",&people.math[1]);
					if(!strcmp("",people.name[0])==0)
					{
						fprintf(fout,"%s\t%d\t%d\t%d\n",people.name[0],people.chinese[0],people.english[0],people.math[0]);	
					}
					fprintf(fout,"%s\t%d\t%d\t%d\n",people.name[1],people.chinese[1],people.english[1],people.math[1]);	
					break;
				}

			}	
			fclose(fin);
 			fclose(fout);			
		}
	
		if(choice==3)//查詢 
		{	
			char word[4][100]={"","","",""}; 
			for(int i=0;i<=100;i++)
			{
				people.chinese[i]=0;
				people.english[i]=0;
				people.math[i]=0;
			}
			for(int i=0; i<=3; ++i ) //儲存數值
			{
				fscanf(fin,"%s",&word[i] );	 
			}
			fscanf(fin,"%s",&people.name[0]);
			fscanf(fin,"%d",&people.chinese[0]);
			fscanf(fin,"%d",&people.english[0]);
			fscanf(fin,"%d",&people.math[0]);			
			fscanf(fin,"%s",&people.name[1]);
			fscanf(fin,"%d",&people.chinese[1]);
			fscanf(fin,"%d",&people.english[1]);
			fscanf(fin,"%d",&people.math[1]);
						
			printf("請選擇你要查詢的學生編號：\n");	
			if(!strcmp("",people.name[0])==0)
			{
				printf("%s 請輸入1\n",people.name[0]);	
			}
			if(!strcmp("",people.name[1])==0)
			{
				printf("%s 請輸入2\n",people.name[1]);	
			}	
			int choice_student=0;
			while(1) //選擇要查詢哪位同學 
			{
				scanf("%d",&choice_student);
				if(choice_student==1)
				{			
					printf("姓名	國文	英文	數學\n");
					printf("%s	%d	%d	%d\n",people.name[0],people.chinese[0],people.english[0],people.math[0],people.math[0]);			
					break;				
				}
				if(choice_student==2)
				{			
					printf("姓名	國文	英文	數學\n");
					printf("%s	%d	%d	%d\n",people.name[1],people.chinese[1],people.english[1],people.math[1],people.math[1]);					
					break;		
				}
			}

			fclose(fin);
 			fclose(fout);
		}
		if(choice==4)//列表 
		{
			char word[100];
     		while(fgets(word,100, fin) != NULL)
			{ 
       			puts(word);
  	 		}
			fclose(fin);
 			fclose(fout);
		}
		if(choice==5)//離開 
		{
			fclose(fin);
 			fclose(fout);
			break;
		}					
	}
	fclose(fin);
    fclose(fout);
} 


	

