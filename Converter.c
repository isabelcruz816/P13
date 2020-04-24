// Converter.c : Degines the epxorted functions for the DLL.
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Converter.h"
/*
    asciiBinaryToInt
    Converts a binary string to int
    @param char * s
    @return int
*/
int asciiBinaryToInt(const char *s) {
    int res = 0;
    int n = strlen(s) - 1;

    if ( s == NULL) {
        return 0;
    }

    for(int i = 0; s[i] != '\0'; i++) {
        int val = 0;
        if(s[i] == '0' || s[i] == '1') {
            if(s[i] == '1'){
                val = pow(2, n);
                res += val;
            }
            n = n - 1;
        }
        else {
            return 0;
        }
    }
    return res;
}
/*
    getHexValue
    Gets int value of hex letters
    @param char
    @return int
*/
int getHexValue(char c){
    switch (c) {
        case 'A' : return 10;
        case 'a' : return 10;
        case 'B' : return 11;
        case 'b' : return 11;
        case 'C' : return 12;
        case 'c' : return 12;
        case 'D' : return 13;
        case 'd' : return 13;
        case 'E' : return 14;
        case 'e' : return 14;
        case 'F' : return 15;
        case 'f' : return 15;

        default : return -1;
    }
}
/*
    asciiHEXToInt
    Converts a hexadecimal string to int
    @param char * s
    @return int
*/
int asciiHEXToInt(char *s) {
    int n = strlen(s) - 1;
    int res = 0;

    if(s == NULL){
        return 0;
    }

    for(int i = 0; s[i] != '\0'; i++){
        int val = 0;
        if((s[i] >= 48 && s[i] <= 57) || getHexValue(s[i]) != -1){
            if(s[i] >= 48 && s[i] <= 57){
                val = (s[i] - 48) * pow(16, n);
            }
            else {
                val = getHexValue(s[i]) * pow(16,n);
            }
            res += val;
            n = n - 1;
        }
        else{
            break;
        }
    }
    return res;
}
/*
    asciiToDouble
    Converts a digits string to a double
    @param char * s
    @return double
*/
double asciiToDouble(char *s) {
    double res = 0.0;

    char *pos = strchr(s, '.');
    int posIndex = pos - s;
    double base = pow(10, posIndex - 1);
    double multiplier = 0.0;
    int start = 0;

    if(s[0] == '-'){
        start = 1;
        multiplier = -1;

    }
    else{
        multiplier = 1;
    }

    if(pos == NULL) {
        posIndex = strlen(s) - 1 - start;
        base = pow(10, posIndex);

        for(int i = start; s[i] != '\0'; i++){
            int num = s[i] - '0';
            res += num * base;
            base = base / 10;
        }
        return res * multiplier;
    }

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '.'){
            continue;
        }
        int num = s[i] - '0';
        res += num * base;
        base = base / 10;
    }

    return res * multiplier;
}