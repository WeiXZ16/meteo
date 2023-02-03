#include <stdio.h>
#include <stdlib.h>
#define SPACE puts ("\n")

typedef struct abr{
	int elmt;
	struct ABR *fg;
	struct ABR *fd;
	int eq;
}ABR;

pABR creerABR(int a){
	pABR pA = malloc(sizeof(ABR));
	if (pA == NULL){
		exit(1);
	}
	pA->elmt = a;
	pA->fg = NULL;
	pA->fd = NULL;
	pA->eq = 0;
	return pA;
}

void ajFilsGauche(pABR a, int e){
	if (a == NULL){
		exit(1);
	}
	a->fg = creerABR(e);
	if (a->fg == NULL){
		exit(2);
	}
	a->eq -= 1;
}

void ajFilsDroit(pABR a, int e){
	if (a == NULL){
		exit(1);
	}
	a->fd = creerABR(e);
	if (a->fd == NULL){
		exit(2);
	}
	a->eq += 1;
}

void traiter(pABR a){
	printf("%d,", a->elmt);
}

void infixe(pABR a){
	if (a != NULL){
		infixe(a->fg);
		traiter(a);
		infixe(a->fd);
	}
}

void prefixe(pABR a){
	if (a != NULL){
		traiter(a);
		prefixe(a->fg);
		prefixe(a->fd);
	}
}

void postfixe(pABR a){
	if (a != NULL){
		postfixe(a->fg);
		traitere(a);
		postfixe(a->fd);
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

pABR rotGauche(pABR a){
	pABR pivot;
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

pABR rotDroite(pABR a){
	pABR pivot;
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

pABR doubleRotGauche(pABR a){
	a->fd = rotDroite(a->fd);
	return rotGauche(a);
}

pABR doubleRotDroite(pABR a){
	a->fg = rotGauche(a->fg);
	return rotDroite(a);
}


pABR insereAVL(pABR a, int e, int *h){
	if (a == NULL){
		*h = 1;
		return creerABR(e);
	}
	else if (e < a->elmt){
		a->fg = insereAVL(a->fg, e, h);
		*h = -*h;
	}
	else if (e > a->elmt){
		a->fd = insereAVL(a->fd, e, h);
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


pArbre insere(pABR racine, int data){
	if (racine == NULL){
		pABR nv = creerABR(data);
		if (nv == NULL){
			return NULL;
		}
		racine = nv;
	}
	else if (data > racine->elmt){
		racine->fd = insere(racine->fd, data);
		if (racine->eq == -2)
		}
			if (data > racine->fd->elmt){
				racine = rotGauche(racine);
			}
			else{
				racine->fd = rotDroite(racine->fd);
				racine = rotGauche(racine);
			}
		}
	}
	else{
		racine->fg = insere(racine->fg, data);
		if (racine->eq == 2){
			if (data < racine->fg->elmt){
				racine = rotDroite(racine);
			}
			else{
				racine->fg = rotGauche(racine->fg);
				racine = rotDroite(racine);
			}
		}
	}
	return racine;
}

