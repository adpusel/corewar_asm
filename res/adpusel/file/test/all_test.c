
#include "all_test.h"

int tests_run = 0;

int all_test()
{

	char *result = NULL;
	// TODO : reecrire les test de label
	// TODO : add test avec letrre dans Label char
//	result = all_label_test();
//	if (result == NULL)
		result = all_label_find_test();
	if (result == NULL)
		result = all_address_test();
	if (result == NULL)
		result = all_get_op_test();

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
