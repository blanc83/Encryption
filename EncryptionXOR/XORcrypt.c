#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "XOR.h"

char* PATH() {
	static char pPath[MAX_PATH];
	char* NAME = getenv("USER");
	if (NAME != NULL) {
		printf(PATH, sizeof(pPath), "%s\\Desktop\\", NAME); //기본경로 바탕화면(""부분 경로변경필요)
	}
	return pPath;
}
void dCryptFile(const char* File, const char* KEY) {
	eCryptFile(File, KEY);
	printf("%s\nDecrypt File.", File);
}
void eCryptFile(const char* File, const char* KEY) {
	FILE* pfile = fopen(File, "rb");
	if (!pfile) {
		printf("%s\nFail Open File.", File);
		return 0;
	}
	fseek(pfile, 0, SEEK_END);
	long File_SIZE = ftell(File);
	fseek(pfile, 0, SEEK_SET);
	char* buff = malloc(File_SIZE);
	if (buff == NULL) {
		printf("Fail Assign Memory");
		fclose(pfile);
		return 0;
	}
	fread(buff, 1, File_SIZE, pfile);
	fclose(pfile);

	int KEY_ = strlen(KEY);

	for (int i = 0; i < File_SIZE; i++) {
		buff[i] ^= KEY[i % KEY_];
	}
	pfile = fopen(File, "wb");
	if (!pfile) {
		printf("%s\nFaild Open File.", File);
		free(buff);
		return 0;
	}
	fwrite(buff, 1, File_SIZE, pfile);
	fclose(pfile);
	free(buff);
	printf("%s\nEncrypted File.", File);
}