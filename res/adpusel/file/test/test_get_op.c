#include "ft_asm_header.h"

static char *test_res()
{
	int p[3] = { REGISTRE, DIRECT, DIRECT };
	int p1[3] = { REGISTRE, DIRECT, REGISTRE };
	int p2[3] = { INDIRECT, 0, 0 };
	unsigned char res_1;
	unsigned char res_2;
	unsigned char res_3;

	res_1 = get_op(p[0], p[1], p[2]);
	res_2 = get_op(p1[0], p1[1], p1[2]);
	res_3 = get_op(p2[0], p2[1], p2[2]);

	TEST("error --> get_op_test 1",
		 res_1 == 0x68);
	TEST("error --> get_op_test 2",
		 res_2 == 0x64);
	TEST("error --> get_op_test 3",
		 res_3 == 0xC0);
	return NULL;
}

char *all_get_op_test()
{
	mu_run_test(test_res);
	return 0;
}