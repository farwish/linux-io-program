#include <stdio.h>
#include <unistd.h> // C/C++语言中提供对POSIX操作系统API的访问功能的头文件的名称
#include <fcntl.h> // 操作文件描述符, 使用man fcntl 查看手册用法: http://man7.org/linux/man-pages/man2/fcntl.2.html

/**
 * touch命令实现
 */
int main(int argc, char* argv[])
{
	int fd;	// 文件描述符

	fd = open(argv[1], O_CREAT | O_RDWR, 0777); // 具体 man open

	/*
	open函数创建文件时的权限是: node & (~umask)
	使用umask查看, 假设当前umask为0022, 设置权限0777, 则最终权限是755
		111 111 111
	  &	000 010 010
		111 101 101

	umask 0000 ,则不使用掩码;
	*/
	

	if (fd < 0) {
		printf("create file %s failure\n", argv[1]);
		return -1;
	}

	printf("create file %s success, fd=%d\n", argv[1], fd);

	close(fd);

	return 0;
}
