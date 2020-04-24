// ConverterClient.c : Client app for Converter DLL
#include<stdio.h>
#include <windows.h>
#include "Converter.h"

// Load functions
typedef int (*BinaryToIntFunction)(const char*);
typedef int (*HexToIntFunction)(char*);
typedef double (*AsciiToDoubleFunc)(char*);

int main() {    
    const char* binario = "1011101";
    char* hex = "a9";
    char* doble = "2.3";

    HMODULE dll = LoadLibraryA("Converter.dll");

    BinaryToIntFunction asciiBinaryToInt = (BinaryToIntFunction)GetProcAddress(dll, "asciiBinaryToInt");
    HexToIntFunction asciiHEXToInt = (HexToIntFunction)GetProcAddress(dll, "asciiHEXToInt");
    AsciiToDoubleFunc asciiToDouble = (AsciiToDoubleFunc)GetProcAddress(dll, "asciiToDouble");

    if (dll != NULL) {
        if (asciiBinaryToInt != NULL) {
            printf("%d\n", asciiBinaryToInt(binario));
        }
        else {
            printf("Proceso asciiBinaryToInt no encontrado.\n");
        }

        if(asciiHEXToInt != NULL) {
            printf("%d\n", asciiHEXToInt("a9"));
        }
        else {
            printf("Proceso asciiHEXToInt no encontrado.\n");
        }

        if (asciiToDouble != NULL) {
            printf("%d\n", asciiToDouble("20"));
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