#include <stdio.h>
#include <string.h>

int overLongAdd(char *addend, char *summand, char *result)
{
	int lenAddend = 0, lenSummand = 0, lenResult = 0;
	int i, cin = 0, maxlen;
	char *p = NULL;

	lenAddend = strlen(addend);
	lenSummand = strlen(summand);

	for (i = 0; i < lenSummand && i <lenAddend; ++i)
	{

		int temp = (addend[lenAddend - 1 - i] - '0' + summand[lenSummand - 1 - i] - '0' + cin);

		result[lenResult++] = temp % 10 + '0';
		cin = temp / 10;
	}

	if (i == lenSummand)
	{
		p = addend;
		maxlen = lenAddend;
	}
	else
	{
		p = summand;
		maxlen = lenSummand;
	}

	while (i < maxlen)
	{
		int temp = (p[maxlen - 1 - i] - '0' + cin);
		result[lenResult++] = temp % 10 + '0';
		cin = temp / 10;
		i++;
	}

	if (cin)
		result[lenResult++] = cin + '0';

	result[lenResult] = 0;

	return lenResult;

}

int main(int argc, int *argv[])
{
	char addend[1001];
	char summand[1001];
	char result[1001];
	int n, i;

	while (~scanf("%d", &n))
	{	
		i = 1;

		while (i <= n)
		{	
			if (i > 1)
				printf("\n");

			scanf("%s%s", addend, summand);
			int lenResult = overLongAdd(addend, summand, result);
			
			printf("Case %d:\n", i);
			printf("%s + %s = ", addend, summand);

			while (lenResult--)
				printf("%c", result[lenResult]);
			printf("\n");
			
			i++;
		}
	}

	return 0;
}