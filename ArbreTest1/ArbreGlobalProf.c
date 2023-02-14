#include <stdio.h>
#include <malloc.h>
#include <windows.h>

typedef struct noeud
{
	int info;
	struct noeud * sag;
	struct noeud * sad;
}noeud;

//Structure de la file
typedef struct file
{
      noeud * valeur;  
      struct file * suivant;
}file;

//Primitives de la file
//il est important de noter qu'il s'agit d'une file qui va contenir des pointeurs sur les noeuds de l'ardre 
//j'avais commenc? par cr?er une file d'entiers, puis j'ai remplac? les int par node *
file * enfiler(file  * f,noeud * i)
{
      file * n, * p=f;
      n=(file *)malloc(sizeof(file)); 
      n->valeur=i;  
      n->suivant=NULL; 
      if(f==NULL)
         f=n;
      else
      {
              while(p->suivant!=NULL)   p=p->suivant;
              p->suivant=n;
      }   
      return f;
}

noeud * defiler(file * * f)
{
      file * p=*f;
      noeud * r=(*f)->valeur;
      *f=(*f)->suivant;      
      free(p);
      return r;
}

void parcoursLargeur(noeud * R)
{
	file * f=NULL;
	noeud * n;
	if(R!=NULL)
		f=enfiler(f,R);
	while(f!=NULL)
	{
		n=defiler(&f);
		printf("%d\t",n->info);
		if(n->sag!=NULL)  f=enfiler(f,n->sag);
		if(n->sad!=NULL)  f=enfiler(f,n->sad);
	}
}

void	creerNoeud(noeud * * racine,int i) //racine pass?e par adresse
{
	if(*racine==NULL)
	{
		*racine=(noeud *)malloc(sizeof(noeud));
		(*racine)->info=i;
		(*racine)->sag=NULL;
		(*racine)->sad=NULL;
	}
	else
	{
		if(i<((*racine)->info))
			creerNoeud(&((*racine)->sag),i);
		else
			creerNoeud(&((*racine)->sad),i);
	}	
}
	
void preordre(noeud * racine) //RGD
{
	if(racine!=NULL)
	{	
		printf("%d\t",racine->info);
		preordre(racine->sag);
		preordre(racine->sad);
	}
}	

void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void inordre(noeud * racine,int * x,int y) //RGD
{
	if(racine!=NULL)
	{			
		inordre(racine->sag,x,y+5);
		gotoxy(*x,y);
		printf("%d\t",racine->info);
		*x=(*x)+5;
		inordre(racine->sad,x,y+5);
	}
}

int nbrNoeuds(noeud * racine)
{
	if(racine==NULL)
		return 0;
	else
		return(1+nbrNoeuds(racine->sag)+nbrNoeuds(racine->sad));
}

int maximum(int a,int b)
{
	return((a<b)?b:a);
}

int hauteur(noeud * r)
{
	if(r==NULL)
		return -1;
	else
		return(1+maximum(hauteur(r->sag),hauteur(r->sad)));
}

void afficherFile(file * F)
{
	while(F!=NULL)
	{
		printf("%d\t",F->valeur);
		F=F->suivant;
	}
}

int main()
{
	noeud * racine=NULL;
	int x=5,y=2;
	
	creerNoeud(&racine,10);
	creerNoeud(&racine,20);
	creerNoeud(&racine,5);
	creerNoeud(&racine,23);
	creerNoeud(&racine,9);
	creerNoeud(&racine,10);
	creerNoeud(&racine,-5);	
	inordre(racine,&x,y);
	printf("\n\n");
	parcoursLargeur(racine);
	printf("La hauteur de l'ABR est : %d",hauteur(racine));
}
