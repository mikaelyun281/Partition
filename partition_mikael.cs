using System;


namespace Partition
{
    class I
    {
        public static void Main()
        {
            long N = 150; // Please input a natural number "N" for P(N) at here.

            if (N >= 0)
            {
                var watch = System.Diagnostics.Stopwatch.StartNew();
                long partition = I.first2terms(N) + II.from_3rd_term(N);

                watch.Stop();
                var elapsedMs = (watch.ElapsedMilliseconds) / 1000;
                Console.WriteLine(partition);
                Console.WriteLine(elapsedMs + "seconds");
            }
            else
            {
                Console.WriteLine("undefined");
            }
        }

        private static long first2terms(long N)
        {
            if (N == 0)
            {
                return 1;
            }
            else
            {
                long secondterm = 0;
                if (N % 2 == 1)
                {
                    secondterm += ((N - 3) / 2) * ((N - 3) / 2) + ((N - 3) / 2);
                }
                else
                {
                    secondterm += (N / 2 - 1) * (N / 2 - 1);
                }
                return N + secondterm;
            }
        }
    }

    class II
    {
        internal static long from_3rd_term(long N)
        {
            long result = 0;
            for (long n = N - 6; n >= 0; n -= 2)
            {
                long k = 3 + ((N - 6) - n) / 2;
                result += A(n, k);
            }
            return result;
        }

        private static long A(long n, long k)
        {
            if (n >= k && k >= 3)
            {
                return C(n) + A(n - k, k) + B(n, k);
            }
            else if (n >= 3 && n < k)
            {
                k = n;
                return C(n) + A(n - k, k) + B(n, k);
            }
            else
            {
                return C(n);
            }
        }

        private static long B(long n, long k)
        {
            long send_back = 0;
            while (k > 3)
            {
                k--;
                send_back += A(n - k, k);
            }
            return send_back;
        }

        private static long C(long n)
        {
            long c_result = 0;
            c_result += D(n);

            return c_result;
        }

        private static long D(long n)
        {
            long result = 0;

            if (n % 2 == 1)
            {
                result += ((n + 1) / 2) * ((n + 1) / 2) + ((n + 1) / 2);
            }
            else
            {
                result += (n / 2 + 1) * (n / 2 + 1);
            }
            return result;
        }
    }
}



