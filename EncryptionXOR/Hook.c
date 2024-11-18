#include "HOOK.h"
#include <Windows.h>
void HookTxt(const char* filePath, const char* text) {
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Not Found file %s\n", filePath);
        return;
    }

    fprintf(file, "%s\n", text);
    fclose(file);

    printf("Hook.\n%s", filePath);
    MessageBoxA(NULL, "Hook!", "Hooking", MB_OK);
}
