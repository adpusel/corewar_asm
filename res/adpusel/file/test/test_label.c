#include "all_test.h"

/*------------------------------------*\
    lines
\*------------------------------------*/
char *line1;
char *line2;
char *line3;
char *line4;

/*------------------------------------*\
	char ret
\*------------------------------------*/
char *str_ret_1;
char *str_ret_2;
char *str_ret_3;
char *str_ret_4;

/*------------------------------------*\
    int ret
\*------------------------------------*/
int ret_1;
int ret_2;
int ret_3;
int ret_4;


/*------------------------------------*\
    parseur list
\*------------------------------------*/
t_parser parser;

void     init_list()
{
    init_parseur(&parser);
}

char *label = "label";
static char *return_good_label()
{
	line1 = "  label:";
	line2 = "  label:   ";
	line3 = "  label:adsf ";

	ret_1 = start_by_label(&line1, &str_ret_1);
	ret_2 = start_by_label(&line2, &str_ret_2);
	ret_3 = start_by_label(&line3, &str_ret_3);

	TEST("error --> label start good 1",
		 STR_EQ(str_ret_1, label) && ret_1 == TRUE);
	TEST("error --> label start good 2",
		 STR_EQ(str_ret_2, label) && ret_2 == TRUE);
	TEST("error --> label start good 3",
		 STR_EQ(str_ret_3, label) && ret_3 == TRUE);
	return 0;
}

static char *is_bad_label()
{
	line1 = "  label :";
	line2 = ":";
	line3 = "a  label:";
	line4 = "fork";

	ret_1 = start_by_label(&line1, &str_ret_1);
	ret_2 = start_by_label(&line2, &str_ret_2);
	ret_3 = start_by_label(&line3, &str_ret_3);
	ret_4 = start_by_label(&line4, &str_ret_4);

	TEST("error --> label start bad 1", STR_NULL(str_ret_1) && ret_1 == FALSE);
	TEST("error --> label start bad 2", STR_NULL(str_ret_2) && ret_2 == FALSE);
	TEST("error --> label start bad 3", STR_NULL(str_ret_3) && ret_3 == FALSE);
	TEST("error --> label start bad 4", STR_NULL(str_ret_4) && ret_4 == FALSE);

	return (NULL);
}

// j'ajoute mon link et je check qu'il soit bien avec les bonnes valeurs
static char *test_good_link()
{
	t_dll_l link_test;

	link_test =
	TEST("error --> label start bad", STR_NULL(str_ret_3));

	return (NULL);
}

char *all_label_test()
{
	mu_run_test(return_good_label);
	mu_run_test(is_bad_label);
	mu_run_test(test_good_link);
	return 0;
}