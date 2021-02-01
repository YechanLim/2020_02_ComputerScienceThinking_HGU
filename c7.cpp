#include <bits/stdc++.h> 
using namespace std; 

int visitedCheck[10002];
int parent[10002];
vector <int> graph[10002];
bool result;
int graph_[100002][2];
int result_num;

bool CheckPowerOfTwo( int nNum )
{
   int nResult = nNum & (nNum-1);
   if( nResult == 0 )
      return true;
      
   else
      return false;
}

void CycleCheck(int beginNode, int endNode){
    if(visitedCheck[endNode] == 2)
        return;

    if(visitedCheck[endNode] == 1){
        int temp = beginNode;
        int count = 0;
        while(temp != endNode){
            temp = parent[temp];
            count++;
        }
        if( (count % 2) == 0)
            result = true;
        return;
    }

    parent[endNode] = beginNode;
    visitedCheck[endNode] = 1;

    for(int v : graph[endNode]){
        if(v == parent[endNode])
            continue;   
        CycleCheck(endNode,v);    
    }
        visitedCheck[endNode] = 2;
}

void bsearch(int left, int right, int n){
    result = false;
    int mid = (left + right)/2;  
    for(int i = mid + 1; i<right + 1; i++){
        graph[graph_[i][0]].pop_back();
        graph[graph_[i][1]].pop_back();
    }

    while(left <= right){
    mid = (left + right)/2; 
    
     for(int j = 0; j<n + 1; j++){
            visitedCheck[j] = 0;
            parent[j] = 0;
        }
    
        for(int j = 1; j<n + 1; j++){
            if(visitedCheck[j] == 0){
                CycleCheck(0,j);
            }
        }

    if(result == true){
        right = mid -1;
        result_num = mid;
        result = false;
        mid = (left + right)/2;
           for(int i = mid + 1; i<right + 2; i++){
        graph[graph_[i][0]].pop_back();
        graph[graph_[i][1]].pop_back();
    }
    }
    else{
        left = mid + 1;
        mid = (left + right)/2; 
        for(int i = left; i<mid + 1; i++){
        graph[graph_[i][0]].push_back(graph_[i][1]);
        graph[graph_[i][1]].push_back(graph_[i][0]);
    }
    }
    }
}

int main(){
int n, m;
cin >> n >> m;
int pair1, pair2;
result = false;
for(int i = 1 ; i< m+1 ; i++){ 
    cin >> pair1 >> pair2;
    graph[pair1].push_back(pair2);
    graph[pair2].push_back(pair1);
    graph_[i][0] = pair1;  graph_[i][1] = pair2; 
        if( (result == false && CheckPowerOfTwo(i)) || (i == m && result == false)){
        for(int j = 0; j<n + 1; j++){
            visitedCheck[j] = 0;
            parent[j] = 0;
        }
        for(int j = 1; j<n + 1; j++){
            if(visitedCheck[j] == 0){
                CycleCheck(0,j);
            }
        }
        if(result == true){
            result_num = i;
            bsearch(i/2 + 1,i,n);
            result = true;
        }
    }
}
   
cout << result_num;
}