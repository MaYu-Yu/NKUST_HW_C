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
	printf("輸入球的起始速度：");
	scanf("%d",&V0);
			
	initwindow(800,600);//設定視窗大小    
	delay(500);  
	

    srand(time(NULL));//設定紅球y的位置 
	Red_y=(rand()%500)+100;
	setfillstyle(1,RED);//把紅球內部塗紅
	setcolor(4);//紅球的外圈改紅 
	fillellipse(600,Red_y, 10, 10);//設定紅球
	
	setfillstyle(1,WHITE);
	setcolor(7);	
	fillellipse(0, 20, 10, 10);//設定白球起始位置 

	while(1)
	{	
		t=t+0.2;	
		White_y = 20+(5*t*t); //白球y 
		White_x = V0*t; //白球x 
		fillellipse(White_x, White_y, 10, 10);	
		delay(200);	
		
		float dis;
		dis=sqrt((White_x-600)*(White_x-600)+(White_y-Red_y)*(White_y-Red_y));//判斷白球是否打到紅球
		if(dis<=10)//判斷白球是否打到紅球 
		{
		setfillstyle(1,YELLOW);//把紅球內部塗黃 
		setcolor(6);//紅球的外圈改黃 
		}
		if(White_x>=800||White_y>=600)//超出邊界跳出 
		{		
			break;
		}
	}

    getch();                 
    closegraph();   
	
	return 0;
	
}
