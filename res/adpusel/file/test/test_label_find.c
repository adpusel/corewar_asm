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
t_dll_l *g_link_1;
t_dll_l *g_link_2;
t_dll_l *g_link_3;
t_dll_l *g_link_4;

t_label *label_1;
t_label *label_2;
t_label *label_3;
t_label *label_4;

char *label_name_1 = "label:";
char *label_name_2 = "super:";
char *label_name_3 = "manger:";
char *label_name_4 = "qwery:";

ssize_t address_1 = 42;
ssize_t address_2 = NO_ADDRESS;
ssize_t address_3 = 4242;
ssize_t address_4 = 578;

/*------------------------------------*\
    helper
\*------------------------------------*/
void init_list()
{
	int ret;
	ret = init_parseur(&parser);

	// init le deuxieme link
}

int print_list_test_label(t_dll_l *link, void *ptr)
{
	t_label *label;

	(void) ptr;
	label = link->content;

	printf(" --%s", label->name);
	return (FALSE);
}

int test_label(t_dll_l *li_1, t_dll_l *li_2)
{
	int ret;
	t_label *l1;
	t_label *l2;

	l1 = li_1->content;
	l2 = li_2->content;
	ret = li_1->content_size == g_link_1->content_size;
	if (ret)
		ret = STR_EQ(l1->name, l2->name);
	if (ret)
		ret = l1->address == l2->address;
	return (ret);
}

/*------------------------------------*\
    test
\*------------------------------------*/
static char *test_good_link()
{
	ret_1 = new_label_link(label_name_1, address_1, &g_link_1);
	ret_2 = new_label_link(label_name_2, address_2, &g_link_2);

	label_1 = g_link_1->content;
	label_2 = g_link_2->content;

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
	ret_3 = new_label_link(label_name_3, address_3, &g_link_3);
	ret_4 = new_label_link(label_name_4, address_4, &g_link_4);

	dll_add_at_index(g_link_1, parser.label_list, list->length);
	dll_add_at_index(g_link_2, parser.label_list, list->length);
	dll_add_at_index(g_link_3, parser.label_list, list->length);
	dll_add_at_index(g_link_4, parser.label_list, list->length);


	// test la recherche du link avec label existe
	ret_link_good_1 = dll_func_lim(list, search_label_in_dll, label_name_1, -1);
	ret_link_good_2 = dll_func_lim(list, search_label_in_dll, label_name_2, -1);
	ret_link_good_3 = dll_func_lim(list, search_label_in_dll, label_name_3, -1);
	ret_link_good_4 = dll_func_lim(list, search_label_in_dll, label_name_4, -1);
	ret_link_bad = dll_func_lim(list, search_label_in_dll, "fuck", -1);

	label_1 = ret_link_good_2->content;
	label_2 = g_link_2->content;
	TEST("error --> test_add_and_find_link -- 1",
		 LINK_EQ(ret_link_good_1, g_link_1) == OK
	);
	TEST("error --> test_add_and_find_link -- 2",
		 LINK_EQ(ret_link_good_2, g_link_2) == OK
	);
	TEST("error --> test_add_and_find_link -- 3",
		 LINK_EQ(ret_link_good_3, g_link_3) == OK
	);
	TEST("error --> test_add_and_find_link -- 4",
		 LINK_EQ(ret_link_good_4, g_link_4) == OK
	);

	TEST("error --> test_add_and_find_link 5",
		 LINK_EQ(ret_link_bad, g_link_4) == PTR_NULL &&
		 ret_link_bad == NULL
	);
	return (NULL);
}

// test si
static char *test_mode_create_1()
{
	t_dll *list = parser.label_list;
	t_dll_l *link_ret;
	t_dll_l *link_cmp;

	char *label_name_1 = "manger_carotte";

	// test label qui existe pas
	ret_1 = mode_create(label_name_1, address_1, list, &link_ret);
	new_label_link(label_name_1, address_1, &link_cmp);

	TEST("error --> test_mode_create -- 1",
		 LINK_FUNC_EQ(link_ret, link_cmp, test_label) == OK &&
		 ret_1 == TRUE);



	// test avec un label qui existe deja et a deja une address

	return (NULL);
}

static char *test_mode_create_2()
{
	t_dll *list = parser.label_list;
	t_dll_l *link_ret;
	t_dll_l *cmp_link;

	//test avec un label qui existe mais pas d'address
	ret_2 = mode_create(label_name_2, 4224, list, &link_ret);
	new_label_link(label_name_2, 4224, &cmp_link);

	TEST("error --> test_mode_create -- 2",
		 LINK_FUNC_EQ(link_ret, cmp_link, test_label) == OK &&
		 ret_2 == TRUE);
	return (NULL);
}

static char *test_mode_create_3()
{
	t_dll *list = parser.label_list;
	t_dll_l *link_ret;

	//le label existe deja et a une address
	ret_3 = mode_create(label_name_3, address_3, list, &link_ret);

	TEST("error --> test_mode_create -- 3",
		 ret_3 == FAIL);
	return (NULL);
}

static char *test_mode_find()
{
	t_dll *list = parser.label_list;
	t_dll_l *link_exist;
	t_dll_l *link_exist_pas;
	t_dll_l *link_test_exist;
	t_dll_l *link_test_exist_pas;

	int retour_1 = mode_find(label_name_1, list, &link_exist);
	new_label_link(label_name_1, address_1, &link_test_exist);

	int retour_2 = mode_find("exist_pas", list, &link_exist_pas);
	new_label_link("exist_pas", NO_ADDRESS, &link_test_exist_pas);

	TEST("error --> test_mode_find -- 1",
		 LINK_FUNC_EQ(link_exist, link_test_exist, test_label) == OK &&
		 retour_1 == TRUE);
	TEST("error --> test_mode_find -- 2",
		 LINK_FUNC_EQ(link_exist_pas, link_test_exist_pas, test_label) == OK &&
		 retour_2 == TRUE);
	return (NULL);
}

char *all_label_find_test()
{
	init_list( );

	mu_run_test(test_good_link);
	mu_run_test(test_add_and_find_link);
	mu_run_test(test_mode_create_1);
	mu_run_test(test_mode_create_2);
	mu_run_test(test_mode_create_3);
	mu_run_test(test_mode_find);
	return 0;
}