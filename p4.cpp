    #include <iostream>
    #include<cmath>
    using namespace std;

    int disk_rodInfo[50];

    int TowerOfHanoi(int disk_num, int destin){
        int returnValue;
        if(disk_num ==1){
                if(disk_rodInfo[disk_num] == destin)
                    return 0;
                    else return 1;
            }            
            if(disk_rodInfo[disk_num] == destin)
                returnValue = TowerOfHanoi(disk_num-1, destin);
            else{
                if(destin + disk_rodInfo[disk_num] == 3) destin = 3;
                else if(destin + disk_rodInfo[disk_num] == 4) destin = 2;
                else destin = 1;
                returnValue = pow(2,disk_num -1) + TowerOfHanoi(disk_num-1,destin);
            }
        return returnValue;
    }

    int main(){

        int n,k;
        cin >> n >> k;
        
        int disk_amount, disk_num;
        for(int rod = 1; rod< 4 ; rod++){
        cin >> disk_amount;
        
        for(int i = 0 ;i < disk_amount ; i++){
        cin >> disk_num;
        disk_rodInfo[disk_num] = rod;
        }
        }

        int result = TowerOfHanoi(n,k);
        cout << result;
    }