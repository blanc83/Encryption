#include <stdio.h>
#include <ctype.h>
#include "ROT13.h"
#include <Windows.h>

// ROT13 ��ȣȭ �Լ�
// �Էµ� �ؽ�Ʈ�� ROT13 ��ȣȭ ������� ��ȯ�Ѵ�. ROT13�� ��ҹ��� ���ĺ��� ��ȯ
void rot13_encrypt(char* text) {
    // ���ڿ��� �� ���ھ� ó���Ѵ�.
    for (int i = 0; text[i] != '\0'; i++) {
        // ���ĺ� ������ ��츸 ó��
        if (isalpha(text[i])) {
            // �ҹ����� ���
            if (islower(text[i])) {
                text[i] = ((text[i] - 'a' + 13) % 26) + 'a';
            }
            // �빮���� ���
            else {
                text[i] = ((text[i] - 'A' + 13) % 26) + 'A';
            }
        }
    }
}

// ROT13�� ��Ī ��ȣ�̹Ƿ� ��ȣȭ �Լ��� ��ȣȭ �Լ��� �����ϴ�.
void rot13_decrypt(char* text) {
    // ��ȣȭ �Լ� ȣ��� ��ȣȭ ó��
    rot13_encrypt(text); // ��Ī ��ȣȭ ����̹Ƿ�, ��ȣȭ�� ��ȣȭ �Լ��� ó���Ѵ�.
}

// ���Ͽ��� �ؽ�Ʈ�� �а� ROT13 ������� ��ȣȭ �� �����ϴ� �Լ�
void rot13_encrypt_file(const char* filePath) {
    // ������ �б� �� ���� ���� ����
    FILE* file = fopen(filePath, "r+");
    if (!file) {
        perror("Error opening file"); // ���� ���� ���� �� ���� �޽��� ���
        return;
    }

    // ���� ���� �б�
    char content[1024] = { 0 }; // �ؽ�Ʈ�� ������ �迭
    fread(content, sizeof(char), sizeof(content) - 1, file); // �ִ� 1024 ���� �б�
    fclose(file);

    // ROT13 ��ȣȭ ����
    rot13_encrypt(content);

    // ��ȣȭ�� ������ �ٽ� ���Ͽ� ����.
    file = fopen(filePath, "w");
    if (!file) {
        perror("File Error."); // ���� ���� ���� �� ���� �޽��� ���
        return;
    }
    fwrite(content, sizeof(char), strlen(content), file); // ��ȣȭ�� �ؽ�Ʈ�� ���Ͽ� ����
    fclose(file);

    // ����ڿ��� ROT13 ��ȣȭ �Ϸ� �޽��� ǥ��
    MessageBoxA(NULL, "Rot13 Crypted!", "Rot13", MB_OK);
    printf("Crypted."); // �ֿܼ� ��ȣȭ �Ϸ� �޽��� ���
}

// ��ȣȭ�� ��ȣȭ�� ������ �����̹Ƿ�, ��ȣȭ �Լ� ȣ��� ��ȣȭ ó��
void rot13_decrypt_file(const char* filePath) {
    // ��ȣȭ�� ������ �о� ��ȣȭ ����
    rot13_encrypt_file(filePath); // ������ �Լ� ȣ��� ��ȣȭ �۾� ����
}
