#include<stdio.h>
#include<math.h>
#include<iostream>

void standard(float i,float j);
void bmi(float i,float j);
void OverWeight(float i,float j);

int main() 
{
	float i,j; 
	printf("請輸入身高體重(m,kg)");
	scanf("%f,%f",&i,&j);
	bmi(i,j);
	OverWeight(i,j);	
	standard(i,j);	
	system("pause");
	return 0 ;
}

void standard(float i,float j)
{
	float Standard;
	Standard=(i*100-80)*0.7;
	printf("標準體重: %0.3f \n",Standard);		
}

void bmi(float i,float j)
{
	float Bmi;
	Bmi=j/(i*i);
	printf("BMI: %0.3f \n",Bmi);		
}

void OverWeight(float i,float j)
{
	float Overweight,Standard;
	Standard=(i*100-80)*0.7;
	Overweight=((j-Standard)/Standard) *1 ;
	printf("超重體重: %0.3f \n",Overweight);	
}


