#include<stdio.h> 
int main() 
{ 
	FILE *fin;
	FILE *fout;
	int num[4], zero=0;

	fin=fopen("test.txt","r"); 
	fout=fopen("answer.txt","w"); 
	
	for(int i=0; i<=3; ++i ) 
	{
		fscanf(fin,"%d", &num[i] );	//輸入數值 
	}
	
    for(int i=0 ; i<=3 ; ++i) //排列 
    {
        for(int j=i+1 ; j<=3 ; ++j)
        {
            if(num[i]> num[j])
            {
                zero = num[i];
                num[i] = num[j];
                num[j] = zero;
            }
        }
    }
	
	for(int i=0; i<=3; ++i) 
	{	
		fprintf(fout,"%d ",num[i]); //輸出數值 
	}
}
