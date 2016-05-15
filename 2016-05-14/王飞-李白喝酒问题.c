/*
 “李白街上走，提壶去买酒，遇店加一倍，见花喝一斗”
 途中，遇见5次店，见了10此花，
 壶中原有2斗酒，最后刚好喝完酒，
 要求最后遇见的是花，求可能的情况有多少种？*/

#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int count = 0;
void counter(int shop, int flower, int drink) {
    if(shop == 5 && flower == 9 && drink == 1)
    {
        count++;
    }
    if(shop <5 && drink >0 )
    {
        counter(shop + 1, flower,drink * 2);
    }
    if(flower < 10 && drink > 1)
    {
        counter(shop, flower + 1, drink -1);
    }
}

int main(int argc, char** argv) {
    int shop = 0;
    int flower = 0;
    int drink = 2;
    counter(shop, flower, drink);
    printf("一共有%d种可能性\n",count);
    return 0;
}

//思路：用递归来实现，注意点：遇店加一倍！只有最后一次才可以把酒喝光，注意判断条件。

