#include <iostream>
#include <chrono>
long first2terms(long N);
long from_3rd_term = 0;
long expansion(long n, long k);


int main(void) {

  auto N = 150;  // Please input a natural number "N" for P(N) at here.
   

      auto start = std::chrono::steady_clock::now();
      long n = N-6, k, partition;  
      
      if(N>=0 && N-(int)N == 0){
         
         for(n; n>=0; n-=2){
            k=3+((N-6)-n)/2;
            expansion(n,k);
         }
          
         partition = first2terms(N) + from_3rd_term;
         std::cout << partition << '\n';
      
         auto end = std::chrono::steady_clock::now();
         auto diff = end - start;
         std::cout << "running time: " 
         << std::chrono::duration<double>(diff).count() << " seconds" << '\n'; 
      
      }
      else{
           std::cout << "undefined" << '\n';
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
