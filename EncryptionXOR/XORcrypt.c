#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "XOR.h"

void dCryptFile(const char* File, const char* KEY) {
    eCryptFile(File, KEY);
    printf("%s\nDecrypted File.\n", File);
}

void eCryptFile(const char* File, const char* KEY) {
    FILE* pfile = fopen(File, "rb");
    if (!pfile) {
        printf("%s\nFailed to Open File.\n", File);
        return;
    }

    fseek(pfile, 0, SEEK_END);
    size_t File_SIZE = ftell(pfile);
    fseek(pfile, 0, SEEK_SET);

    char* buff = malloc(File_SIZE);
    if (buff == NULL) {
        printf("Failed to Allocate Memory.\n");
        fclose(pfile);
        return;
    }
    fread(buff, 1, File_SIZE, pfile);
    fclose(pfile);

    size_t KEY_LEN = strlen(KEY);

    for (size_t i = 0; i < File_SIZE; i++) {
        buff[i] ^= KEY[i % KEY_LEN];
    }

    pfile = fopen(File, "wb");
    if (!pfile) {
        printf("%s\nFailed to Open File.\n", File);
        free(buff);
        return;
    }

    fwrite(buff, 1, File_SIZE, pfile);
    fclose(pfile);

    free(buff);
    printf("%s\nEncrypted File.\n", File);
}
