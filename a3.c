#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    int hs(int i, int j, char array[6][5], char string[6], int size , int index);
	int vs(int i, int j, char array[6][5], char string[6], int size , int index); 
int main()
{
	//taking input.
	char array[6][5];
	char array2[4]={'4','1','3','1'};
	srand(time(NULL));//seed random number generator. 
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(i==5&&(j==0||j==1||j==2||j==3))
			array[i][j]=array2[j];
			else
			array[i][j]='A'+rand()%25;
		}
	}
	//now output the ARRAY in table form.
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<5; j++)
		{
			printf("%c\t",array[i][j]);
		}
		printf("\n");
	}
	int score=0;
	for(;;)
	{
	char string[6];
	puts("Enter the search string: ");
	gets(string);
	if(strcmp(string,"END")==0)
	break;
	int size=strlen(string);
    int count=0;
   	for(int i=0; i<6; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(hs(i,j,array,string,size,0)==3)
			count++;
		}
		
	}
	for(int j=0; j<5; j++)
	{
		for(int i=0; i<6; i++)
		{
			if(vs(i,j,array,string,size,0)==3)
			{
				count++;
			}
		}
	} 

	if(count>0)
	{
		score++;
		printf("%s is present-> score %d\n", string, score);
	}
	else                  
	{
		score--;
		printf("%s is not present-> score %d\n", string, score);
	}
	}
	return 0;
}
	int hs(int i, int j, char array[6][5], char string[6], int size , int index) 
	{
		int found=0;
	
		if(i>=0 &&j>=0 && i<6 && j<5  && index >=0 && index<5 )
		{
			if(array[i][j]==string[index])
			{
				index++;
				if(index==size)
				{
				found=3;
				}
				else
				{
				found+=hs(i,j+1,array, string,size, index);
				//found+=hs(i,j-1,array, string,size, index);(for searching reight to left)
				}
				
				
			}
		}
	
		return found;
	}
	
	int vs(int i, int j, char array[6][5], char string[6], int size , int index) 
	{
		int found=0;
	
		if(i>=0 &&j>=0 && i<6 && j<5  && index >=0 && index<6 )
		{
			if(array[i][j]==string[index])
			{
				index++;
				if(index==size)
				{
				found=3;
				}
				else
				{
				found+=vs(i+1,j,array, string,size, index);
				//found+=vs(i-1,j,array, string,size, index);(for searching reight to left)
				}
				
				
			}
		}
	
		return found;
	}
	
