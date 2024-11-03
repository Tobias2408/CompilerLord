#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef enum {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREM,
} TypeSeparator;

typedef enum{
    EXIT
}TypeKeyword;

typedef enum {
    INT,
} TypeLiteral;


typedef struct {
 TypeKeyword type;
}TokenKeyWord;

typedef struct {
TypeLiteral type;
char *value;
}TokenLiteral;

typedef struct {
    TypeSeparator type;
}TokenSeparator;

TokenLiteral *generate_number(char *current, int *current_index){
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while(isdigit(current[*current_index]) && current[*current_index] != '\0'){
        if(!isdigit(current[*current_index])){
            break;
        }
        value[value_index] = current[*current_index];
        value_index++;
        current_index++;
    }
    token->value = value;
    return token;
}

TokenKeyWord * generate_keyword(char *current, int *current_index){
    TokenKeyWord *token = malloc(sizeof(TokenKeyWord));
    char *keyword = malloc(sizeof(char) * 4);
    int keyword_index = 0;
    while(isalpha(current) && current[*current_index] != '\0'){
        keyword[keyword_index] = current[*current_index];
        keyword_index++;
        current_index++;
    }
    if(strcmp(keyword, "exit")){
        token->type = EXIT;
        printf("TOKEN TYPE EXIT\n");
    }
    return token;
}


void lexer(FILE *file){
    int length;
    char *buffer = 0;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file,0,SEEK_SET);
    buffer = malloc(sizeof(char) * length);

    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length+1] = '\0';
    char *current = malloc(sizeof(char) * length +1);
    current = buffer;
    int current_index = 0;

    while(current[current_index] != '\0'){
        printf("curr: %c\n", current[current_index]);
        if(current[current_index] == ';'){
            printf("FOUND SEMICOLON\n");
        }else if(current[current_index] == '('){
            printf("FOUND OPEN PAREN\n");
        }else if(current[current_index] == ')' ){
            printf("FOUND CLOSED PAREN\n");
        }else if(isdigit(current[current_index])){
            TokenLiteral *test_token = generate_number(current, &current_index);
            printf("TEST TOKEN VALUE: %s\n", test_token->value);
            free(test_token);
        } else if(isalpha(current[current_index])){
           TokenKeyWord *test_keyword = generate_keyword(current, &current_index);
           //printf("FOUND CHARACTER: %c\n", current[current_index]);
        }
        current_index++;
    }
}


int main(){
  
    FILE *file;
    file = fopen("test.unn", "r");
    
   
    lexer(file);
}