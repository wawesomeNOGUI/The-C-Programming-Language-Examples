strlen(s) /* return length of string s */
char *s;
{
	char *p = s;

	while (*p != '\0')
		p++;
	return(p - s);
}