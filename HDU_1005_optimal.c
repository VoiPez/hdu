#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define UNFOLD_LENGTH 100

/*
Header is not counted from index--0, It is very important and convenient!
*/

int overwrite_1005(int A, int B, int n) {
	int rotation[7][7];
	int values[UNFOLD_LENGTH];
	int i;
	int T;
	int head;

	memset(*rotation, 0, 49 * sizeof(int));

	values[1] = values[2] = 1;

	for (i = 3; i <= UNFOLD_LENGTH; ++i) {
		values[i] = values[i - 1] * A + values[i - 2] * B;
		values[i] %= 7;

		if (rotation[values[i-2]][values[i-1]])
			break;

		rotation[values[i - 2]][values[i - 1]] = i;
	}

	assert(i < 100);

	T = i - rotation[values[i - 2]][values[i - 1]];
	head = rotation[values[i - 2]][values[i - 1]] - 1;

	if (n > head) 
		return values[(n - head) % T + head];
	else
		return values[n];
}

int main(int argc, char const *argv[])
{
	int A, B, n;

	while(~scanf("%d %d %d", &A, &B, &n) && (A || B || n))
		printf("%d\n", overwrite_1005(A, B, n));

	return 0;
}
