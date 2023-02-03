#include <stdio.h>
#include <stdlib.h>
#define SPACE puts ("\n")

typedef struct tree{
	int elmt;
	struct tree *lc;
	struct tree *rc;
	int eq;
}Tree;

pArbre createTree(int a){
	pTree pnew = malloc(sizeof(Tree));
	if (pnew == NULL){
		exit(1);
	}
	pnew->elmt = a;
	pnew->lc = NULL;
	pnew->rc = NULL;
	pnew->eq = 0;
	return pnew;
}

void addLeftChild(pTree a, int e){
	if (a == NULL){
		exit(1);
	}
	a->lc = createTree(e);
	if (a->lc == NULL){
		exit(2);
	}
	a->eq -= 1;
}

void addRightChildt(pTree a, int e){
	if (a == NULL){
		exit(1);
	}
	a->rc = creatTree(e);
	if (a->rc == NULL){
		exit(2);
	}
	a->eq += 1;
}

void process(pTree a){
	printf("%d,", a->elmt);
}

void infix(pTree a){
	if (a != NULL){
		infix(a->lc);
		process(a);
		infix(a->rc);
	}
}

void prefix(pTree a){
	if (a != NULL){
		process(a);
		prefix(a->lc);
		prefix(a->rc);
	}
}

void postfix(pTree a){
	if (a != NULL){
		postfix(a->lc);
		process(a);
		postfix(a->rc);
	}
}

int min2(int a, int b, int c){
	if (a <= b && a <= c){
		return a;
	}
	else if (b <= a && b <= c){
		return b;
	}
	else{
		return c;
	}
}

int max(int a, int b){
	if (a >= b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a, int b){
	if (a <= b){
		return a;
	}
	else{
		return b;
	}
}

int max2(int a, int b, int c){
	if (a >= b && a >= c){
		return a;
	}
	else if (b >= a && b >= c){
		return b;
	}
	else{
		return c;
	}
}

pArbre rotLeft(pArbre a){
	pTree pivot;
	int eq_a;
	int eq_p;
	pivot = a->rc;
	a->rc = pivot->lc;
	pivot->lc = a;
	eq_a = a->eq;
	eq_p = pivot->eq;
	a->eq = eq_a - max(eq_p, 0) - 1;
	pivot->eq = min2(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);
	a = pivot;
	return pivot;
}

pArbre rotRight(pArbre a){
	pTree pivot;
	int eq_a;
	int eq_p;
	pivot = a->lc;
	a->lc = pivot->rc;
	pivot->rc = a;
	eq_a = a->eq;
	eq_p = pivot->eq;
	a->eq = eq_a - min(eq_p, 0) + 1;
	pivot->eq = max2(eq_a + 2, eq_a + eq_p + 2, eq_p + 1);
	a = pivot;
	return pivot;
}

pArbre doubleRotLeft(pTree a){
	a->rc = rotRight(a->rc);
	return rotLeft(a);
}

pArbre doubleRotRight(pTree a){
	a->lc = rotLeft(a->lc);
	return rotRight(a);
}


pArbre insertAVL(pArbre a, int e, int *h){
	if (a == NULL){
		*h = 1;
		return createTree(e);
	}
	else if (e < a->elmt){
		a->lc = insertAVL(a->lc, e, h);
		*h = -*h;
	}
	else if (e > a->elmt){
		a->rc = insertAVL(a->rc, e, h);
	}
	else{
		*h = 0;
		return a;
	}
	if (*h != 0){
		a->eq = a->eq + *h;
		if (a->eq == 0){
			*h = 0;
		}
		else{
			*h = 1;
		}
	}
	return a;
}


pArbre insert(pTree root, int data){
	if (root == NULL){
		pTree new_node = createTree(data);
		if (new_node == NULL){
			return NULL;
		}
		root = new_node;
	}
	else if (data > root->elmt){
		// insert the new node to the right
		root->rc = insert(root->rc, data);
		// tree is unbalanced, then rotate it
		if (root->eq == -2)
		}
			if (data > root->rc->elmt){
				root = rotLeft(root);
			}
			else{
				root->rc = rotRighte(root->rc);
				root = rotLeft(root);
			}
		}
	}
	else{
		// insert the new node to the left
		root->lc = insert(root->lc, data);
		// tree is unbalanced, then rotate it
		if (root->eq == 2){
			if (data < root->lc->elmt){
				root = rotRight(root);
			}
			else{
				root->lc = rotLeft(root->lc);
				root = rotRight(root);
			}
		}
	}
	return root;
}

