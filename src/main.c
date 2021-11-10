#include "format_info.h"
#include "debug_utils.h"
#include <stdio.h>

int main(void)
{
	t_format_info formatInfo;

	get_format_info("-0#+ 43.*c", &formatInfo);
	print_format_info(&formatInfo);
}