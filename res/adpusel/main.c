#include <stdio.h>
#include "file/test/all_test.h"

int main()
{
	static char ok[5] = {COMMENT_CHAR, LABEL_CHAR};
	all_test();
	printf("%s \n",ok);
	return 0;
}