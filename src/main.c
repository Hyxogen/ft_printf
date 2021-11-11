#include <stdio.h>
#include "../include/ft_printf.h"

//void test(const char *format, t_format_info *formatInfo, ...)
//{
//	va_list	args;
//
//	va_start(args, formatInfo);
//	get_format_info(format, formatInfo, args);
//	va_end(args);
//}

int main(void)
{
//	t_format_info formatInfo;
//
//	test("-0#+ *.*c", &formatInfo, 999, 42);
////	get_format_info("-0#+ *.*c", &formatInfo);
//	print_format_info(&formatInfo);
	ft_printf("Hallo, dit is %% een %c\n", 'c');
}
