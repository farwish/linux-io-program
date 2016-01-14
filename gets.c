#include <stdio.h>
#include <string.h>

/*
 * gets(): 只能从标准输入读入, 不会读入\n
 */
int main()
{
	char buf[128] = {0};
	int len;

	//gets(buf); // 因为没有指定读入多少个, 所以有可能会越界; 编译的时候会有警告
	fgets(buf, 128, stdin); // 会将新行符(回车)存入缓存

	len = strlen(buf);

	//fputs(buf, stdout);
	puts(buf); // 输出时会添加一行新行符

	printf("len=%d\n", len);

	return 0;
}
