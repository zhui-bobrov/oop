echo off
chcp 65001
set PROGRAM=node src\multmatrix.js

%PROGRAM% testData\multMatrix\matrix1.txt testData\multMatrix\matrix2.txt

%PROGRAM% testData\multMatrix\matrix2.txt testData\multMatrix\matrix3.txt

%PROGRAM% testData\multMatrix\brokenMatrix1.txt testData\multMatrix\matrix3.txt

%PROGRAM% testData\multMatrix\brokenMatrix2.txt testData\multMatrix\matrix3.txt
