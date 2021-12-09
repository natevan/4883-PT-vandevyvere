#include <iostream>

int main (){
    int tri [3];
    int temp;
    while(1){
        scanf("%d%d%d",&tri[0],&tri[1],&tri[2]);
        // printf("%d %d %d\n",tri[0],tri[1],tri[2]); //debug
        if (tri[0]==0 && tri[1]==0 && tri[2]==0){break;}
        for(int n = 0;n<2;n++){
            for (int i = 0; i<2;i++){
                if (tri[i]>tri[i+1]){
                    temp = tri[i];
                    tri[i] = tri[i+1];
                    tri[i+1] = temp;
                }
            }
        }
        if(tri[0]*tri[0] + tri[1]*tri[1] == tri[2]*tri[2]){
            printf("right\n");
        }
        else {printf("wrong\n");}
    }
}