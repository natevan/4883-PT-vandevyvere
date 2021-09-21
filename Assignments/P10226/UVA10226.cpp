#include <iostream>
#include <string>
#include <stdio.h>
#include <map>

using namespace std;

int main() {
  int T;
  
  string name;
  cin>>T;
  getline(cin,name);
  getline(cin,name);
  while(T>0){
    map<string,float> trees;
    float total=0;
    while(getline(cin,name) && name!=""){
      trees[name]++;
      total++;
    }
    for(auto i = trees.begin();i!=trees.end();i++){
      i->second = (i->second / total)*100;
    }

    for(auto i = trees.begin();i!=trees.end();i++){
      printf("%s %0.4f\n",i->first.c_str(),i->second);
    }
    T--;
    if(T>0){cout<<endl;}
  }
  
}
