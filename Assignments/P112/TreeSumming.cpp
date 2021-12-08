#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> q;
string list;
int ans;
bool out;


void sum_tree(){
    int sum = 0;
    for (int i = 0; i < q.size(); i++){
        sum += q[i];
    }
    // cout<<"sum = "<<sum<<endl;
    if (sum == ans){out = true;}
}

void read_tree(){
    int par = 0;
    list = "";
    char c;
    do{
        cin >> c;
        if (c!=' ' || c!='\n'){
            if (c == '('){par++;}
            else if(c == ')'){par--;}
            list.push_back(c);
        }
    }while (par);
}
void process_tree(){
    int s = 0;
    string temp;
    bool sign;
    for (int i = 0; i < list.size(); i++){
        if (list[i] == '('){
            i++;
            if (list[i]==')'){
                if (!q.empty()){
                    s++;
                    if (s == 2){sum_tree();}
                }
            }
            else{
                s = 0;
                temp = "";
                sign = true;
                while(list[i] != '('){
                    if (list[i] == '-'){
                        sign = false;
                    }
                    else{
                        temp.push_back(list[i]);
                    }
                    i++;
                }
                i--;
                if (!sign){q.push_back(stoi(temp)*-1);}
                else{q.push_back(stoi(temp));}
            }
        }
        else if(list[i] == ')'){
            q.pop_back();
        }
    }
}

int main(){
    while(cin>>ans){
        read_tree();
        out = false;
        // cout<<list<<endl;
        process_tree();
        if (out){cout<<"yes"<<endl;}
        else{cout<<"no"<<endl;}
    }

}