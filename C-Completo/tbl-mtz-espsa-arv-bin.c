#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell{
	char name[9];
	char formula[128];
	struct cell *left;
	struct cell *right;
};

struct cell *stree(struct cell *root, struct cell *r, struct cell *new);
struct cell *dtree(struct cell *root, char *key);
struct cell *search_tree(struct cell *root, char *key);

int main(int argc, char *argv[])
{		
	putchar('\n');
	exit(EXIT_SUCCESS);
}
struct cell *stree(struct cell *root, struct cell *r, struct cell *new)
{
	if(!r){ /* primeiro no da arvora */
		new->left = NULL;
		new->right = NULL;
		if(!root) return new;
		if(strcmp(new->name, root->name)<0){
			root->left = new;
		}
		else
			root->right = new;
		return new;
	}
	if(strcmp(r->name, new->name)<=0) stree(r, r->right, new);
	else stree(r, r->left, new);
	return root;
}

struct cell *dtree(struct cell *root, char *key)
{
	struct cell *p, *p2;
	if(!root) return root; /* item nao encontrado */
	if(!strcmp(root->name, key)){ /* apagar a raiz */
		if(root->left == root->right){ /* isso significa uma arvore vazia */
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			p=root->right;
			free(root);
			return p;
		}
		else if(root->right==NULL) {
			p = root->left;
			free(root);
			return p;
		}
		else{
			p2 = root->right;
			p = root->right;
			while(p->left) p = p->left;
			p->left = root->left;
			free(root);
			return p2;
		}
	}
	if(strcmp(root->name, key) <= 0)
		root->right = dtree(root->right, key);
	else root->left = dtree(root->left, key);
	return root;
}

struct cell *search_tree(struct cell *root, char *key)
{
	if(!root) return root;
	while(strcmp(root->name, key)){
		if(strcmp(root->name, key)<=0)
			root = root->right;
		else root = root->left;
		if(root==NULL) break;
	}
	return root;
}
