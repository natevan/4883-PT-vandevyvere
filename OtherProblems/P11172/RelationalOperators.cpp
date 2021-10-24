#include <iostream>

int main(){
    long int a,b;
    int c;
    scanf("%d",&c);
    for(;c>0;c--){
        scanf("%ld%ld",&a,&b);
        if (a>b){
            printf(">\n");
        }
        else if (a<b){
            printf("<\n");
        }
        else{
            printf("=\n");
        }
    }

}