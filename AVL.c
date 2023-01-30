#include <stdio.h>
#include <stdlib.h>
#define SPACE puts ("\n")

typedef struct arbre
{
	int elmt;
	struct arbre *fg;
	struct arbre *fd;
	int eq;
} Arbre;

typedef Arbre *pArbre;

pArbre creerArbre(int a)
{
	pArbre pnew = malloc(sizeof(Arbre));
	if (pnew == NULL)
	{
		exit(1);
	}
	pnew->elmt = a;
	pnew->fg = NULL;
	pnew->fd = NULL;
	pnew->eq = 0;
	return pnew;
}

void ajouterFilsGauche(pArbre a, int e)
{
	if (a == NULL)
	{
		exit(1);
	}
	a->fg = creerArbre(e);
	if (a->fg == NULL)
	{
		exit(2);
	}
	a->eq -= 1;
}

void ajouterFilsDroit(pArbre a, int e)
{
	if (a == NULL)
	{
		exit(1);
	}
	a->fd = creerArbre(e);
	if (a->fd == NULL)
	{
		exit(2);
	}
	a->eq += 1;
}

void traiter(pArbre a)
{
	printf("%d,", a->elmt);
}

void parcoursInfixe(pArbre a)
{
	if (a != NULL)
	{
		parcoursInfixe(a->fg);
		traiter(a);
		parcoursInfixe(a->fd);
	}
}

void parcoursPrefixe(pArbre a)
{
	// RGD
	if (a != NULL)
	{
		traiter(a);
		parcoursPrefixe(a->fg);
		parcoursPrefixe(a->fd);
	}
}

void parcoursPostfixe(pArbre a)
{
	// GrD

	if (a != NULL)
	{
		parcoursPostfixe(a->fg);
		traiter(a);
		parcoursPostfixe(a->fd);
	}
}

int min2(int a, int b, int c)
{
	if (a <= b && a <= c)
	{
		return a;
	}
	else if (b <= a && b <= c)
	{
		return b;
	}
	else
	{
		return c;
	}
}

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int min(int a, int b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int max2(int a, int b, int c)
{
	if (a >= b && a >= c)
	{
		return a;
	}
	else if (b >= a && b >= c)
	{
		return b;
	}
	else
	{
		return c;
	}
}

pArbre rotationGauche(pArbre a)
{
	pArbre pivot;
	int eq_a;
	int eq_p;
	pivot = a->fd;
	a->fd = pivot->fg;
	pivot->fg = a;
	eq_a = a->eq;
	eq_p = pivot->eq;
	a->eq = eq_a - max(eq_p, 0) - 1;
	pivot->eq = min2(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);
	a = pivot;
	return pivot;
}

pArbre rotationDroite(pArbre a)
{
	pArbre pivot;
	int eq_a;
	int eq_p;
	pivot = a->fg;
	a->fg = pivot->fd;
	pivot->fd = a;
	eq_a = a->eq;
	eq_p = pivot->eq;
	a->eq = eq_a - min(eq_p, 0) + 1;
	pivot->eq = max2(eq_a + 2, eq_a + eq_p + 2, eq_p + 1);
	a = pivot;
	return pivot;
}

pArbre doubleRotationGauche(pArbre a)
{
	a->fd = rotationDroite(a->fd);
	return rotationGauche(a);
}

pArbre doubleRotationDroite(pArbre a)
{
	a->fg = rotationGauche(a->fg);
	return rotationDroite(a);
}


// cette fonction est sur le modèle du cours mais je l'ai pas tester donc je sais pas si elle marche bien
pArbre insertAVL(pArbre a, int e, int *h)
{
	// h difference d'équilibre
	if (a == NULL)
	{
		*h = 1;
		return creerArbre(e);
	}
	else if (e < a->elmt)
	{
		a->fg = insertAVL(a->fg, e, h);
		*h = -*h;
	}
	else if (e > a->elmt)
	{
		a->fd = insertAVL(a->fd, e, h);
	}
	else
	{
		*h = 0;
		return a;
	}
	if (*h != 0)
	{
		a->eq = a->eq + *h;
		if (a->eq == 0)
		{
			*h = 0;
		}
		else
		{
			*h = 1;
		}
	}
	return a;
}


// je l'ai trouvé sur internet elle marche bien et fait le réequilibrage automatiquement
pArbre insert(pArbre root, int data)

{

	if (root == NULL)

	{

		pArbre new_node = creerArbre(data);

		if (new_node == NULL)

		{

			return NULL;
		}

		root = new_node;
	}

	else if (data > root->elmt)

	{

		// insert the new node to the right

		root->fd = insert(root->fd, data);

		// tree is unbalanced, then rotate it

		if (root->eq == -2)

		{

			if (data > root->fd->elmt)

			{

				root = rotationGauche(root);
			}

			else

			{

				root->fd = rotationDroite(root->fd);

				root = rotationGauche(root);
			}
		}
	}

	else

	{

		// insert the new node to the left

		root->fg = insert(root->fg, data);

		// tree is unbalanced, then rotate it

		if (root->eq == 2)

		{

			if (data < root->fg->elmt)

			{

				root = rotationDroite(root);
			}

			else

			{

				root->fg = rotationGauche(root->fg);

				root = rotationDroite(root);
			}
		}
	}

	return root;
}

int main(int argc, char **argv)
{
	/*pArbre AVL1 = creerArbre(10);
	pArbre p1 = AVL1;
	ajouterFilsGauche(AVL1,5);
	ajouterFilsDroit(AVL1, 15);
	p1 = p1->fg;
	ajouterFilsGauche(p1, 3);
	ajouterFilsDroit(p1, 7);
	p1 = p1->fd;
	ajouterFilsDroit(p1, 9);
	p1 = AVL1->fd;
	ajouterFilsDroit(p1, 20);
	ajouterFilsGauche(p1, 12);



	pArbre AVL2 = creerArbre(9);
	ajouterFilsGauche(AVL2, 5);
	ajouterFilsDroit(AVL2, 20);
	p1 = AVL2 -> fg;
	ajouterFilsGauche(p1, 3);
	ajouterFilsDroit(p1, 7);
	p1 = AVL2->fd;
	ajouterFilsGauche(p1, 15);
	ajouterFilsGauche(p1->fg, 12);
	p1 = p1->fg;
	ajouterFilsGauche(p1->fg, 10);

	// display AVL1
	SPACE;
	parcoursInfixe(AVL1);

	SPACE;
	parcoursInfixe(AVL2);*/

	// rotation simple test OK
	/*pArbre AVL3 = creerArbre(1);
	ajouterFilsDroit(AVL3,2);
	ajouterFilsDroit(AVL3->fd,3);

	AVL3->eq = 2;
	AVL3->fd->eq = 1;
	AVL3->fd->fd->eq = 0;
	SPACE;
	printf("%d %d %d",AVL3->elmt, AVL3->fd->elmt,AVL3->fd->fd->elmt);
	SPACE;
	AVL3 = rotationGauche(AVL3);
	SPACE;

	printf("%d %d %d",AVL3->fg->elmt, AVL3->elmt,AVL3->fd->elmt);
	AVL3 = rotationGauche(AVL3);
	SPACE;
	printf("%d %d %d",AVL3->fg->fg->elmt, AVL3->fg->elmt,AVL3->elmt);*/

	// rotation double test
	pArbre AVL = creerArbre(10);
	ajouterFilsGauche(AVL, 5);
	ajouterFilsDroit(AVL, 20);
	ajouterFilsDroit(AVL->fd, 26);
	ajouterFilsGauche(AVL->fd, 15);
	ajouterFilsDroit(AVL->fd->fg, 17);
	ajouterFilsGauche(AVL->fd->fg, 13);

	AVL->eq = 2;
	AVL->fg->eq = 0;
	AVL->fd->eq = -1;
	AVL->fd->fg->eq = 0;
	AVL->fd->fd->eq = 0;
	AVL->fd->fg->fd->eq = 0;
	AVL->fd->fg->fg->eq = 0;
	parcoursInfixe(AVL);
	AVL = doubleRotationGauche(AVL);
	SPACE;
	// AVL->fd = rotationDroite(AVL->fd);
	parcoursInfixe(AVL);
	SPACE;
	printf("%d %d", AVL->fd->elmt, AVL->fd->eq);
	int *equilibre = malloc(sizeof(int));
	AVL = insertAVL(AVL, 12, equilibre);
	SPACE;
	parcoursInfixe(AVL);
	SPACE;
	printf("%d %d", AVL->fg->fd->fg->elmt, AVL->fg->fd->fg->eq);

	return 0;
}
