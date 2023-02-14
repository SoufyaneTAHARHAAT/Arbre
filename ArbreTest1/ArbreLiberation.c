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

void det(noeud * *racine)
{	
	if(*racine!=NULL)
	{
		det(&((*racine)->sag));
		det(&((*racine)->sad));	
		free(*racine);
		(*racine)=NULL;
	}
}

noeud * predecesseur(noeud * racine)
{
	noeud *p;
	p=racine->sag;
	if(p!=NULL)
	{
		predecesseur((p->sad));
	}
	return (p);
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
//	det(&racine);
//	inorder(racine);
printf("%d",(predecesseur(racine))->info);
}
