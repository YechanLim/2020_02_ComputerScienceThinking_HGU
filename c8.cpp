#include <bits/stdc++.h> 
#include<cmath>

using namespace std; 

enum State{
    notHavingWell,
    makingWell,
    HavingWell,
};

struct Village{
    int x;
    int y;  
    enum State state = notHavingWell;
};

int main(){
    int n, d;
    int wellNum = 0;
    struct Village villages[10000];
    cin >> n >> d;
    for(int i = 0; i< n ; i++)
        cin>> villages[i].x >> villages[i].y;
    
    typedef pair<double,int> x_range;
    priority_queue<x_range, vector<x_range>, greater<x_range> > x_ranges;

    double l_x, r_x;

    for(int i = 0; i<n ; i++){
        l_x = (double) villages[i].x - sqrt( pow(d,2) - pow(villages[i].y,2)) ; 
        x_ranges.push(make_pair(l_x,i));
        
        r_x = (double) villages[i].x + sqrt(pow(d,2) - pow(villages[i].y,2)) ;
        x_ranges.push(make_pair(r_x,i));
    }

    vector<int> makingWellVills;

    while(!x_ranges.empty()){
        int villNum = x_ranges.top().second;
        double x_range = x_ranges.top().first;
        x_ranges.pop();
  
        if(villages[villNum].state == notHavingWell){
            villages[villNum].state = makingWell;
            makingWellVills.push_back(villNum);
        }

        else if(villages[villNum].state == makingWell){
        wellNum ++;

        while(1){
        int next_villNum = x_ranges.top().second;
        double next_x_range = x_ranges.top().first;
        if(next_x_range == x_range && villages[next_villNum].state == notHavingWell){
            villages[next_villNum].state = HavingWell;
            x_ranges.pop();     
        }
        else 
        break;
        }
            while(!makingWellVills.empty()){
                   int a = makingWellVills[makingWellVills.size() -1];
                   villages[a].state = HavingWell;
                   makingWellVills.pop_back();
            }
        }
    }
 cout << wellNum;

}