#include <stdio.h>
#include <time.h>
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
   
      clock_t start, end;
      double running_time;
      start = clock();

            if (n-(int)n == 0 && k-(int)k == 0 && n >= 0 && k >= 0){
               
                expansionI(n,k);
                
                printf("%ld\n", result);
           
                end = clock();
                running_time = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("%s%lf%s\n", "running time: ", running_time, " seconds");   
            }

            else{
              printf("%s\n", "undefined");
            }
            return 0;
}

long expansionI(long n, long k){

     if (n >= k && k > 0) {
        long m=n, limitlength = n-k;
        for(n-=1; n>=limitlength; n-=1){ 
            k=m-n;
            if (k == 1) {result += 1;}
            else {expansionII(n,k);}
        }
     }
     else if (k > n && n != 0 && k != 0) {
        long m=n, k=n, limitlength = n-k;
        for(n-=1; n>=limitlength; n-=1){ 
            k=m-n;
            if (k == 1) {result += 1;}
            else {expansionII(n,k);}
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
