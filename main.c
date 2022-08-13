#include <stdio.h>

int get_processors_num(void);

int main()
{
	int processors_num = get_processors_num();
	if (!(processors_num < 1))
	{
		printf("%d\n", processors_num);
	}
	return EOF;
}
