#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stateFromLabel(int n, char labels[][100], char label[]) {
    int i;
    for(i=0; i<n; i++) {
        if(!strcmp(labels[i],label)){
            return i;
        }
    }
    return -1;
}

int main(){
    char fname[FILENAME_MAX];
    printf("Enter file name : ");
    scanf("%s", fname);
    FILE *file;
    file = fopen(fname, "r");
    char data[100];
    fgets(data, 100, file);
    if(data[strlen(data)-1] == '\n')
        data[strlen(data)-1] = '\0';
    //reading 1st line
    // printf("Reading file. 1st line : %s\n", data);
    int type = strtol(strtok(data, " "), NULL, 10);
    // printf("Tpye = %d\n", type);
    int inputSymbols = strtol(strtok(NULL, " "), NULL, 10);
    // printf("No. of input symbols = %d\n", inputSymbols);
    int NoOfstates = strtol(strtok(NULL, " "), NULL, 10);
    // printf("No. of states = %d\n", NoOfstates);
    char labels[NoOfstates][100];
    int states[NoOfstates][inputSymbols];
    char outputs[NoOfstates][inputSymbols][100];
    int i,j;
    
    for(i=0; i<NoOfstates; i++){
        strcpy(labels[i],strtok(NULL, " "));
        // printf("State %d = %s\n", i, labels[i]);
    }

    for (i = 0; i < NoOfstates; i++) {
        // printf("State %d = %s\n", i, labels[i]);
        fgets(data, 100, file);
        if(data[strlen(data)-1] == '\n')
            data[strlen(data)-1] = '\0';
        // printf("State %s, data read = %s\n", labels[i], data);
        
        states[i][0] = stateFromLabel(NoOfstates, labels, strtok(data, " "));
        strcpy(outputs[i][0],strtok(NULL, " "));
        // printf("state %s on input %d, new state = %d, output = %s\n", labels[i], 0, states[i][0], outputs[i][0]);
        
        for(j=1; j<inputSymbols; j++) {
            states[i][j] = stateFromLabel(NoOfstates, labels, strtok(NULL, " "));
            strcpy(outputs[i][j],strtok(NULL, " "));
            // printf("state %s on input %d, new state = %d, output = %s\n", labels[i], j, states[i][j], outputs[i][j]);
        }
    }

    //input
    int head = 0;
    printf("\n\n\n\nEnter binary string (max length 20 characters): ");
    char str[20];
    scanf("%20s", str);
    for(i=0; i<20; i++){
        if(str[i] == '\0')
            break;
        else if (str[0] >= '0' && str[i] <='1')
        {
            int input = (int)(str[i]-'0');
            // printf("input = %d, current head = %d, next head = ", input, head);
            if(type == 1)
                printf("%s", outputs[head][input]);
            head = states[head][input];
            // printf("%d\n", head);
        }
        else
        {
            printf("Invalid input\n");
            return 1;
        }
    }

    fgets(data, 100, file);
    if(data[strlen(data)-1] == '\n')
        data[strlen(data)-1] = '\0';
    if(!strcmp(data, labels[head]))
        printf("\nInput Accepted");
    else
        printf("\nInput Rejected");    
    printf("\nFinal state = %s\n", labels[head]);            
}