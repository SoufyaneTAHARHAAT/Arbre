#include<stdio.h>

int factoriel(int n)
{
	if(n==1 || n==0) return 1;
	else
	return (n * factoriel (n-1));
}
int main()
{
	int n;
	printf("Enter an integer : ");
	scanf("%d", &n);
	printf("Factoriel %d = %d",n,factoriel(n));
}
