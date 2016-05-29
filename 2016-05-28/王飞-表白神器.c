//
//  main.m
//  表白神器
//
//  Created by iOS-aFei on 16/5/28.
//  Copyright © 2016年 iOS-aFei. All rights reserved.
//

#include <stdlib.h>
int main(void) {
    int c = 30063, b = 2032166262, a = 1869357129;
    printf("%s\n",(char *)&a);
    return 0;
}
//打印一下结果：
//I love you
//Program ended with exit code: 0
//
//为啥呢？？？
/*
 30063 ＝ 01110101（u） 01101111（o）
 2032166262 ＝ 01111001（y） 00100000 01100101（e） 01110110（v）
 1869357129 ＝  01101111（o） 01101100（l） 00100000（数据链路层的转义字符） 01001001（I）
 */
//至于顺序的问题，百度一下大小端存储就OK了！

