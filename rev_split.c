#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *s)
{
    while(*s != '\0')
        write(1, s++, 1);
}

int countwords(char *s)
{
	int counter = 0;
	int i = 0;
	if (!s)
		return 0;
	if (s[0] != ' ' || s[0] != '\n' || s[0] != '\t')
		counter++;
	i = 1;
	while(s[i] != '\0')
	{
		if((s[i-1] == ' ' || s[i-1] == '\n' || s[i-1] == '\t') && ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t')))
			counter++;
		i++;
	}
	return (counter);
}
int	ft_strlen(char *s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
char *substr_lite(char *s, int substrlen)
{
	char *substr = malloc(substrlen + 1);
	int i = 0;
	int j = 0;
	while (i < substrlen)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
    substr[j] = '\0';
	return (substr);
}

char *ft_strchr_lite(char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			return (&s[i]);
		i++;
	}
	return NULL;
}

char **ft_split(char *s)
{
	char **lst;
	int i = 0;
	int wordlen = 0;
    if (!s || !*s)
        return NULL;

	lst = (char **)malloc(sizeof(char *) * (countwords(s) + 1));
    if (!lst)
        return NULL;
	while (*s)
	{
		while(*s == ' ' || *s == '\n' || *s == '\t')
		{
			s++;
		}
		if (*s != '\0')
		{

			if (ft_strchr_lite(s))
				wordlen = ((ft_strchr_lite(s)) - s);
			else
				wordlen = ft_strlen(s);
			lst[i] = substr_lite(s, wordlen);
			i++;
            s = s + wordlen;
		}
		
	}
	lst[i] = NULL;
    char *sp;
    int last = i -1;
    int j = 0;
    while (j<=last)
    {
        sp = lst[j];
        lst[j] = lst[last];
        lst[last] = sp;
        j++;
        last--;         
    }
	return (lst);

}

int main(int argc, char **argv)
{
    char **result = ft_split(argv[1]);
    int i = 0;
    if (argc != 2)
    {
        return 0;
    }
    else
    {
        while(result[i] != NULL)
        {
            ft_putstr(result[i]);
            if(result[i+1] != NULL)
                write(1, " ", 1);
            i++;
        }
    }
    return 0;
}
