#include "ex13.h"

void add_bTree(bTree *b, bTree *_parent, char *buffer) {
	if (*b == NULL) 
	{
		char* _data = malloc(strlen(buffer) + 1);
		strcpy(_data, buffer);
		*b = malloc(sizeof(bTreeRoot));
		(*b)->data = _data;
		(*b)->counter = 1;
		(*b)->parent = _parent;
		(*b)->left = (*b)->right = NULL;
	}
	else 
	{
		int w = strcoll(buffer, (*b)->data);
		if (w < 0) { add_bTree(&(*b)->left, &(*b), buffer); }
		else if (w > 0) { add_bTree(&(*b)->right, &(*b), buffer); }
		else (*b)->counter++;
	}
}

void print_bTree0(bTree b, int depth) {
	if (b == 0) return;
	print_bTree0(b->left, depth + 1);
	char* extr_data = b->data;
	for (int i = 0; i < depth; i++) { putchar('--'); }
	for (int i = 0; i <= strlen(extr_data + 1); i++) { printf("%c", extr_data[i]); }
	printf("\n");
	print_bTree0(b->right, depth + 1);
}

void print_bTree(bTree b) {
	putchar('\n');
	print_bTree0(b, 0);
	putchar('\n');
}

void traverse_in_order(bTree *b) {
	if ((*b)->left != NULL) { traverse_in_order(&(*b)->left); }
	string_data_print(&(*b));
	if ((*b)->right != NULL) { traverse_in_order(&(*b)->right); }
}

bTree *MaxT(bTree *tmp) {
	if (*tmp == NULL) return 0;
	while ((*tmp)->right) { tmp = &(*tmp)->right; }
	return tmp;
}

bTree *MinT(bTree *tmp) {
	if (*tmp == NULL) return 0;
	while ((*tmp)->left) { tmp = &(*tmp)->left; }
	return tmp;
}

bTree *find_in_bTree(bTree *b, char *buffer) {
	int w;
	if (*b == NULL) return 0;
	bTree tmp = *b;
	w = strcoll(buffer, (tmp)->data);
	if (w < 0) { return find_in_bTree(&(tmp)->left, buffer); }
	else if (w > 0) { return find_in_bTree(&(tmp)->right, buffer); }
	else return &tmp;
}
void del_node_bTree(bTree *b, char *buffer) {
	bTree *to_del, del, *tmp;
	if (*b == NULL) return;
	tmp = find_in_bTree(b, buffer);
	if (tmp == NULL) return;
	if ((*tmp)->counter > 1) 
	{
		(*tmp)->counter--;
		return;
	}
	//tu cos smierdzi, gdzie ta glowa?:
	if ((*tmp)->left == NULL && (*tmp)->right == NULL) { to_del = tmp; }
	else 
	{
		to_del = tmp;
		(*to_del)->parent->left = (*to_del)->left;
		(*to_del)->parent->right = (*to_del)->right;
		//to_del = MaxT((*b)->left);
		//(*b)->data = (*to_del)->data;
		//(*b)->counter = (*to_del)->counter;
	}
	del = *to_del;
	if ((*to_del)->left == NULL) { *to_del = (*to_del)->right; }
	else { *to_del = (*to_del)->left; }
	free(del);
}

////stare
bTree* ZnajdzD(bTree *d, int klucz) {
	if (*d == 0) return 0;
	if (klucz < (*d)->data)
		ZnajdzD(&(*d)->left, klucz);
	else if (klucz >(*d)->data)
		ZnajdzD(&(*d)->right, klucz);
	else
		return *d;
}

void ZwolnijD(bTree *d) {
	if (*d == 0) return;
	ZwolnijD(&(*d)->left);
	ZwolnijD(&(*d)->right);
	free(*d);
	*d = 0;
}







//////
void parent_inorder(bTree *b) {
	bTree current = *b;
	bTree previous = NULL;

	while (current != NULL) {
		if (previous == current->parent) { //go down
			previous = current;
			if (current->left) {
				current = current->left;
			}
			else {
				string_data_print(&(*b));
				if (current->right)
					current = current->right;
				else
					current = current->parent;
			}
		}
		else if (previous == current->left) { // up from left child.
			previous = current;
			string_data_print(&(*b));
			if (current->right)
				current = current->right;
			else
				current = current->parent;
		}
		else if (previous == current->right) { // up from right child.
			previous = current;
			current = current->parent;
		}
	}
}






//homeworks:
bTree *nast_t(bTree *b) {
	if ((*b)->right)
	{
		b = MinT(b);
	}
	return b;
}

int calc_leaves_bTree(bTree b) {
	if (b == NULL) return 0;
	if (b->left == NULL && b->right == NULL) return 1;
	else return calc_leaves_bTree(b->left) + calc_leaves_bTree(b->right);
}
int calc_depth_bTree(bTree b) {
	if (b == NULL) return 0;
	else {
		int lDepth = calc_depth_bTree(b->left);
		int rDepth = calc_depth_bTree(b->right);
		if (lDepth > rDepth) { return (lDepth + 1); }
		else { return (rDepth + 1); }
	}
}

void string_data_print(bTree b) {
	char* extr_data = b->data;
	printf(">");
	for (int i = 0; i <= strlen(extr_data + 1); i++) { printf("%c", extr_data[i]); }
	putchar(' ');
}

