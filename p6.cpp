#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

int square[10][10] = {-1};
int squareLength,n,count;
bool isUsedPoly[6];
bool isFinished;


bool FillSquare(int sqaure_column,int square_row, vector < vector <int>> & polyomino, int polyomino_index){

   int count_copy = count;
    for(int column = sqaure_column; column < sqaure_column + polyomino.size(); column ++ ){
        for(int row = square_row; row < square_row + polyomino[0].size(); row ++ ){
            if(square[column][row] == -1 || (square[column][row] > 0 && polyomino[column - sqaure_column][row - square_row] == 1)){
                row --;
                for(; column >= sqaure_column ; column --){
                    for(row; row >= square_row ; row--){

                        if(polyomino[column - sqaure_column][row - square_row] == 1)
                        square[column][row] = 0;
 
                        }
                        row = square_row + polyomino[0].size() -1;
                    }
                    count = count_copy;
                    return false;
                }
                
           if(polyomino[column - sqaure_column][row - square_row] == 0)
                continue;
           else{
               square[column][row] = polyomino_index + 1;
            count ++;
           }
        }
    }

            if(count == squareLength * squareLength){
                for(int i = 1; i<squareLength + 1 ; i++){
                    for(int j = 1; j<squareLength + 1 ; j++){
                        cout << square[i][j] << " ";
                    }
                    if(i != squareLength)
                        cout << endl;
                    isFinished = true;
                }
            }
            return true;
}

void UnFillSquare(int sqaure_column, int square_row,  vector < vector <int>> & polyomino)
{
       for(int column = sqaure_column; column < sqaure_column + polyomino.size(); column ++ ){
        for(int row = square_row; row < square_row + polyomino[0].size(); row ++ ){
            if(polyomino[column - sqaure_column][row - square_row] == 0)
                continue;
            else{
                square[column][row] = 0;
                count --;
            }
        }
        }
}

int InsertPolyomino(vector <vector <vector <int>>> &polyominos){
    if(isFinished == true)
        return 0;

    for(int polyNum = 0; polyNum < n; polyNum ++){
       if(isUsedPoly[polyNum] == true)
                continue;    
       for(int column = 1; column < squareLength + 1 ; column ++ ){
        for(int row = 1; row < squareLength + 1 ; row ++ ){
            if(FillSquare( column, row, polyominos[polyNum],polyNum )){
                if(isFinished == true)
                    return 0;
                else{
                isUsedPoly[polyNum] = true;
                InsertPolyomino(polyominos);
                if(isFinished == true)
                    return 0;
                UnFillSquare(column, row, polyominos[polyNum]);
                isUsedPoly[polyNum] = false; 
                }
            }   
            }
        }
    }
}    
    



int main(){
    int column_temp, row_temp, digit;
     vector <vector <vector <int>>> polyominos;
   
    cin >> n;
    isFinished = false;
    for(int i = 0; i<n ; i++){
        isUsedPoly[i] = false;
        cin >> column_temp >> row_temp;
        vector <vector <int>> polyomino;
        for(int j = 0; j<column_temp ; j++){
            vector <int> digits;
            for(int k = 0; k<row_temp ; k++){
                cin >> digit;
                if(digit == 1)
                    squareLength++;

                digits.push_back(digit);
            }
            polyomino.push_back(digits);
        }
        polyominos.push_back(polyomino);
    }
  //  cout << "squareLength == " << squareLength;
     if(squareLength != 1 && squareLength != 4 && squareLength != 9 && squareLength != 16 && squareLength != 25 && squareLength != 36 && squareLength != 49 && squareLength != 64)
    {
            cout << "No solution possible";
            return 0;
    }   
    squareLength = sqrt(squareLength);

    memset(square, -1, sizeof(square)); 

    for(int column = 1; column < squareLength + 1 ; column ++ ){
        for(int row = 1; row < squareLength + 1 ; row ++ ){
            square[column][row] = 0;                     
        }
    }

    InsertPolyomino(polyominos);

    if(isFinished == true)
        return 0;
    else
        cout << "No solution possible";
}