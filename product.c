#include <string.h>
#include <stdio.h>

typedef struct {
 char name[20]; //제품명
 float weight; // 중량
 int price; // 가격
 int star;  // 별점 1~5까지 숫자
 int star_count; //별점 숫자
} Product;

int selectMenu(){
  int menu;
  printf("\n*** 한동과일 ***\n");
  printf("1. 메뉴조회\n");
  printf("2. 메뉴추가\n");
  printf("3. 메뉴수정\n");
  printf("4. 메뉴삭제\n");
  printf("5. 메뉴저장\n");
  printf("6. 이름으로 메뉴찾기\n");
  printf("7. 가격으로 메뉴찾기\n");
  printf("8. 별점으로 메뉴찾기\n");
  printf("9. 중량으로 메뉴찾기\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);
  return menu;
} // 사용자의 원하는 메뉴 선택을 위한 함수 

void clearbuffer(){
    while (getchar() != '\n');
}

int createProduct(Product *p)
{
    fputs("추가할 상품의 이름은? ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->name);
    fputs("중량은? ",stdout);
    clearbuffer();
    scanf("%f" ,&p->weight);
    fputs("판매 가격은? ",stdout);
    clearbuffer();
    scanf("%d",&p->price);
    fputs("별점은? ",stdout);
    clearbuffer();
    scanf("%d",&p->star);
    fputs("총 별점의 수는?",stdout);
    clearbuffer();
    scanf("%d",&p->star_count);
 return 1;
}// 제품을 추가하는 함수

int readProduct(Product p){
    
    printf("%s \t%.1f \t%d \t%d \t%d\n",p.name,p.weight,p.price,p.star,p.star_count);
    return 1;
} // 하나의 제품 출력 함수

void listProduct(Product *p, int count){
    int i = 0;
    printf("\nNo \t제품명 \t중량 \t가격 \t별점 \t별점개수 \n");
    for(i= 0; i < count; i++){
      if(p[i].price == -1) continue;
        printf("%d\t", i+1);
        readProduct(p[i]);
    }
} // 전체 등록된 제품 리스트 출력

int selectDataNo(Product *s,int count){
  int num; 
  listProduct(s, count);
  printf("번호는(취소:0)? ");
  scanf(" %d",&num);

  return num; 
}

int deleteProduct(Product *s){
    s->price = -1;
    printf("==> 삭제됨!\n");
    return 1;
}
// 원하는 상품을 삭제하는 함수 
 
void searchProduct_name(Product p[], int count){
    int scnt = 0;
    char search[20];
    printf("검색할 물건? ");
    scanf("%s", search);

    printf("\n*****************\n");
    for(int i = 0; i<count; i++){
      if(p[i].price == -1) continue;
      if(strstr(p[i].name,search)){
        printf("%2d",i+1);
        readProduct(p[i]);
        scnt++;
      }
    }
   if(scnt == 0) printf("=> 검색된 데이터 없음!");
   printf("\n");
} // 제품이름 검색

void searchProduct_weight(Product p[], int count){
    int scnt = 0;
    int search;
    printf("원하는 무게보다 작은것? ");
    scanf("%d", &search);

    printf("\n*****************\n");
    for(int i = 0; i<count; i++){
      if(p[i].price == -1) continue;
      if(p[i].weight < search){
        printf("%2d",i+1);
        readProduct(p[i]);
        scnt++;
      }
    }
   if(scnt == 0) printf("=> 검색된 데이터 없음!");
   printf("\n");
} // 입력값보다 가벼운 상품 검색

void searchProduct_price(Product p[], int count){
    int scnt = 0;
    int search;
    printf("원하는 가격보다 싼것? ");
    scanf("%d", &search);

    printf("\n*****************\n");
    for(int i = 0; i<count; i++){
      if(p[i].price == -1) continue;
      if(p[i].price < search){
        printf("%2d",i+1);
        readProduct(p[i]);
        scnt++;
      }
    }
   if(scnt == 0) printf("=> 검색된 데이터 없음!");
   printf("\n");
} // 입력값보다 싼 상품 검색 

void searchProduct_star(Product p[], int count){
    int scnt = 0;
    int search;
    printf("원하는 별점보다 높은 것? ");
    scanf("%d",& search);

    printf("\n*****************\n");
    for(int i = 0; i<count; i++){
      if(p[i].price == -1) continue;
      if(p[i].star > search){
        printf("%2d",i+1);
        readProduct(p[i]);
        scnt++;
      }
    }
   if(scnt == 0) printf("=> 검색된 데이터 없음!");
   printf("\n");
} // 입력한 별점보다 별점이 높은 상품 검색 

void saveData(Product *s, int count){
  FILE *fp;
  fp = fopen("product.txt","wt");

  for(int i = 0; i < count; i++){
    if(s[i].price == -1) continue;
    fprintf(fp, "%f %d %d %d %s\n",s[i].weight,s[i].price,s[i].star,s[i].star_count,s[i].name);
   }
   fclose(fp);
   printf("=>저장됨! ");
}// 추가된 데이터나 수정된것을 파일로 저장하는 함수 

int loadData(Product *s){
  int count = 0, i = 0;
  FILE *fp;
  fp = fopen("Product.txt", "rt");
  if(fp ==NULL) printf("파일 없음");

  else{
    for(; i < 100; i++){
      fscanf(fp, "%f", &s[i].weight);
      if(feof(fp)) break;
      fscanf(fp, "%d", &s[i].price);
      fscanf(fp, "%d", &s[i].star);
      fscanf(fp, "%d", &s[i].star_count);
      fscanf(fp, "%[^\n]s", s[i].name);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
  }

  return 0;
}//파일 불러오는 함수 


