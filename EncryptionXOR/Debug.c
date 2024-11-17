#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RSAdCryptFile(const char* File, const char* PrivateKey) {
    FILE* pFile = fopen(File, "rb");
    if (!pFile) {
        printf("Failed to open file: %s\n", File);
        return;
    }

    fseek(pFile, 0, SEEK_END);
    size_t File_SIZE = ftell(pFile);
    rewind(pFile);

    char* buffer = malloc(File_SIZE);
    if (!buffer) {
        printf("Memory Error.\n");
        fclose(pFile);
        return;
    }

    fread(buffer, 1, File_SIZE, pFile);
    fclose(pFile);

    size_t Keyl = strlen(PrivateKey);
    printf("Buffer read successfully, size: %zu\n", File_SIZE);

    // RSA ��ȣȭ
    for (size_t i = 0; i < File_SIZE; i++) {
        buffer[i] = (buffer[i] - PrivateKey[i % Keyl] + 256) % 256;  // XOR ������� ��ȣȭ
    }

    // �����: ��ȣȭ�� �����͸� ���
    printf("Decrypted buffer: %s\n", buffer);

    pFile = fopen(File, "wb");  // ������ ���� ���� �ٽ� ����
    if (!pFile) {
        printf("Failed to open file for writing: %s\n", File);
        free(buffer);
        return;
    }

    fwrite(buffer, 1, File_SIZE, pFile);
    fclose(pFile);
    free(buffer);

    printf("Decrypted RSA: %s\n", File);
}

void RSAeCryptFile(const char* File, const char* PKey) {
    FILE* pFile = fopen(File, "rb+");  // �б� �� ���� ���� ����
    if (!pFile) {
        printf("Failed to open file: %s\n", File);
        return;
    }

    fseek(pFile, 0, SEEK_END);
    size_t File_SIZE = ftell(pFile);
    rewind(pFile);

    char* buffer = malloc(File_SIZE);
    if (!buffer) {
        printf("Memory Error.\n");
        fclose(pFile);
        return;
    }

    fread(buffer, 1, File_SIZE, pFile);
    fclose(pFile);

    size_t Keyl = strlen(PKey);
    printf("Buffer read successfully, size: %zu\n", File_SIZE);

    // RSA ��ȣȭ
    for (size_t i = 0; i < File_SIZE; i++) {
        buffer[i] = (buffer[i] + PKey[i % Keyl]) % 256;  // XOR ������� ��ȣȭ
    }

    // �����: ��ȣȭ�� �����͸� ���
    printf("Encrypted buffer: %s\n", buffer);

    pFile = fopen(File, "wb");  // ������ ���� ���� �ٽ� ����
    if (!pFile) {
        printf("Failed to open file for writing: %s\n", File);
        free(buffer);
        return;
    }

    fwrite(buffer, 1, File_SIZE, pFile);
    fclose(pFile);
    free(buffer);

    printf("Encrypted RSA file: %s\n", File);
}
