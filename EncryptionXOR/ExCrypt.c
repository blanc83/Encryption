#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "ExtenCrypt.h"

void ExECrpyt(char* FilePath, const char* exe) { // Ȯ���� �߰�
	strcat(FilePath, exe);
}
void ExDCrpyt(char* FilePath, const char* exe) { //Ȯ���� ����
	char* Ext = srtstr(FilePath, exe);
	if (Ext != NULL) {
		*Ext = '\0';
	}
}
int FindTxt(const char* FilePath); // �ؽ�Ʈ �����̸� 
