#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Size 1000

typedef struct{
    char text[Size+1];
    int all_characters;
    int eng_letters;
    int tokens;
    int words;
    int keywords;
    char longest_word[Size+1];
} String;

String string;

void clear_string();
void add_string(const char *str);
void require_all_characters();
void require_eng_letters();
void require_tokens();
void require_words();
void require_keywords(const char *str);
void require_longest_word();
void process_keywords(const char *str, int mode);
void convert_keywords_to_capital(const char *str);
void delete_keywords(const char *str);
void require_all_numbers();
void print_result(const int mode);

int check_valid_word(const char *token, const char *keyword, int *alpha_start, int *alpha_len) {
    int len = strlen(token);
    int s = 0, e = len - 1;
    
    while (s < len && ispunct(token[s])) s++;
    while (e >= s && ispunct(token[e])) e--;

    if (s > e) return 0;

    for (int i = s; i <= e; i++) {
        if (!isalpha(token[i])) return 0;
    }

    if (keyword != NULL) {
        int k_len = strlen(keyword);
        if (e - s + 1 != k_len) return 0;
        for (int i = 0; i < k_len; i++) {
            if (token[s + i] != keyword[i]) return 0;
        }
    }

    if (alpha_start) *alpha_start = s;
    if (alpha_len) *alpha_len = e - s + 1;
    
    return 1;
}

int main(){
    int mode;
    char input_string[Size+1];

    string.text[0] = '\0';

    while(scanf("%d", &mode) != EOF){
        getchar();
        if(mode > 10 || mode < 1)
            return 0;
        else{
            clear_string();

            if(mode == 1 || mode == 6 || mode == 8 || mode == 9){
                fgets(input_string, sizeof(input_string), stdin);
                input_string[strcspn(input_string, "\n")] = '\0';
            }

            switch(mode){
                case 1: add_string(input_string); break;
                case 2: require_all_characters(); break;
                case 3: require_eng_letters(); break;
                case 4: require_tokens(); break;
                case 5: require_words(); break;
                case 6: require_keywords(input_string); break;
                case 7: require_longest_word(); break;
                case 8: convert_keywords_to_capital(input_string); break;
                case 9: delete_keywords(input_string); break;
                case 10: require_all_numbers(); break;
            }
            print_result(mode);
        }
    }
    return 0;
}

void clear_string(){
    string.all_characters = 0;
    string.eng_letters = 0;
    string.tokens = 0;
    string.words = 0;
    string.keywords = 0;
    string.longest_word[0] = '\0';
}

void add_string(const char *str){
    strcat(string.text, str);
}

void require_all_characters(){
    string.all_characters = strlen(string.text);
}

void require_eng_letters(){
    for(int i = 0; string.text[i] != '\0'; i++){
        if(isalpha(string.text[i]))
            string.eng_letters++;
    }
}

void require_tokens(){
    char str_copy[Size+1];
    strcpy(str_copy, string.text);
    char *token = strtok(str_copy, " ");

    while(token != NULL){
        string.tokens++;
        token = strtok(NULL, " ");
    }
}

void require_words(){
    char str_copy[Size+1];
    strcpy(str_copy, string.text);
    char *token = strtok(str_copy, " ");

    while(token != NULL){
        if (check_valid_word(token, NULL, NULL, NULL)) {
            string.words++;
        }
        token = strtok(NULL, " ");
    }
}

void require_keywords(const char *str){
    char str_copy[Size+1];
    strcpy(str_copy, string.text);
    char *token = strtok(str_copy, " ");

    while(token != NULL){
        if (check_valid_word(token, str, NULL, NULL)) {
            string.keywords++;
        }
        token = strtok(NULL, " ");
    }
}

void require_longest_word(){
    char str_copy[Size+1];
    strcpy(str_copy, string.text);
    char *token = strtok(str_copy, " ");
    int max_length = 0;

    string.longest_word[0] = '\0';

    while(token != NULL){
        int alpha_start, alpha_len;
        if (check_valid_word(token, NULL, &alpha_start, &alpha_len)) {
            if(alpha_len > max_length){
                max_length = alpha_len;
                strncpy(string.longest_word, token + alpha_start, alpha_len);
                string.longest_word[alpha_len] = '\0';
            }
        }
        token = strtok(NULL, " ");
    }
}

void process_keywords(const char *str, int mode){
    char result[Size+1] = "";
    int len = strlen(string.text);
    int i = 0;
    int res_idx = 0;

    while (i < len) {
        while (i < len && string.text[i] == ' ') {
            result[res_idx++] = string.text[i++];
        }
        if (i >= len) break;

        int t_start = i;
        while (i < len && string.text[i] != ' ') i++;
        int t_end = i;
        
        int t_len = t_end - t_start;
        char token[Size+1];
        strncpy(token, &string.text[t_start], t_len);
        token[t_len] = '\0';

        int alpha_start, alpha_len;
        int is_match = check_valid_word(token, str, &alpha_start, &alpha_len);

        if (is_match) {
            if (mode == 8) {
                for (int k = 0; k < alpha_len; k++) {
                    token[alpha_start + k] = toupper(token[alpha_start + k]);
                }
                strcpy(&result[res_idx], token);
                res_idx += t_len;
            } else if (mode == 9) {
                strncpy(&result[res_idx], token, alpha_start);
                res_idx += alpha_start;
                
                int after_alpha_len = t_len - alpha_start - alpha_len;
                strncpy(&result[res_idx], token + alpha_start + alpha_len, after_alpha_len);
                res_idx += after_alpha_len;
            }
        } else {
            strcpy(&result[res_idx], token);
            res_idx += t_len;
        }
    }
    result[res_idx] = '\0';
    strcpy(string.text, result);
}

void convert_keywords_to_capital(const char *str){
    process_keywords(str, 8);
}

void delete_keywords(const char *str){
    process_keywords(str, 9);
}

void require_all_numbers(){
    int i = 0;
    int found_number = 0;
    while(string.text[i] != '\0'){
        if(isdigit(string.text[i])){
            found_number = 1;
            if (i > 0 && string.text[i - 1] == '-') {
                printf("-");
            } else {
                printf("+");
            }
            while (isdigit(string.text[i])) {
                putchar(string.text[i]);
                i++;
            }
            printf("\n");
            continue;
        }
        i++;
    }
    if (found_number == 0){
        printf("NONE\n");
    }
}

void print_result(const int mode){
    switch(mode){
        case 1:
        case 8:
        case 9:
            printf("Current string=%s\n", string.text);
            break;
        case 2:
            printf("Total number of characters=%d\n", string.all_characters);
            break;
        case 3:
            printf("Number of English letters=%d\n", string.eng_letters);
            break;
        case 4:
            printf("Number of tokens=%d\n", string.tokens);
            break;
        case 5:
            printf("Number of words=%d\n", string.words);
            break;
        case 6:
            printf("Number of keywords=%d\n", string.keywords);
            break;
        case 7:
            printf("Longest word=%s\n", string.longest_word);
            break;
    }
}