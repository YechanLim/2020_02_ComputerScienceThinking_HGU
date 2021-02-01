#include <bits/stdc++.h> 
using namespace std; 

struct WordConnect{
    int prevW;
    int nextW;
};

int main(){
    int n;
    int noPrevW = 0 ;
    int noNextW = 0;
    int firstWordIndex = 0;
    string words[1001];
    struct WordConnect wordConnect[1001];
    cin >> n;
    for(int i = 0; i< n ; i++){
    cin >> words[i];
    wordConnect[i].nextW = -1;
    wordConnect[i].prevW = -1;
    }
    for(int i = 0; i< n ; i++){
        char firAlpha = words[i][0];
        char lastAlpha = words[i][words[i].length()-1];

        for(int j = 0; j<n ; j++){
            if(i == j)
                continue;
            if(wordConnect[i].prevW == j || wordConnect[i].nextW == j)
                continue;

        char firAlphaForComp = words[j][0];
        char lastAlphaForComp = words[j][words[j].length()-1];
        if(lastAlpha == firAlphaForComp && wordConnect[i].nextW == -1 
        && wordConnect[j].prevW == -1){
            wordConnect[i].nextW = j;
            wordConnect[j].prevW = i;
        }
        else if(firAlpha == lastAlphaForComp && wordConnect[i].prevW == -1
        && wordConnect[j].nextW == -1){
            wordConnect[i].prevW = j;
            wordConnect[j].nextW = i;
        }
        }

            if(wordConnect[i].nextW == -1)
            noNextW += 1;
        
            if(wordConnect[i].prevW == -1){
            noPrevW += 1;
            firstWordIndex = i;
            }
    }
    int wordIndex = firstWordIndex;    
    // for(int i = 0; i< n ; i++){
    //     cout << wordConnect[i].prevW << "  " << wordConnect[i].nextW << endl;
    // }


    if(noNextW != 1 && noPrevW !=1)
        cout<< 0;
    
    else{
        for(int i = 0; i< n ; i++){
            cout << words[wordIndex] << endl;
            wordIndex = wordConnect[wordIndex].nextW;
        }
    }    
}