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
		printf("��J1�s�W�A2�ק�A3�d�ߡA4�C��A5���}\n");
		printf("�п�J�A����ܡG");
		scanf("%d",&choice);	
		printf("\n");
		if(choice==1)//�s�W 
		{		
			printf("�ǥͩm�W\n");
			scanf("%s",&people.name[times]);
			printf("��妨�Z\n");	
			scanf("%d",&people.chinese[times]);	
			printf("�^�妨�Z\n");
			scanf("%d",&people.english[times]);
			printf("�ƾǦ��Z\n");
			scanf("%d",&people.math[times]);
			fprintf(fout,"%s\t%d\t%d\t%d\n",people.name[times],people.chinese[times],people.english[times],people.math[times]);
			times++;
			fclose(fin);
 			fclose(fout);	
		}
		
		if(choice==2)//�ק�
		{
			char word[4][100]={"","","",""}; 
			for(int i=0;i<=100;i++)
			{
				people.chinese[i]=0;
				people.english[i]=0;
				people.math[i]=0;
			}
			for(int i=0; i<=3; ++i ) //�x�s�ƭ�
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
			fprintf(fout,"�m�W	���	�^��	�ƾ�\n");

			printf("�п�ܱz�n�ק諸�ǥͽs���G\n");
			if(!strcmp("",people.name[0])==0)
			{
				printf("%s �п�J1\n",people.name[0]);	
			}
			if(!strcmp("",people.name[1])==0)
			{
				printf("%s �п�J2\n",people.name[1]);	
			}
	
			int choice_student=0;
			while(1) //��ܭn������P�� 
			{
				scanf("%d",&choice_student);
				if(choice_student==1) 
				{
					printf("����ǥͩm�W\n");
					scanf("%s",&people.name[0]);
					printf("�����妨�Z\n");	
					scanf("%d",&people.chinese[0]);	
					printf("����^�妨�Z\n");
					scanf("%d",&people.english[0]);
					printf("����ƾǦ��Z\n");
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
					printf("����ǥͩm�W\n");
					scanf("%s",&people.name[1]);
					printf("�����妨�Z\n");	
					scanf("%d",&people.chinese[1]);	
					printf("����^�妨�Z\n");
					scanf("%d",&people.english[1]);
					printf("����ƾǦ��Z\n");
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
	
		if(choice==3)//�d�� 
		{	
			char word[4][100]={"","","",""}; 
			for(int i=0;i<=100;i++)
			{
				people.chinese[i]=0;
				people.english[i]=0;
				people.math[i]=0;
			}
			for(int i=0; i<=3; ++i ) //�x�s�ƭ�
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
						
			printf("�п�ܧA�n�d�ߪ��ǥͽs���G\n");	
			if(!strcmp("",people.name[0])==0)
			{
				printf("%s �п�J1\n",people.name[0]);	
			}
			if(!strcmp("",people.name[1])==0)
			{
				printf("%s �п�J2\n",people.name[1]);	
			}	
			int choice_student=0;
			while(1) //��ܭn�d�߭���P�� 
			{
				scanf("%d",&choice_student);
				if(choice_student==1)
				{			
					printf("�m�W	���	�^��	�ƾ�\n");
					printf("%s	%d	%d	%d\n",people.name[0],people.chinese[0],people.english[0],people.math[0],people.math[0]);			
					break;				
				}
				if(choice_student==2)
				{			
					printf("�m�W	���	�^��	�ƾ�\n");
					printf("%s	%d	%d	%d\n",people.name[1],people.chinese[1],people.english[1],people.math[1],people.math[1]);					
					break;		
				}
			}

			fclose(fin);
 			fclose(fout);
		}
		if(choice==4)//�C�� 
		{
			char word[100];
     		while(fgets(word,100, fin) != NULL)
			{ 
       			puts(word);
  	 		}
			fclose(fin);
 			fclose(fout);
		}
		if(choice==5)//���} 
		{
			fclose(fin);
 			fclose(fout);
			break;
		}					
	}
	fclose(fin);
    fclose(fout);
} 


	

