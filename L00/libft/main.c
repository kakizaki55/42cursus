#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

static int	check_chars(char c1, char c2)
{
	if (c1 == c2)
			return (1);
	return (0);
}

int count_sub_strings(char *s, char c)
{
	int i;
	int count;
	int is_sub_string;

	is_sub_string = 0;
	count = 0;
	i = 0;
	while(check_chars(s[i], c))
		i++;
	while(s[i] != '\0')
	{
		if(check_chars(s[i], c))
		{
			if(is_sub_string)
				count ++;
			is_sub_string = 0;
		}
		else
		{
			is_sub_string = 1;
		}
		i++;
	}
	if(!check_chars(s[i], c) && count == 0)
		count = 1;
	return(count);
}

int main() {
   char str[] = "\0aa\0bbb";
    char c = '\0';
    char **result;

	int split_count = count_sub_strings(str, c);


    printf("length is %d\n", split_count);

    result = ft_split(str, c);
	if (result == NULL)
	{
		printf("fail\n");
		return 1;
	}

    for (int i = 0; i < split_count; i++) {
        printf("%s\n", result[i]);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < split_count ; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
