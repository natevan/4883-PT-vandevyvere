#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string word;

int main()
{
    int T, Case = 1;
    cin >> T;
    cin.ignore();
    while (T > 0)
    {
        getline(cin, word);
        for (int i = 0; i < word.length(); i++)
        {
            if (int(word[i]) < 97 || int(word[i]) > 122)
            {
                word.erase(i, 1);
                i--;
            }
        }

        if (int(sqrt(word.length())) == float(sqrt(word.length())))
        {

            // cout<<word<<endl;

            bool pal = true;
            string::reverse_iterator j = word.rbegin();
            for (int i = 0; i < word.length() / 2; i++)
            {
                if (word[i] != *j)
                {
                    pal = false;
                }
                j++;
            }
            printf("Case #%d:\n", Case);
            if (pal == true)
            {
                cout << sqrt(word.length()) << endl;
            }
            else
            {
                cout << "No magic :(" << endl;
            }
        }
        else
        {
            printf("Case #%d:\n", Case);
            cout << "No magic :(" << endl;
        }
        T--;
        Case++;
    }
}