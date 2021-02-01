#include <stdio.h>
#include <stdlib.h>

void QuickSort(int *arr, int left, int right) {
   int L = left, R = right;
   int temp;
   int pivot = arr[(left + right) / 2]; 
   while (L <= R) {
      while (arr[L] < pivot) 
         L++;
      while (arr[R] > pivot)
         R--;

      if (L <= R) { 
         if (L != R) { 
            temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;             
         } 
         L++; R--; 
      }
   }
   if (left < R)
      QuickSort(arr, left, R);
   if (L < right)
      QuickSort(arr, L, right);
}
   

void main(){
    int M;
    int weight;
    int result = 0;
    int list[100000];
    int count = 0;
    scanf("%d",&M);
    while(scanf("%d",&weight)==1){
        list[count++] = weight;
    }
    count--;
    QuickSort(list,0,count);
    
    int i = 0;
        while(i!=count )  {
          if(i == count -1){
                 if(list[i]+list[count]<=M){
                     result++;                   
            break;            
            }
            else{
                result +=2;
                break;
            }
            }
            else{
            if(list[i]+list[count]<=M){
            result++;
            i++;
            count--;
            continue;
            }
            else
            {
                count--;
                result++;
                continue;
            }
            }
    }
    if(i == count)
    result++;

    printf("%d",result);
}