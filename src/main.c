#include "../include/ft_printf.h"
#include <stdio.h>
#include "utils/utils.h"
#include <limits.h>

/*
signed ints implementeren
unsigned ints implementeren
hex implementeren

-00000000000000000127
-000000000000000000127

checken met waardes van INT_MAX en INTMIN
If both the converted value and the precision are ​0​ the conversion results in no characters. 

printf("%d\n", printf("%*d\n", INT_MAX, 45)); Moet deze behaviour geimplementeerd worden?
*/
int main(void)
{
	// put_ihex_fd(1, -127);
	// ft_printf("%x\n", -127);
	printf("%#X\n", -127);
}
//-000000000000000000127
//000000000000000127