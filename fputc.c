#include <stdio.h>

/**
 * fputc
 */
int main(int argc, char *argv[])
{
	FILE *fp;

	fp = fopen("./a.c", "w+");
	if (fp == NULL) {
		printf("open file a.c failure\n");
		return -1;
	}

	printf("open file a.c success\n");

	fputc('a', fp);
	//fputc('\n', fp);
	while(1); // a不能写入文件, 证明fputc不是行缓存函数; 如果在之前用fflush(fp), 则a会写入,证明有缓存

	fclose(fp);

	return 0;
}
