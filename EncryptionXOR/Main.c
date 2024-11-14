#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "XOR.h"

char File[100];
char KEY[50];
int or ;
int main() {
	char* dPath = PATH();
	printf("Please Enter File Name. : ");
	scanf("%s", File);

	char Path_[100];
	snprintf(Path_, sizeof(Path_), "%s%s", dPath, File);

	printf("Please Enter KEY : ");
	scanf("%s", KEY);
	printf("1.EnCrypt\n2.DeCrypt");
	scanf("%d", or );

	if (or == 1) {
		eCryptFile(Path_, KEY);
	}
	else if (or == 2) {
		dCryptFile(Path_, KEY);
	}
	else {
		printf("ERROR");
	}
	system("PAUSE");
	return 0;
}