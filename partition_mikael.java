
public class partition_mikael {
    public static void main(String[] args) {
        long N = 150; // Please input a natural number "N" for P(N) at here.

        if (N >= 0) {
            long startTime = System.nanoTime();
            long partition = first2terms(N) + expansion.after_3rd_term(N);

            long endTime = System.nanoTime();
            long totalTime = (endTime - startTime) / 1000000000;
            System.out.println(partition);
            System.out.println(totalTime + "seconds");
        } else {
            System.out.println("undefined");
        }
    }

    static long first2terms(long N) {
        if (N == 0) {
            return 1;
        } else {
            long second_term = 0;
            if (N % 2 == 1) {
                second_term += ((N - 3) / 2) * ((N - 3) / 2) + ((N - 3) / 2);
            } else {
                second_term += (N / 2 - 1) * (N / 2 - 1);
            }
            return N + second_term;
        }
    }
}

class expansion {
    static long after_3rd_term(long N) {
        long result = 0;
        for (long n = N - 6; n >= 0; n -= 2) {
            long k = 3 + ((N - 6) - n) / 2;
            result += A(n, k);
        }
        return result;
    }

    private static long A(long n, long k) {
        if (n >= k && k >= 3) {
            return C(n) + A(n - k, k) + B(n, k);
        } else if (n >= 3 && n < k) {
            k = n;
            return C(n) + A(n - k, k) + B(n, k);
        } else {
            return C(n);
        }
    }

    private static long B(long n, long k) {
        long send_back = 0;
        while (k > 3) {
            k--;
            send_back += A(n - k, k);
        }
        return send_back;
    }

    private static long C(long n) {
        long c_result = 0;
        c_result += D(n);
        return c_result;
    }

    private static long D(long n) {
        long result = 0;

        if (n % 2 == 1) {
            result += ((n + 1) / 2) * ((n + 1) / 2) + ((n + 1) / 2);
        } else {
            result += (n / 2 + 1) * (n / 2 + 1);
        }
        return result;
    }
}