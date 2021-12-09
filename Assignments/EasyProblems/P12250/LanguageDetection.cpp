#include <iostream>
#include <string>
using namespace std;

int main(){
    string hi;
    int c=1;
        getline(cin,hi);
        while(hi != "#"){
            cout<<"Case "<<c++<<": ";
            if(hi=="HELLO"){
                cout<<"ENGLISH"<<endl;
            }
            else if(hi=="HOLA"){
                cout<<"SPANISH"<<endl;
            }
            else if(hi=="HALLO"){
                cout<<"GERMAN"<<endl;
            }
            else if(hi=="BONJOUR"){
                cout<<"FRENCH"<<endl;
            }
            else if(hi=="CIAO"){
                cout<<"ITALIAN"<<endl;
            }
            else if(hi=="ZDRAVSTVUJTE"){
                cout<<"RUSSIAN"<<endl;
            }
            else{
                cout<<"UNKNOWN"<<endl;
            }
            getline(cin,hi);
        }
}