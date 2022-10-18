// Prinafsika
// 21081010278

#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void delete();
void sum();
void addfirst();
void addafter();

struct node* phead = NULL;
struct node{
    int data;
    struct node* next;
}; typedef struct node node;

int main(){
    int pilih;
    menu:
    printf("1. Create\t 5. Add First\n");
    printf("2. Display\t 6. Add After\n");
    printf("3. Delete\n");
    printf("4. Sum\n");
    printf("0. Exit\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    system("clear");

    if (pilih == 1){
        create();
        goto menu;
    } 
    else if (pilih == 2){
        display();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
        
    } 
    else if (pilih == 3){
        delete();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    } 
    else if (pilih == 4){
        sum();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 5){
        addfirst();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 6){
        addafter();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 0){
        system("clear");
        printf("good bye!");
        return 0;
    } 
    else {
        printf("Pilihan tidak ada\n");
        goto menu;
    }
}

void create(){
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Masukan Data : ");
    scanf("%d", &pnew->data);
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
    }
    else{
        struct node* ppre = phead;
        while (ppre->next != NULL){
            ppre = ppre->next;
        }
        ppre->next = pnew;
    }
    system("clear");
}

void display(){
    if (phead == NULL){
        printf("Data kosong!\n");
    }
    else{
        struct node* pwalker = phead;
        while (pwalker != NULL){
            printf("%d ", pwalker->data);
            pwalker = pwalker->next;
        }
    }
}

void delete(){
    int pos ,i;

    if (phead == NULL){
        printf("Data kosong!\n");
    }
    else if (phead != NULL){
        struct node* pwalker = phead;
        while (pwalker != NULL){
            printf("%d ", pwalker->data);
            pwalker = pwalker->next;
        }
        printf("\nMasukan posisi yang ingin dihapus (angka awal = urutan 0) : ");
        scanf("%d", &pos);
        
        if (pos == 0){
            struct node* ppre = phead;
            phead = phead->next;
            free(ppre);
            system("clear");
            printf("Data berhasil dihapus!\n");
        }
        else{
            struct node* pcur = phead;
            struct node* ppre = phead;
            for (i=0; i<pos; i++){
                pcur = ppre;
                ppre = ppre->next;
            }
            pcur->next = ppre->next;
            free(ppre);
            system("clear");
            printf("Data berhasil dihapus!\n");
        }
    }
    
}

void sum(){
    int sum = 0;
    if (phead == NULL){
        printf("Data kosong!\n");
    }
    else{
        struct node* pwalker;
        pwalker = phead;
        while (pwalker != NULL){
            sum += pwalker->data;
            printf("%d+", pwalker->data);
            pwalker = pwalker->next;
        }
        printf("0 \n\nJumlah data : %d", sum);
    }
}

void addfirst(){
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Masukan Data : ");
    scanf("%d", &pnew->data);
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n");
    }
    else{
        pnew->next = phead;
        phead = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n");
    }
}

void addafter(){
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Masukan Data : ");
    scanf("%d", &pnew->data);
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n");
    }
    else{
        struct node* pwalker = phead;
        while (pwalker->next != NULL){
            pwalker = pwalker->next;
        }
        pwalker->next = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n");
    }
}