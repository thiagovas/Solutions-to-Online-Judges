/*
     Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int current = 0;

int findLetter(char *str, char key)
{
    int len = strlen(str);
    int i = 0;
    
    for(i = 0; i < len; i++)
        if(str[i] == key)
            return i;
    
    return -1;
}

void rMakeTreePreIn(char *pre, char *in, int begin, int end)
{
    if(begin > end) return;
    int root = findLetter(in, pre[current]);
    
    current++;
    if(begin <= root)
        rMakeTreePreIn(pre, in, begin, root-1);
    
    if(root <= end)
        rMakeTreePreIn(pre, in, root+1, end);

    printf("%c", in[root]);
}

void makeTreePreIn(char *pre, char *in)
{
    current = 0;
    rMakeTreePreIn(pre, in, 0, strlen(pre)-1);
}

int main()
{
    char preorder[30], inorder[30];
    
    while(scanf("%s%s", preorder, inorder) != EOF)
    {
        makeTreePreIn(preorder, inorder);
        printf("\n");
    }
    return 0;
}
