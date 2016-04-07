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

* 文件读写函数效率排行:  
> `time ./read a.c b.c`  // 用time可以查看用户空间和内核空间运行时间
fread, fwrite  
fgets, fputs  
fgetc, fputc  
read, write  

* 静态库制作  
> `gcc -c sub.c`   // 生成 sub.o 文件  
> `ar -cr -o libsub.a sub.o`  // 生成 libsub.a 存档文件, ar 即 archives, 选项查看手册  
> `gcc -o build main.c -L. -lsub`  // -l 指定库名, -L 指定库的路径  
>    // -l 和 -L 参数区别 http://www.cnblogs.com/benio/archive/2010/10/25/1860394.html  

* 动态库制作
> `gcc -c -o sub.o sub.c`  // 生成 sub.o 目标文件  
> `gcc -shared -fpic -o libsub.so sub.o`  // -shared生成共享库,-fpic产生位置无关代码  
> `gcc -o build main.c -L. -lsub`  // 执行./build 报错, 可使用下面两种方式解决
>   // .so 所在路径加入到环境变量 export LD_LIBRARY_PATH=/home/weichen/sub:$LD_LIBRARY_PATH  
>	// .so 所在路径加入到 /etc/ld.so.conf 中, 运行 ldconfig /etc/ld.so.conf 生效

