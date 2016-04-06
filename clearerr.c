#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ret;
	int ret2;

	fp = fopen("a.c", "w+");

	if (fp == NULL) {
		printf("open file a.c failure\n");
		return -1;
	}

	printf("open file a.c success\n");

	fputc('a', fp);
	
	ret = fgetc(fp);
	printf("ret = %c\n", ret); // 由于a写入之后, 指针在最后面, 此时读取, 打印出来的是非法字符, 

	rewind(fp);

	ret2 = fgetc(fp);
	printf("ret2 = %c\n", ret2); // ret2 = a

	ret2 = fgetc(fp);
	printf("ret2 = %d\n", ret2); // 读取的文件结尾EOF, ret2 = -1

	clearerr(fp);
	printf("feof is %d, ferror is %d\n", feof(fp), ferror(fp));

	fclose(fp);

	return 0;
}
