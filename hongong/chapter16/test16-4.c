#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
        char    temp[80];
        char    *sp[3];
        int             i;

        for (i = 0; i < 3; i++)
        {
                printf("���ڿ��� �Է��ϼ��� : ");
                fgets(temp, 80, stdin);
                sp[i] = (char *)malloc(sizeof(char) * strlen(temp) + 1);
                strcpy(sp[i], temp);
        }
        for (i = 0; i < 3; i++)
        {
                printf("%s\n", sp[i]);
        }
        for (i = 0; i < 3; i++)
        {
                free(sp[i]); // �����Ҵ� ���� ��ȯ
        }
        return 0;
}
