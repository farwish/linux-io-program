#include <stdio.h>

// fread 是全缓存
int main()
{
	FILE *fp;
	char buf[] = "hello\n";
	char readbuf[128] = {0};

	fp = fopen("./a.c", "w+");

	if (fp == NULL) {
		printf("open file a.c failure\n");
		return -1;
	}

	fwrite(buf, sizeof(char), sizeof(buf), fp);

	rewind(fp);
	fread(readbuf, sizeof(char), sizeof(readbuf), fp);

	printf("readbuf is %s", readbuf);

	fclose(fp);
	return 0;
}
