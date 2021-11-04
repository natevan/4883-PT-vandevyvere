#include <iostream>
#include <vector>

using namespace std;

#define GROUP_SIZE 100000 

int main(){
    int T,N,type,height,max,group,sum;
    vector <int> price;
    max = 0;
    scanf("%d",&T);
    for(int i = 1; i<=T;i++){
        vector<int> G(GROUP_SIZE,0);
        group = 1;
        scanf("%d",&N);
        for(;N>0;N--){
            scanf("%d%d",&type,&height);
            // printf("type = %d, height = %d\n",type,height);
            if (G[type] != group){
                G[type] = group;
            }
            else{
                price.push_back(max);
                group++;
                G[type] = group;
                max = height;
            }
            if (height>max)max = height;
            // printf("type = %d, height = %d, max = %d, group = %d ",type,height,max,group);
            // printf("array = %d\n",G[type]);
        }
        price.push_back(max);
        sum = max = 0;
        for(int j = 0; j < price.size(); j++){
            sum += price[j];
            // printf("max = %d\n",price[j]);
        }
        printf("Case %d: %d\n",i,sum);
        price.clear();

    }
}