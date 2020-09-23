#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

int nullCheck(void *p) {
	int res		=	(p == NULL) ? 1 : 0;
	return res;
}

Vector initVector() {
    Vector		    v;
    v			=   malloc(sizeof(*v));
    
    if (nullCheck(v))
	return NULL;

    v->data		=   NULL;
    v->size		=   0;
    v->step		=   VECTOR_INIT_STEP;

    return v;
}

int addElement(Vector v, void *data) {
	if (nullCheck(v) || nullCheck(data))
		return 0;

    v->data				=	realloc(v->data, (v->size + v->step) * sizeof(void *));
    v->data[v->size]	=	data;
    v->size++;

    return 1;
}

int searchElement(Vector v, void *data, int(*compare)(const void *, const void *)) {
	int lowerLimit, upperLimit, middle, cmp;

	lowerLimit	=	0;
	upperLimit	=	v->size - 1;

	while (lowerLimit <= upperLimit) {
		middle	=	lowerLimit	+	((upperLimit - lowerLimit) >> 1);		//Bitwise operator used to find floor of division by 2
		cmp		=	compare(data, v->data[middle]);
		
		if (cmp > 0) {
			lowerLimit	=	middle + 1;
			continue;
		}

		if (cmp < 0) {
			upperLimit	=	middle - 1;
			continue;
		}
	}

	return middle;
}

void sortVector(Vector v, int(*compare)(const void **, const void **)) {
	qsort(v->data, v->size, sizeof(void *), (int(*)(const void *, const void *))(compare));
}

//Second argument is a pointer to a function of your choice
//For default behaviour, use free as the parameter
void freeVector(Vector v, void(*func)(void *)) {
    int	    i;

    if (nullCheck(v))	return; 

    for (i = 0; i < v->size; i++) {
		if (nullCheck(v->data[i]))	
			continue;
			
		func(v->data[i]); 
		v->data[i] = NULL;
    }
    
    free(v->data);
    free(v);
    v = NULL;
}
