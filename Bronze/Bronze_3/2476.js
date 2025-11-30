ck = (arr) => {
    for (let i = 1; i <= 6; i++) {
        if (i == arr[0] &&
            i == arr[1] &&
            i == arr[2]) {
            return [3, i];
        } else if ((i == arr[0] && i == arr[1]) ||
            (i == arr[0] && i == arr[2]) ||
            (i == arr[1] && i == arr[2])) {
            return [2, i];
        }
    }
    return [1,
        (() => {
            if (arr[0] > arr[1] && arr[0] > arr[2]) {
                return arr[0];
            } else if (arr[1] > arr[0] && arr[1] > arr[2]) {
                return arr[1];
            } else {
                return arr[2];
            }
        })()
    ]
}

let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().trim().split("\n");

let count = input[0];
let max = 0;
for (let i = 1; i <= count; i++) {
    let arr = input[i].split(" ");
    let result = ck(arr);
    let number;
    switch (result[0]) {
        case 1:
            number = result[1] * 100;
            if (max < number) { max = number; }
            break;
        case 2:
            number = result[1] * 100 + 1000;
            if (max < number) { max = number; }
            break;
        case 3:
            number = result[1] * 1000 + 10000;
            if (max < number) { max = number; }
            break;
    }
}

console.log(max);