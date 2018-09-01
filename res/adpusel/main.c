#include <stdio.h>
#include <string.h>
#include "file/test/all_test.h"

// faire str_chr_char
// str_find_first_char
// je retourne la premiere fois que je trouve l'occurence d'un de mes char

char *str_find_first_char(char *str, char *char_researched)
{
	if (str == NULL)
	    return (NULL);
	while (*str)
	{
	    if (check_char_into_str(char_researched, *str) == TRUE)
			return(str);
	    ++str;
	}
	return (NULL);
}


int main()
{

	char *sup = "123456";
	char *ret = str_find_first_char(sup, "6");
	printf("%ld \n", ret - sup);
	printf("%c \n",*(sup + (ret - sup) ));


	return 0;
}