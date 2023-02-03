#include "ABR.h"
PArbre researchABR(PTree A, Element x)
{
if (!A) return ARBRENULL;
if (x < A->elmt)
return researchABR(A->fg, x);
else
if (x > A->elmt)
return researchABR(A->fd, x);
return A;
}
PArbre InsereABR(PTree A, Element x)
{
if (!A) return creatTree(x);
if (x < A->elmt)
A->fg = InsereABR(A->fg, x);
else
if (x > A->elmt)
A->fd = InsereABR(A->fd, x);
return A;
}
PTree InsereABRIteratif(PTree A, Element x)
{
PTree tmp = A;
if (!A) return creatTree(x);
do {
if (x == tmp->elmt)
return A;
if (x < tmp->elmt)
if (tmp->fg)
tmp = tmp->fg;
else {
tmp->fg = creatTree(x);
return A;
}
else // x > tmp->elmt
if (tmp->fd)
tmp = tmp->fd;
else {
tmp->fd = creatTree(x);
return A;
}
}
while (1);
}
PTree SuppMax(PTree A, Element *x)
{
PTree tmp;
if (A->fd)
A->fd = SuppMax(A->fd, x);
else {
*x = A->elmt; 
tmp = A;
A = A->fg;
free(tmp);
}
return A;
}
PTree SuppABR(PTree A, Element x)
{
Ptree tmp;
if (A)
if (x > A->elmt)
A->fd = SuppABR(A->fd, x);
else
if (x < A->elmt)
A->fg = SuppABR(A->fg, x);
else
if (A->fg)
A->fg = SuppMax(A->fg, &(A->elmt)); 
else { 
tmp = A;
A = A->fd;
free(tmp);
}
return A;
}

PPile empile(PPile p, Element e) {
PPile ptr;
if ((ptr = MALLOC(Pile)) == NULL) {
fprintf(stderr, "ERROR");
exit(1);
}
*ptr = (Pile) { e, p };
return ptr;
}
void suppPile(PPile p) {
PPile tmp;while (p) {
tmp = p;
p = p->suiv;
free(tmp);
}
}

PPile ABtoPile(PTree a, PPile p) {
if (! estVide(a)) {
p = ABtoPile(LeftChild(a), p);
p = empile(p, a->elmt);
p = ABtoPile(RightChild(a), p);
}
return p;
}
int isABR2(PTree a) {
PPile p = NULL, tmp;
if (isEmpty(a))
return true;
p = ABtoPile(a, p); 
tmp = p;
while (p->suiv) {
if (p->val < p->suiv->val) {
suppPile(tmp);
return false;
}
p = p->suiv;
}
suppPile(tmp);
return true;
}
bool isABRRec(PTree a, Element *e) {
if (estVide(a))
return true;
if ( ! isABRRec(LeftChild(a), e))
return false;
if (*e > racine(a))
return false;
*e = racine(a);
return isABRRec(RightChils(a), e);
}
bool isUnABR(PTree a) {
Element e = ELEMENTNULL;
return isABRRec(a, &e);
}
