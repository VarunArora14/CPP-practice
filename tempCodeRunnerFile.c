#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void addmat(int a[50][50],int b[50][50], int row,int col)
{
int c[row][col];
int i=0,j=0;
printf("The resultant matrix is : \n");
for(i;i<row;i++)
{
for(j;j<col;j++)
{
c[i][j]=a[i][j]+b[i][j];
printf("%d  ",c[i][j]);
}
printf("\n");
}
}

void submat(int a[50][50],int b[50][50], int row,int col)
{
int c[row][col];
int i=0,j=0;
printf("The resultant matrix is : \n");
for(i;i<row;i++)
{
for(j;j<col;j++)
{
c[i][j]=a[i][j]-b[i][j];
printf("%d  ",c[i][j]);
}
printf("\n");
}
}



void upptri(int a[50][50], int row,int col)
{
printf("The upper triangle is : \n");
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(i<=j)
printf("%d",a[i][j]);
}
printf("\n");
}
}


void lowtri(int a[50][50], int row,int col)
{
printf("The lower triangle is : \n");
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(i>=j)
printf("%d",a[i][j]);
}
printf("\n");
}
}


void transmat(int a[50][50], int row,int col)
{
int temp;
printf("The transpose matrix is : \n");
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(i>j)
{
temp=a[i][j];
a[i][j]=a[j][i];
a[j][i]=temp;
}
}
}

for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        printf("%d",a[i][j]);
        printf(" ");
    }
    printf("\n");
}

}

void prodmat(int a[50][50],int b[50][50], int row,int col,int elim)
{
int c[row][col];
int i=0,j=0;
printf("The resultant matrix is : \n");
for(i;i<row;i++)
{
for(j;j<col;j++)
{
c[i][j]=0;
for(int k=0;k<elim;k++)
{
c[i][j]+=a[i][k]*b[k][j];
}
printf("%d",c[i][j]);
}
printf("\n");
}
}


int main()
{
system("cls");
char a,c;
int i;
do
{
printf(" MATRIX CALCULATIONS \n");
printf(" 1. CALCULATIONS INVOLVING 2 MATRICES :\n");
printf(" 2. CALCULATIONS INVOLVING 1 MATRIX :\n");
printf(" Press 1 or 2\n");
scanf("%d",&i);
if(i==2)
{
int a[50][50];
int m,n,choice;
printf("ENTER THE ROWS AND COLUMNS OF THE MATRIX : ");
scanf("%d",&m);
scanf("%d",&n);
printf("\nENTER THE ELEMENTS OF THE MATRIX :\n");
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf(" 1. UPPER TRIANGULAR MATRIX \n 2. LOWER TRIANGULAR MATRIX\n 3. TRANSPOSE OF A MATRIX\nENTER YOUR CHOICE(1/2/3) - ");
scanf("%d",&choice);
switch(choice)
{
case 1:upptri(a,m,n);
	break;
case 2:lowtri(a,m,n);
	break;
case 3:transmat(a,m,n);
	break;
default:printf("WRONG OPTION ENTERED ");
}
}
else if(i==1)
{
int a[50][50],b[50][50];
int m1,n1,m2,n2,choice;
printf("ENTER THE ROWS AND COLUMNS OF THE 1st MATRIX : ");
scanf("%d",&m1);
scanf("%d",&n1);
printf("\nENTER THE ELEMENTS OF THE 1ST MATRIX :\n");
for(int i=0;i<m1;i++)
{
for(int j=0;j<n1;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("ENTER THE ROWS AND COLUMNS OF THE 2nd MATRIX : ");
scanf("%d",&m2);
scanf("%d",&n2);
printf("\nENTER THE ELEMENTS OF THE 2nd MATRIX :\n");
for(int i=0;i<m2;i++)
{
for(int j=0;j<n2;j++)
{
scanf("%d",&b[i][j]);
}
}
printf("	1. ADDITION OF MATRICES \n 		2.SUBTRACTION OF MATRICES\n 		3. PRODUCT OF MATRICES\nENTER YOUR CHOICE(1/2/3) - ");
scanf("%d",&choice);
switch(choice)
{
case 1: if((m1==m2)&&(n1==n2))
	{
	addmat(a,b,m1,n1);
	}
	else
	{
	printf("THE MATRICES CANNOT BE ADDED ");
	}
	break;
case 2:if((m1==m2)&&(n1==n2))
	{
	submat(a,b,m1,n1);
	}
	else
	{
	printf("THE MATRICES CANNOT BE SUBTRACTED.");
	}
	break;
case 3:if(n1==m2)
	{
	prodmat(a,b,m1,n2,n1);
	}
	else
	{
	printf("THE MATRICES CANNOT BE MULTIPLIED.");
	}
	break;

default:printf("WRONG OPTION ENTERED ");
}
}
printf("DO YOU WANT TO CONTINUE ?(Y/N)");

scanf("%c",&c);
}while(c=='Y');
getch();
}

