#include "HOOK.h"
#include <Windows.h>

// HookTxt �Լ��� �־��� ���� ��ο� �ؽ�Ʈ�� ����ϰ�, ��ŷ�� �ùķ��̼��ϴ� �Լ��̴�.
void HookTxt(const char* filePath, const char* text) {
    // ������ ���� ���� ����
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        // ������ �� �� ������ ���� �޽��� ���
        printf("Not Found file %s\n", filePath);
        return; // ���� �߻� �� �Լ� ����
    }

    // ���Ͽ� �ؽ�Ʈ ���
    fprintf(file, "%s\n", text); // �ؽ�Ʈ ���� �ٹٲ��� �߰��Ͽ� ���
    fclose(file); // ���� �ݱ�

    // ��ŷ ���� �� ��µǴ� �޽���
    printf("Hook.\n%s", filePath); // �ֿܼ� ���� ��� ���
    // ��ŷ�� �Ϸ�Ǿ����� �˸��� �޽��� �ڽ� ǥ��
    MessageBoxA(NULL, "Hook!", "Hooking", MB_OK);
}
