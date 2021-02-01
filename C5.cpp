#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

double GetMaxRadius(double x1, double rad1, double x2){
    double fTemp = pow(x1 - x2, 2)/(4*rad1);
    return fTemp;
}

int main(){
int n, x ,r;

cin >> n;

int x_coordinates[100000];  int radius_bound[100000];
double radius[100000];      bool isUsed[100000];

for(int i = 0 ; i< n ; i++){
    cin >> x >> r;
    x_coordinates[i] = x;
    radius_bound[i] = r;
    isUsed[i] = false;
}

radius[0] = radius_bound[0];

for(int b_num = 1; b_num< n ; b_num ++){
        for(int b_num_comp = b_num -1 ; b_num_comp >=0 ; b_num_comp--){

            double tempMaxRadius = GetMaxRadius((double) x_coordinates[b_num_comp], radius[b_num_comp], (double) x_coordinates[b_num]);

            if(tempMaxRadius > radius_bound[b_num])
                tempMaxRadius = radius_bound[b_num];

            if(isUsed[b_num] == false){
                radius[b_num] = tempMaxRadius;
                isUsed[b_num] = true;
            }
            else{
                if(tempMaxRadius < radius[b_num])
                    radius[b_num] = tempMaxRadius;
            }        
            
            if(radius[b_num_comp] >= radius[b_num])
                break;
                }
}          

        cout << fixed;
        cout.precision(3);

    for(int i = 0 ; i<n ; i++){
        cout << radius[i] << endl;
    }

}