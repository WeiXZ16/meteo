#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arbreBinaire.h"

typedef struct pile {
Element val;
struct pile *suiv;
} Pile;
typedef Pile* PPile;

/*********************************
* Prototypes ABR
*/
PArbre researchABR(PTree , Element );
PArbre InsereABR(PTree , Element );
PArbre InsereABRIteratif(PTree , Element );
PArbre SuppMax(PTree , Element *);
PArbre SuppABR(PTree , Element );
bool isABR(PTree );
PArbre calculHauteursABR(PTree );
PArbre calculEquilibresABR(PTree );
PPile ABtoPile(PTree , PPile );
bool isABR(PTree );

#endif
