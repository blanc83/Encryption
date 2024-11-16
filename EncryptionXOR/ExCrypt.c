#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "ExtenCrypt.h"

void ExECrpyt(char* FilePath, const char* exe) { // 확장자 추가
	strcat(FilePath, exe);
}
void ExDCrpyt(char* FilePath, const char* exe) { //확장자 삭제
	char* Ext = srtstr(FilePath, exe);
	if (Ext != NULL) {
		*Ext = '\0';
	}
}
int FindTxt(const char* FilePath); // 텍스트 파일이면 
