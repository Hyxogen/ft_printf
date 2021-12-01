#include "../include/ft_printf.h"
#include <stdio.h>
#include "utils/utils.h"
#include <limits.h>

/*
signed ints implementeren
unsigned ints implementeren
hex implementeren

000000000004294967295
num_len:8 prec_len:13 width_len:0
00000000000004294967295

checken met waardes van INT_MAX en INTMIN
If both the converted value and the precision are ​0​ the conversion results in no characters. 

printf("%d\n", printf("%*d\n", INT_MAX, 45)); Moet deze behaviour geimplementeerd worden?
*/
int main(void)
{
	   printf("%021p\n", (void*)UINT_MAX);
	ft_printf("%021p\n", (void*)UINT_MAX);
}
//-000000000000000000127
//000000000000000127