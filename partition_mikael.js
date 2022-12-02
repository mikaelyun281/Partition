
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

    function from_3rd_term(N) {
        let n = N - 6;
        let result = 0;
        for (n; n >= 0; n -= 2) {
            let k = 3 + (N - 6 - n) / 2;
            result += A(n, k);
        }
        return result;
    }

    function A(n, k) {
        if (n >= k && k >= 3) {
            return C(n) + A(n - k, k) + B(n, k);
        } else if (n >= 3 && n < k) {
            k = n;
            return C(n) + A(n - k, k) + B(n, k);
        } else {
            return C(n);
        }
    }

    function B(n, k) {
        let send_back = 0;
        while (k > 3) {
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
        let result = 0;

        if (n % 2 == 1) {
            result += ((n + 1) / 2) * ((n + 1) / 2) + (n + 1) / 2;
        } else {
            result += (n / 2 + 1) * (n / 2 + 1);
        }

        return result;
    }

    let partition = first2terms(N) + from_3rd_term(N);
    console.log(partition);

    let endTime = performance.now();
    let duration = ((endTime - startTime) / 1000).toFixed(6);
    console.log(`running time: ${duration} seconds`);
}

else {
    console.log("undefined");
}
