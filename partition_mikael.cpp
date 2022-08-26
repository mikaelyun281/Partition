#include <iostream>
#include <chrono>

auto start = std::chrono::steady_clock::now();

long first2terms(long N);
long after_3rd_term = 0;
long A(long n, long k);
long B(long n, long k);
long C(long n);
long D(long n);



int main(void) {

  auto N = 150.7;  // Please input a natural number "N" for P(N) at here.
   
   
      long n = N-6, k, partition;  
      
      if(N>=0 && N-(int)N == 0){
         
         for(n; n>=0; n-=2){
            k=3+((N-6)-n)/2;
            A(n,k);
         }
          
         partition = first2terms(N) + after_3rd_term;
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

     after_3rd_term  += D(n);
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