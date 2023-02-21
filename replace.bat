echo off
chcp 65001
set PROGRAM=node src\replace.js

%PROGRAM% testData\replace\data00.txt testData\replace\result00.txt " " " "

%PROGRAM% testData\replace\data01.txt testData\replace\result01.txt ma pa

%PROGRAM% testData\replace\data02.txt testData\replace\result02.txt 1231234 *******

%PROGRAM% testData\replace\data03.txt testData\replace\result03.txt и ii

%PROGRAM% testData\replace\data01.txt testData\replace\protected.txt nope da
rem Ошибка записи.
%PROGRAM% testData\nope\data03.txt testData\replace\result03.txt и i
rem Нет исходника.
%PROGRAM% testData\replace\data01.txt testData\replace\result01.txt " "
rem Нехватка агументов.