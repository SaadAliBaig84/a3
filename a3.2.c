#include<stdio.h>
#include<string.h>
int rowpos(int i,char array2[30][15]);
int colpos(int i,char array2[30][15]);
int main()
{
	char array[300];
	char array2[30][15]={'\0'};
	int array3[30]={0};
	
	printf("Enter id: ");
    char id[8];
    gets(id);
    
	printf("Enter string: ");
    gets(array);
    int n=strlen(array);
   
    
    int b=0,j=0,a=0;
  while(array[j]!='\0')
  {
    
  	if(array[j]==32)
  	{
  		b++;
  		j++;
  		a=0;
  		continue;
	}
	else
	{
		array2[b][a]=array[j];
		j++;
		a++;
	}  
  }

    int capitali[10],capitalj[10];
  //  for(int i=0; i<b+1; i++)
  //  {
  //  	printf("%s ", array2[i]);
  //	}
    
/*	 for(int i=0; i<b+1; i++)
	  {
	  	for(int j=0,a=0; j!='\0'; j++)
	  	{
		  	if (array2[i][j]>=65 && array2[i][j]<=90)
		  	{
		  	capitali[a]=i;
		  	capitalj[a]=j;
		  	a++;
		  	array2[i][j]+=32;
	  		}		
		}
		}*/
		char temp1;
	    int vowelposinyvowel=0;
		int count;
		for(int i=0;i<b+1;i++)
		{
			
		
		if(array2[i][0]=='s'&&array2[i][1]=='c'&&array2[i][2]=='h')
		{
			for(int k=0; k<3; k++)
			{
				
			temp1=array2[i][0];
		
			for(int j=0; j<(strlen(array2[i])-1); j++)
			{	
				array2[i][j]=array2[i][j+1];//backward shift
			}
			array2[i][strlen(array2[i])-1]=temp1;
			}
			array2[i][strlen(array2[i])-1]='\0';
			array2[i][strlen(array2[i])-1]='k';
		}	
		if(array2[i][0]!='A'&&array2[i][0]!='a'&&array2[i][0]!='E'&&array2[i][0]!='e'&&array2[i][0]!='I'&&array2[i][0]!='i'&&array2[i][0]!='O'&&array2[i][0]!='o'&&array2[i][0]!='U'&&array2[i][0]!='u'&&array2[i][0]!='s'&&array2[i][1]!='c'&&array2[i][2]!='h')
		{
			
		for(int k=0; k<2; k++)
			{
				
			temp1=array2[i][strlen(array2[i])-1];
		
			for(int j=(strlen(array2[i])-1); j>0; j--)
			{	
				array2[i][j]=array2[i][j-1];//forward shift
			}
			array2[i][0]=temp1;
			}
			strcat(array2[i],"ay");
		}
		else
		{
		
			strcat(array2[i], "way");
		}
		
	}
		
	/*	for(int i=0,u=0 ;i<b+1; i++,u++)
	  {
	 	for(int j=0,z=0; j!='\0'; j++,z++)
	  	{
	  		if(i==capitali[u]&&j==capitalj[z])
	  		array2[i][j]-=32;
	  	}
			  }*/
		printf("%s ",id);
		for(int i=0; i<b+1; i++)
    	{
    	 printf("%s ",array2[i]);
		}
		
}

