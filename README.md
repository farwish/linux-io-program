### linux io program
===
* touch命令实现: open和close函数（touch.c）

* read, write, lseek函数（read.c, write.c, lseek.c）

* cp命令实现: 组合使用open,read,write,close 及条件判断（cp.c）

* 标准IO - fopen和fclose（touch_fopen.c）

* 标准IO - fgets和fputs（fgets.c, fputs.c）

* 标准IO - fflush,无缓存,fseek（fflush.c, fseek.c）

* 标准IO - gets,puts,fprintf,sprintf（gets.c）

* 标准IO - fgetc,fputc（fgetc.c, fputc.c）

* 标准IO - feof, ferror, clearerr ( feof_ferror.c, clearerr.c )

* cat命令实现: 组合使用fgetc, feof, fputc (cat.c)

> 查看函数原型和头文件 使用man fopen / man 3 fopen
