#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "XOR.h"

// ��ȣȭ�� ������ ��ȣȭ�Ͽ� ���� ���Ϸ� �ǵ�����.
void dCryptFile(const char* File, const char* KEY) {
    eCryptFile(File, KEY); // ��ȣȭ�� ��ȣȭ�� ������ ������� ����
    MessageBoxA(NULL, "XOR", "XOR DCrypted!", MB_OK); // ��ȣȭ �Ϸ� �޽��� �ڽ� ǥ��
    printf("%s\nDecrypted File.\n", File); // �ֿܼ� ��ȣȭ�� ���� ���� ���
}

// ���� ������ ��ȣȭ�Ͽ� ����� �ȴ�.
void eCryptFile(const char* File, const char* KEY) {
    // ���̳ʸ� ���� ���� ����
    FILE* pfile = fopen(File, "rb"); // rb = �б� ���� ���̳ʸ� ���
    if (!pfile) {
        printf("%s\nFailed to Open File.\n", File); // ���� ���� ���� �� ���� �޽��� ���
        return;
    }

    // ������ ������ �̵��Ͽ� ũ�� Ȯ��
    fseek(pfile, 0, SEEK_END);
    size_t File_SIZE = ftell(pfile); // ���� ũ��
    fseek(pfile, 0, SEEK_SET); // ���� �����͸� ó������ �ǵ�����

    // ���� ũ�⿡ �´� �޸� �Ҵ�
    char* buff = malloc(File_SIZE); // ���� ũ�⸸ŭ �޸� �Ҵ�
    if (buff == NULL) { // �޸� �Ҵ� ���� �� ���� �޽��� ���
        printf("Failed to Allocate Memory.\n");
        fclose(pfile); // ������ �� �� �޸� �Ҵ� ���� �� ���� �ݱ�
        return;
    }

    // ������ ������ �о������
    fread(buff, 1, File_SIZE, pfile); // ���� ���� �б�
    fclose(pfile); // ���� �ݱ�

    // Ű ���̸� ���ؼ� XOR ��ȣȭ ó��
    size_t KEY_LEN = strlen(KEY); // Ű�� ����

    // ���� ���뿡 XOR ��ȣȭ ����
    for (size_t i = 0; i < File_SIZE; i++) {
        buff[i] ^= KEY[i % KEY_LEN]; // ������ �� ����Ʈ�� Ű�� XOR ����
    }

    // ��ȣȭ�� �����͸� �ٽ� ���Ͽ� ����
    pfile = fopen(File, "wb"); // ������ ����� ���� ���� ���� ����
    if (!pfile) {
        printf("%s\nFailed to Open File.\n", File); // ���� ���� ���� �� ���� �޽��� ���
        free(buff);
        return;
    }

    fwrite(buff, 1, File_SIZE, pfile); // ��ȣȭ�� �����͸� ���Ͽ� ����
    fclose(pfile);
    free(buff);
    printf("%s\nEncrypted File.\n", File); // ��ȣȭ �Ϸ� �޽��� ���
    MessageBoxA(NULL, "XOR", "XOR ECrypted!", MB_OK);
}
/* XOR��ȣȭ�� �����͸� �ڼ����Ƿ� ��Ʈ���� ���������� ����
    ��ȣȭ�ص� �Ϻ� ��ȣȭ������ ������� ���� �Ǵ� ��� �߻�*/
