#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int compare(const void **pa, const void **pb) {
	char *a		=	NULL;
	a			=	*(char **) pa; 
	char *b		=	NULL;
	b			=	*(char **) pb; 

	return strcmp(a,b);
}

int main () {
    Vector	v;
    int		i,j;
	char	*str, *str2;

    v	    =	initVector();
    
    for (i=0; i < 10; i++) {

		str		=	 malloc(2000);
		strcpy(str, "wacky string lmao");
		sprintf(str, "%s %d", str, rand());

		if (i == 1)
			str2	=	strdup(str);
		addElement(v, str);
		str		=  NULL;
    }

	printf("%s\n", str2);
	sortVector(v, compare);

	printf("after\n");
    for (i=0; i < v->size; i++) {
		printf("k[%d]: %s\n", i, (char *) v->data[i]);
    }

	j	=	searchElement(v, str2, strcmp);
	printf("%d\n", j);

	free(str2);
    freeVector(v,free);
    return 0;
}
