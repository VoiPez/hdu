#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 16

typedef int (*CMPSTR)(const char *src, const char *dest);

int quick_sort(char (*colors)[16], int begin, int end, CMPSTR cmpstr) {
	int i = begin, j = end;
	char temp[MAX_COLOR_LENGTH] = {0};

	if (i >= j)
		return 0;

	strcpy(temp, colors[i]);

	while (i < j) {
		while (cmpstr(colors[j], temp) >= 0 && i < j)
			--j;

		strcpy(colors[i], colors[j]);

		while (cmpstr(colors[i], temp) <= 0 && i < j)
			++i;

		strcpy(colors[j], colors[i]);
	}

	strcpy(colors[i], temp);

	quick_sort(colors, begin, i - 1, cmpstr);
	quick_sort(colors, i + 1, end, cmpstr);

	return 0;
}

char *most_popular_problem(char (*colors)[16], int n)
{
	int most_color_cnt = 1, cur_color_cnt = 1, i;
	char *most_color_index = colors[0];
	char *cur_color_index = colors[0];

	for (i = 1; i < n; ++i) {
		if (strcmp(cur_color_index, colors[i]) == 0) {
			cur_color_cnt ++;
		}
		else {
			if (cur_color_cnt > most_color_cnt) {
				most_color_index = cur_color_index;
				most_color_cnt = cur_color_cnt;
			}

			cur_color_cnt = 1;
			cur_color_index = colors[i];
		}
	}

	if (cur_color_cnt > most_color_cnt) {
		most_color_index = cur_color_index;
		most_color_cnt = cur_color_cnt;
	}

	return most_color_index;
}

int main(int argc, char const *argv[]) {
	int count = 0;
	char colors[1000][16];

	int i;

	while (~scanf("%d", &count) && count) {
		for (i = 0; i < count; ++i)
			scanf("%s", colors[i]);

		quick_sort(colors, 0, count - 1, strcmp);

		printf("%s\n", most_popular_problem(colors, count));
	}

	return 0;
}