#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
int main()
{

	int word;
	int gd = DETECT, gm , color; 
    int left=200,top=200,right=200,bottom=200;
    int BiG_Head_X=300,BiG_Head_Y=200,SMALL_Head_X=300,SMALL_Head_Y=210,radius=100;
    int lefteye_X=270,lefteye_Y=170;
    int eye_X=280,eye_Y=170 ;

	
    printf("請輸入你要的顏色的數字:\n");
    printf("藍色:1\n");
    printf("綠色:2\n");
    printf("青色:3\n");
    scanf("%d",&word);
    
	if(word>3 || word<1)
	{
		printf("輸入錯誤");
		closegraph();
	}
   
   initgraph(&gd,&gm, "C:\\TC\\BGI");
   delay(500); 
   setcolor(word);
   
   circle(BiG_Head_X,BiG_Head_Y,radius);
   circle(SMALL_Head_X,SMALL_Head_Y,radius-10);   
   circle(SMALL_Head_X-5,SMALL_Head_Y,radius-85);      
   ellipse(lefteye_X,lefteye_Y,0,360,23,33);
   ellipse(lefteye_X+50,lefteye_Y,0,360,23,33);   
   ellipse(eye_X,eye_Y,0,360,13,20);   
   ellipse(eye_X+50,eye_Y,0,360,13,20);      
   arc(BiG_Head_X-5,BiG_Head_Y+10,210,330,60);
   line(240,210,200,190);
   line(240,223,200,210);
   line(240,235,200,230);
   line(370,190,330,210);
   line(370,210,330,223);   
   line(370,230,330,235);   
   line(370,230,330,235);   
   line(SMALL_Head_X-5,SMALL_Head_Y+13,SMALL_Head_X-5,272) ;
   
   
   getch();
   closegraph();
   system("pause"); 
   return 0;
}
