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

		if (feof(fp)) {
			break;
		}

		ret = fgetc(fp);

		fputc(ret, stdout);
	}

	fclose(fp);

	return 0;
}
