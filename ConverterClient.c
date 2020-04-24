/* 
    Autor:
    Isabel Cruz
    Paulina Gonzalez

    Fecha: 24 abril 2020

    ConverterClient.c : Client app for Converter DLL
*/
#include<stdio.h>
#include <windows.h>
#include "Converter.h"

// Pointers to functions
typedef int (*BinaryToIntFunction)(const char*);
typedef int (*HexToIntFunction)(char*);
typedef double (*AsciiToDoubleFunc)(char*);

int main() {    
    const char* binario = "1011101";
    char* hex = "a9";

    HMODULE dll = LoadLibraryA("Converter.dll");

    // Load functions
    BinaryToIntFunction asciiBinaryToInt = (BinaryToIntFunction)GetProcAddress(dll, "asciiBinaryToInt");
    HexToIntFunction asciiHEXToInt = (HexToIntFunction)GetProcAddress(dll, "asciiHEXToInt");
    AsciiToDoubleFunc asciiToDouble = (AsciiToDoubleFunc)GetProcAddress(dll, "asciiToDouble");

    if (dll != NULL) {
        if (asciiBinaryToInt != NULL) {
            printf("Binary: %d\n", asciiBinaryToInt(binario));
        }
        else {
            printf("Proceso asciiBinaryToInt no encontrado.\n");
        }

        if(asciiHEXToInt != NULL) {
            printf("HEX: %d\n", asciiHEXToInt("a9"));
        }
        else {
            printf("Proceso asciiHEXToInt no encontrado.\n");
        }

        if (asciiToDouble != NULL) {
            printf("Double: %f\n", asciiToDouble("3.5"));
        }
        else {
            printf("Proceso asciiToDoble no encontrado.\n");
        }
    }
    else {
        printf("Libreria no encontrada.\n");
    }

    FreeModule(dll);
    return 0;
}