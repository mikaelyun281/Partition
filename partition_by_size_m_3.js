
let [n, k] = [100, 50];
/* 
Please input [n,k] for the ps(n,k) function above here.
Note that when k>=n, then ps(n,k) = P(n), 
where P(n) is the partition function. 
*/


let startTime = performance.now();


if (n - parseInt(n) == 0 && k - parseInt(k) == 0 && n >= 0 && k >= 0) {

    function partition_by_size(n, k) {
        let m = n;
        let lowerlimit = n - k;
        let result = 0;
        if (n >= k && k > 0) {
            for (n -= 1; n >= lowerlimit; n -= 1) {
                k = m - n;
                result += A(n, k);
            }
            return result;
        }
        else if (k > n && n != 0 && k > 0) {
            k = n, lowerlimit = n - k;
            for (n -= 1; n >= lowerlimit; n -= 1) {
                k = m - n;
                result += A(n, k);
            }
            return result;
        }
        else {
            return 1;
        }
    }

    function A(n, k) {
        if (n >= k && k == 1) {
            return 1;
        } else if (n >= k && k == 2) {
            if (n % 2 == 1) {
                return (n + 1) / 2;
            } else {
                return (n / 2) + 1;
            }
        } else if (n >= k && k >= 4) {
            return C(n) + A(n - k, k) + B(n, k);
        }
        else if (n >= 4 && n < k) {
            k = n;
            return C(n) + A(n - k, k) + B(n, k);
        }
        else {
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

    let ps_function = partition_by_size(n, k);
    console.log(ps_function);

    let endTime = performance.now();
    let duration = ((endTime - startTime) / 1000).toFixed(6);
    console.log(`running time: ${duration} seconds`);
}

else {
    console.log("undefined");
}
