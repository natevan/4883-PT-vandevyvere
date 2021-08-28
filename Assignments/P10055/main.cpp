/**
* Nathan Van De Vyvere
* 4883 Programming Techniques
* 08/31/2021
*
* Hashmat the Brave - 10055
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    long int B = 0, A = 0;
    
    while (cin >> A >> B) {

        B-=A;

        if (B<0){
          B*=-1;
        }

        cout << B << endl;


    }
    return 0;
}
