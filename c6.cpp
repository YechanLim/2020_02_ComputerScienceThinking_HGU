#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;  long cards[50000]; int cardsMaxAcendVal[50000];  int cardsMaxDiscVal[50000]; 
    int min_dist; int max_dist; int target_dist;
    int temp;
    vector<pair<int,long>> maxDiscSet; vector<pair<int,long>> maxAcendSet;
    cin >> n;
    for(int i = 0 ; i< n ; i++){
        cin >> cards[i] ; 
    }

    maxAcendSet.push_back(make_pair(-1,-1));   
    for(int i = 0; i<n ; i++){
        min_dist = 0; max_dist = maxAcendSet.size() -1; temp = 0;
        while(min_dist<=max_dist){
        target_dist = (max_dist + min_dist)/2;
        if(maxAcendSet[target_dist].second < cards[i]){
                    min_dist = target_dist + 1;
                    temp = target_dist;
                    continue;
        }
        else{
            max_dist = target_dist -1;
            continue;
        }
        }

        if(temp != maxAcendSet.size()-1){
            cardsMaxAcendVal[i] = maxAcendSet[temp+1].first;
            if(maxAcendSet[temp+1].second <= cards[i]){
                continue;
            }
             else{
                maxAcendSet[temp+1].second = cards[i];
             }   
        }
        else{
            maxAcendSet.push_back(make_pair(maxAcendSet[temp].first + 1,cards[i]));
            cardsMaxAcendVal[i] = maxAcendSet[temp].first + 1;
        }
    }

    maxDiscSet.push_back(make_pair(-1,-1));   
    for(int i = n-1; i>=0 ; i--){
        min_dist = 0; max_dist = maxDiscSet.size() -1; temp = 0;
        while(min_dist<=max_dist){
        target_dist = (max_dist + min_dist)/2;
        if(maxDiscSet[target_dist].second < cards[i]){
                    min_dist = target_dist + 1;
                    temp = target_dist;
                    continue;
        }
        else{
            max_dist = target_dist -1;
            continue;
        }
        }
        if(temp != maxDiscSet.size()-1){
            cardsMaxDiscVal[i] = maxDiscSet[temp+1].first;
            if(maxDiscSet[temp+1].second <= cards[i]){
                continue;
            }
             else{
                maxDiscSet[temp+1].second = cards[i];
             }   
        }
        else{
            maxDiscSet.push_back(make_pair(maxDiscSet[temp].first + 1,cards[i]));
            cardsMaxDiscVal[i] = maxDiscSet[temp].first + 1;
        }
    }

    int max = 0;
    for(int i = 0; i< n; i++){
        if(max < cardsMaxAcendVal[i] +cardsMaxDiscVal[i] + 1 )
        max =  cardsMaxAcendVal[i] +cardsMaxDiscVal[i] + 1 ;
    }
    cout << max;
}
