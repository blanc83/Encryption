#include <stdio.h>
#include <ctype.h>
#include "ROT13.h"
#include <Windows.h>
// ROT13 암호화 함수
void rot13_encrypt(char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { // 알파벳 문자만 변환
            if (islower(text[i])) {
                text[i] = ((text[i] - 'a' + 13) % 26) + 'a';
            }
            else {
                text[i] = ((text[i] - 'A' + 13) % 26) + 'A';
            }
        }
    }
}

void rot13_decrypt(char* text) {
    rot13_encrypt(text); // 대칭 암호화
}

void rot13_encrypt_file(const char* filePath) {
    FILE* file = fopen(filePath, "r+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char content[1024] = { 0 };
    fread(content, sizeof(char), sizeof(content) - 1, file);
    fclose(file);

    rot13_encrypt(content);

    file = fopen(filePath, "w");
    if (!file) {
        perror("File Error.");
        return;
    }
    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
    MessageBoxA(NULL, "Rot13 Crypted!", "Rot13", MB_OK);
    printf("Crypted.");
}

void rot13_decrypt_file(const char* filePath) {
    rot13_encrypt_file(filePath); // 동일 함수 호출
}
