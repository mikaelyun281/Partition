#include <stdio.h>
#include <time.h>
long first2terms(long N);
long after_3rd_term = 0;
long A(long n, long k);
long B(long n, long k);
long C(long n);
long D(long n);



int main(void) {

  double N = 150;  // Please input a natural number "N" for P(N) at here.
   

      clock_t start, end;
      double running_time;
      start = clock();
   
      long n = N-6, k, partition;    


      if(N>=0 && N-(int)N == 0){
           
         for(n; n>=0; n-=2){
            k=3+((N-6)-n)/2;
            A(n,k);
         }
           
         partition = first2terms(N) + after_3rd_term;
         printf("%ld\n",partition);
     
         end = clock();
         running_time = ((double) (end - start))/ CLOCKS_PER_SEC;
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


long A(long n, long k){

     if(n>=k && k>=3){
        return C(n) + A(n-k, k) + B(n,k); 
     }  
     
     else if(n>=3 && n<k){
        k=n;
        return C(n) + A(n-k, k) + B(n,k);
     }

     else{
        return C(n);
     }
}
  
 
long B(long n, long k){
     
     while(k>3){
       k--;
       A(n-k,k);
     }
 
     return 0;
} 


long C(long n){
     
     after_3rd_term += D(n);
     return after_3rd_term; 
}


long D(long n){
 
     long result = 0;
    
     if(n%2==1){
        result += ((n+1)/2)*((n+1)/2)+((n+1)/2);
     }
      
     else{
        result += (n/2+1)*(n/2+1);
     }

     return result;
} 
