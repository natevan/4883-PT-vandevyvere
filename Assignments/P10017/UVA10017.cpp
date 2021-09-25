#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> A, B, C;
int m = 0;

void print(){
    if(!A.empty()){
        printf("A=>  ");
        for (int i = 0;i<A.size();i++){
            printf(" %d",A[i]);
        }
        cout<<endl;
    }
    else{
        printf("A=>\n");
    }
    if(!B.empty()){
        printf("B=>  ");
        for (int i = 0;i<B.size();i++){
            printf(" %d",B[i]);
        }
        cout<<endl;
    }
    else{
        printf("B=>\n");
    }
    if(!C.empty()){
        printf("C=>  ");
        for (int i = 0;i<C.size();i++){
            printf(" %d",C[i]);
        }
        cout<<endl;
    }
    else{
        printf("C=>\n");
    }
    cout<<endl;
}

void TOH (int n, vector<int> &from, vector<int> &to, vector<int> &aux){
    if (m == 0){return;}
    if (n == 1){
        to.push_back(from.back());
        from.pop_back();
        print();
        m--;
        return;
    }
    TOH(n-1,from,aux,to);
    if (m==0){return;}
    to.push_back(from.back());
    from.pop_back();
    print();
    m--;
    TOH(n-1,aux,to,from);
}
int main(){
    int n, p = 1;
    while(1){
        scanf("%d",&n);
        scanf("%d",&m);
        if (n == 0 && m == 0){
            return 0;
        }
        printf("Problem #%d\n\n",p);
        p++;
        for (int i = n; i>0; i--){
            A.push_back(i);
        }
        print();
        TOH(n,A,C,B);
        A.clear();
        B.clear();
        C.clear();
    }
}