#include "all_test.h"

int foo = 9;

int bar = 4;

static char *return_good_label()
{
	char *line = "lala:";
	char *ret;

	ret = start_by_label(&line);

	TEST("error if not same label", ft_strcmp(ret, line));
	return 0;
}

static char *test_bar()
{
	TEST("error --> bar != 5", bar == 4);
	return 0;
}

char *all_label_test()
{
	mu_run_test(return_good_label);
	mu_run_test(test_bar);
	return 0;
}