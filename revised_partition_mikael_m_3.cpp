#include <iostream>
#include <chrono>
long first2terms(long N);
long after_3rd_term = 0;
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

long expansion(long n, long k){
  
     if(n>=k && k>=4){
        for(k; k>=4; k--)expansion(n-k,k);}  
     else if(n>=4 && n<k){k=n;
        for(k; k>=4; k--)expansion(n-k,k);}
     else{}

     double a;
   
     if(n%6==1){
        a = (n-1)/6;
        after_3rd_term += 6*a*a*a+(27*a*a)/2+(19*a)/2+2;
     }
     else if(n%6==2){
        a = (n-2)/6;
        after_3rd_term += 6*a*a*a+(33*a*a)/2+(29*a)/2+4;
     }
     else if(n%6==3){
        a = (n-3)/6;
        after_3rd_term += 6*a*a*a+(39*a*a)/2+(41*a)/2+7; 
     }
     else if(n%6==4){
        a = (n-4)/6;
        after_3rd_term += 6*a*a*a+(45*a*a)/2+(55*a)/2+11; 
     }
     else if(n%6==5){
        a = (n-5)/6;
        after_3rd_term += 6*a*a*a+(51*a*a)/2+(71*a)/2+16;
     }
     else {
        a = n/6;
        after_3rd_term += 6*a*a*a+(21*a*a)/2+(11*a)/2+1;
     }
     return after_3rd_term;     
}