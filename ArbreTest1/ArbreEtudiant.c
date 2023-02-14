#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Etudiant
{
	char nom[10];
	float note;
	struct Etudiant* sag;
	struct Etudiant* sad;
}Etudiant;

void creerEtudiant(Etudiant **racine, char nom[], float note)
{
	int i=0;
	if(*racine == NULL)
	{
		*racine=(Etudiant *)malloc(sizeof(Etudiant));
		strcpy((*racine)->nom,nom);
		/*while(nom[i]!='\0')
		{
			(*racine)->nom[i]=nom[i];
			i++;
		}	
		(*racine)->nom[i]='\0';
		/*for(i=0;i<strlen(nom);i++)
		{
			(*racine)->nom[i]=nom[i];
		}*/
		(*racine)->note=note;
		(*racine)->sag=NULL;
		(*racine)->sad=NULL;
	}
	else
	{
			if(strcmp((*racine)->nom,nom)>0)
		{
			creerEtudiant(&((*racine)->sag),nom,note);
		}
		else
			creerEtudiant(&((*racine)->sad),nom,note);
	}
}

void inorder(Etudiant * racine)
{
	//char nom[10];
	int i=0;
	if(racine!=NULL)
	{
		inorder(racine->sag);
		
		printf(" %s",((racine->nom)));

		
		printf("\t %.02f\n",racine->note);
		inorder(racine->sad);	
	}
}

/*void inorder(Etudiant * racine)
{
	//char nom[10];
	int i=0;
	if(racine!=NULL)
	{
		inorder(racine->sag);
		while((racine->nom)[i]!='\0')
		{
			printf(" %c",((racine->nom)[i]));
			i++;
		}
		printf(" %f\n",racine->note);
		inorder(racine->sad);	
	}
}*/

int main()
{
	Etudiant * racine=NULL;
	
	creerEtudiant(&racine, "HAKIM",12);
	creerEtudiant(&racine, "jALIL",15);
	creerEtudiant(&racine, "MALAK",9);
	creerEtudiant(&racine, "AKRAM",17);
	creerEtudiant(&racine, "SAAD",11);
	creerEtudiant(&racine, "SIHAM",16);
	creerEtudiant(&racine, "FARID",12);
	creerEtudiant(&racine, "ISSAM",10);

	inorder(racine);
}
