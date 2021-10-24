#include <stdio.h>

int main() {
  long int B = 0, A = 0;
  while(scanf("%ld%ld",&A,&B)!=EOF){
    A-=B;
    if (A<0){A = ~A++;}
    printf("%ld\n",A);
}    
  return 0;
}
