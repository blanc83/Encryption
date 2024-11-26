#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "XOR.h"

// 암호화된 파일을 복호화하여 원본 파일로 되돌린다.
void dCryptFile(const char* File, const char* KEY) {
    eCryptFile(File, KEY); // 복호화는 암호화와 동일한 방식으로 수행
    MessageBoxA(NULL, "XOR", "XOR DCrypted!", MB_OK); // 복호화 완료 메시지 박스 표시
    printf("%s\nDecrypted File.\n", File); // 콘솔에 복호화된 파일 정보 출력
}

// 파일 내용을 암호화하여 덮어쓰게 된다.
void eCryptFile(const char* File, const char* KEY) {
    // 바이너리 모드로 파일 열기
    FILE* pfile = fopen(File, "rb"); // rb = 읽기 전용 바이너리 모드
    if (!pfile) {
        printf("%s\nFailed to Open File.\n", File); // 파일 열기 실패 시 오류 메시지 출력
        return;
    }

    // 파일의 끝으로 이동하여 크기 확인
    fseek(pfile, 0, SEEK_END);
    size_t File_SIZE = ftell(pfile); // 파일 크기
    fseek(pfile, 0, SEEK_SET); // 파일 포인터를 처음으로 되돌리기

    // 파일 크기에 맞는 메모리 할당
    char* buff = malloc(File_SIZE); // 파일 크기만큼 메모리 할당
    if (buff == NULL) { // 메모리 할당 실패 시 오류 메시지 출력
        printf("Failed to Allocate Memory.\n");
        fclose(pfile); // 파일을 연 후 메모리 할당 실패 시 파일 닫기
        return;
    }

    // 파일의 내용을 읽어버리기
    fread(buff, 1, File_SIZE, pfile); // 파일 내용 읽기
    fclose(pfile); // 파일 닫기

    // 키 길이를 구해서 XOR 암호화 처리
    size_t KEY_LEN = strlen(KEY); // 키의 길이

    // 파일 내용에 XOR 암호화 적용
    for (size_t i = 0; i < File_SIZE; i++) {
        buff[i] ^= KEY[i % KEY_LEN]; // 파일의 각 바이트에 키를 XOR 연산
    }

    // 암호화된 데이터를 다시 파일에 쓰기
    pfile = fopen(File, "wb"); // 파일을 덮어쓰기 위해 쓰기 모드로 열기
    if (!pfile) {
        printf("%s\nFailed to Open File.\n", File); // 파일 열기 실패 시 오류 메시지 출력
        free(buff);
        return;
    }

    fwrite(buff, 1, File_SIZE, pfile); // 암호화된 데이터를 파일에 쓰기
    fclose(pfile);
    free(buff);
    printf("%s\nEncrypted File.\n", File); // 암호화 완료 메시지 출력
    MessageBoxA(NULL, "XOR", "XOR ECrypted!", MB_OK);
}
/* XOR암호화는 데이터를 뒤섞으므로 비트들이 깨질수있음 따라서
    암호화해도 일부 암호화값들이 비워지고 띄어쓰기 되는 경우 발생*/
