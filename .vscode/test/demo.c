/*
 * @Description: 在vscode上配置C和C++环境的demo
 * @Author: aLittleMango
 * @Date: 2021-07-01 21:21:32
 * @LastEditTime: 2021-07-08 19:33:53
 * @FilePath: \VSCode-C\.vscode\test\demo.c
 */

#include <stdio.h>

int main()
{
    printf("hello");
    
//这两句代码是清空输入缓冲区内容，等同于fflush(stdin);
    while(getchar()!='\n')  
    continue;
    getchar();

    return 0;
}

//头注释快捷键：ctrl+alt+i
//运行快捷键：ctrl+alt+n
