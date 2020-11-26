#include <stdio.h>
#include <string.h>


int min(int x, int y, int z)
{
    int tmp = x < y ? x : y ;
    return tmp < z ? tmp : z;
}

void editDistance(char *str1, char *str2, int size1, int size2)
{
    int table[size1+1][size2+1];
    for (int i =0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            table[i][j] = (i == 0)                  ?                 j :       // 1st string empty, insert j char from 2nd
                          (j == 0)                  ?                 i :       // 2nd string empty, delete i char from 1st
                          (str1[i-1] == str2[j-1])  ?   table[i-1][j-1] :       // if chars same, ignore & continue to the rest
                                                        1 + min(
                                                            table[i-1][j],      // deletion
                                                            table[i][j-1],      // insertion
                                                            table[i-1][j-1]     // substitution
                                                        );
        }
    }

    printf(" \n\t# -");
    for (int j = 0; j < size2; j++)
        printf(" %c -", str2[j]);
    printf("\n");
    printf("\n------------------------------------------------------------------\n");

    for (int i = 0; i <= size1; i++)
    {
        printf(" %c -  ", i == 0 ? '#' : str1[i-1]);
        for (int j = 0; j <= size2; j++)
            printf(" %d -", table[i][j]);
        printf("\n------------------------------------------------------------------\n");
    }
    // for (int i = 0; i <= size1; i++)
    // {
    //     for (int j = 0; j <= size2; j++)
    //         printf("%d ", table[i][j]);
    //     printf("\n");
    // }
}



int main()
{
    size_t max_size = 100;
    char *str1, *str2;
    getline(&str1, &max_size, stdin);
    getline(&str2, &max_size, stdin);
    // printf("%ld  %ld\n", strlen(str1) - 1, strlen(str2) - 1);

    editDistance(str1, str2, strlen(str1) - 1, strlen(str2) - 1);
    return 0;
}