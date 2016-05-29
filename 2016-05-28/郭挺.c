#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1024
#define INF 0xeFFFFFFF

//定义边的结构
typedef struct Ele{
    int x,y;    //边的端点
    int w;      //边的权重
    bool inSet;
}Ele;

Ele * eles[MAXN];//对于n个顶点，最多有n*(n-1)条边

int m;//m条边

int pa[MAXN];
int r[MAXN];

void make_set(){
    int i;
    for(i=0;i<n;i++){
        pa[i] = i;
        r[i] = 1;
    }
}

int find_set(int x){
    if(x != pa[x]){
        pa[x] = find_set(x);
    }
    return pa[x];
}

bool unin_set(int x,int y){
    if(x==y) return;
    int xp = find_set(x);
    int yp = find_set(y);
    if(xp == yp) return false;//构成回路，不能合并
    if(r[xp]>r[yp]){
        pa[yp] = xp;//zhi小的放在zhi大的下面
    }
    else{
        pa[xp] = yp;
        if(r[xp] == r[yp]){
            r[yp]++;
        }
    }
    return true;
}

void sort(){
    int i,j;
    for(i=0;i<n-2;i++){
        int p = i;
        for(j = i+1;j<n-1;j++){
            if(eles[p].w > eles[j].w){
                p = j;
            }
        }
        if(p!=i){
            Ele * tmp = eles[i];eles[i] = eles[p];eles[p] = tmp;
        }
    }
}
/*
 int cmp(void * a,void * b){
 return (Ele*)a->w - (Ele*)b->w;
 }
 */
int klske(){
    //将边由小到大排序
    //qsort(eles,sizeof(eles),sizeof(eles[0]),cmp)
    sort();
    int res;
    for(int i=0;i<m;i++){
        if(unin_set(find_set(eles[i].x),find_set(eles[i].y))){
            printf("%d %d %d\n",else[i].x,eles[i].y,eles[i].w);
        }
    }
    return res;
}

int main(void){
    int i;
    scanf("%d",&m);
    //eles = (Ele*)malloc(n*sizeof(Ele));
    for(i=0;i<m-1;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        eles[i] = (Ele*)malloc(sizeof(Ele));
        eles[i]->x = x;
        eles[i]->y = y;
        eles[i]->w = w;
        eles[i]->inSet = false;
    }
    int res = klske(k);
    printf("%d\n",res);
    
    for(i=0;i<m-1;i++){
        free(eles[i]);
    }
    return 0;
}
