#include <iostream>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
int n,k,location;
int max_dist,min_dist,target_dist;
int result;
int poles[100000];
cin >> n >> k;

for(int i = 0 ; i<n ; i++){
cin >> location;
poles[i] = location;
}

qsort (poles ,n, sizeof(int),compare);

max_dist = poles[n-1] - poles[0];
min_dist = 1;

while(min_dist<=max_dist){
    target_dist = (max_dist + min_dist)/2;
    int division_count = 1, sum = 0;
    
    for(int i = 0; i<n-1 ; i++){
        sum += poles[i+1] - poles[i];
    if(sum >= target_dist){
        division_count++;
        sum = 0;
        continue;
    }
    else continue;
}
    if(division_count >= k){
        result = target_dist;
        min_dist = target_dist + 1;
    }
    else{
        max_dist = target_dist -1;
    }
}

cout << result;

}