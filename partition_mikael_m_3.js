
let N = 150  // Please input a natural number "N" for P(N) at here.


let startTime = performance.now();

if (N >= 0 && N - parseInt(N) == 0) {

    function first2terms(N) {
        if (N == 0) {
            return 1;
        }
        else {
            let secondterm;
            if (N % 2 == 1) {
                secondterm = ((N - 3) / 2) * ((N - 3) / 2) + (N - 3) / 2;
            } else {
                secondterm = (N / 2 - 1) * (N / 2 - 1);
            }
            return N + secondterm;
        }
    }

    function after_3rd_term(N) {
        let n = N - 6;
        let result = 0;
        for (n; n >= 0; n -= 2) {
            let k = 3 + (N - 6 - n) / 2;
            result += A(n, k);
        }
        return result;
    }

    function A(n, k) {
        if (n >= k && k >= 4) {
            return C(n) + A(n - k, k) + B(n, k);
        } else if (n >= 4 && n < k) {
            k = n;
            return C(n) + A(n - k, k) + B(n, k);
        } else {
            return C(n);
        }
    }

    function B(n, k) {
        let send_back = 0;
        while (k > 4) {
            k--;
            send_back += A(n - k, k);
        }
        return send_back;
    }

    function C(n) {
        let c_result = 0;
        c_result += D(n);
        return c_result;
    }

    function D(n) {
        let result = 0, a;

        if (n % 6 == 1) {
            a = (n - 1) / 6;
            result += 6 * a * a * a + (27 * a * a) / 2 + (19 * a) / 2 + 2;
        } else if (n % 6 == 2) {
            a = (n - 2) / 6;
            result += 6 * a * a * a + (33 * a * a) / 2 + (29 * a) / 2 + 4;
        } else if (n % 6 == 3) {
            a = (n - 3) / 6;
            result += 6 * a * a * a + (39 * a * a) / 2 + (41 * a) / 2 + 7;
        } else if (n % 6 == 4) {
            a = (n - 4) / 6;
            result += 6 * a * a * a + (45 * a * a) / 2 + (55 * a) / 2 + 11;
        } else if (n % 6 == 5) {
            a = (n - 5) / 6;
            result += 6 * a * a * a + (51 * a * a) / 2 + (71 * a) / 2 + 16;
        } else {
            a = n / 6;
            result += 6 * a * a * a + (21 * a * a) / 2 + (11 * a) / 2 + 1;
        }

        return result;
    }

    let partition = first2terms(N) + after_3rd_term(N);
    console.log(partition);

    let endTime = performance.now();
    let duration = ((endTime - startTime) / 1000).toFixed(6);
    console.log(`running time: ${duration} seconds`);
}

else {
    console.log("undefined");
}
