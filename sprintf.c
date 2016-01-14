#include <stdio.h>

int main()
{
	int i = 10;
	char buf[128] = {0};

	sprintf(buf, "'i=%d'", i); // 把"i=10"写到buf中

	printf("buf=%s\n", buf);

	return 0;
}
