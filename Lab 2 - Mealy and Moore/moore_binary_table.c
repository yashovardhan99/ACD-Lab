#include <stdio.h>
#include <stdlib.h>

int main(){
    int states[3][2] = {{1, 2}, {1, 2}, {1,2}};
    int outputs[3] = {0, 1, 0};
    int head = 0;
    printf("Enter binary string (max length 20 characters): ");
    char str[20];
    scanf("%20s", str);
    
    int i;
    for(i=0; i<20; i++){
        if(str[i] == '\0')
            break;
        else if (str[0] >= '0' && str[i] <='1')
        {
            int input = (int)(str[i]-'0');
            // printf("input = %d, current head = %d, next head = ", input, head);
            head = states[head][input];
            printf("%d", outputs[head]);
            // printf("%d\n", head);
        }
        else
        {
            printf("Invalid input\n");
            return 1;
        }
    }
   printf("\nFinal state = q%d\n", head);
}