#ifndef VECTOR_HEADER_INCLUDED
#define VECTOR_HEADER_INCLUDED
#include <stdio.h>

//CONSTANTS
#define VECTOR_INIT_STEP 8

//STRUCTURES
struct Vector {
    void    **data;
    int     size;
    int     step;
};
typedef struct Vector *Vector;

//FUNCTION PROTOTYPES

int         nullCheck(void *p);
Vector	    initVector();
int         addElement(Vector v, void *data);
void	    freeVector(Vector v, void(*func)(void *));
int 		searchElement(Vector v, void *data, int(*compare)(const void *, const void *));
void		sortVector(Vector v, int(*compare)(const void **, const void **));

#endif
