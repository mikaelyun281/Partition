
let [n, k] = [100, 50];
/* 
Please input [n,k] for the ps(n,k) function above here.
Note that when k>=n, then ps(n,k) = P(n), 
where P(n) is the partition function. 
*/


let startTime = performance.now()


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
        }
        else if (n >= k && k >= 3) {
            return C(n) + A(n - k, k) + B(n, k);
        }
        else if (n >= 3 && n < k) {
            k = n;
            return C(n) + A(n - k, k) + B(n, k);
        }
        else {
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
            result += (n + 1) / 2;
        } else {
            result += (n / 2) + 1;
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
