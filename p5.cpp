#include <bits/stdc++.h> 
using namespace std;

struct FuncStruct {
   int position = 0;
   long long value = 0;
};

int main() {

   int kf, kg, p, q;
   long long sum = 0 ;
   cin >> kf;
   vector <struct FuncStruct> f (kf + 2);
   for (int i = 1; i < kf + 1; i++) 
      cin >> f[i].position >> f[i].value;

      f[0].position = INT_MIN;
      f[0].value = 0;
   cin >> kg;
      vector <struct FuncStruct> g (kg + 2);

   for (int i = 1; i < kg + 1; i++) 
      cin >> g[i].position >> g[i].value;

      g[0].position = INT_MIN;
      g[0].value = 0;  

   cin >> p >> q;
   
   int f_index; int g_index;
   while(f_index < kf && f[f_index + 1].position < p) f_index++;
   while(g_index < kg && g[g_index + 1].position < p) g_index++;

int from = p;
while(from <= q){
	int to;
	long long fValue = f[f_index].value;
	long long gValue = g[g_index].value;
	if( (f[ (f_index + 1 < kf) ? f_index + 1 : f_index].position) < (g[(g_index + 1 < kg) ? g_index + 1 : g_index].position )){
		to = ( f[(f_index + 1 < kf) ? ++f_index : f_index].position) -1;
	}
		else
		to = ( g[(g_index + 1 < kg) ? ++g_index : g_index].position) -1;
		sum += ( ( ( (to > q) ? q : to) - from + 1 ) *max(fValue,gValue));
		from = to + 1;
	}
    cout << sum % 10007;
}
