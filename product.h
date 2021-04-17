typedef struct {
 char name[20]; //제품명
 float weight; // 중량
 int price; // 가격
 int star;  // 별점 1~5까지 숫자
 int star_count; //별점 숫자
} Product; 
        
int selectMenu();
void clearbuffer();
int createProduct(Product *p);
int readProduct(Product p);
int listProduct(Product *p, int count);
int selectDataNo(Product *s,int count); 
int updateProduct(Product *s);
int deleteProduct(Product *s); 
void searchProduct_name(Product p[], int count);
void searchProduct_weight(Product p[], int count);
void searchProduct_price(Product p[], int count);
void searchProduct_star(Product p[], int count);
//void saveData(Product *s, int count);
//int loadData(Product *s);
