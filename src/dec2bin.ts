function decimalToBinary(num: number) {
    let binary: string = '';
    do {
        if (num % 2 == 1) {
            binary = "1" + binary;
        } else {
            binary = "0" + binary;
        }
        num = Math.floor(num / 2);
    } while (num > 0);
    return binary;
};

if (!process.argv[2]) {
    console.log(`Enter a natural number.`);
}
else {
    let decimal = parseInt(process.argv[2]);
    if ((decimal % 1 === 0) && (decimal >= 0)) {
        console.log(decimalToBinary(decimal));
    }
    else {
        console.log(`'${decimal}' is not natural number.`);
    };
};