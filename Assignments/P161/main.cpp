//Nathan Van De Vyvere
//CMPS 4883 Programming Techniques
//Sep 7,2021

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  vector<int> lights(100);
  int a = 1;
  int i = 100000;
  int x = 0;
  bool green = false;
  int end = 0; //counts 0's

  while(cin>>a && end<3){
    if(a!=0){
      end=0;
      if(a<i){i=a;}
      lights[x] = a;
      x++;
    }
    else{
      end++;
      
      if(end<2){
        while(i<=18000){
            for(int j=0;j<x;j++){
              if (i % (lights[j]*2) <lights[j]-5){
                green = true;
                //cout<<"test1";
              }
              else{
                green = false;
                break;
              }
            }
            if (green){
              int hours = i/3600;
              i%=3600;
              int min = i/60;
              i%=60;
              cout<<setfill('0')<<setw(2)<<hours<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<i<<endl;
              i=20000;
            }
            else{
              i++;
              //cout<<"test3";
            }

        }
        if (i>18000 && i<20000){
          cout<<"Signals fail to synchronise in 5 hours"<<endl;
        }
        else{
          
        }
        
        lights.clear();
        x=0;
      }
    }
  }
}
