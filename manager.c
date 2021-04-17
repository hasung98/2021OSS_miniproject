#include <string.h>
#include <stdio.h>
#include "product.h"

int updateProduct(Product *s1){
    fputs("새 상품명은? ",stdout);
    clearbuffer();
    scanf("%[^\n]s",s1->name);
    clearbuffer();
    fputs("새 상품 중량은? ",stdout);
    clearbuffer();
    scanf("%f",&s1->weight);
    fputs("새 상품 판매 가격은? ",stdout);
    clearbuffer();
    scanf("%d",&s1->price);
    fputs("새 상품 별점은? ",stdout);
    clearbuffer();
    scanf("%d",&s1->star);
    fputs("새 상품 별점 갯수는? ",stdout);
    clearbuffer();
    scanf("%d",&s1->star_count);
    printf("=> 수정성공!\n");
    return 1; 
} // 새로운 상품 추가하는 함수 

