#include "HOOK.h"
#include <Windows.h>

// HookTxt 함수는 주어진 파일 경로에 텍스트를 기록하고, 후킹을 시뮬레이션하는 함수이다.
void HookTxt(const char* filePath, const char* text) {
    // 파일을 쓰기 모드로 열기
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        // 파일을 열 수 없으면 오류 메시지 출력
        printf("Not Found file %s\n", filePath);
        return; // 오류 발생 시 함수 종료
    }

    // 파일에 텍스트 기록
    fprintf(file, "%s\n", text); // 텍스트 끝에 줄바꿈을 추가하여 기록
    fclose(file); // 파일 닫기

    // 후킹 동작 시 출력되는 메시지
    printf("Hook.\n%s", filePath); // 콘솔에 파일 경로 출력
    // 후킹이 완료되었음을 알리는 메시지 박스 표시
    MessageBoxA(NULL, "Hook!", "Hooking", MB_OK);
}
