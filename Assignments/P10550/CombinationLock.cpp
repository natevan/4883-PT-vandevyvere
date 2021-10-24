#include <iostream>

int main(){
    int lock[4];
    int sum;
    while(1){
        sum = 720;
        scanf("%d%d%d%d",&lock[0],&lock[1],&lock[2],&lock[3]);
        if(lock[0] == 0 && lock[1] == 0 && lock[2] == 0 && lock[3] == 0){break;}
        // printf("%d %d %d %d",lock[0],lock[1],lock[2],lock[3]);

        if (lock[1]>lock[0]){
            sum+= (40 - lock[1] + lock[0])*9;
        }
        else{
            sum+=(lock[0]-lock[1])*9;
        }
        sum+=360;
        if (lock[1]>lock[2]){
            sum+= (40 - lock[1] + lock[2])*9;
        }
        else{
            sum+=(lock[2]-lock[1])*9;
        }
        if (lock[3]>lock[2]){
            sum+= (40 - lock[3] + lock[2])*9;
        }
        else{
            sum+=(lock[2]-lock[3])*9;
        }
        printf("%d\n",sum);

    }
}