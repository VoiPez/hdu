#include <stdio.h>

/*max sum of subsequence*/

int main(int argc, char *argv[])
{
	int cases, array[100000];
	int begin, end;
	int sum, i, j, temp, max;


	while (~scanf("%d", &cases))
	{
		temp = 1;
		while (temp <= cases)
		{
			scanf("%d", array);

			for (i = 1; i <= array[0]; i++)
				scanf("%d", array + i);

			j = i = 1;
			begin = end  = 1;
			max = array[1];
			sum = 0;
			while (i <= array[0])
			{	
				sum += array[i];

				if (sum > max)
				{
					max = sum;
					begin = j;
					end = i;
				}

				if (sum < 0)
				{
					j = i + 1;
					sum = 0;
				}

				++i;
			}

			if (temp > 1)
				printf("\n");

			printf("Case %d:\n", temp);
			printf("%d %d %d\n", max, begin, end);

			temp++;
		}
	}

	return 0;
}