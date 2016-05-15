//题目：
//键盘输入一个的正整数ｎ，
//去掉任意ｓ个数字后剩下的数字按原左右次序将组成一个新的正整数。
//编程对给定的ｎ和ｓ，寻找一种方案，使得剩下的数最小。

#include <stdio.h>

int main() {
    
    int num ,k;
    printf("please input number:\n");
    scanf("%d",&num);
    getchar();
    printf("input k:\n");
    scanf("%d",&k);
    getchar();
    // printf("%d\n", num);
    
    int x[8],a = num, count = 0;
    while(1){
        if (a == 0)
            break;
        
        x[count] = a % 10;
        a = a / 10;
        count++;
    }
    int i = count - 1;
    // printf("%d\n",count);
    while(1){
        
        if (x[i] > x[i-1]) {
            for (int j = i ; j >= 0 ; j--) {
                x[j] = x[j-1];
            }
            i = count - 1;
        }
        else{
            i--;
        }
        
        if (x[k-1] == 0) {
            break;
        }
    }
    
    // for (int i = 0 ; i < count; i++) {
    //     printf("~%d",x[i]);
    // }
    // printf("\n");
    
    for (int j = count - 1 ; j >= k ; j --) {
        printf("%d" ,x[j]);
    }
    printf("\n");
    
    getchar();
    return 0;
}


