#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include "stringUtils.h"
#include "traceIf.h"
#include "stringUtils_tpt_provider.h"

using namespace CommonUtils::V1::StringUtils;

int main()
{
	std::cout << SSTR("a = ", 10, ", b = ", 1.25) << std::endl;

	fprintf(stdout, "%s\n", SSTR("a = ", 10, ", b = ", 1.25));
	fflush(stdout);

	TPT_TRACE(TRACE_ERROR, SSTR("a = ", 10, ", b = ", 1.25));

	return 0;
}