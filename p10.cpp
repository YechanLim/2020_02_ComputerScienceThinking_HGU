#include <bits/stdc++.h> 
using namespace std; 

bool isCompleteGraph(int numV);
void findCompleteGraph(int minV, int numV, int n);
  
int storeV[451]; 
int graph[451][451];   
int weight[451];
int maxWeight = 0;

int main() 
{ 
    int n,b;
    int l,r;
    cin >> n >> b;
    weight[0] = 0;
    for(int i = 1; i<n+1 ; i++){
        cin>>weight[i];
    }

    for(int i = 0; i< b; i++){
        cin>>l>>r;
        graph[l][r] = 1;
        graph[r][l] = 1;
    }

    findCompleteGraph(1, 1,n); 
    cout << maxWeight;
    return 0; 
} 


void findCompleteGraph(int minV, int numV, int n) 
{ 
    for (int vertex = minV; vertex <= n; vertex++) { 
        storeV[numV] = vertex; 

       if (isCompleteGraph(numV)) 
            findCompleteGraph(minV + 1, numV + 1,n); 
    }

} 

bool isCompleteGraph(int numV) 
{ 
    int max_temp = 0;

    for (int i = 1; i <= numV; i++) { 
        max_temp += weight[storeV[i]];
        for (int j = i + 1; j <= numV; j++){ 
            if (graph[storeV[i]][storeV[j]] == 0) 
                return false; 
        }
    }
        if(maxWeight < max_temp)
            maxWeight = max_temp;  
    return true; 
} 
