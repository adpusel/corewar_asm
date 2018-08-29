#include "../includes/ft_asm_header.h"

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
	TEST("error --> test good link 1",
		 STR_EQ(label_1->name, label_name_1) &&
		 NB_EQ(label_1->address, address_1) &&
		 ret_1 == TRUE
	);
	TEST("error --> test good link 2",
		 STR_EQ(label_2->name, label_name_2) &&
		 NB_EQ(label_2->address, address_2) &&
		 ret_2 == TRUE
	);
	return (NULL);
}

int print_list_test_label(t_dll_l *link, void *ptr)
{
	t_label *label;

	(void) ptr;
	label = link->content;

	printf(" -- %s", label->name);
	return (FALSE);
}

// test si
// --> j'ajoute
// --> find
static char *test_add_and_find_link()
{
	t_dll *list;
	t_dll_l *ret_link_good_1;
	t_dll_l *ret_link_good_2;
	t_dll_l *ret_link_good_3;
	t_dll_l *ret_link_good_4;
	t_dll_l *ret_link_bad;

	list = parser.label_list;
	(void) list;
	ret_3 = new_label_link(label_name_3, address_3, &link_3);
	ret_4 = new_label_link(label_name_4, address_4, &link_4);

	dll_add_at_index(link_1, parser.label_list, list->length);
	dll_add_at_index(link_2, parser.label_list, list->length);
	dll_add_at_index(link_3, parser.label_list, list->length);
	dll_add_at_index(link_4, parser.label_list, list->length);


	// test la recherche du link avec label existe
	ret_link_good_1 = dll_func_lim(list, search_label_in_dll, label_name_1, -1);
	ret_link_good_2 = dll_func_lim(list, search_label_in_dll, label_name_2, -1);
	ret_link_good_3 = dll_func_lim(list, search_label_in_dll, label_name_3, -1);
	ret_link_good_4 = dll_func_lim(list, search_label_in_dll, label_name_4, -1);
	ret_link_bad = dll_func_lim(list, search_label_in_dll, "fuck", -1);

	label_1 = ret_link_good_2->content;
	label_2 = link_2->content;
	TEST("error --> test_add_and_find_link -- 1",
		 LINK_EQ(ret_link_good_1, link_1) == OK
	);
	TEST("error --> test_add_and_find_link -- 2",
		 LINK_EQ(ret_link_good_2, link_2) == OK
	);
	TEST("error --> test_add_and_find_link -- 3",
		 LINK_EQ(ret_link_good_3, link_3) == OK
	);
	TEST("error --> test_add_and_find_link -- 4",
		 LINK_EQ(ret_link_good_4, link_4) == OK
	);

	TEST("error --> test_add_and_find_link 5",
		 LINK_EQ(ret_link_bad, link_4) == PTR_NULL &&
		 ret_link_bad == NULL
	);
	return (NULL);
}

static char *test_mode_create()
{
	t_dll *list;
	t_dll_l *ret_link_good_1;
	//	t_dll_l *ret_link_good_2;
	//	t_dll_l *ret_link_good_3;
	//	t_dll_l *ret_link_good_4;
	//	t_dll_l *ret_link_bad;

	list = parser.label_list;
	(void) list;
	char *label_name_1 = "mager_carotte";

	// test label qui existe pas
	TEST("error --> test_mode_create -- 1",
		 LINK_EQ(ret_link_good_1, link_1) == OK
	);

	//test avec un label qui existe mais pas d'address

	// test avec un label qui existe deja et a deja une address

	return (NULL);
}

// la fonction de recherche prends l'address du link et retourn ok s'il
// est --> inexistant ==> create link || with or not address
// si existe mais n'as pas d'address --> update ?

char *all_label_find_test()
{
	init_list();

	mu_run_test(test_good_link);
	mu_run_test(test_add_and_find_link);
	mu_run_test(test_mode_create);
	return 0;
}