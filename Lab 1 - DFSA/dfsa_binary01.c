/*
* Design a DFSA that will accept a binary string ending with 01 (using LinkedList)
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    char label;
    struct Node* ptr_0;
    struct Node* ptr_1;
};
int main(){
    struct Node* q0 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* q1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* q2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = q0;
    
    q0->label = '0';
    q0->ptr_0 = q1;
    q0->ptr_1 = q0;
    q1->label = '1';
    q1->ptr_0 = q1;
    q1->ptr_1 = q2;
    q2->label = '2';
    q2->ptr_0 = q1;
    q2->ptr_1 = q0;
    
    printf("Enter binary string (max length 20 characters): ");
    char str[20];
    scanf("%20s", str);
    
    int i;
    for(i=0; i<20; i++){
        if(str[i] == '\0')
            break;
        if(str[i] == '0')
            head = head->ptr_0;
        else if(str[i] == '1')
            head = head->ptr_1;
        else {
            printf("Invalid input\n");
            return 1;
        }
    }
    if(head->label == '2')
        printf("String %s accepted\n",str);
    else
        printf("String %s rejected\n",str);

    return 0;
}
    
