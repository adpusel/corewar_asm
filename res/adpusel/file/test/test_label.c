#include "all_test.h"

char *label = "label";

/*------------------------------------*\
    lines
\*------------------------------------*/
char *line1;

char *line2;

char *line3;

char *line4;

/*------------------------------------*\
    ret
\*------------------------------------*/
char *ret_1;

char *ret_2;

char *ret_3;

char *ret_4;

static char *return_good_label()
{
	line1 = "  label:";
	line2 = "  label:   ";
	line3 = "  label:adsf ";

	ret_1 = start_by_label(&line1);
	ret_2 = start_by_label(&line2);
	ret_3 = start_by_label(&line3);

	TEST("error --> label start good", STR_EQ(ret_1, label));
	TEST("error --> label start good", STR_EQ(ret_2, label));
	TEST("error --> label start good", STR_EQ(ret_3, label));
	return 0;
}

static char *is_bad_label()
{
	line1 = "  label :";
	line2 = ":";
	line3 = "a  label:";

	ret_1 = start_by_label(&line1);
	ret_2 = start_by_label(&line2);
	ret_3 = start_by_label(&line3);

	TEST("error --> label start bad", STR_NULL(ret_1));
	TEST("error --> label start bad", STR_NULL(ret_2));
	TEST("error --> label start bad", STR_NULL(ret_3));

	return (NULL);
}

char *all_label_test()
{
	mu_run_test(return_good_label);
	mu_run_test(is_bad_label);
	return 0;
}