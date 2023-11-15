/*-----------------------------------------------------------------*/
/*
    Implémentation de la pile
*/
/*-----------------------------------------------------------------*/

#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include "etat.h"

#define STACK_SIZE 2048

/* Full definition of the s_stack structure */
struct s_stack {
	Etat **stack; // array of Etat *
	int top;
	int capacity;
};

Stack *createStack(int max_size) {
	Stack *s;
	size_t capacity = (max_size > 0 ? max_size : STACK_SIZE);
	s = malloc(sizeof(struct s_stack));
	s->stack = malloc(sizeof(Etat *) * capacity);
	s->capacity = capacity;
	s->top=-1;
	return (s);
}

void deleteStack(ptrStack *s) {
	free ((*s)->stack);
	free (*s);
	*s = NULL;
}

Stack *stackPush(Stack *s, Etat * e) {
	assert(s->top != STACK_SIZE-1);
	s->stack[++(s->top)] = e;
	return(s);
}

bool stackEmpty(Stack *s) {
	return (s->top == -1);
}

Stack *stackPop(Stack *s) {
	assert(!stackEmpty(s));
	--(s->top);
	return(s);
}

Etat *stackTop(Stack *s) {
	assert(!stackEmpty(s));
	return (s->stack[s->top]);
}

bool stackOverflow(Stack *s){
	return s->top + 1 == s->capacity;
}

void stackDump(FILE *f, Stack *s, void(*dumpfunction)(FILE *f, Etat *e)) {
	fprintf(f, "(%d) --  ", s->top+1);
	for (int i=s->top; i>=0; --i)
		dumpfunction(f, s->stack[i]);
}

int stackSize(Stack *s) {
	return (s->top)+1;
}