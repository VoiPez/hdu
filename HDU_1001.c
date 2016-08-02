#include <stdio.h>

/*sum = (n + 1) * n / 2*/
int main (int argc, int *argv[])
{
	int n, sum = 0;
	int flag = 0;

	while (~scanf("%d", &n))
	{
		if (n > 1)
		{
			if (n % 2 == 0)
				sum = n / 2 * (1 + n);
			else
				sum = (n + 1) / 2 * n;
		}
		else
			sum = n;

		printf("%d\n", sum);
		printf("\n");
	}

	return 0;
}