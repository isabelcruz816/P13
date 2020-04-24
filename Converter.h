#pragma once
#ifndef _Converter_
#define _Converter_

#define DllExport   __declspec( dllexport )

DllExport int asciiBinaryToInt(const char *s);

DllExport int getHexValue(char c);

DllExport int asciiHEXToInt(char *s);

DllExport double asciiToDouble(char *s);

#endif