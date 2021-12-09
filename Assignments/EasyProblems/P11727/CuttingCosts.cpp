#include <iostream>

int main(){
    int t,temp;
    int s[3];
    scanf("%d",&t);
    for (int i = 1; i <= t; i++){
        scanf("%d%d%d",&s[0],&s[1],&s[2]);
        for(int n = 0;n<2;n++){
            for (int j = 0; j<2;j++){
                if (s[j]>s[j+1]){
                    temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
        printf("Case %d: %d\n",i,s[1]);
    }

}