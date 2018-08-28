
#include "../includes/ft_asm_header.h"

t_debug g_debug;

int main_debug()
{
	ft_memset(&g_debug, 0, sizeof(t_debug));
	g_debug.show_label = TRUE;
	return (TRUE);
}