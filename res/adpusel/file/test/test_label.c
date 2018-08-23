#include "all_test.h"

char *label = "label";

static char *return_good_label()
{
	char *line = "label:";
	char *ret;

	ret = start_by_label(&line);

	TEST("error --> get label", STR_EQ(ret, label));
	printf("%s \n", ret);
	return 0;
}

static char *test_bar()
{
	return (NULL);
}

char *all_label_test()
{
	mu_run_test(return_good_label);
	mu_run_test(test_bar);
	return 0;
}