#include<stdio.h>
#include<malloc.h>

typedef struct noeud
{
	int info;
	struct noeud *sag;
	struct noeud *sad;
}noeud;

void creerNoeud(noeud * *racine, int i)
{
	if(*racine == NULL)
	{
		*racine=(noeud *)malloc(sizeof(noeud));
		(*racine)->info=i;
		(*racine)->sag=NULL;
		(*racine)->sad=NULL;
	}
	else
	{
		if(i<(*racine)->info)
		{
			creerNoeud(&((*racine)->sag),i);
		}
		else
			creerNoeud(&((*racine)->sad),i);
	}
}

void inorder(noeud * racine)
{
	if(racine!=NULL)
	{
		inorder(racine->sag);
		printf("%d\t",racine->info);
		inorder(racine->sad);	
	}
}

int main()
{
	noeud * racine=NULL;
	
	creerNoeud(&racine, 10);
	creerNoeud(&racine, -5);
	creerNoeud(&racine, 20);
	creerNoeud(&racine, 5);
	creerNoeud(&racine, 23);
	creerNoeud(&racine, -10);
	creerNoeud(&racine, 100);
	creerNoeud(&racine, 9);

	inorder(racine);
}


