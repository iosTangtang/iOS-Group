//
//  main.c
//  Triangle
//
//  Created by Tangtang on 16/4/27.
//  Copyright © 2016年 Tangtang. All rights reserved.
//
//  问题描述
//  从顶点开始,每个数字向下层走只能有左下和右下两个方向,求出到达最后一行时最大的路径之和.
//
//  Input
//  第1 行是数字三角形的行数n，1<= n <=100。
//  接下来n行是数字三角形各行中的数字。所有数字在0---99之间。
//  比如Input是：
//  5
//  7
//  3 8
//  8 1 0
//  2 7 4 4
//  4 5 2 6 5
//  则output是30
//
//

#include <stdio.h>
#define MAXSIZE 1000
int S[MAXSIZE + 1][MAXSIZE + 1];

int ResultMax(int n);

int main(int argc, const char * argv[]) {
    
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 1; i < n + 1; i++) {
        for (j = 1; j < i + 1; j++) {
            scanf("%d", &S[i][j]);
        }
    }
    
    printf("The Max is %d\n", ResultMax(n));
    
    return 0;
}

int ResultMax(int n) {
    int resultMax[MAXSIZE + 1][MAXSIZE + 1];
    int i, j;
    
    //给resultMax赋上最后一行数据
    for (i = 1; i < n + 1; i++) {
        resultMax[n][i] = S[n][i];
    }
    
    //从底部开始计算
    for (i = n; i > 1; i--) {
        for (j = 1; j < i; j++) {
            if (resultMax[i][j] > resultMax[i][j + 1]) {
                resultMax[i - 1][j] = resultMax[i][j] + S[i - 1][j];
            } else {
                resultMax[i - 1][j] = resultMax[i][j + 1] + S[i - 1][j];
            }
        }
    }
    
    
    return resultMax[1][1];
}
