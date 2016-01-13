#include <stdio.h>

/*
 * fflush
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

	fflush(fp);

	while(1); // 如果buf没有换行符, 运行到这里, argv[1]文件依然没有内容

	fclose(fp);

	return 0;
}
