#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<time.h>

int main()
{
	int White_x=0, White_y=0, Red_y, V0;
	float t=0 ;
	printf("��J�y���_�l�t�סG");
	scanf("%d",&V0);
			
	initwindow(800,600);//�]�w�����j�p    
	delay(500);  
	

    srand(time(NULL));//�]�w���yy����m 
	Red_y=(rand()%500)+100;
	setfillstyle(1,RED);//����y�������
	setcolor(4);//���y���~���� 
	fillellipse(600,Red_y, 10, 10);//�]�w���y
	
	setfillstyle(1,WHITE);
	setcolor(7);	
	fillellipse(0, 20, 10, 10);//�]�w�ղy�_�l��m 

	while(1)
	{	
		t=t+0.2;	
		White_y = 20+(5*t*t); //�ղyy 
		White_x = V0*t; //�ղyx 
		fillellipse(White_x, White_y, 10, 10);	
		delay(200);	
		
		float dis;
		dis=sqrt((White_x-600)*(White_x-600)+(White_y-Red_y)*(White_y-Red_y));//�P�_�ղy�O�_������y
		if(dis<=10)//�P�_�ղy�O�_������y 
		{
		setfillstyle(1,YELLOW);//����y������� 
		setcolor(6);//���y���~���� 
		}
		if(White_x>=800||White_y>=600)//�W�X��ɸ��X 
		{		
			break;
		}
	}

    getch();                 
    closegraph();   
	
	return 0;
	
}
