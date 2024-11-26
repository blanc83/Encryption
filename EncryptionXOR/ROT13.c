#include <stdio.h>
#include <ctype.h>
#include "ROT13.h"
#include <Windows.h>

// ROT13 암호화 함수
// 입력된 텍스트를 ROT13 암호화 방식으로 변환한다. ROT13은 대소문자 알파벳만 변환
void rot13_encrypt(char* text) {
    // 문자열을 한 문자씩 처리한다.
    for (int i = 0; text[i] != '\0'; i++) {
        // 알파벳 문자일 경우만 처리
        if (isalpha(text[i])) {
            // 소문자일 경우
            if (islower(text[i])) {
                text[i] = ((text[i] - 'a' + 13) % 26) + 'a';
            }
            // 대문자일 경우
            else {
                text[i] = ((text[i] - 'A' + 13) % 26) + 'A';
            }
        }
    }
}

// ROT13은 대칭 암호이므로 암호화 함수와 복호화 함수가 동일하다.
void rot13_decrypt(char* text) {
    // 암호화 함수 호출로 복호화 처리
    rot13_encrypt(text); // 대칭 암호화 방식이므로, 복호화도 암호화 함수로 처리한다.
}

// 파일에서 텍스트를 읽고 ROT13 방식으로 암호화 후 저장하는 함수
void rot13_encrypt_file(const char* filePath) {
    // 파일을 읽기 및 쓰기 모드로 열기
    FILE* file = fopen(filePath, "r+");
    if (!file) {
        perror("Error opening file"); // 파일 열기 실패 시 오류 메시지 출력
        return;
    }

    // 파일 내용 읽기
    char content[1024] = { 0 }; // 텍스트를 저장할 배열
    fread(content, sizeof(char), sizeof(content) - 1, file); // 최대 1024 문자 읽기
    fclose(file);

    // ROT13 암호화 수행
    rot13_encrypt(content);

    // 암호화된 내용을 다시 파일에 쓴다.
    file = fopen(filePath, "w");
    if (!file) {
        perror("File Error."); // 파일 쓰기 실패 시 오류 메시지 출력
        return;
    }
    fwrite(content, sizeof(char), strlen(content), file); // 암호화된 텍스트를 파일에 저장
    fclose(file);

    // 사용자에게 ROT13 암호화 완료 메시지 표시
    MessageBoxA(NULL, "Rot13 Crypted!", "Rot13", MB_OK);
    printf("Crypted."); // 콘솔에 암호화 완료 메시지 출력
}

// 암호화와 복호화가 동일한 과정이므로, 암호화 함수 호출로 복호화 처리
void rot13_decrypt_file(const char* filePath) {
    // 암호화된 파일을 읽어 복호화 수행
    rot13_encrypt_file(filePath); // 동일한 함수 호출로 복호화 작업 수행
}
