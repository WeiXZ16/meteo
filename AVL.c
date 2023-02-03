#include <stdio.h>
#include <stdlib.h>
#define SPACE puts ("\n")

typedef struct tree
{
	int elmt;
	struct tree *fg;
	struct tree *fd;
	int eq;
} Tree;

typedef Tree *pTree;

pArbre createTree(int a)
{
	pTree pnew = malloc(sizeof(Tree));
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

void addLeftChild(pTree a, int e)
{
	if (a == NULL)
	{
		exit(1);
	}
	a->fg = createTree(e);
	if (a->fg == NULL)
	{
		exit(2);
	}
	a->eq -= 1;
}

void addRightChildt(pArbre a, int e)
{
	if (a == NULL)
	{
		exit(1);
	}
	a->fd = creatTree(e);
	if (a->fd == NULL)
	{
		exit(2);
	}
	a->eq += 1;
}

void traiter(pTree a)
{
	printf("%d,", a->elmt);
}

void parcoursInfixe(pTree a)
{
	if (a != NULL)
	{
		parcoursInfixe(a->fg);
		traiter(a);
		parcoursInfixe(a->fd);
	}
}

void parcoursPrefixe(pTree a)
{
	// RGD
	if (a != NULL)
	{
		traiter(a);
		parcoursPrefixe(a->fg);
		parcoursPrefixe(a->fd);
	}
}

void parcoursPostfixe(pTree a)
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

pArbre rotLeft(pArbre a)
{
	pTree pivot;
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

pArbre rotRight(pArbre a)
{
	pTree pivot;
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

pArbre doubleRotLeft(pTree a)
{
	a->fd = rotRight(a->fd);
	return rotLeft(a);
}

pArbre doubleRotRight(pTree a)
{
	a->fg = rotLeft(a->fg);
	return rotRight(a);
}


pArbre insertAVL(pArbre a, int e, int *h)
{
	if (a == NULL)
	{
		*h = 1;
		return createTree(e);
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


pArbre insert(pTree root, int data)

{

	if (root == NULL)

	{

		pTree new_node = createTree(data);

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

				root = rotLeft(root);
			}

			else

			{

				root->fd = rotRighte(root->fd);

				root = rotLeft(root);
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

				root = rotRight(root);
			}

			else

			{

				root->fg = rotLeft(root->fg);

				root = rotRight(root);
			}
		}
	}

	return root;
}

