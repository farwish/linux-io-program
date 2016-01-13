#include <stdio.h>

/*
 * fseek
 */
int main(int argc, char* argv[])
{
	FILE* fp;
	char buf[] = "hello\n";
	char readbuf[128] = {0};

	fp = fopen(argv[1], "w+");

	if (fp == NULL) {
		printf("open file %s failure\n", argv[1]);
		return -1;
	}
	printf("open file a.c success\n");

	fputs(buf, fp);

	// 指针头指向开头
	fseek(fp, 0, SEEK_SET);
	// rewind(fp, 0, SEEK_SET); // 功能和fseek一样

	fgets(readbuf, 128, fp); // 最终没有写到readbuf中

	printf("readbuf: %s\n", readbuf);

	fclose(fp);

	return 0;
}
