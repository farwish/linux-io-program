#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * cp实现
 */
int main(int argc, char* argv[])
{
	int rd_fd, wr_fd; // 读文件描述符(源文件), 写文件描述符(目标文件)
	char read_buf[128] = {0}; // 用户空间缓存
	int rd_ret = 0; // 实际读的字节数(read函数返回值)

	// 如果参数个数小于3, 停止执行
	if (argc < 3) {
		printf("please input src file and des file\n");
		return -1;
	}

	// 打开源文件
	rd_fd = open(argv[1], O_RDONLY);

	if (rd_fd < 0) {
		printf("open src file %s failure\n", argv[1]);
		return -2;
	}

	printf("open src file %s success, rd_fd=%d\n", argv[1], rd_fd);

	// 打开目标文件
	wr_fd = open(argv[2], O_CREAT | O_RDWR, 0777);

	if (wr_fd < 0) {
		printf("open des file %s failure\n", argv[2]);
		return -3;
	}

	printf("open des file %s success, wr_fd=%d\n", argv[2], wr_fd);

	// 循环读写
	while(1) {
		// 把源文件读入缓存中,128个
		rd_ret = read(rd_fd, read_buf, 128);

		// 读完跳出循环
		if (rd_ret < 128) {
			break;
		}

		// 缓存写到目标文件
		write(wr_fd, read_buf, rd_ret);

		// 清空缓存
		memset(read_buf, 0, 128);
	}

	// 跳出后的最后一次写入
	write(wr_fd, read_buf, rd_ret);

	// 关闭文件
	close(rd_fd);
	close(wr_fd);

	return 0;
}
