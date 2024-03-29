const fs = require('fs');
const readline = require('readline');

//-----------------------------------------//

function replaceString(strLine, searchStr, replaceStr: string) {
    let resultStr: string = '';
    for (let i: number = 0; i < strLine.length;) {
        if (strLine.substring(i, i + searchStr.length) !== searchStr) {
            resultStr += strLine.charAt(i);
            i++;
        }
        else {
            resultStr += replaceStr;
            i += (searchStr.length);
        }
    }
    return resultStr;
}

function copyStreamWithReplacement(inputFile: string, outputFile: string, searchStr: string, replaceStr: string) {
    const readInterface = readline.createInterface({
        input: fs.createReadStream(inputFile)
    });

    readInterface.on('line', function (strLine: string) {
        fs.appendFile(outputFile, replaceString(strLine, searchStr, replaceStr) + '\n', function (error) {
            if (error) throw error;
        })
    });
    return 0;
}

const argv = process.argv;
if (argv.length < 6) {
    throw "Invalid argument count\n" +
    "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
}

let inputFile: string = argv[2];
let outputFile: string = argv[3];
let searchStr: string = argv[4];
let replaceStr: string = argv[5];

copyStreamWithReplacement(inputFile, outputFile, searchStr, replaceStr);