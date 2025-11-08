
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    char sentence[1024];
    char prop_non[100][20];
    int count = 0;
    int sen_len;
    int i, j;
    fgets(sentence, 1024, stdin);
    sen_len = strlen(sentence);

    for (i = 0; i < sen_len; i++) {
//alpaha bit cheching
if(i!=0){
        if (isalpha(sentence[i]) && (i == 0 || !isalpha(sentence[i-1]))) {
//super chachter
            if (isupper(sentence[i])) {
                j = i;
                //reading the noun
                while (isalpha(sentence[j]) && j < sen_len && j - i < 20) {
                    prop_non[count][j-i] = sentence[j];
                    j++;
                }
                if((strlen(prop_non[count]))>1){
                prop_non[count][j-i] = '\0';
                count++;}
            }
        }
    }
}


    printf("%d\n", count);
    for (i = 0; i < count; i++) {
        printf("%s ", prop_non[i]);
    }
    printf("\n");

    return 0;
}
