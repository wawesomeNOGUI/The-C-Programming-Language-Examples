#include "stdio.h"
#include "../Chapter 4/4.5GetchUngetch.c"
#include "../Chapter 5/5.4AllocFree.c"


#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'

type(c)		/* return type of ASCII character */
int c;
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return(LETTER)
	else if (c >= '0' && c <= '9')
		return(DIGIT);
	else
		return(c);
}

getword(w, lim)		/* get next word from input */
char *w;
int lim;
{
	int c, t;

	if (type(c = *w++ = getch()) != LETTER) {
		*w = '\0';
		return(c);
	}
	while (--lim > 0) {
		t = type(c = *w++ = getch());
		if (t != LETTER && t != DIGIT) {
			ungetch(c);
			break;
		}
	}
	*(w-1) = '\0';
	return(LETTER);
}

struct tnode {      /* the basic node */
	char *word;     /* points to the text */
	int count;      /* number of occurences */
	struct tnode* left;		/* left child */
	struct tnode* right;	/* right child */
};

struct tnode *talloc()
{
	char *alloc();

	return((struct tnode *) alloc(sizeof(struct tnode)));
}

struct tnode *tree(p, w) /* install w at or below p */
struct tnode *p;
char *w;
{
	struct tnode *talloc();
	char *strsave();
	int cond;

	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strsave(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;     /* repeated word */
	else if (cond < 0)	/* lower goes into left subtree */
		p->left = tree(p->left, w);
	else          /* greater into right subtree */
		p->right = tree(p->right, w);
	return(p);
}

treeprint(p)	/* print tree p recursively */
struct tnode *p;
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

main() {	/* word frequency count */
	struct tnode *root, *tree();
	char word[MAXWORD];
	int	t;

	root = NULL;
	while ((t = getword(word, MAXWORD)) != EOF)
		if (t == LETTER)
			root = tree(root, word);
	treeprint(root);
}