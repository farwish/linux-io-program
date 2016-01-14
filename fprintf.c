#include <stdio.h>

int main()
{
	FILE* fp;
	int i = 10;

	fp = fopen("./a.c", "w+");

	if (fp == NULL) {
		printf("open a.c failure\n");
		return -1;
	}

	fprintf(fp, "open a.c success, i=%d", i); // 输出到文件中
	//fprintf(stdout, "open a.c success, i=%d", i); // 输出到显示器

	fclose(fp);

	return 0;
}
