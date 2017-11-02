/**
* Sudoku solver using recursion
* Author: Ronith 
*
**/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int s[9][9],r[80],c[80];
void accept()
{
	int i,j,a=0,b=0,x,y,z,l;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			s[i][j] = 0;
		}
	}
	printf("enter the values\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			
			for(l=0;l<3;l++)
			{
				for(x=0;x<3;x++)	
				{
					for(y=0;y<3;y++)	
					{
						for(z=0;z<3;z++)	
						{
							printf("%d",s[a][b]);
							b++;
						}
						printf("\t");
					}
					printf("\n");b=0;
					a++;
				}
				printf("\n\n");
			}
			a=0;
			printf("\n enter the value for Row = %d Column = %d\n",i+1,j+1);
			scanf("%d",&s[i][j]);
			system("cls");
		
		}
	}
}

int conditions(int a,int b)
{
	int j,i,count=0,value; 
	for(j=0;j<9;j++)//horizontal conditon checking
	{
		if(s[a][j]!=0 && b!=j)
		{
			if(s[a][j]==s[a][b])
			{
				count++;
				return(count);
			}
		}
	}
	for(i=0;i<9;i++)//vertical condition checking
	{
		if(s[i][b]!=0 && a!=i)
		{
			if(s[i][b]==s[a][b])
			{
				count++;
				return count;
			}
		}
	}	
	if (a>=0&&a<=2 && b>=0&&b<=2) //condition checking in 3X3 square
	value = 1;
	else if (a>=0&&a<=2 && b>=3&&b<=5)
	value = 2;
	else if (a>=0&&a<=2 && b>=6&&b<=8)
	value = 3;
	else if (a>=3&&a<=5 && b>=0&&b<=2)
	value = 4;
	else if (a>=3&&a<=5 && b>=3&&b<=5)
	value = 5;
	else if (a>=3&&a<=5 && b>=6&&b<=8)
	value = 6;
	else if (a>=6&&a<=8 && b>=0&&b<=2)
	value = 7;
	else if (a>=6&&a<=8 && b>=3&&b<=5)
	value = 8;
	else if (a>=6&&a<=8 && b>=6&&b<=8)
	value = 9;
	switch(value)
	{
		case 1: {
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if((s[i][j]!=0)&&(i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
								break;
							}
						}
					}
				}
				break;
				}	
		case 2: {
				for(i=0;i<3;i++)
				{
					for(j=3;j<6;j++)
					{
						if((s[i][j]!=0)&&(i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
								break;
							}
						}
					}
				}
				break;
				}
		case 3: {
				for(i=0;i<3;i++)
				{
					for(j=6;j<9;j++)
					{
						if((s[i][j]!=0)&&(i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
								break;
							}
						}
					}
				}
				break;
				}
		case 4: {
				for(i=3;i<6;i++)
				{
					for(j=0;j<3;j++)
					{
						if((s[i][j]!=0) && (i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;	
								break;
							}
						}
					}
				}
				break;
				}
		case 5: {
				for(i=3;i<6;i++)
				{
					for(j=3;j<6;j++)
					{
						if((s[i][j]!=0)&&(i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;	
								break;
							}
						}
					}
				}
				break;
				}
		case 6: {
				for(i=3;i<6;i++)
				{
					for(j=6;j<9;j++)
					{
						if((s[i][j]!=0) && (i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
								break;
							}
						}
					}
				}
				break;
				}
		case 7:{
				for(i=6;i<9;i++)
				{
					for(j=0;j<3;j++)
					{
						if((s[i][j]!=0) && (i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
									break;
							}
						}
					}
				}
				break;
				}
		case 8:{
				for(i=6;i<9;i++)
				{
					for(j=3;j<6;j++)
					{
						if((s[i][j]!=0) && (i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
								break;
							}
						}
					}
				}
				break;
				}
		case 9:{
				for(i=6;i<9;i++)
				{
					for(j=6;j<9;j++)
					{
						if((s[i][j]!=0) && (i!=a || j!=b))
						{
							if(s[a][b]==s[i][j])
							{
								count++;
								break;
							}
						}
					}
				}
				break;
				}
				default : printf("default is activated\n");
							break;
	}
	return(count);
							
}

void sudoku(int i,int j,int x)
{
	int count,a,b;
 	if (s[i][j]!=0&&s[i][j]==9)
	{
		s[i][j]=0;
		sudoku(r[x-1],c[x-1],x-1);
		sudoku(r[x],c[x],x);
	}
	
	else if(s[i][j]!=0&&s[i][j]!=9)
	{
		for(b=s[i][j]+1;b<=9;b++)
		{
			s[i][j]=b;
			count=conditions(i,j);
			if(count==0)
			break;
		}
			if(count!=0&&b==10)
			{
				s[i][j]=0;
				sudoku(r[x-1],c[x-1],x-1);
				sudoku(r[x],c[x],x);
			}
		
	}
			
	else if(s[i][j]==0)
	{
		for(a=1;a<=9;a++)
		{
			s[i][j]=a;
			count=conditions(i,j);
			if(count==0)
			break;
		}
			if(count!=0&&a==10)
			{
				s[i][j]=0;
				sudoku(r[x-1],c[x-1],x-1);
				sudoku(r[x],c[x],x);
			}
		
	}	
}

void display()
{
	int l,x,y,z,a=0,b=0;
	
			for(l=0;l<3;l++)
			{
				for(x=0;x<3;x++)	
				{
					for(y=0;y<3;y++)	
					{
						for(z=0;z<3;z++)	
						{
							printf("%d",s[a][b]);
							b++;
						}
						printf("\t");
					}
					printf("\n");b=0;
					a++;
				}
				printf("\n\n");
			}
}
						
int main()
{
	int i,j,x=0,z,count=0;
	accept();
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(s[i][j]==0)
			{
				r[x]=i;
				c[x]=j;
				x++;
			}
		}
	}
	r[x]=100;
	x=0;
	
	while(r[x]!=100)
	{
		sudoku(r[x],c[x],x);
		x++;
	}
	display();
	getch();
	return 0;
}
	
	
	
	
