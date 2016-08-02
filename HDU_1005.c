#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int start = 1, end = 0;
int unfold_func_to_array(int array[100], int A, int B)
{
	int i, j;

	array[1] = 1, array[2] = 1;
	for (i = 3; i <= 100; i++) {
		array[i] = (A * array[i - 1] + B * array[i - 2]) % 7;

		for (j = 2; j <= i - 1; ++j)
			if (array[j - 1] == array[i - 1] && array[j] == array[i]) {
				start = j - 1;
				end = i - 2;
				return 0;
			}
	}

	return 1;
}

int main(int argc, char const *argv[])
{
	int A, B, n, index;
	int unfold_func[100];
	int i;

	while (~scanf("%d %d %d", &A, &B, &n) && (A || B || n)) {
		int temp; 

		unfold_func_to_array(unfold_func, A, B);

		if (n <= end)
			index = n;
		else {
			/*At the begin, I wrote temp = n % (end - start + 1). It costs my 2 hours to check it.*/
			temp = (n - start + 1) % (end - start + 1);

			if (temp == 0)
				index = end;
			else
				index = start - 1 + temp;
		}

		printf("%d\n", unfold_func(index));
	}

	return 0;
}
