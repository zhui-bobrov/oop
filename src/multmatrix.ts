import * as fs from 'fs';

//-----------------------------------------//

function readMatrix(filePath: string) {
    let matrix = [];
    let fileData = fs.readFileSync(filePath, 'utf8');
    let strArray = fileData.split('\r\n');
    for (let i: number = 0; i < strArray.length; i++) {
        matrix[i] = [];
        for (let str of strArray[i].split(',')) {
            let num = parseFloat(str);
            if (!isNaN(num)) {
                matrix[i].push(num);
            }
            else {
                throw `${str} not a number!`
            };
        };
    };
//    for (let strLine of fileData.split('\r\n')) {
//        matrix.push(line.split(','))
//    };
    return matrix;
};

function initMatrix(cols, rows, value: any = 0) {
    let matrix = [];
    for (let i: number = 0; i < cols; i++) {
        matrix[i] = [];
        for (let y: number = 0; y < rows; y++) {
            matrix[i][y] = value;
        };
    };

    return matrix;
};

function multMatrix(matrixA, matrixB) {
    let aCols = matrixA.length;
    let aRows = matrixA[0].length;
    let bCols = matrixB.length;
    let bRows = matrixB[0].length;
    if (aRows !== bCols) {
        throw 'The number of rows A and columns B do not match!'
    }

    let resultMatrix = initMatrix(aCols,bRows);
    for (let i: number = 0; i < aCols; i++) {
        for (let x: number = 0; x < bRows; x++) {
            for (let y: number = 0; y < aRows; y++) {
//                console.log(`C${i}${x} += A${i}${y} * B${y}${x}`);
                resultMatrix[i][x] += matrixA[i][y] * matrixB[y][x];
            };
        };
    };

    return resultMatrix;
};

function roundingMatrix(matrix) {
    let roundedMatrix = [];

    for (let i:number = 0; i < matrix.length; i++) {
        roundedMatrix[i] = [];
        for (let y:number = 0; y < matrix[0].length; y++) {
            roundedMatrix[i][y] = parseFloat(matrix[i][y].toFixed(3));
        };
    };

    return roundedMatrix;
};

const argv = process.argv;
let matrixA = readMatrix(argv[2]);
let matrixB = readMatrix(argv[3]);
let matrixC = multMatrix(matrixA, matrixB);
console.log(roundingMatrix(matrixC));