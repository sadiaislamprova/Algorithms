#include<stdio.h>
int max(int m, int b) {
   if(m>b){
      return m;
   } else {
      return b;
   }
}
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() {
   int val[] = {3, 4, 5, 6};
   int wt[] = {2, 3, 4, 5};
   int W = 5;
   int n = sizeof(val)/sizeof(val[0]);
   printf("The solution is : %d", knapsack(W, wt, val, n));
   return 0;
}
