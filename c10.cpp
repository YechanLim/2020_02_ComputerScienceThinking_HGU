#include <bits/stdc++.h> 
using namespace std;

int p,c,minSum;
bool isChineses[50001];
vector <int> graph[50001];
vector<pair<int,int>> building;

void bfs(int start, vector<int> graph[], bool check[],bool isChinese){
  if(!check[start]){
  if(isChinese)
      c++;
  else
      p++;
  }
  isChineses[start] = true;

  queue<int> q;
  q.push(start);
  check[start] = true;

  while(q.empty()){
    int tmp = q.front();
    q.pop();
    for(int i = 0; i<graph[tmp].size(); i++){
      if(check[graph[tmp][i]] == false){
      isChineses[graph[tmp][i]] = !isChineses[tmp];

      if(isChineses[tmp])
          p++;
  
         else
          c++;

        q.push(graph[tmp][i]);
        check[graph[tmp][i] = true];
      }
    }
  }  
}

int main(){
    int n;
    cin >> n;
    
    bool check[n+1];
	  fill(check, check+n+1, false);

    int x,y;
    for(int i = 0; i< n ; i++){
        cin >> x >> y;
        building.push_back(make_pair(x,y));
    }
    sort(building.begin(), building.end()); 

    for(int i = 0; i< n; i++){
        for(int j = i+1; j<n ; j++){
        //  cout << "i = " << i << " j = " << j << endl;
            if(building[j].first - building[i].first >5)
                break;
           
            if(building[j].second - building[i].second > 5){
              int min = j; int max = n-1;
              int mid;
              while(min<=max){
                mid = (min + max)/2;
                if(building[mid].first == building[i].first){
                    min = mid+1;
                    j = min;
                }
                else{
                    max = mid-1;                 
                }
              }
              if(j != n-1)
                  j -= 1;
            continue;           
            }

    if( sqrt(pow(building[i].first - building[j].first,2) + pow(building[i].second - building[j].second,2)) <=5) {
     graph[i].push_back(j);
     graph[j].push_back(i);
      }
    }
    }

  for(int i = 0 ; i< n ; i++){
  if(!check[i]){
  p =0; c = 0;
  bfs(i, graph, check,1);
  if(p>c)
    minSum += c;
  else
    minSum += p;  
  }
  }
  cout << minSum;
}