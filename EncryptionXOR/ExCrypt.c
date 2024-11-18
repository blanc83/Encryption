//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include "ExtenCrypt.h"
//// 파일 확장자 관련
//void ExECrpyt(char* FilePath, const char* exen) { // 확장자 추가
//	if (strstr(FilePath, exen) == NULL) {
//		strcat(FilePath, exen);
//		printf("Encrypted File: %s\n", FilePath);
//	}
//	else {
//		printf("already has the %s extension.", exen);
//	}
//}
//void ExDCrpyt(char* FilePath, const char* exe) { //확장자 삭제
//	char* Ext = strstr(FilePath, exe);
//	if (Ext != NULL) {
//		*Ext = '\0'; // 확장자 제거 수정X
//		printf("%s\nDecrypted File.\n", FilePath);
//	}
//	//else {
//		printf("not found in %s\n", FilePath);
//	}
//}
