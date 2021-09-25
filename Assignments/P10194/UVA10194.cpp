#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include<algorithm>

using namespace std;

void compare(int i, int j, vector<int> &rank, const vector<vector<int> > &stat, const vector<string> Teams){
  vector<string>TeamsTB(Teams);
  for(int i=0; i<TeamsTB.size();i++){
    transform(TeamsTB[i].begin(),TeamsTB[i].end(),TeamsTB[i].begin(), ::tolower);
  }
  if(i!=j && rank[i]==rank[j]){
          //win tiebreaker
          if(stat[i][2]==stat[j][2]){
            //goal diff tiebreaker
            if(stat[i][5]-stat[i][6]==stat[j][5]-stat[j][6]){
              //goals for tiebreaker
              if(stat[i][5]==stat[j][5]){
                //games played tiebreaker
                if(stat[i][0]==stat[j][0]){
                  //lexigraphic tiebreaker
                  //transform(Teams[i].begin(),Teams[i].end(),tb[0].begin(), ::tolower);
                  //transform(Teams[i].begin(),Teams[j].end(),tb[1].begin(), ::tolower);
                  if(TeamsTB[i].compare(TeamsTB[j])<0){
                    rank[j]++;
                  }
                  else{
                    rank[i]++;
                  }
                }
                //games played tb
                else{
                  if(stat[i][0]>stat[j][0]){
                    rank[i]++;
                  }
                  else{
                    rank[j]++;
                  }
                }
              }
              //goals for tb
              else{
                if(stat[i][5]<stat[j][5]){
                  rank[i]++;
                }
                else{
                  rank[j]++;
                }
              }
            }
            //goal diff tb
            else{
              if(stat[i][5]-stat[i][6]<stat[j][5]-stat[j][6]){
                rank[i]++;
              }
              else{
                rank[j]++;
              }
            }
          }
          //win tb
          else{
            if(stat[i][2]<stat[j][2]){
              rank[i]++;
            }
            else{
              rank[j]++;
            }
          }
        }
}

void stdCompare(int i,int temp, vector<int> &rank,vector<int> &standing,const vector<vector<int> > &stat, const vector<string> Teams){
  if(standing[rank[i]]==-1){
      standing[rank[i]]=i;
    }
  else{
    temp=standing[rank[i]];
    compare(temp,i,rank,stat,Teams);
    if(rank[i]<rank[temp]){
      standing[rank[i]]=i;
      for(int j=rank[temp];j<standing.size();j++){
        if(standing[j]!=-1){
          compare(standing[j],temp,rank,stat,Teams);
          if(rank[standing[j]]>rank[temp]){
            int move = standing[j];
            standing[j] = temp;
            temp = move; 
          }
        }
        else{
          standing[j]=temp;
          break;
        }
      }
    }
    else{
      for(int j=rank[i];j<standing.size();j++){
        if(standing[j]!=-1){
          compare(standing[j],i,rank,stat,Teams);
          if(rank[standing[j]]>rank[i]){
            int move = standing[j];
            standing[j] = i;
            i = move; 
          }

        }
        else{
          standing[j]=i;
          break;
        }
      }
    }
    
  }    
}

int main() {
  int N,T,G,fH,fA,mid,h,a,gH,gA;
  //vector<string> tb(2,"");
  string tournament, team, game, home, away;
  cin>>N;
  getline(cin,tournament);

  while(N>0){
    getline(cin,tournament);
    cout<<tournament<<endl;
    cin>>T;
    getline(cin,team);
    vector<string> Teams;
    vector<vector<int> > stat(T, vector<int>(7,0));
    
    while(T>0){
      getline(cin, team);
      Teams.push_back(team);
      T--;
    }
    cin>>G;
    getline(cin,game);
    
    while(G>0){
      getline(cin,game);
      fH = game.find("#",0);
      mid = game.find("@",fH);
      home = game.substr(0,fH);
      fA = game.rfind("#");
      away = game.substr(fA+1,-1);
      for(int i=0;i<Teams.size();i++){
        if(home == Teams[i]){
          h=i;
        }
        else if(away == Teams[i]){
          a=i;
        }
      }
      gH = stoi(game.substr(fH+1,mid));
      gA = stoi(game.substr(mid+1,fA));
      // games played
      stat[h][0]+=1;
      stat[a][0]+=1;
      //goals for
      stat[h][5]+=gH;
      stat[a][5]+=gA;
      //goals against
      stat[a][6]+=gH;
      stat[h][6]+=gA;
      if (gH > gA){
        stat[h][1]+=3;
        stat[h][2]++;
        stat[a][3]++;
      }
      else if (gA > gH){
        stat[a][1]+=3;
        stat[a][2]++;
        stat[h][3]++;
      }
      else{
        stat[h][4]++;
        stat[a][4]++;
        stat[h][1]++;
        stat[a][1]++;
      }
      G--;
    }

    vector<int> standing(Teams.size()+1,-1);
    vector<int> rank(Teams.size());
    for (int i=0;i<Teams.size();i++){
      int r=1;
      for(int j=0;j<Teams.size();j++){
        if(stat[j][1]>stat[i][1]){
          r++;
        }
      }
      rank[i]=r;
    }


    for(int i=0;i<rank.size();i++){
      for(int j=0;j<rank.size();j++){
        compare(i,j,rank,stat,Teams);
      }
    }

    int temp;
    for(int i=0;i<rank.size();i++){
        stdCompare(i,temp,rank,standing,stat,Teams);
    }

/*
    for(int i =0;i<rank.size();i++){
      cout<<rank[i]<<" ";
    }
    cout<<endl;
    for(int i =0;i<standing.size();i++){
      cout<<standing[i]<<" ";
    }
*/
    for (int i=1;i<standing.size();i++){
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,Teams[standing[i]].c_str(),stat[standing[i]][1],stat[standing[i]][0],stat[standing[i]][2],stat[standing[i]][4],stat[standing[i]][3], stat[standing[i]][5]-stat[standing[i]][6], stat[standing[i]][5],stat[standing[i]][6]);
    }


    N--;
    if(N>0){
      cout<<endl;
    }
  }
}

// 0 - Games Played
// 1 - Points
// 2 - Wins
// 3 - Losses
// 4 - Ties
// 5 - Goals for
// 6 - Goals Against
