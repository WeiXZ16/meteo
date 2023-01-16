#include <stdio.h>
#include <stdlib.h>
#include<math.h>


void AfficheTableau(int tab[], int debut, int fin)
{
	int i;
	for(i=debut;i<=fin;i++)
	{
		printf("%d\n",tab[i]);
	}
	printf("\n________\n");
}


int tabTri(int tab[])
{
	int i;
	for(i=0;i<TAILLE-1;i++) // attention ici on va sortir du tableau si on ne met pas TAILLE -1
	{   
		if(tab[i]>tab[i+1]) // on regarde si le tableau n'est pas trié (element de gauche plus grand que son voisin droite)
		{
			return 0;
		}
	}
  // si on est pas sorti de la fonction à l'issue de la boucle, c'est que le tableau est trié
	return 1;
	
}


void triInsertion(int tab[], int taille){
     int decalage, temp;
  //  boucle pour la gestion de l'element à traiter
     for(int i=1;i<taille;i++)
     {
        temp=tab[i];
        decalage=i-1;
       //Recherche de l'endroit ou placer l'element et decallage des elements qui vont à sa droite
        while(decalage>=0 && tab[decalage]>temp)
        {
        	  tab[decalage+1]=tab[decalage];
            decalage=decalage-1;
        } 
       //placement de l'element 
        tab[decalage+1]=temp;
     }
}


