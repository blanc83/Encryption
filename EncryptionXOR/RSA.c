#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RSA.h"
void RSAdCryptFile(const char* File, const char* PrivateKey) {
	FILE* pFile = fopen(File, "r+");
	if (!pFile) {
		printf("Failed to open file: %s", File);
		return;
	}
	fseek(pFile, 0, SEEK_END);
	size_t File_SIZE = ftell(pFile);
	rewind(pFile);

	char* buffer = malloc(File_SIZE + 1);
	if (!buffer) {
		printf("Memory Error.");
		fclose(pFile);
		return;
	}

	fread(buffer, 1, File_SIZE, pFile);
	buffer[File_SIZE] = '\0';

	// RSA º¹È£È­
	for (size_t i = 0; i < File_SIZE; i++) {
		buffer[i] = (buffer[i] - PrivateKey[i % strlen(PrivateKey)] + 256) % 256;
	}

	rewind(pFile);
	fwrite(buffer, 1, File_SIZE, pFile);
	fclose(pFile);
	free(buffer);

	printf("Decrypted RSA: %s", File);
}
void RSAeCryptFile(const char* File, const char* PKey) {
	FILE* pFile = fopen(File, "r+");
	if (!pFile) {
		printf("Failed Open File.");
		return 0;
	}

	fseek(pFile, 0, SEEK_END);
	size_t File_SIZE = ftell(pFile);
	rewind(pFile);

	char* buf = malloc(File_SIZE + 1);
	if (!buf) {
		printf("Memory Error.");
		fclose(pFile);
		return 0;
	}
	fread(buf, 1, File_SIZE, pFile);
	buf[File_SIZE] = '\0';
	for (size_t i = 0; i < File_SIZE; i++) {
		buf[i] = (buf[i] + PKey[i %  strlen(PKey)]) % 256;
	}
	rewind(pFile);
	fwrite(buf, 1, File_SIZE, pFile);
	fclose(pFile);
	free(buf);

	printf("Encrypted RSA file:%s", File);
	return;

}