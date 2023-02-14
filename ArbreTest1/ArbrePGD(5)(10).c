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

void supprimer(noeud ** racine, int i)
{
	noeud *p,*g,*d;
	p=(*racine);
	g=p->sag;
	d=p->sad;
	
	if(p->info==i)
	{
		d->sag=g;
	//	p=d;
		(*racine)=p->sad;
	//	free(p);
	}
	else
	{
		if(p->info>i)
		{
			if(g->info==i)
			{
				supprimer(&g,i);
			}
			else
			{
				if(g->info<i)
				{
					supprimer(&(g->sad),i);
				}
			}
		}
		else //(p->info<i)
		{
			p=d;
			g=d->sag;
			d=p->sad;
			supprimer(&p,i);
		}
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
	creerNoeud(&racine, 4);
	creerNoeud(&racine, 21);
	creerNoeud(&racine, 9);

	inorder(racine);
	supprimer(&racine,10);
	printf("\n\n");
	inorder(racine);
}
