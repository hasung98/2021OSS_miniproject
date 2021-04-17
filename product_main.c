//메뉴 관리 프로그램 
//윤하성 개발 
#include <string.h>
#include <stdio.h>
#include "product.h"

int main(void) {

#ifdef DEBUG
	printf("DEBUG mode=> \n");
#endif
Product slist[100];
int count=0, index = 0, menu;
 count = loadData(slist);
 index = count;

 while(1){
 menu = selectMenu();
 if(menu == 0) break;
 if(menu == 1 || menu ==3 || menu == 4)
      if(count == 0) continue;
 if(menu == 1){
   listProduct(slist, index);
 }
 else if(menu == 2)
   count += createProduct(&slist[index++]);
 else if(menu == 3) {
   int no = selectDataNo(slist, index);
   if( no > 0){
     updateProduct(&slist[no-1]);
   }
 }
 else if(menu == 4){
   int no = selectDataNo(slist, index);
   if( no > 0){
     int deleteok ;
     printf("정말로 삭제하시겠습니까?(삭제:1)");
     scanf("%d", &deleteok);
     if(deleteok == 1){
       deleteProduct(&slist[no-1]);
      count --;
     }
   }
 }
 else if (menu == 5){
   saveData(slist,index);
 }
 else if (menu == 6){
   searchProduct_name(slist, index);
 }
 else if (menu == 7){
   searchProduct_price(slist,index);
 }
 else if(menu == 8){
   searchProduct_star(slist,index);
 }
 else if(menu == 9){
   searchProduct_weight(slist,index);
 }
}
return 0;
}

