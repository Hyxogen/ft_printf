#include "../include/ft_printf.h"
#include <stdio.h>
#include "utils/utils.h"
#include <limits.h>

int main(void)
{
	
	printf("%.21d", -127);
	printf("\n-----\n");
	ft_printf("%.21d\n", -127);
	// printf("\n\n\n\n");
	// printf(TESTS_TWO_SPECIFIER_LORUM(".42c"), -127);
}
//-000000000000000000127
//000000000000000127