import timeit
timer_start = timeit.default_timer()


N = 120  # Please input a natural number "N" for P(N) at here.


try:
    def first2terms(N):
        if N == 0:
            return 1
        else:
            if N % 2 == 1:
                secondterm = ((N-3)/2)*((N-3)/2)+((N-3)/2)
            else:
                secondterm = (N/2-1)*(N/2-1)
            return N + secondterm

    def from_3rd_term(N):
        n = N-6
        result = 0
        for n in range(n, -1, -2):
            k = 3+((N-6)-n)/2
            result += A(n, k)
        return result

    def A(n, k):
        if n >= k and k >= 3:
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
            return ((n+1)/2)*((n+1)/2)+((n+1)/2)
        else:
            return (n/2+1)*(n/2+1)

    partition = int(first2terms(N) + from_3rd_term(N))
    timer_stop = timeit.default_timer()
    running_time = round(timer_stop - timer_start, 6)

    if __name__ == '__main__':
        print(partition, "\n" "running time: ",
              running_time, " seconds") if N >= 0 else print("undefined")


except:
    print("undefined")
