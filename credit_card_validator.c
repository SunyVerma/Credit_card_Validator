#include<stdio.h>
#include<stdlib.h>
int main(){
    int prince = 0;
    int love = 0;
    um:
    if(prince == 0){
        printf("Welcome to this program! ^`~`^ <3\n");
    }
    else{
        printf("Again welcome to this program! ^`~`^ <3\n");
    }
    ret:
    printf("\n");
    printf("Enter the respective number and press enter\n");
    printf("1.Validate a credit card number\n");
    printf("2.Find a single missing number on the card\n");
    int click=0;
    scanf("%d",&click);
    getchar(); 
    
    if(!(click == 1 || click == 2)){
        printf("\nChoose a valid number! :-(\n\n");
        love++;
        printf("Press Enter!");
        getchar();
        goto um;
    }
    if(love>0){
        printf("After so much struggle you have finally Enterd a valid number ^/~/^\n");
        
    }
    shift:
    if(click ==2){
        printf("***********notice***********\n");
        printf("For the respective number, leave the place for missing number with a sapce\n");
        
    }
    printf("\nEnter you credit card numer\n");
    if(click ==1){
        printf("--Example__1234123412341234\n");
    }
    else{
        printf("--Example__12341234123412 4\n");
    }
    char *input = NULL;
    char ch;
    int size = 0;
    while((ch = getchar()) != '\n'){
        char *temp = NULL;
        temp = realloc(input,(size+2)*sizeof(char));
        if(temp == NULL){
            free(input);
            return 1;
        }
        temp[size] = ch;
        input = temp;
        size++;
    } 
    if(size != 16){
        if(click ==1){
            printf("Please enter 16 digits! ^/~/^\n");
        }
        else{
            printf("Please enter 15 digits plus a space at the respective missing index number! ^/~/^\n");
        }
        free(input);
        goto shift;
    }
    printf("\n");
    int god;
    input[size] = '\0';
    int digit[size];
    for(int i = 0; i<size; i++){
        if(click == 2){
            if(input[i] == ' '){
            god = i;
            digit[i] = 0;
            continue;
        }
    }
        digit[i] = input[i] - '0';
    }
    int sum = 0;
    
    int pri[size];
    for(int i = 0; i<size; i++){
        if(i%2 == 0){
            pri[i] = digit[i]*2;
            if(pri[i]/10 != 0){
                pri[i] = pri[i]%10 + 1;
                digit[i] = pri[i];
            }
            else{
                digit[i] = pri[i];
            }
        }
        sum+=digit[i];
    }
    if(click == 1){
        if(sum%10 == 0){
        printf("%s is a valid Credit Card number :-)\n",input);
    }
    else{
        printf("%s is a not valid Credit Card number :-(\n",input);
    }
    }
    else{
        int i = 0;
        int k = 0;
        while(1){
            if((i+sum)%10 == 0){
                break;
            }
            i++;
        }
        if(god%2 == 0){
            if(i%2==0){
                i = i/2;
            }
            else{
                while(1){
                    if(i == (1+k)){
                        break;
                    }
                    k++;
                }
                i = (10+k)/2;
            }
        }
        input[god] = (char)(i+'0'); 
        printf("The missing number is %d\n",i);
        printf("And you credit card number is %s\n\n",input);
    }
    unique:
    printf("1.Leave this program `~`\n");
    printf("2.Go back to the start menu :-)\n");
    int umm;
    scanf("%d",&umm);
    getchar();
    if(!(umm==1 || umm == 2)){
        printf("Please select the correct number\n");
        goto unique;
    }
    else{
        if(umm == 2){
            goto ret;
        }
        else{
            printf("BYE ^/~/^\n");
        }
    }
    return 0;
}
