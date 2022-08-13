#include "main.h"

int main()
{
	int processors_num_alpha = get_processors_num_alpha();
	int processors_num_beta = get_processors_num_beta();
	printf("\n%d\n", processors_num_alpha);
	printf("\n%d\n", processors_num_beta);
	/*if (!(processors_num < 1))
	{
		printf ("This machine has %d processors\n", get_cpu_cores_beta());
	}*/
}
