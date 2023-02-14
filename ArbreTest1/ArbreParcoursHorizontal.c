#include<stdio.h>
#include<malloc.h>

typedef struct noeud
{
	int info;
	struct noeud *sag;
	struct noeud *sad;
}noeud;

typedef struct file
{
	noeud * info;
	struct file * suivant;
}File;

int filevide(File *file)
{
	if(file==NULL) return 1;
	else return 0;
}

void enfiler(File **file, noeud *rac)
{
	File * nouveau, *p;
	p=(*file);
	
	nouveau=(File*)malloc(sizeof(File));
	nouveau->info=rac;
	nouveau->suivant=NULL;
	
	if(filevide(*file)==1)
	{
		(*file)=nouveau;
	}
	else
	{
		while(p->suivant!=NULL)
		{
			p=p->suivant;
		}
		p->suivant=nouveau;
	}
}

noeud *defiler(File **file)
{
	noeud * r;
	File * p;
	r=(*file)->info;
	p=(*file);
	(*file)=(*file)->suivant;
	free(p);
	return(r);
}

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

void ParcoursHoriz(File *file, noeud *racine)
{
	noeud *racine1;
	
	enfiler(&file,racine);
	do
	{
		racine1=defiler(&file);
		printf("%d\t",racine1->info);
		if((racine1->sag)!=NULL)
			enfiler(&file,(racine1->sag));
		if((racine1->sad)!=NULL)
			enfiler(&file,(racine1->sad));	
	}while(filevide(file)==0);
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
	File *file=NULL;
	
	creerNoeud(&racine, 20);
	creerNoeud(&racine, 40);
	creerNoeud(&racine, 10);
	creerNoeud(&racine, 50);
	creerNoeud(&racine, 15);
	creerNoeud(&racine, 30);
	creerNoeud(&racine, 5);
	creerNoeud(&racine, -2);
	creerNoeud(&racine, -4);
	creerNoeud(&racine, 17);
	creerNoeud(&racine, 25);
	creerNoeud(&racine, 55);
	creerNoeud(&racine, 9);
	creerNoeud(&racine, -6);

	inorder(racine);
	printf("\n");
	ParcoursHoriz(file,racine);
}
