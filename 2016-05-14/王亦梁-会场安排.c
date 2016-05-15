#include <stdio.h>

struct metting {
    int start;
    int end;
    int flag;
}Mee[5];


int main(){
    Mee[0].start =1;
    Mee[1].start =12;
    Mee[2].start =25;
    Mee[3].start =27;
    Mee[4].start =36;
    
    Mee[0].end =23;
    Mee[1].end =28;
    Mee[2].end=35;
    Mee[3].end =80;
    Mee[4].end =50;
    
    for (int i =0; i<5; i++) {
        Mee[i].flag =0;
    }
    
    int n = 4;
    int k =n;
    int num = 0;
    while (k>0) {
        int time = -1 ;
        if (num ==0) {
            Mee[0].flag=1;
            time =Mee[0].end;
            num++;
            k--;
            
            for (int i=0 ; i< n; i++) {
                if (Mee[i].start >time && Mee[i].flag ==0) {
                    Mee[i].flag =1;
                    time =Mee[i].end;
                    k--;
                }
            }
        }
        
        else{
            for (int i =0; i <n; i++) {
                if (Mee[i].flag ==0 && Mee[i].start >time) {
                    Mee[i].flag =1;
                    time =  Mee[i].end;
                    num++;
                    k--;
                }
            }
        }
    }
    printf("%d",num);
    
    printf("\n");
    
    return 0;
}
