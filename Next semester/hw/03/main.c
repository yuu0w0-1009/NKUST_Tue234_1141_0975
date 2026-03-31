#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define member_size 100
#define name_size 10
#define phone_size 10
#define address_size 50

typedef struct{
    char name[name_size+1];
    char phone[phone_size+1];
    char address[address_size+1];
} Member;

Member member[member_size];
int user_check[member_size] = {0}; // 0 = none; 1 = used
int current_count = 0;

void main_block();
void print_id(int id);
void add_member();
void edit_member();
void del_member();
void require_one_member();
void require_all_member();

int main(){
    int mode;

    while((scanf("%d",&mode) != EOF)){
        if(mode==-1){
            printf("Goodbye\n");
            return 0;
        }
        else if(mode!=1){
            printf("No such command\n");
        }
        else{
            printf("Use member function\n");
            main_block();
        }
    }
}


void main_block(){
    int manage_mode;

    while(scanf("%d", &manage_mode) != EOF){

        if(manage_mode < 1 || manage_mode > 5){
            printf("Exit member function\n");
            return;
        }

        else{
            switch (manage_mode){
            case 1:
                add_member();
                break;
            case 2:
                edit_member();
                break;
            case 3:
                del_member();
                break;
            case 4:
                require_one_member();
                break;
            case 5:
                require_all_member();
                break;
            }
        }
    }
    return;
}

void print_id(int id){
    printf("%d %s %s %s\n", id, member[id].name, member[id].phone, member[id].address);
}

void add_member(){
    int id;
    scanf("%d", &id);
    char name[name_size+1], phone[phone_size+1], address[address_size+1];
    scanf("%10s %10s %50s", name, phone, address);

    if(user_check[id]==1){
        printf("ID duplicated\n");
        return;
    }

    strcpy(member[id].name, name);
    strcpy(member[id].phone, phone);
    strcpy(member[id].address, address);
    user_check[id] = 1;
    printf("Creation successful\n");

    // printf("id=%d user_check=%d member[id].name=%10s member[id].phone=%10s member[id].address=%50s",
    // id, user_check[id], member[id].name, member[id].phone, member[id].address);

    return;
}

void edit_member(){
    int id;
    int picking_mode;
    char nwe_data[50+1] = "";
    scanf("%d %d %50s", &id, &picking_mode, nwe_data);

    if(user_check[id] == 0){
        printf("No such ID\n");
        return;
    }

    switch(picking_mode){
        case 1:
            strcpy(member[id].name, nwe_data);
            break;
        case 2:
            strcpy(member[id].phone, nwe_data);
            break;
        case 3:
            strcpy(member[id].address, nwe_data);
            break;
    }
    print_id(id);

    return;
}

void del_member(){
    int id;
    scanf("%d", &id);

    if(user_check[id] == 0){
        printf("No such ID\n");
        return;
    }

    user_check[id]=0;
    printf("Deletion successful\n");

    return;
}

void require_one_member(){
    int id;
    scanf("%d", &id);

    if(user_check[id] == 0){
        printf("No such ID\n");
        return;
    }

    print_id(id);

    return;
}

void require_all_member(){
    for (int i = 0; i <= member_size; i++){
        if(user_check[i]==1){
            print_id(i);
        }
    }
    return;
}