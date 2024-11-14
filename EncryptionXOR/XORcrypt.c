#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "XOR.h"

char* PATH() {
	static char pPath[MAX_PATH];
	char* NAME = getenv("USER");
	if (NAME != NULL) {
		printf(PATH, sizeof(pPath), "%s\\Desktop\\", NAME);
	}
	return pPath;
}
