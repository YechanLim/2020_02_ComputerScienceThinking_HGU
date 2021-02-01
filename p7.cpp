#include <bits/stdc++.h> 
using namespace std; 

int minConnectTime(int first, int last) ;

int minTimeFromTo[500][500]; 
bool isCalculated[500][500];
int cables[500];

int main() 
{ 
    int n;
    cin >> n;
    for(int i = 0; i< n ; i++)
        cin >> cables[i];

    int result = minConnectTime(0, n - 1); 
    cout << result;
} 

int minConnectTime(int first, int last) 
{ 
    int sum = 0;  int minimum = 0;
    if (first == last) 
        return 0;

   if (isCalculated[first][last] == 1) 
        return minTimeFromTo[first][last]; 

    for (int i = first; i <= last; i++) 
        sum += cables[i]; 

    int &x = minTimeFromTo[first][last]; 
    isCalculated[first][last] = 1;

    for (int i = first; i < last; i++) { 
        minimum = sum + minConnectTime(first, i) + minConnectTime(i + 1, last); 
        if(minimum < x || x ==0){
           x = minimum; 
        }
    } 
    return x; 
} 