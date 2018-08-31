#include "all_test.h"

/*------------------------------------*\
	RET TAB
\*------------------------------------*/
int res[4] = { 0 };

t_dll *g_list;
t_dll_l *link_tab[4];
char *label_tab[4] = {
	"label:",
	"super:",
	"manger:",
	"qwery:"
};
int position_tab[4] =
	{ 42, NO_ADDRESS, 4545, 75 };

void init_test_list()
{
	new_dll(FALSE, &g_list);

	new_label_link(label_tab[0], position_tab[0], &link_tab[0]);
	new_label_link(label_tab[1], position_tab[1], &link_tab[1]);
	new_label_link(label_tab[2], position_tab[2], &link_tab[2]);
	new_label_link(label_tab[3], position_tab[3], &link_tab[3]);
	dll_add_at_index(link_tab[0], g_list, g_list->length);
	dll_add_at_index(link_tab[1], g_list, g_list->length);
	dll_add_at_index(link_tab[2], g_list, g_list->length);
	dll_add_at_index(link_tab[3], g_list, g_list->length);
}

static int test_label(t_label *l1, t_label *l2)
{
	int ret;
	ret = STR_EQ(l1->name, l2->name);
	if (ret)
		ret = l1->address == l2->address;
	return (ret);
}

// je dois check si j'ai --> bien mon label et qu'il match bien avec les autres link
static char *test_new_address()
{
	t_dll_l *address_link;
	t_label *label;
	t_label *label_to_link;
	int ret;
	char *name_label = "manger:";

	// il y a le label
	label = dll_func_lim(g_list, search_label_in_dll, name_label,
						 ALL_LIST)->content;
	label_to_link = link_tab[2]->content;
	ret = new_address_link(label, &address_link);
	TEST("error --> test_new_address -- 1",
		 test_label(label, label_to_link)== OK &&
		 ret == TRUE);

	// il y a PAS le label
	label = NULL;
	ret = new_address_link(label, &address_link);
	TEST("error --> test_new_address -- 2",
		 address_link == NULL &&
		 ret == PTR_NULL);

	return (NULL);
}

char *all_address_test()
{
	init_test_list();

	mu_run_test(test_new_address);
	//	mu_run_test(test_add_and_find_link);
	//	mu_run_test(test_mode_create_1);
	//	mu_run_test(test_mode_create_2);
	//	mu_run_test(test_mode_create_3);
	//	mu_run_test(test_mode_find);
	return 0;
}