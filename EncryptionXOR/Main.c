#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "XOR.h"
#include "RSA.h"
#include "Hook.h"
char File[100];
char KEY[100];
int or ;
char* PATH() {
    static char pPath[100];
    snprintf(pPath, sizeof(pPath), "C:\\Users\\05053\\OneDrive\\문서"); //경로 수정필요
    return pPath;
}
int main() {
    char* dPath = PATH();
    printf("Please Enter File Name\n");
    scanf("%s", File);
    char Path_[300];
    snprintf(Path_, sizeof(Path_), "%s\\%s", dPath, File); // 전체경로 생성부분 수정X

    printf("Please Enter KEY: ");
    scanf("%s", KEY);

    printf("1. XOR Encrypt\n2. XOR Decrypt\n3. Hook Txt\n");
    printf("Please Enter Number : ");
    scanf("%d", &or );
    //if (or == 1) {
    //    eCryptFile(Path_, KEY);
    //}
    //else if (or == 2) {
    //    dCryptFile(Path_, KEY);
    //}
    //else {
    //    printf("Invaild\n");
    //}
    switch (or ) { // 기능추가위해 switch로 변경
    case 1:
        eCryptFile(Path_, KEY);
        break;
    case 2:
        dCryptFile(Path_, KEY);
        break;
    case 3:
        printf("Enter Text. : ");
        char text[200];
        getchar();
        fgets(text, sizeof(text), stdin); // 텍스트 입력
        text[strcspn(text, "\n")] = '\0';
        HookTxt(Path_, text);
        break;
    //case 3:
    //    RSAeCryptFile(File, KEY);  // RSA 암호화
    //    break;
    //case 4:
    //    RSAdCryptFile(File, KEY);  // RSA 복호화
    //    break;
    //case 3:
    //    ExECrpyt(Path_, ".Crypt");
    //    break;
    //case 4:
    //    ExDCrpyt(Path_, ".Crypt");
    //    break;
    default:
        printf("ERROR: Invalid option\n");
        break;
    }
    system("PAUSE");
    return 0;
    
}
