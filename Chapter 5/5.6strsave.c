#include "5.4strlen.c"

char *strsave(s)	/* save string s somewhere */
char *s;
{
	char *p, *alloc();

	if ((p = alloc(strlen(s) + 1)) != NULL)
		strcpy(p, s);
	return(p);
}