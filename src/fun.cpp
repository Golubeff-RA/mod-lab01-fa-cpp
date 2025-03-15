// Copyright 2022 UNN-IASR

#include <cmath>
#include <iostream>
#include "fun.h"

bool isUpperLetter(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool isLowerLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

bool isLetter(char c) {
    return isUpperLetter(c) || isLowerLetter(c);
}

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (std::isspace(str[i])) {
            if (inWord && !hasDigit) {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
            }
            if (std::isdigit(str[i])) {
                hasDigit = true;
            }
        }
    }

    if (inWord && !hasDigit) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = false;
    bool firstLetter = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (std::isspace(str[i])) {
            if (inWord && validWord) {
                ++count;
            }
            inWord = false;
            validWord = false;
            firstLetter = false;
        } else if (!inWord) {
            inWord = true;
            if (isUpperLetter(str[i])) {
                validWord = true;
                firstLetter = true;
            } else {
                validWord = false;
            }
        } else if (validWord && !isLowerLetter(str[i])) {
            validWord = false;
        }
    }

    if (inWord && validWord) {
        ++count;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;
    unsigned int currentWordLength = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (std::isspace(str[i])) {
            if (inWord) {
                totalLength += currentWordLength;
                wordCount++;
                inWord = false;
                currentWordLength = 0;
            }
        } else {
            if (!inWord) {
                inWord = true;
            }
            currentWordLength++;
        }
    }

    if (inWord) {
        totalLength += currentWordLength;
        ++wordCount;
    }

    if (wordCount == 0) {
        return 0;
    }

    double avgLen = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(std::round(avgLen));
}
