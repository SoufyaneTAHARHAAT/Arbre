#include<stdio.h>
#include<malloc.h>
#include<windows.h>

int cp=0;
int b=0;
int S=0;


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
		S=S+(racine->info);
		inorder(racine->sad);	
	}
}

/* à n ' a p p e l e r que s u r de s a r b r e s != NULL */
int verifie_rec(noeud *racine , int *min , int *max) {
int i ;
*min=*max=racine->info ;
if(racine->sag !=NULL)
/* on u t i l i s e l ' é v a l u a t i o n p a r e s s e u s e du | | */
if ( !verifie_rec(&(racine->sag),&i,max) || !(racine->info>*max))
return 0 ;
if (racine->sad!=NULL)
/* on u t i l i s e l ' é v a l u a t i o n p a r e s s e u s e du | | */
if (!verifie_rec( &(racine->sad),min,&i) || !(racine->info<=*min ))
return 0 ;
return 1 ;
}
int verifie (racine) {
int min , max ;
return ((racine==NULL) ?1:verifie_rec(&racine,&min,&max )) ;
}


void nbrn(noeud * racine)
{
	if(racine!=NULL)
	{
	//	printf("%d\t",racine->info);
		nbrn(racine->sag);
		
		if((racine->info)%2==0)
			cp++;
		nbrn(racine->sad);	
	}
}

/*void find(noeud * racine,int i)
{
	if(racine!=NULL)
	{
	//	printf("%d\t",racine->info);
		find(racine->sag,i);
		find(racine->sad,i);	
		if((racine->info)==i)
		{
			printf("trouve");
		} 
	}
}*/

void find(noeud * racine,int i)
{
	if(racine!=NULL)
	{
	//	printf("%d\t",racine->info);
		find(racine->sag,i);
		find(racine->sad,i);	
		if((racine->info)==i)
		{
			b=1;
		} 
	}
}


void arbreForme(noeud * racine, short * a, short b)
{
	if(racine!=NULL)
	{
		arbreForme(racine->sag,a,b+5);
		gotoxy(*a,b);
		printf("%d\t",racine->info);
		*a=(*a)+5;
		arbreForme(racine->sad,a,b+5);	
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

	if((racine->sad)==NULL)
		return (racine);
	else
	{
		predecesseur((racine->sad));
	}
}

noeud * successeur(noeud * racine)
{

	if((racine->sag)==NULL)
		return (racine);
	else
	{
		successeur((racine->sag));
	}
}

void supprimer(noeud ** racine, int x)
{
	noeud * p,*k;
	
	if(x==(*racine)->info)
	{
		if((*racine)->sag==NULL && (*racine)->sad==NULL)
		{
			p=(*racine);
			(*racine)=NULL;
			free(p);
		}
		else
		{
			if((*racine)->sag==NULL && (*racine)->sad!=NULL)
			{
				(*racine)=(*racine)->sad;
			}
			else
			{
				if((*racine)->sag!=NULL && (*racine)->sad==NULL)
				{
					(*racine)=(*racine)->sag;
				}
				else
				{
					if((*racine)->sag!=NULL && (*racine)->sad!=NULL)
					{
						k=predecesseur((*racine)->sag);
						(*racine)->info=k->info;
						supprimer(&(*racine)->sag,k->info);
						//free(k);
					}
				}
			}
			
		}
	}
	else
	{
		if(x<(*racine)->info)
		{
			supprimer(&((*racine)->sag),x);
		}
		else
		{
			supprimer(&((*racine)->sad),x);
		}
	}
}

/*int testSimilarite(noeud *racine,noeud *racine1)
{
	if(racine!=Null && racine1==NULL)
		return 0;
	if(racine==Null && racine1!=NULL)
		return 0;
	if(racine==Null && racine1==NULL)
		{
			TestSimilarite(racine->sad,racine1->sad);
			TestSimilarite(racine->sag,racine1->sag);
		}
	if(racine!=Null && racine1!=NULL)
}


int testSimilarite(noeud *r1,noeud *r2)
{
	if(racine->info!=racine1->info)
		return 0;
	else
	{
		if(testSimilarite(noeud *r1,noeud *r2))
		TestSimilarite(racine->sad,racine1->sad);
		TestSimilarite(racine->sag,racine1->sag);
	}
}*/

int main()
{
	noeud * racine=NULL;
	noeud * racine1=NULL;
	short x=5,y=2;
	File *file=NULL;
	
	creerNoeud(&racine, 20);
	creerNoeud(&racine, 40);
	creerNoeud(&racine, 10);
	creerNoeud(&racine, 50);
	creerNoeud(&racine, 15);
	creerNoeud(&racine, 30);
	creerNoeud(&racine, 5);
	creerNoeud(&racine, -2);
	creerNoeud(&racine, 17);
	creerNoeud(&racine, 25);
	creerNoeud(&racine, 55);
	creerNoeud(&racine, 9);
	
//	supprimer(&racine, 30);
	inorder(racine);
	printf("\n\n");
	arbreForme(racine,&x,y);
	printf("%d",S);
//	ParcoursHoriz(file,racine);
	
//	printf("\n\nLe predecesseur est : %d",(predecesseur(racine->sag))->info);
//	printf("\n\nLe successeur est : %d",(successeur(racine->sad))->info);
	
	
//	getch();
//	system("cls");
	x=5,y=2;
//	arbreForme(racine,&x,y);
/*	nbrn(racine);
	printf("\n%d",cp);
	(find(racine,40));
	if(b==1)
		printf("trouve");
	else printf ("non trouve");
	if(testSimilarite(racine,racine1)==0)
		printf("Les arbres sont identiques");
	else printf("Les arbres ne sont pas identiques");*/
}
