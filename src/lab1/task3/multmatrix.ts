import * as fs from 'fs';

function readMatrix(filePath: string) {
    let matrix = [];
    let fileData = fs.readFileSync(filePath, 'utf8');
    let strList = fileData.split('\r\n');
    for (let i: number = 0; i < strList.length; i++) {
        matrix[i] = [];
        for (let str of strList[i].split(',')) {
            let num = parseFloat(str);
            if (!isNaN(num)) {
                matrix[i].push(num);
            } else {
                throw new Error(`${str} not a number!`);
            }
        }
    }

    return matrix;
}

function initMatrix(cols, rows, value: any = 0) {
    let matrix = [];
    for (let i: number = 0; i < cols; i++) {
        matrix[i] = [];
        for (let y: number = 0; y < rows; y++) {
            matrix[i][y] = value;
        }
    }

    return matrix;
}

function multMatrix(matrixA, matrixB) {
    let aCols = matrixA.length;
    let aRows = matrixA[0].length;
    let bCols = matrixB.length;
    let bRows = matrixB[0].length;
    if (aRows !== bCols) {
        throw new Error(`The number of rows A and columns B do not match!`);
    }

    let resultMatrix = initMatrix(aCols, bRows);
    for (let i: number = 0; i < aCols; i++) {
        for (let x: number = 0; x < bRows; x++) {
            for (let y: number = 0; y < aRows; y++) {
                resultMatrix[i][x] += matrixA[i][y] * matrixB[y][x];
            }
        }
    }

    return resultMatrix;
}

function roundingMatrix(matrix) {
    let roundedMatrix = [];

    for (let i: number = 0; i < matrix.length; i++) {
        roundedMatrix[i] = [];
        for (let y: number = 0; y < matrix[0].length; y++) {
            roundedMatrix[i][y] = parseFloat(matrix[i][y].toFixed(3));
        }
    }

    return roundedMatrix;
}

function printMatrix(matrix) {
    for (let matrixRow of matrix) {
        console.log(matrixRow.join(' | '))
    }
}

function main() {
    const argv = process.argv;
    let matrixA = readMatrix(argv[2]);
    let matrixB = readMatrix(argv[3]);
    let matrixC = multMatrix(matrixA, matrixB);
    printMatrix(roundingMatrix(matrixC));
}

main();
//TODO: ctrl+alt+L - форматирование