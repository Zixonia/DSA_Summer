#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h> 

#define MAX 20

typedef struct{
    bool elems[MAX];
    int count;
} Set;

Set newSet();
bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);
void visualizeSet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDiffSet(Set a, Set b);
int cardinality(Set s);
#endif
