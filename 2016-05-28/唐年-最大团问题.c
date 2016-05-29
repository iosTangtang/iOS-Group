//本周算法—最大团问题
//1.问题描述
//团就是最大完全子图。
//给定无向图G=(V,E)。如果U V，且对任意u，v U 有(u，v)   E，则称U 是G 的完全子图。
//G 的完全子图U是G的团当且仅当U不包含在G 的更大的完全子图中，即U就是最大完全子图。
//G 的最大团是指G中所含顶点数最多的团。
//例如：
//
//(a)                                        (b)                             (c)                            (d)
//图a是一个无向图，图b、c、d都是图a的团，且都是最大团。
//2.思路分析
//首先设最大团为一个空团，往其中加入一个顶点，然后依次考虑每个顶点，查看该顶点加入团之后仍然构成一个团，如果可以，考虑将该顶点加入团或者舍弃两种情况，如果不行，直接舍弃，然后递归判断下一顶点。对于无连接或者直接舍弃两种情况，在递归前，可采用剪枝策略来避免无效搜索。
//为了判断当前顶点加入团之后是否仍是一个团，只需要考虑该顶点和团中顶点是否都有连接。
//程序中采用了一个比较简单的剪枝策略，即如果剩余未考虑的顶点数加上团中顶点数不大于当前解的顶点数，可停止继续深度搜索，否则继续深度递归
//当搜索到一个叶结点时，即可停止搜索，此时更新最优解和最优值。
//可以用子集树表示问题的解空间。设当前扩展节点Z位于解空间树的第i层。在进入左子树前，必须确认从顶点i到已入选的顶点集中每一个顶点都有边相连。在进入右子树之前，必须确认还有足够多的可选择顶点使得算法有可能在右子树中找到更大的团。
//附上代码：
//
//  main.c
//  MaxClique
//
//  Created by Tangtang on 16/5/25.
//  Copyright © 2016年 Tangtang. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 100

/**
 * 定义邻接矩阵的结构体
 * @param vexData:  用来记录顶点数据的数组
 * @param arcs: 用来记录边的数据
 * @param vexNumbers:   顶点总数
 * @param arcNumbers:   边总数
 */
typedef struct Graph {
    char    vexData[MAXSIZE];
    int     arcs[MAXSIZE][MAXSIZE];
    int     vexNumbers;
    int     arcNumbers;
}Graph;

/**
 * 创建邻接矩阵的方法
 * @param G: 传入的需要创建的无向图变量
 */
void CreateDG(Graph *G);

/**
 * 获取顶点下标的方法
 * @param G: 传入的需要创建的无向图变量
 * @param v: 需要知道下标的顶点
 * @return 返回下标值
 */
int GetVex(Graph *G, char v);

/**
 * 输出无向图的方法
 * @param G: 传入的需要创建的无向图变量
 */
void OutPutDG(Graph G);

void backTrack(int i, int n, Graph G);

int MaxClique(Graph G, int n);

int x[MAXSIZE];
int bestx[MAXSIZE];
int bestn;
int cn;

int main(int argc, const char * argv[]) {
    
    Graph G;
    int i;
    CreateDG(&G);
    OutPutDG(G);
    
    printf("\n最大团的顶点数：%d\n", MaxClique(G, G.vexNumbers));
    
    for (i = 1; i <= G.vexNumbers; i++) {
        printf("%d ",bestx[i]);
    }
    
    printf("\n");
    
    return 0;
}

#pragma mark - 邻接矩阵操作方法
void CreateDG(Graph *G) {
    int i, j;
    int row, cols;
    char v1, v2;
    
    //输入总顶点数和总边数
    printf("请输入总顶点数和总边数：");
    scanf("%d %d", &G->vexNumbers, &G->arcNumbers);
    while (getchar() != '\n');
    
    //输入具体的顶点信息
    printf("请输入每个顶点:\n");
    for (i = 0; i < G->vexNumbers; i++) {
        scanf("%c", &G->vexData[i]);
    }
    
    for (i = 0; i < G->vexNumbers; i++) {
        for (j = 0; j < G->vexNumbers; j++) {
            G->arcs[i][j] = 0;
        }
    }
    
    //输入顶点之间的关系，也就是边
    printf("请输入每条边\n");
    for (i = 0; i < G->arcNumbers; i++) {
        printf("请输入第%d条边", i);
        while (getchar() != '\n');
        scanf("%c %c", &v1, &v2);
        row = GetVex(G, v1);
        cols = GetVex(G, v2);
        if (row != -1 && cols != -1) {
            G->arcs[row][cols] = 1;
            G->arcs[cols][row] = 1;
        }
    }
}

int GetVex(Graph *G, char v) {
    int i;
    for (i = 0; i < G->vexNumbers; i++) {
        if (v == G->vexData[i]) {
            return i;
        }
    }
    return -1;
}

void OutPutDG(Graph G) {
    int i,j;
    for (i = 0; i < G.vexNumbers; i++) {
        printf("\t%c", G.vexData[i]);
    }
    for (i = 0; i < G.vexNumbers; i++) {
        printf("\n%c\t", G.vexData[i]);
        for (j = 0; j < G.vexNumbers; j++) {
            printf("%d\t", G.arcs[i][j]);
        }
    }
}

void backTrack(int i, int n, Graph G) {
    int j;
    if (i > n) {
        for (j = 1; j <= n; j++) {
            bestx[j] = x[j];
            bestn = cn;
        }
        printf("\n");
        return;
    }
    int  OK = 1;
    for (j = 1; j < i; j++) {
        if (x[j] && G.arcs[i-1][j-1] == 0) {
            OK = 0;
            break;
        }
    }
    if (OK) {
        x[i] = 1;
        cn++;
        backTrack(i + 1, n, G);
        x[i] = 0;
        cn--;
    }
    if (cn + n - i > bestn) {
        x[i] = 0;
        backTrack(i + 1, n, G);
    }
}

int MaxClique(Graph G, int n) {
    cn = 0;
    bestn = 0;
    backTrack(1, n, G);
    return bestn;
}
