#include <stdlib.h>
#include <unistd.h>

void    ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

int    is_space(char c)
{
    return (c == 32 || c == '\t' || c == '\0');
}

int     count_words(char *s)
{
    int     count;
    int     index;

    index = 0;
    count = 0;
    while (s[index])
    {
        if (!is_space(s[index]))
        {
            count++;
            while (!is_space(s[index]))
                index++;
        }
        else
            index++;
    }
    return (count);
}

char    *wb_strdup(char *s)
{
    int     len;
    int     index;
    char    *word;

    len = 0;
    while (!is_space(s[len]))
        len++;
    word = malloc(len);
    if (!word)
        return (NULL);
    index = 0;
    while (index < len)
    {
        word[index] = s[index];
        index++;
    }
    return (word[index] = '\0', word);
}

char    **ft_split(char *s)
{
    int     index;
    int     size;
    char    **words;

    size = count_words(s) + 1;
    index = 0;
    words = malloc(sizeof(char *) * size);
    if (!words)
        return (NULL);
    while (*s)
    {
        if (!is_space(*s))
        {
            words[index] = wb_strdup(s);
            index++;
            while (!is_space(*s))
                s++;
        }
        else
            s++;
    }
    return (words[index] = NULL, words);
}

void    rev_wstr(char *str)
{
    int     words_counter;
    char    **words;

    words = ft_split(str);
    words_counter = count_words(str) - 1;
    while (words_counter >= 0)
    {
        ft_putstr(words[words_counter]);
        if (words_counter > 0)
            write(1, " ", 1);
        words_counter--;
    }
}

int main(int ac, char *av[])
{
    if (ac == 2)
        rev_wstr(av[1]);
    write(1, "\n", 1);
}
