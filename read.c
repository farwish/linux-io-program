#include <stdio.h>
#include <unistd.h> // C/C++语言中提供对POSIX操作系统API的访问功能的头文件的名称
#include <fcntl.h> // 操作文件描述符, 使用man fcntl 查看手册用法: http://man7.org/linux/man-pages/man2/fcntl.2.html

int main(int argc, char* argv[])
{
	int fd, wr_ret, rd_ret;
	char buf[] = "linux";
	char read_buf[120] = {0};

	fd = open("./a.c", O_RDWR | O_TRUNC); // 打开文件,如果有内容时删除

	if (fd < 0) {
		printf("open file ./a.c failure\n");
		return -1;
	}
	printf("open file ./a.c success, fd=%d\n", fd);

	wr_ret = write(fd, buf, sizeof(buf));
	printf("wr_ret=%d\n", wr_ret);

	// 开始读
	rd_ret = read(fd, read_buf, 128); // 此时是从写入的文件末尾开始读,所以没有内容,需要重新定位
	printf("read_buf=%d\n", rd_ret);

	close(fd);

	return 0;
}
