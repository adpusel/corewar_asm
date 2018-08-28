#include "../includes/ft_asm_header.h"

// les liste que je vais manipuler
// comment je vais les manipurler
// il me faut des debug pour set les breakpoints tout ca tout ca


// TODO: test qui la recherche


// TODO: test l'ajout avec address

// TODO: test ajout sans address

// TODO: test probleme


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


/*------------------------------------*\
    link
\*------------------------------------*/
t_dll_l *link_1;
t_dll_l *link_2;
t_dll_l *link_3;

t_label *label_1;
t_label *label_2;
t_label *label_3;

char *label_name_1 = "label:";
char *label_name_2 = "bebel:";
char *label_name_3 = "bebel:";

size_t address_1 = 42;
size_t address_2 = 24;

void init_list()
{
	int ret;
	ret = init_parseur(&parser );

	// init le deuxieme link
}

static char *test_good_link()
{
	ret_1 = new_label_link(label_name_1, address_1, &link_1);
	label_1 = link_1->content;

	TEST("error --> test good link",
		 STR_EQ(label_1->name, label_name_1) &&
		 NB_EQ(label_1->address, address_1) &&
		 ret_1 == TRUE
	);
	return (NULL);
}

static char *test_ajout_and_find_link()
{
	char *label_name = "label:";
	size_t address = 42;

	t_dll_l *link_1;
	t_label *label_1;

	ret_1 = new_label_link(label_name, address, &link_1);
	label_1 = link_1->content;
	//	ret_2 = start_by_label(&line2, &str_ret_2);
	//	ret_3 = start_by_label(&line3, &str_ret_3);
	//	ret_4 = start_by_label(&line4, &str_ret_4);

	TEST("error --> test good link",
		 STR_EQ(label_1->name, label_name) &&
		 NB_EQ(label_1->address, address) &&
		 ret_1 == TRUE
	);
	return (NULL);
}

char *all_label_find_test()
{
	init_list();

	mu_run_test(test_good_link);
	mu_run_test(test_ajout_and_find_link);
	return 0;
}