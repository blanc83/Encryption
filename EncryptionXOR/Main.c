#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "XOR.h"

char File[100];
char KEY[50];
int or ;
char* PATH() {
    static char pPath[100];
    snprintf(pPath, sizeof(pPath), "C:\\Users\\05053\\OneDrive\\����"); //��� �����ʿ�
    return pPath;
}
int main() {
    char* dPath = PATH();
    printf("Please Enter File Name: ");
    scanf("%s", File);
   
    char Path_[200];
    snprintf(Path_, sizeof(Path_), "%s\\%s", dPath, File); // ��ü��� �����κ� ����X

    printf("Please Enter KEY: ");
    scanf("%s", KEY);

    printf("1. EnCrypt\n2. DeCrypt: ");
    scanf("%d", &or );
    //if (or == 1) {
    //    eCryptFile(Path_, KEY);
    //}
    //else if (or == 2) {
    //    dCryptFile(Path_, KEY);
    //}
    //else {
    //    printf("ERROR: Invalid option\n");
    //}
    switch (or ) { // ����߰����� switch�� ����
    case 1:
        eCryptFile(Path_, KEY);
        break;
    case 2:
        dCryptFile(Path_, KEY);
        break;
    default:
        printf("ERROR: Invalid option\n");
        break;
    }
    system("PAUSE");
    return 0;
    
}
