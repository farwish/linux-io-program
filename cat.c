#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ret;

	if (argv[1] == NULL) {
		printf("please input src file\n");
		return -1;
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL) {
		printf("open file %s failure\n", argv[1]);
		return -2;
	}
	
	while (1) {

		ret = fgetc(fp); // 放在feof判断前, 否则输出结尾出现乱码

		if (feof(fp)) {
			break;
		}

		fputc(ret, stdout);
	}

	fclose(fp);

	return 0;
}
