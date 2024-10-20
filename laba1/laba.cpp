// Удалить все символы, которые повторяются 
// больше одного раза подряд, кроме знаков «+», «-» и цифр. 
// Если таких символов нет, 
// добавить в конец строки символ «*».
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

void mainFunk(char str[]) {
    int length = std::strlen(str);
    int writeIndex = 0;
    bool hasRepetitions = false;

    for (int i = 0; i < length; ++i) {
        char current = str[i];
        int count = 1;

        while (i + 1 < length && str[i + 1] == current) {
            ++count;
            ++i;
        }
 
        if (count == 1 || current == '+' || current == '-' || isdigit(current)) {
            str[writeIndex++] = current;
        }
        else {
            hasRepetitions = true;
        }
    }

    if (!hasRepetitions) {
        str[writeIndex++] = '*';
    }
    str[writeIndex] = '\0'; 
}

int funk1() {
    const int maxLength = 100;
    char inputString[maxLength];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxLength);

    int length = 0;
    while (inputString[length] != '\0') {
        ++length;
    }

    mainFunk(inputString);

    std::cout << "Processed string: " << inputString << std::endl;

    return 0;
}

int funk2() {
    const int maxLength = 100;
    char inputString[maxLength];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxLength);

    int length = 0;
    while (inputString[length] != '\0') {
        ++length;
    }

    mainFunk(inputString);

    std::cout << "Processed string: " << inputString << std::endl;

    return 0;
}

int funk3() {
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";
    const int maxLength = 100;
    char inputString[maxLength];


   
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == nullptr) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if (fgets(inputString, maxLength, inputFile) == nullptr) {
        std::cerr << "Error reading from input file" << std::endl;
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);


    char* newlinePos = strchr(inputString, '\n');
    if (newlinePos != nullptr) {
        *newlinePos = '\0';
    }

    
    mainFunk(inputString);


    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == nullptr) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    if (fputs(inputString, outputFile) == EOF) {
        std::cerr << "Error writing to output file" << std::endl;
        fclose(outputFile);
        return 1;
    }
    fclose(outputFile);

    std::cout << "Processed string written to " << outputFileName << std::endl;

    return 0;
}


void main() {
    funk3();
}
