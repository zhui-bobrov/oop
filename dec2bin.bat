echo off
chcp 65001
set PROGRAM=node src\dec2bin.js

%PROGRAM% 1

%PROGRAM% 0

%PROGRAM% 9090909090

%PROGRAM%

%PROGRAM% -1

%PROGRAM% string'a

