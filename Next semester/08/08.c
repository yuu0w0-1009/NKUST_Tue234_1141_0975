#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[15];
    char phone[15];
    char address[60];
} Member;

typedef struct {
    char id[10];
    char name[20];
    int borrower_id;
} Book;

Member members[100];
int member_count = 0;
Book books[20];

void init_books() {
    const char* BookId[20] = {"B01","B02","B03","B04","B05","B06","B07","B08","B09","B10",
                                "B001","B002","B003","B004","B005","B006","B007","B008","B009","B010"};
    const char* BookName[20] = {"CPrimer","VerilogX","LogicLab","FPGAPro","BitFlow","CircuitX","DataBus","RegMap","SignalIQ","WaveCore",
                                "CMOSArt","SyncEdge","ByteCode","StackMem","AXIWorld","BusLogic","ICDesign","NetClock","EmbedSys","WireLink"};
    for(int i = 0; i < 20; i++) {
        strcpy(books[i].id, BookId[i]);
        strcpy(books[i].name, BookName[i]);
        books[i].borrower_id = -1;
    }
}

int find_member(int id) {
    for(int i = 0; i < member_count; i++) {
        if(members[i].id == id) return i;
    }
    return -1;
}

int find_book(const char* id) {
    for(int i = 0; i < 20; i++) {
        if(strcmp(books[i].id, id) == 0) return i;
    }
    return -1;
}

void sort_members() {
    for(int i = 0; i < member_count - 1; i++) {
        for(int j = 0; j < member_count - 1 - i; j++) {
            if(members[j].id > members[j+1].id) {
                Member temp = members[j];
                members[j] = members[j+1];
                members[j+1] = temp;
            }
        }
    }
}

void member_module() {
    printf("Use member function\n");
    int cmd;
    while(scanf("%d", &cmd) == 1) {
        if (cmd == 1) {
            int id;
            char name[15], phone[15], address[60];
            scanf("%d %s %s %s", &id, name, phone, address);
            if (find_member(id) != -1) {
                printf("ID duplicated\n");
            } else {
                members[member_count].id = id;
                strcpy(members[member_count].name, name);
                strcpy(members[member_count].phone, phone);
                strcpy(members[member_count].address, address);
                member_count++;
                printf("Creation successful\n");
            }
        } else if (cmd == 2) {
            int id, field;
            char new_data[60];
            scanf("%d %d %s", &id, &field, new_data);
            int idx = find_member(id);
            if (idx == -1) {
                printf("No such ID\n");
            } else {
                if (field == 1) strcpy(members[idx].name, new_data);
                else if (field == 2) strcpy(members[idx].phone, new_data);
                else if (field == 3) strcpy(members[idx].address, new_data);
                
                printf("%d %s %s %s\n", members[idx].id, members[idx].name, members[idx].phone, members[idx].address);
            }
        } else if (cmd == 3) {
            int id;
            scanf("%d", &id);
            int idx = find_member(id);
            if (idx == -1) {
                printf("No such ID\n");
            } else {
                for (int i = idx; i < member_count - 1; i++) {
                    members[i] = members[i+1];
                }
                member_count--;
                printf("Deletion successful\n");
            }
        } else if (cmd == 4) {
            int id;
            scanf("%d", &id);
            int idx = find_member(id);
            if (idx == -1) {
                printf("No such ID\n");
            } else {
                printf("%d %s %s %s\n", members[idx].id, members[idx].name, members[idx].phone, members[idx].address);
            }
        } else if (cmd == 5) {
            sort_members();
            for (int i = 0; i < member_count; i++) {
                printf("%d %s %s %s\n", members[i].id, members[i].name, members[i].phone, members[i].address);
            }
        } else {
            printf("Exit member function\n");
            break;
        }
    }
}

void borrow_module() {
    printf("Use borrow function\n");
    int cmd;
    while(scanf("%d", &cmd) == 1) {
        if (cmd == 1) {
            // 1. 借書
            char b_id[10];
            int m_id;
            scanf("%s %d", b_id, &m_id);
            int b_idx = find_book(b_id);
            if (b_idx == -1) {
                printf("No such book ID\n");
                continue;
            }
            int m_idx = find_member(m_id);
            if (m_idx == -1) {
                printf("No such member ID\n");
                continue;
            }
            if (books[b_idx].borrower_id != -1) {
                int borrower_idx = find_member(books[b_idx].borrower_id);
                if (borrower_idx != -1) {
                    printf("Not returned yet,%s is borrowed by %d_%s\n", books[b_idx].id, members[borrower_idx].id, members[borrower_idx].name);
                }
            } else {
                books[b_idx].borrower_id = m_id;
                printf("%s is borrowed by %d_%s\n", books[b_idx].id, members[m_idx].id, members[m_idx].name);
            }
        } else if (cmd == 2) {
            char b_id[10];
            scanf("%s", b_id);
            int b_idx = find_book(b_id);
            if (b_idx == -1) {
                printf("No such book ID\n");
                continue;
            }
            if (books[b_idx].borrower_id == -1) {
                printf("No such transaction\n");
            } else {
                int m_idx = find_member(books[b_idx].borrower_id);
                if (m_idx != -1) {
                    printf("%s is returned by %d_%s\n", books[b_idx].id, members[m_idx].id, members[m_idx].name);
                }
                books[b_idx].borrower_id = -1;
            }
        } else if (cmd == 3) {
            int m_id;
            scanf("%d", &m_id);
            int m_idx = find_member(m_id);
            if (m_idx == -1) {
                printf("No such member ID\n");
            } else {
                printf("%d %s\n", members[m_idx].id, members[m_idx].name);
                int has_book = 0;
                for (int i = 0; i < 20; i++) {
                    if (books[i].borrower_id == m_id) {
                        printf("%s %s\n", books[i].id, books[i].name);
                        has_book = 1;
                    }
                }
                if (!has_book) {
                    printf("None\n");
                }
            }
        } else if (cmd == 4) {
            char b_id[10];
            scanf("%s", b_id);
            int b_idx = find_book(b_id);
            if (b_idx == -1) {
                printf("No such book ID\n");
            } else {
                if (books[b_idx].borrower_id == -1) {
                    printf("%s %s\n", books[b_idx].id, books[b_idx].name);
                } else {
                    int m_idx = find_member(books[b_idx].borrower_id);
                    if (m_idx != -1) {
                        printf("%s %s (%d_%s)\n", books[b_idx].id, books[b_idx].name, members[m_idx].id, members[m_idx].name);
                    }
                }
            }
        } else if (cmd == 5) {
            for (int i = 0; i < 20; i++) {
                if (books[i].borrower_id == -1) {
                    printf("%s %s\n", books[i].id, books[i].name);
                } else {
                    int m_idx = find_member(books[i].borrower_id);
                    if (m_idx != -1) {
                        printf("%s %s (%d_%s)\n", books[i].id, books[i].name, members[m_idx].id, members[m_idx].name);
                    } else {
                        printf("%s %s\n", books[i].id, books[i].name);
                    }
                }
            }
        } else {
            printf("Exit borrow function\n");
            break;
        }
    }
}

int main() {
    init_books();
    int module;
    
    while(scanf("%d", &module) == 1) {
        if (module == 1) {
            member_module();
        } else if (module == 2) {
            borrow_module();
        } else if (module == -1) {
            printf("Goodbye\n");
            break;
        } else {
            printf("No such command\n");
        }
    }
    
    return 0;
}