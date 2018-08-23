
#include "all_test.h"

int tests_run = 0;

int all_test()
{

	char *result = test_label();

	if (result != 0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
