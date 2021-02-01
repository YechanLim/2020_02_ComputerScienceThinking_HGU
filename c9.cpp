#include <bits/stdc++.h> 
using namespace std;

struct PersonInfo {
    int x;
    int y;
    bool isGrouped;
};

struct PersonInfo p[8001];

void groupMemCheckAndAdd(int n, int x, int y,vector<int> &groupMem ){
      for(int i = 0; i<n ; i++){
                if(p[i].isGrouped)
                    continue;
                if( (x > p[i].x && y < p[i].y) || (x < p[i].x && y > p[i].y)){
                    p[i].isGrouped = true;
                    groupMem.push_back(i);
            }
            }    
            }


int main(){
    int n;
    int x,y;
    int groupNum = 0;
    vector<int> groupMem;
    int checkedMemNum = 0;  
    cin >> n;

    for(int i = 0; i< n ; i++)
        cin >> p[i].x >> p[i].y;

    for(int i = 0; i<n ; i++){
        if(p[i].isGrouped)
            continue;
            
            groupNum++;
            p[i].isGrouped = true;
            x = p[i].x;  y = p[i].y;
            groupMemCheckAndAdd(n,x,y,groupMem);
            
            while(checkedMemNum < groupMem.size()){
            x = p[groupMem[checkedMemNum]].x;   y = p[groupMem[checkedMemNum]].y;
            groupMemCheckAndAdd(n,x,y,groupMem);
            checkedMemNum++;
            }
        }
    
    cout << groupNum;
}