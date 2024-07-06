#include "mathif_ut_tpt_provider.h"
#include "mathif.h"
#include "traceIf.h"


int add(int a, int b)
{
	int tmp = a + b;
	TPT_TRACE(TRACE_INFO, "Add %d and %d equal to %d", a, b, tmp);
	return tmp;
}

int sub(int a, int b)
{
	int tmp = a - b;
	TPT_TRACE(TRACE_DEBUG, "Sub %d and %d equal to %d", a, b, tmp);
	return tmp;
}

int mul(int a, int b)
{
	int tmp = a * b;
	TPT_TRACE(TRACE_ABN, "Mul %d and %d equal to %d", a, b, tmp);
	return tmp;
}

int div(int a, int b)
{
	if(b == 0)
	{
		TPT_TRACE(TRACE_ERROR, "Divide by zero detected!");
		return -1;
	}

	int tmp = a / b;
	TPT_TRACE(TRACE_INFO, "Div %d and %d equal to %d", a, b, tmp);
	return tmp;
}
