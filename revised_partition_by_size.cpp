#include <iostream>
#include <chrono>
long result = 0;
long expansionI(long n, long k);
long expansionII(long n, long k);


int main(void) {

  double n = 100, k = 50;  
  /* 
  Please input (n,k) for the ps(n,k) function above here.
  Note that when k>=n, then ps(n,k) = P(n) holds, 
  where P(n) is the partition function. 
  */
      auto start = std::chrono::steady_clock::now();

            if (n-(int)n == 0 && k-(int)k == 0 && n >= 0 && k >= 0){
               
                expansionI(n,k);
                
                std::cout << result << '\n';
           
                auto end = std::chrono::steady_clock::now();
                auto diff = end - start;
                std::cout << "running time: " 
                << std::chrono::duration<double>(diff).count() 
                << " seconds" << '\n';   
            }

            else{
              std::cout << "undefined" << '\n';
            }
            return 0;
}

long expansionI(long n, long k){

     if (n >= k && k > 0) {
        long m=n, limitlength = n-k;
        for(n-=1; n>=limitlength; n-=1){ 
            k=m-n;
            if (k == 1) {result += 1;}
            else{expansionII(n,k);}
        }
     }
     else if (k > n && n != 0 && k != 0) {
        long m=n, k=n, limitlength = n-k;
        for(n-=1; n>=limitlength; n-=1){ 
            k=m-n;
            if (k == 1) {result += 1;}
            else{expansionII(n,k);}
        }
     }
     else {
            return result += 1;
     }

     return 0;
}

long expansionII(long n, long k){

     if(n>=k && k>=3){
        for(k; k>=3; k--)expansionII(n-k,k);}  
     else if(n>=3 && n<k){k=n;
        for(k; k>=3; k--)expansionII(n-k,k);}
     else{}
    
     if(n%2==1){
         result += (n+1)/2;
     }
     else{
         result += (n/2)+1;
     }
     return result;     
}
