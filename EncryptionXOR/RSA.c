#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RSA.h"

void RSAeCryptFile(const char* File, const char* PKey) {
	FILE* pFile = fopen(File, "r+");
	if (!pFile) {
		printf("Failed Open File.");
		return 0;
	}

	fseek(pFile, 0, SEEK_END);
	size_t File_SIZE = ftell(pFile);
	rewind(pFile);
}