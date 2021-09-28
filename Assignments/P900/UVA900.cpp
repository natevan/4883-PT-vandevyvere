#include <iostream>

using namespace std;

const unsigned int INPUT_SIZE = 50;
unsigned long int A[INPUT_SIZE];

int main(){
    A[0] = 1;
    A[1] = 2;
    for (int i = 2;i < INPUT_SIZE;i++){
        A[i] = A[i-1] + A[i-2];
    }
    int wall;
    while(cin >> wall){
        if (wall == 0){return 0;}
        cout<<A[wall-1]<<endl;
    }
}