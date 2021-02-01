#include <iostream> 
using namespace std; 

int startDate[100005];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool checkPossible(int n, int d, int m, int k){
    int arrIndex = 0;
    for(int date = 1 ; date< n + 1 ; date++ ){
        for(int bullNum = 1 ; bullNum < k + 1 ; bullNum++ ){
            if(startDate[arrIndex] + d < date || arrIndex == m)
                break;

            if(startDate[arrIndex] <= date)
                arrIndex++;                
        }
            if(startDate[arrIndex] + d < date  || arrIndex == m)
               break;
    }
    if(arrIndex == m)
        return true;
     else
        return false;   
}

int main(){
int n, d, m;
int k = 0;

cin >> n >> d >> m;
for(int i = 0; i<m ; i++)
    cin >> startDate[i];

qsort(startDate ,m, sizeof(int),compare);

int l = 1 ; int r = m ; int mid;
    while(l <= r){
        mid = (l + r) /2;
        if(checkPossible(n,d,m,mid)){
            k = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
        cout << k;
}

