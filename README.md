# How to use Windows Dynamic Library
Make sure you have `Converter.dll` in your app's folder. If not, download it from this repo and add it to your folder.

1. Add the windows header to your client program `#include <windows.h>`
2. Create a HMODULE instance to point to your library
```
  HMODULE codeDLL = LoadLibraryA("Converter.h")
```
3. Create type defintions for the functions to be used of the DLL
```
  Example:
  typedef int (*BinaryFunc)(const char*);
```
4. Get the address of the process in the DLL using `GetProcAddress`
````
  BinaryFunc asciiBinaryToInt = GetProcAddress(codeDLL, "asciiBinaryToInt);
