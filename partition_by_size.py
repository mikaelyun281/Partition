import timeit
timer_start = timeit.default_timer()


(n,k) = (100,50)  
# Please input (n,k) for the ps(n,k) function above here.
# Note that when k>=n, then ps(n,k) = P(n), 
# where P(n) is the partition function.


if(n-int(n) == 0 and k-int(k) == 0 and n >=0 and k >= 0):
    def partition_by_size(n, k):
        m=n
        result = 0
        if n>=k and k>0:    
            for n in range(n-1, n-k-1, -1):
                k=m-n
                result += A(n,k)
            return result  
        elif k>n and n != 0 and k>0:
            k=n
            for n in range(n-1, n-k-1, -1):
                k=m-n
                result += A(n,k)
            return result  
        else:
            return 1


    def A(n, k):
        if n >=k and k == 1:
            return 1
        elif n >= k and k >= 3:
            return C(n) + A(n-k, k) + B(n, k)
        elif n >= 3 and n < k:
            k = n
            return C(n) + A(n-k, k) + B(n, k)
        else:
            return C(n)

    def B(n, k):
        send_back = 0
        while k > 3:
            k -= 1
            send_back += A(n-k, k)
        return send_back

    def C(n):
        c_result = 0
        c_result += D(n)
        return c_result

    def D(n):
        if n % 2 == 1:
            return (n+1)/2
        else:
            return (n/2)+1


    ps_function = int(partition_by_size(n, k))
    timer_stop = timeit.default_timer()
    running_time = round(timer_stop - timer_start, 6)


    if __name__ == '__main__':
        print("ps(n,k): ", ps_function, "\n" "running time: ",
        running_time, " seconds") 

else:
    print("undefined")
