#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct point;

int c,n;
vector<point> points;

struct point{
  int x;
  int y;
  point(){
      x=0;
      y=0;
      }
  point(int x1, int y1){
      x = x1;
      y = y1;
  }
};

bool cmp(point &a, point &b){
    return a.x < b.x;
}

void printPoints(){
    for(int i=0;i<points.size();i++){
        cout<<"["<<points[i].x<<","<<points[i].y<<"] ";
  }
}

double slope (int index){
    return ((double)(points[index].y-points[index+1].y))/(double)(points[index].x-points[index+1].x);
}

double distance(int index,int py){
    double s,b,tempx;
    if (py == 0){
        return sqrt((pow(points[index].x-points[index+1].x,2)+(pow(points[index].y-points[index+1].y,2))));
    }
    s = slope(index);
    b = -1*(s*(double)points[index].x-(double)points[index].y);
    //printf("slope = %f + %f\n",s,b);
    tempx = ((double)py-b)/s;
    //printf("x = %f\n",tempx);
    return sqrt((pow(points[index].x-tempx,2)+(pow(points[index].y-py,2))));
}


int main() {
    int x,y;
    cin >> c;
    while(c--){
        int max = -1;
        int py = 0;
        double tdistance = 0;
        cin>>n;
        while(n--){
            cin >> x>> y;
            points.push_back(point(x,y));
        }
    sort(points.begin(),points.end(),cmp);
    for(int i = points.size()-2; i >= 0; i -= 2){
        if (points[i].y > max){
            max = points[i].y;
            tdistance += distance(i,py);
            py = points[i].y;
            //printf("prev y = %d\n",py);
        }
    }
    
    printf("%0.2f\n",tdistance);
    //printPoints(); // debug
    points.clear();
    //if(c>0){cout<<endl;}
  }

  
}