#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

int num,x,bP,sP,p,s,cP,cS,pR,cY,dd,mm,yyyy;
int eNum,eX,eBp,eSp,eP,eS,eCp,ePr,eCy,eCs;
FILE *fptr;
FILE *fdt;
int c;

void itemData(){
    fdt = fopen("items.txt", "w");
    if(fdt == NULL){
        exit(1);
    }else{
        fprintf(fdt, "%d", num);
    }
    fclose(fdt);
}


void openitemData(){
    fdt = fopen("items.txt", "rb");
    
    fscanf(fdt, "%d", &c);
    fclose(fdt);
}

void savedData(){
    
    fptr = fopen("data.txt", "r+");
    if(fptr == NULL){
        exit(1);
    }else{
        fprintf(fptr, "            BOOK STORE SALES SUMMARY ");
        fprintf(fptr, "                         DATE: %s\n", __DATE__);
        fprintf(fptr, "                         TIME: %s\n", __TIME__);
        fprintf(fptr, "Initial number of books: %d\n", cY);
        fprintf(fptr, "Books remaining: %d\n", num);
        fprintf(fptr, "Books sold: %d\n", cY-num);
        fprintf(fptr, "Buying price: sh.%d\n", bP);
        fprintf(fptr, "Selling price: sh.%d\n", sP);
        fprintf(fptr, "Profit per book: sh.%d\n", p);
        fprintf(fptr, "The last sales: sh.%d\n", s);
        fprintf(fptr, "Cumulative profit: sh.%d\n", cP);
        fprintf(fptr, "Cumulative sales: sh.%d\n", cS);
        fprintf(fptr, "Profit in the last sale: sh.%d\n", pR);
        fclose(fptr);
        
}
}

void date(){
    printf("Current date: %s\n ", __DATE__);
    
}

void totalItems(){
    openitemData();
    if(c != 0){
        printf("no of books %d\n", c);
        printf("Enter the number of books: ");
        scanf("%d", &eNum);
        num=eNum + c;
    
        cY = num;


        printf("The total number of books is: %d\n", num);
    }else{
        printf("The number of books is: 0\n");
        printf("Enter the number of books: ");
        scanf("%d", &num);
        num=num + eNum;
        cY = num;
        printf("The total number of books is: %d\n", num);
    }
}

void totalItemsSold(){
    printf("The total number of books sold is: %d\n", cY - num);
}

void itemsAfterAddition(){
    printf("Enter the number of books to add: ");
    scanf("%d", &x);
    num = num + x;
    savedData();
    printf("The total number of books after addition is: %d\n", num);
}
void price(){
    printf("Enter the buying price each book: sh.");
    scanf("%d", &bP);
    printf("The buying price each book is: sh.%d\n", bP);
    printf("Enter the selling price each book: sh.");
    scanf("%d", &sP);
    printf("The selling price each book is: sh.%d\n", sP);
    p = sP - bP;
    printf("The profit per book is: sh.%d\n", p);
}
void accounts(){
    s= sP * x;
    printf("The total sales is: sh.%d\n", s);
    pR= p * x;
    printf("The total profit is: sh.%d\n", pR);
}
void cummulativeAccount(){
    cS = cS + s;
    cP = cP + pR;
    printf("The cummulative sales is: sh.%d\n", cS);
    printf("The cummulative profit is: sh.%d\n", cP);
}
void sell(){
    
    printf("Enter the number of books to sell: ");
    scanf("%d", &x);
    if(x>num){
        printf("You cannot sell more than the available books since the number of books is %d\n", num);
        printf("Do you want to add more books? Press 1 for yes and 2 for no: ");
        scanf("%d", &x);
        if(x==1){
            itemsAfterAddition();
            price();
            itemData();
            sell();
        }else{
            itemData();
            sell();
        }
    }else{
        num = num - x;
        printf("You have sold %d books\n", x);
        printf("The remaining number of books is: %d\n", num);
        totalItemsSold();
        accounts();
        cummulativeAccount();
        if(num<100 &&num>0){
            printf("The remaining number of books is less than 100\n");
            printf("Do you want to add more books? Press 1 for yes and 2 for no: ");
            scanf("%d", &x);
            if(x==1){
                itemsAfterAddition();
                price();
                itemData();
                savedData();
                sell();
            }else{
                itemData();
                savedData();
                sell();
            }
        }
        if(num==0){
            printf("The number of books is zero\n");
            printf("Do you want to add more books? Press 1 for yes and 2 for no: ");
            scanf("%d", &x);
            if(x==1){
                itemsAfterAddition();
                price();
                itemData();
                savedData();
                sell();
            }else{
                printf("You can no longer sell.Add more books\n");
                itemsAfterAddition();
                price();
                itemData();
                savedData();
                sell();
            }
        }
    }
    itemData();
    savedData();
    sell();
}

int main(){
    printf("                           BOOK STORE\n");
    date();
    totalItems();
    price();
    sell();

    return 0;
}