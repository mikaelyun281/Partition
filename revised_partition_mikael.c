#include <stdio.h>
#include <time.h>
long first2terms(long N);
long from_3rd_term = 0;
long expansion(long n, long k);


int main(void) {

  double N = 150;  // Please input a natural number "N" for P(N) at here.
   

      clock_t start, end;
      double running_time;
      start = clock();
   
      long n = N-6, k, partition;    


      if(N>=0 && N-(int)N == 0){
           
         for(n; n>=0; n-=2){
            k=3+((N-6)-n)/2;
            expansion(n,k);
         }
           
         partition = first2terms(N) + from_3rd_term;
         printf("%ld\n",partition);
     
         end = clock();
         running_time = ((double)(end - start))/CLOCKS_PER_SEC;
         printf("%s%lf%s\n", "running time: ", running_time, " seconds");   
      }
      else{
         printf("%s\n", "undefined");
      }
      return 0;
}

long first2terms(long N){
  
      if(N==0){
         return 1;
      }
      else{ 
         long secondterm = 0;
         if(N%2==1){
           secondterm += ((N-3)/2)*((N-3)/2)+((N-3)/2);
         }
         else{
           secondterm += (N/2-1)*(N/2-1);
         }
         return N + secondterm;
      } 
}

long expansion(long n, long k){
  
     if(n>=k && k>=3){
        for(k; k>=3; k--)expansion(n-k,k);}  
     else if(n>=3 && n<k){k=n;
        for(k; k>=3; k--)expansion(n-k,k);}
     else{}
    
     if(n%2==1){
         from_3rd_term += ((n+1)/2)*((n+1)/2)+((n+1)/2);
     }
     else{
         from_3rd_term += (n/2+1)*(n/2+1);
     }
     return from_3rd_term;     
}
