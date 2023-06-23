function decimalToBinary(num: number) {
    let binary: string = '';
    do {
        binary += (num % 2).toString();
        num = Math.floor(num / 2);
    } while (num > 0);
    return binary;
}

// @ts-ignore
function main() {
    let result: string;
    if (process.argv.length == 3) {
        let inputStr = process.argv[2];
        let decimal = parseFloat(inputStr);
        if (decimal >= 0 && decimal <= Number.MAX_SAFE_INTEGER) {
            result = `${inputStr} -> ${decimalToBinary(decimal)}`;
        }
        else {
            result = `${inputStr} -> Input error!`;
        }
    }
    else {
        result = `Empty input!`;
    }
    console.log(result);
}

main();