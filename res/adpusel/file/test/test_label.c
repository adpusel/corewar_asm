#include "../includes/all_test.h"

int foo = 9;

int bar = 4;

static char *test_foo()
{
	TEST("error --> foo != 7", foo == 9);
	return 0;
}

static char *test_bar()
{
	TEST("error --> bar != 5", bar == 4);
	return 0;
}

char *all_label_test()
{
	mu_run_test(test_foo);
	mu_run_test(test_bar);
	return 0;
}