#include <stdio.h>
#include "include/transpiler.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		return -1;
	}
	else if (argc > 2)
	{
		printf("%s\n", transpiler_init(argv[1]));
		return 0;
	}
	transpiler_init(argv[1]);
	transpiler_run();
	return 0;
}