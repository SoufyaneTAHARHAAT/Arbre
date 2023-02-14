#include<stdio.h>
#include<malloc.h>
#include<windows.h>


void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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

void inorder(noeud * racine, short * a, short b)
{
	if(racine!=NULL)
	{
		inorder(racine->sag,a,b+5);
		gotoxy(*a,b);
		printf("%d\t",racine->info);
		*a=(*a)+5;
		inorder(racine->sad,a,b+5);	
	}
}

int nbrNoeuds(noeud * racine)
{
	int cp=0;
	if(racine==NULL)
	{
		return 0;
	}
	else
	{
		cp++;
		return (nbrNoeuds(racine->sag));
	}
}


int main()
{
	noeud * racine=NULL;
	short x=5,y=2;	
	int cp=0;
	creerNoeud(&racine, 10);
	creerNoeud(&racine, -5);
	creerNoeud(&racine, 20);
	creerNoeud(&racine, 5);
	creerNoeud(&racine, 23);
	creerNoeud(&racine, -10);
	creerNoeud(&racine, 15);

	inorder(racine,&x,y);
}
