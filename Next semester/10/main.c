#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[500];
char stack[500];
int stack_top = -1;
int count_parentheses = 0;
int count_bracket = 0;
int count_brace = 0;
int symbol_flag = 0;
int check_flag = 0;
int previous = 1;

void check_symbol(char x){
    if(x == '(' || x == '[' || x == '{'){
        stack_top++;
        stack[stack_top] = x;
    }
    else if(x == ')' && stack_top >= 0){
        if(stack[stack_top]=='('){
            stack_top--;
            count_parentheses++;
        }
        else
            check_flag = 1;
    }
    else if(x == ']' && stack_top >= 0){
        if(stack[stack_top]=='['){
            stack_top--;
            count_bracket++;
        }
        else
            check_flag = 1;
    }
    else if(x == '}' && stack_top >= 0){
        if(stack[stack_top]=='{'){
            stack_top--;
            count_brace++;
        }
        else
            check_flag = 1;
    }
    else
        check_flag = 1;
}

void clear() {
    count_parentheses = 0;
    count_bracket = 0;
    count_brace = 0;
    stack_top = -1;
    check_flag = 0;
    previous = 1;
}

int main() {
    while (scanf("%s", input) == 1){
        if((input[0] < 'A' || input[0] > 'Z') && (input[0] != '(' && input[0] != '[' && input[0] != '{'))check_flag = 1;
        else{
            for (int i = 0; i < strlen(input); i++) {
                if(check_flag==0){
                    if(previous == 1){
                        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){check_symbol(input[i]); previous = 1;}
                        else if(input[i] >= 'A' && input[i] <= 'Z')previous = 2;
                        else check_flag = 1;
                        symbol_flag = 0;
                    }
                    else if(previous == 2){
                        if(input[i] == ')' || input[i] == ']' || input[i] == '}'){check_symbol(input[i]); previous = 2;}
                        else if(input[i] == '+' || input[i] == '*'){previous = 1; symbol_flag = 1;}
                        else check_flag = 1;
                    }
                    else previous = -1;
                }
                else
                    break;
            }
        }

        if(check_flag == 1 || symbol_flag == 1 || stack_top != -1)printf("false\n");
        else printf("true ():%d []:%d {}:%d\n",count_parentheses,count_bracket,count_brace);
        clear();
    }
    return 0;
}