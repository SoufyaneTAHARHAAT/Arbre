#include<stdio.h>
#include<stdlib.h>
#define N 50 // maximum nodes possible

int papa[N+1];
int h=0;
int n=16;
int tab[16];
int m=0;

void saisie()
{
	int i,n;
	printf("How many nodes ? ==>  ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
	{
		printf("son %d :  ",i+1);
		scanf("%d", &papa[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("son : %d ==> father : %d\n",i+1,papa[i]);
	}
}

void leefs()
{
	int i,j,n=16;
	int leaf=1;
	
	for(i=1;i<=n;i++)//sons
	{
		leaf=1;
		for(j=0;j<n;j++)//fathers
		{
			if(i==papa[j])
			{
				leaf=0;
				break;
			}
		}
		if(leaf)
		{
			tab[m]=i;
			m++;
			printf("%d\t", i);
		}
			
	}printf("\n%d",m);
}

int hauteur(int tab[m])
{
	if(m==0) return 0;
	else
	{
		m--;
		return (max())
	}
}
/*typedef struct node
{
	int info;
	struct node * arr_sons;
}node;*/

int main()
{
	int r;
	saisie();
	leefs();
	printf("\n");
	r=hauteur(tab[16]);
	printf("%d",r);
}
