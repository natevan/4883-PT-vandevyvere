#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int T;
  int v, e, a, b, gc;
  queue<int> q;
  int c [2];
  bool guard;

  cin >> T;
  for(int t = 0; t < T; t++){
    gc = 0;
    guard = true;
    cin >> v >> e;
    vector<vector<int> > s(v);
    vector<int> g(v, -1);

    for (int i = 0; i < e; i++){
      cin >> a >> b;
      s[a].push_back(b);
      s[b].push_back(a);
    }

    /* for (int i = 0; i<v;i++){
      cout << s[i][0]<<" ";
    } */

    for (int i = 0; i < v && guard == true; i++){
      c[0] = c[1] = 0;
      if (g[i] == -1){
        g[i] = 0;
        c[0]++;
        q.push(i);

        while(!q.empty()){
          a = q.front();
          q.pop();
          
          for(int j = 0; j < s[a].size(); j++){
            b = s[a][j];
            if (g[a] == g[b]){
              guard = false;
            }
            else if(g[b] == -1){
              if(g[a] == 0){
                g[b] = 1;
                c[1]++;
              }
              else{
                g[b] = 0;
                c[0]++;
              }
              q.push(b);
            }
          }
        }
        if (min(c[0], c[1]) == 0){
          gc++;
        }
        else{
          gc += min(c[0], c[1]);
        }
      }
    }

/*     for(int i = 0; i< g.size(); i++){
      cout << g[i]<< " ";
    }
    cout<<endl<<c[0]<<" "<<c[1]<<endl; */

    if (guard == true){
      cout<<gc<<endl;
    }
    else{
      cout << -1 << endl;
    }
      
  }
}
