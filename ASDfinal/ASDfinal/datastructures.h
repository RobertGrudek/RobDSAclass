#pragma once
#include "libincludes.h"

//lista jednokierunkowa
typedef struct listEl {
	int key;
	struct listEl *next;
} listElement;
typedef listElement *list;

//lista dwukierunkowa
typedef struct twlistEl {
	int key;
	struct twlistEl *next;
	struct twlistEl *prev;
} twlistElement;
typedef twlistElement *twlist;

//lista priorytetowa
typedef struct prlistEl {
	int key;
	int priority;
	struct prlistEl *next;
} prlistElement; 
typedef prlistElement *prlist; 

//drzewo binarne z rodzicem
typedef struct bTree {
	char* data;
	int counter;
	struct bTree *left;
	struct bTree *right;
	struct bTree *parent;
} bTreeRoot;
typedef bTreeRoot *bTree;

