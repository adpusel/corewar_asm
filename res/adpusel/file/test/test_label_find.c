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
t_dll_l *link_4;

t_label *label_1;
t_label *label_2;
t_label *label_3;
t_label *label_4;

char *label_name_1 = "label:";
char *label_name_2 = "super:";
char *label_name_3 = "manger:";
char *label_name_4 = "qwery:";

ssize_t address_1 = 42;
ssize_t address_2 = -1;
ssize_t address_3 = 4242;
ssize_t address_4 = 578;

void init_list()
{
	int ret;
	ret = init_parseur(&parser);

	// init le deuxieme link
}

static char *test_good_link()
{
	ret_1 = new_label_link(label_name_1, address_1, &link_1);
	ret_2 = new_label_link(label_name_2, -1, &link_2);

	label_1 = link_1->content;
	label_2 = link_2->content;

	//	printf("%s \n", label_1->name);
	//	printf("%lu \n", label_1->address);
	TEST("error --> test good link",
		 STR_EQ(label_1->name, label_name_1) &&
		 NB_EQ(label_1->address, address_1) &&
		 ret_1 == TRUE
	);
	TEST("error --> test good link",
		 STR_EQ(label_2->name, label_name_2) &&
		 NB_EQ(label_2->address, address_2) &&
		 ret_2 == TRUE
	);
	return (NULL);
}

// test si
// --> j'ajoute
// --> find
// --> update
// il ma ajoute le label s'il n'existe pas,
// l'update s'il y besion,
// return err si label existe deja, ok sinon
// 1 --> fonction de recherche de label ==> un ok et un pas ok
static char *test_ajout_and_find_link()
{
	t_dll *list;
	t_dll_l *ret_link_1;

	list = parser.label_list;
	(void) list;
	ret_3 = new_label_link(label_name_3, address_3, &link_3);
	ret_4 = new_label_link(label_name_4, address_4, &link_4);

	dll_add_at_index(link_1, parser.label_list, 0);
	dll_add_at_index(link_2, parser.label_list, 0);
	dll_add_at_index(link_3, parser.label_list, 0);


	// test la recherche du link avec label existe
	ret_link_1 = dll_func_lim(list, search_label_in_dll,label_name_4, -1);
	label_1 = ret_link_1->content;
	printf("%s \n",label_1->name);

	//	dll_add_at_index(link_4, parser.label_list, 0);

	return (NULL);
}

char *all_label_find_test()
{
	init_list();

	mu_run_test(test_good_link);
	mu_run_test(test_ajout_and_find_link);
	return 0;
}