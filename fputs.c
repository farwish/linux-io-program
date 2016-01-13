#include <stdio.h>

/*
 * fputs
 */
int main(int argc, char* argv[])
{
	FILE* fp;
	char buf[] = "hello\n";
	fp = fopen(argv[1], "w+");

	if (fp == NULL) {
		printf("open file %s failure\n", argv[1]);
		return -1;
	}
	printf("open file a.c success\n");

	fputs(buf, fp);

	fclose(fp);

	return 0;
}
