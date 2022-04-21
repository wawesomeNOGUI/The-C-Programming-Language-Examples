strcpy(s, t)	/* copy t to s; pointer version 3 */
char *s, *t;
{
	while (*s++ = *t++)
		;
}

strcmp(s, t)	/* return <0 if s<t, 0 if s==t, >0 if s>t */
char *s, *t;
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return(0);
	return(*s - *t);
}