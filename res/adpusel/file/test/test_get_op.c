#include "ft_asm_header.h"

static char *return_good_label()
{
	int p[3] = {REGISTRE, DIRECT, DIRECT};
	unsigned char res;

	res = get_op(p[0], p[1], p[2]);


//	TEST("error --> label start good 3",
//		 STR_EQ(str_ret_3, label) && ret_3 == TRUE);
	return NULL;
}

char *all_get_op_test()
{
	mu_run_test(return_good_label);
	return 0;
}