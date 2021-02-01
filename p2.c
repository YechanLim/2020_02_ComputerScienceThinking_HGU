#include <stdio.h>
#include <stdlib.h>


void QuickSort(int **arr, int left, int right) {
   int L = left, R = right;
   int* temp;
   int pivot = arr[0][(left + right) / 2]; 
   while (L <= R) {
      while (arr[0][L] < pivot) 
         L++;
      while (arr[0][R] > pivot)
         R--;

      if (L <= R) { 
         if (L != R) { 
             for(int i = 0; i<4; i++){
            int tem = arr[i][L];
            arr[i][L] = arr[i][R];
            arr[i][R] = tem;
             }
         } 
         L++; R--; 
      }
   }
   if (left < R)
      QuickSort(arr, left, R);
   if (L < right)
      QuickSort(arr, L, right);
}
   



int main() {
   int n, k;
   int g, x, p;
   int biggest = 0;
   static int* b_list[4];

   if(fscanf(stdin,"%d %d",&n,&k) == 1);
   for(int i = 0; i<4; i++)
   b_list[i] = malloc(sizeof(int)*(n+1));

   for (int i = 1; i < n+1; i++) {
      if(fscanf(stdin,"%d %d",&g,&x) == 1);
      b_list[0][i] = x;
      b_list[1][i] = g;
      b_list[2][i] = g;
      b_list[3][i] = 0;
   }
   
   QuickSort(b_list, 1, n);   

    b_list[0][0] = 0; b_list[1][0] = 0; b_list[2][0] = 0; b_list[3][0] = 0; 
   
   for (int i = 1; i < n+1; i++)
   {       
        if(i==1)
        p =2;            
      	else if(b_list[0][i] - b_list[0][i-1] < (k * 2)){
		b_list[2][i] = b_list[2][i-1] - b_list[1][i-1];
        if(i == p)
        {
            p = i+1;
            b_list[3][i] = p;

        }
        else{
        p = b_list[3][i -1] + 1;
        b_list[3][i] = b_list[3][i -1];
        }
          }
      else{
          p = i+1;
      }

      while ((b_list[0][p] <= b_list[0][i] + (k * 2)) && p < n+1)
      {
      b_list[2][i] += b_list[1][p];
      b_list[3][i] = p;
         p++;      
      }
   }

   for (int i = 1; i < n+1; i++) {
      if (b_list[2][i] > biggest)
      biggest = b_list[2][i];
   }
   fprintf(stdout,"%d", biggest);
   return 0;
}