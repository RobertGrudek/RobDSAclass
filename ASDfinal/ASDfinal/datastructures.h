#pragma once
#include "libincludes.h"

//lista jednokierunkowa
typedef struct listEl {
	int key;
	struct listEl *next;
} listElement;
typedef listElement *list;

//lista dwumiekurnkowa
typedef struct twlistEl {
	int key;
	struct twlistEl *next;
	struct twlistEl *prev;
} twlistElement;
typedef twlistElement *twlist;

//drzewo binarne z rodzicem
typedef struct bTree {
	char* data;
	int counter;
	struct bTree *left;
	struct bTree *right;
	struct bTree *parent;
} bTreeRoot;
typedef bTreeRoot *bTree;
