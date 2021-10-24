#include <iostream>
#include <vector>

using namespace std;

int main(){
    int C,N;
    float avg,x;
    scanf("%d",&C);
    for (;C>0;C--){
        avg = x = 0;
        scanf("%d",&N);
        vector<float> grade(N);
        for (int i = 0;i<N;i++){
            scanf("%f",&grade[i]);
            avg += grade[i];
        }
        avg /= N;
        for(int i = 0; i < N; i++){
            if (grade[i] > avg){
                x++;
            }
        }
        x /= (float)N;
        printf("%.3f%%\n",x*100);


    }

}