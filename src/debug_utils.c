#include <stdio.h>
#include "debug_utils.h"

void
	print_format_info(t_format_info *formatInfo)
{
	printf("Flags: %x\n", formatInfo->m_Flags);
	printf("Fill zeroes: %d\n", formatInfo->m_FillZeroes);
	printf("Variable width: %d\n", formatInfo->m_VariableWidth);
	printf("Width: %d\n", formatInfo->m_Width);
	printf("Variable precision: %d\n", formatInfo->m_VariablePrecision);
	printf("Precision: %d\n", formatInfo->m_Precision);
	printf("Size: %d\n", formatInfo->m_Size);
	printf("Type: %d\n", formatInfo->m_Type);
	printf("\n");
	printf("FLAG_MINUS: %d\n", formatInfo->m_Flags & FLAG_MASK_MINUS);
	printf("FLAG_PLUS: %d\n", formatInfo->m_Flags & FLAG_MASK_PLUS);
	printf("FLAG_ZERO: %d\n", formatInfo->m_Flags & FLAG_MASK_ZERO);
	printf("FLAG_BLANK: %d\n", formatInfo->m_Flags & FLAG_MASK_BLANK);
	printf("FLAG_SHARP: %d\n", formatInfo->m_Flags & FLAG_MASK_SHARP);
}