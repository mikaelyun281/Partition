
public class partition_by_size {
    public static void main(String[] args) {
        long n = 100, k = 50;
        /*
        Please input (n,k) for the ps(n,k) function above here.
        Note that when k>=n, then ps(n,k) = P(n) holds,
        where P(n) is the partition function.
        */

        if (n >= 0 && k >= 0) {
            long startTime = System.nanoTime();
            long result = expansion(n, k);

            long endTime = System.nanoTime();
            long totalTime = (endTime - startTime) / 1000000000;
            System.out.println(result);
            System.out.println(totalTime + "seconds");
        } else {
            System.out.println("undefined");
        }
    }

    private static long expansion(long n, long k) {
        long m = n, lower_limit = n - k, result = 0;

        if (n >= k && k > 0) {
            for (n -= 1; n >= lower_limit; n -= 1) {
                k = m - n;
                result += A(n, k);
            }
            return result;
        } else if (k > n && n != 0 && k > 0) {
            k = n;
            lower_limit = n - k;
            for (n -= 1; n >= lower_limit; n -= 1) {
                k = m - n;
                result += A(n, k);
            }
            return result;
        } else {
            return 1;
        }
    }

    private static long A(long n, long k) {
        if (n >= k && k == 1) {
            return 1;
        } else if (n >= k && k >= 3) {
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
            result += (n + 1) / 2;
        } else {
            result += (n / 2) + 1;
        }
        return result;
    }
}
