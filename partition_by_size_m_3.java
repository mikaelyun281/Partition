public class partition_by_size_m_3 {
    public static void main(String[] args) {
        long n = 150, k = 50;
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
                if (k == 1) {
                    result += 1;
                } else if (k == 2) {
                    if (n % 2 == 1) {
                        result += (n + 1) / 2;
                    } else {
                        result += (n / 2) + 1;
                    }
                } else {
                    result += A(n, k);
                }
            }
            return result;
        } else if (k > n && n != 0 && k > 0) {
            k = n;
            lower_limit = n - k;
            for (n -= 1; n >= lower_limit; n -= 1) {
                k = m - n;
                if (n >= k && k == 1) {
                    result += 1;
                } else if (n >= k && k == 2) {
                    if (n % 2 == 1) {
                        result += (n + 1) / 2;
                    } else {
                        result += (n / 2) + 1;
                    }
                } else {
                    result += A(n, k);
                }
            }
            return result;
        } else {
            return 1;
        }
    }

    private static long A(long n, long k) {
        if (n >= k && k >= 4) {
            return C(n) + A(n - k, k) + B(n, k);
        } else if (n >= 4 && n < k) {
            k = n;
            return C(n) + A(n - k, k) + B(n, k);
        } else {
            return C(n);
        }
    }

    private static long B(long n, long k) {
        long send_back = 0;
        while (k > 4) {
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

    private static double D(long n) {
        long result = 0, a;

        if (n % 6 == 1) {
            a = (n - 1) / 6;
            result += 3 * a * a + 4 * a + 1;
        } else if (n % 6 == 2) {
            a = (n - 2) / 6;
            result += 3 * a * a + 5 * a + 2;
        } else if (n % 6 == 3) {
            a = (n - 3) / 6;
            result += 3 * a * a + 6 * a + 3;
        } else if (n % 6 == 4) {
            a = (n - 4) / 6;
            result += 3 * a * a + 7 * a + 4;
        } else if (n % 6 == 5) {
            a = (n - 5) / 6;
            result += 3 * a * a + 8 * a + 5;
        } else {
            a = n / 6;
            result += 3 * a * a + 3 * a + 1;
        }
        return result;
    }
}

