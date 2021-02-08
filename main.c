#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define size_naghshe 10
#define tedad_keshti 10
struct ships{
    int x1;
    int y1;
    int x2;
    int y2;
    int tool;
    int arz;
};
struct node{
    struct ships boot;
    struct node *next;
};
struct node *create(int x1_boot,int y1_boot,int x2_boot,int y2_boot,int tool_boot,int arz_boot){
    struct node *list;
    list=(struct node *)malloc(sizeof(struct node));
    if (list==NULL)
        printf("NO");
    list->boot.x1=x1_boot;
    list->boot.y1=y1_boot;
    list->boot.x2=x2_boot;
    list->boot.y2=y2_boot;
    list->boot.tool=tool_boot;
    list->boot.arz=arz_boot;
    list->next=NULL;
    return list;
}
void add(struct node **list,int x1_boot,int y1_boot,int x2_boot,int y2_boot,int tool_boot,int arz_boot){
    if (*list==NULL){
        *list=create(x1_boot,x2_boot,y1_boot,y2_boot,tool_boot,arz_boot);
    }
    else {
        struct node *current,*node_list;
        node_list = create(x1_boot,x2_boot,y1_boot,y2_boot,tool_boot,arz_boot);
        for (current=*list;current->next!=NULL;current=current->next);
        current->next=node_list;
        node_list->next=NULL;
    }
}
int check(int array_naghshe[size_naghshe][size_naghshe],int m,int n) {
    while (1) {

        if (array_naghshe[m][n] != 0)
            return -1;

        if (m == 0) {
            if (n == 0) {
                if ((array_naghshe[m][n + 1] != 0 &&array_naghshe[m][n + 1] != -1)
                || (array_naghshe[m + 1][n] != 0 && array_naghshe[m + 1][n] != -1)
                ||(array_naghshe[m + 1][n + 1] != 0 &&array_naghshe[m + 1][n + 1] != -1))
                    return -1;
            } else if (n == 9) {
                if ((array_naghshe[m][n - 1] != 0 &&array_naghshe[m][n - 1] != -1)
                || (array_naghshe[m + 1][n] != 0 &&array_naghshe[m + 1][n] != -1)
                || (array_naghshe[m + 1][n - 1] != 0 &&array_naghshe[m + 1][n - 1] != -1))

                    return -1;
            } else {
                if ((array_naghshe[m][n - 1] != 0 &&array_naghshe[m][n - 1] != -1)
                || (array_naghshe[m][n + 1] != 0 && array_naghshe[m][n + 1] != -1)
                || (array_naghshe[m + 1][n - 1] != 0 &&array_naghshe[m + 1][n - 1] != -1)
                || (array_naghshe[m + 1][n] != 0 &&array_naghshe[m + 1][n] != -1)
                ||(array_naghshe[m + 1][n + 1] != 0 &&array_naghshe[m + 1][n + 1] != -1))
                    return -1;
            }
        } else if (m == 9) {
            if (n == 0) {
                if ((array_naghshe[m][n + 1] != 0 &&array_naghshe[m][n + 1] != -1)
                    || (array_naghshe[m - 1][n] != 0 && array_naghshe[m - 1][n] != -1)
                    ||(array_naghshe[m - 1][n + 1] != 0 &&array_naghshe[m - 1][n + 1] != -1))
                    return -1;
            } else if (n == 9) {
                if ((array_naghshe[m][n - 1] != 0 &&array_naghshe[m][n - 1] != -1)
                    || (array_naghshe[m - 1][n] != 0 &&array_naghshe[m - 1][n] != -1)
                    || (array_naghshe[m - 1][n - 1] != 0 &&array_naghshe[m - 1][n - 1] != -1))
                    return -1;
            } else {
                if ((array_naghshe[m][n - 1] != 0 &&array_naghshe[m][n - 1] != -1)
                    || (array_naghshe[m][n + 1] != 0 && array_naghshe[m][n + 1] != -1)
                    || (array_naghshe[m - 1][n - 1] != 0 &&array_naghshe[m - 1][n - 1] != -1)
                    || (array_naghshe[m - 1][n] != 0 &&array_naghshe[m - 1][n] != -1)
                    ||(array_naghshe[m - 1][n + 1] != 0 &&array_naghshe[m - 1][n + 1] != -1))
                    return -1;
            }

        }
        else if (n==9){
            if ((array_naghshe[m][n-1] != 0 &&array_naghshe[m][n-1] != -1)
                || (array_naghshe[m+1][n - 1] != 0 && array_naghshe[m+1][n - 1] != -1)
                || (array_naghshe[m - 1][n - 1] != 0 &&array_naghshe[m - 1][n - 1] != -1)
                || (array_naghshe[m - 1][n] != 0 &&array_naghshe[m - 1][n] != -1)
                ||(array_naghshe[m + 1][n ] != 0 &&array_naghshe[m + 1][n ] != -1))
                return -1;
        }
        else if (n==0) {
            if ((array_naghshe[m][n+1] != 0 &&array_naghshe[m][n+1] != -1)
                || (array_naghshe[m+1][n + 1] != 0 && array_naghshe[m+1][n + 1] != -1)
                || (array_naghshe[m - 1][n + 1] != 0 &&array_naghshe[m - 1][n + 1] != -1)
                || (array_naghshe[m - 1][n] != 0 &&array_naghshe[m - 1][n] != -1)
                ||(array_naghshe[m + 1][n ] != 0 &&array_naghshe[m + 1][n ] != -1))
                return -1;
        }
        else {
            if ((array_naghshe[m][n - 1] != 0 && array_naghshe[m][n - 1] != -1)
            || (array_naghshe[m][n + 1] != 0 &&array_naghshe[m][n + 1] != -1)
            || (array_naghshe[m - 1][n - 1] != 0 && array_naghshe[m - 1][n - 1] != -1)
            || (array_naghshe[m - 1][n] != 0 && array_naghshe[m - 1][n] != -1)
            || (array_naghshe[m - 1][n + 1] != 0 &&array_naghshe[m - 1][n + 1] != -1)
            || (array_naghshe[m + 1][n] != 0 &&array_naghshe[m + 1][n] != -1)
            ||(array_naghshe[m + 1][n - 1] != 0 && array_naghshe[m + 1][n - 1] != -1)
            ||(array_naghshe[m + 1][n +1] != 0 &&array_naghshe[m + 1][n +1] != -1))
                return -1;
        }
        break;

    }
        return 1;

}
void por_kardan_naghshe(int array_naghshe[size_naghshe][size_naghshe],int m,int n){
    if (m == 0) {
        if (n == 0) {
            array_naghshe[m][n + 1] = -1;
            array_naghshe[m + 1][n] = -1;
            array_naghshe[m + 1][n + 1] = -1;

        } else if (n == 9) {
            array_naghshe[m][n - 1] = -1;
            array_naghshe[m + 1][n] = -1;
            array_naghshe[m + 1][n - 1] = -1;

        } else {
            array_naghshe[m][n - 1] = -1 ;
            array_naghshe[m][n + 1] = -1;
            array_naghshe[m + 1][n - 1] = -1;
            array_naghshe[m + 1][n] = -1 ;
            array_naghshe[m + 1][n + 1] = -1;
        }
    } else if (m == 9) {
        if (n == 0) {
            array_naghshe[m][n + 1] = -1;
            array_naghshe[m - 1][n] = -1 ;
            array_naghshe[m - 1][n + 1] = -1;

        } else if (n == 9) {
            array_naghshe[m][n - 1] = -1;
            array_naghshe[m - 1][n] = -1;
            array_naghshe[m - 1][n - 1] = -1;

        } else {
            array_naghshe[m][n - 1] = -1;
            array_naghshe[m][n + 1] = -1;
            array_naghshe[m - 1][n - 1] = -1;
            array_naghshe[m - 1][n] = -1;
            array_naghshe[m - 1][n + 1] = -1;

        }
    }
    else if (n==0){
        array_naghshe[m][n+1]=-1;
        array_naghshe[m+1][n ] = -1;
        array_naghshe[m - 1][n ] = -1;
        array_naghshe[m - 1][n+1] = -1;
        array_naghshe[m + 1][n+1 ] = -1;

    }
    else if (n==9){
        array_naghshe[m][n-1]=-1;
        array_naghshe[m+1][n ] = -1;
        array_naghshe[m - 1][n ] = -1;
        array_naghshe[m - 1][n-1] = -1;
        array_naghshe[m + 1][n-1 ] = -1;
    }
    else {
        array_naghshe[m][n - 1] = -1;
        array_naghshe[m][n + 1] = -1;
        array_naghshe[m - 1][n - 1] = -1;
        array_naghshe[m - 1][n] = -1;
        array_naghshe[m - 1][n + 1] = -1 ;
        array_naghshe[m + 1][n] = -1 ;
        array_naghshe[m + 1][n - 1] = -1;
        array_naghshe[m + 1][n +1] = -1;

    }
}
void print1(int arr[size_naghshe][size_naghshe]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}
void print_naghshe(char arr[size_naghshe][size_naghshe]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}
void sakht_naghshe(int array_naghshe[size_naghshe][size_naghshe]) {
    int x, m1, n1,m2,n2;
    static int tedad_keshti1 = 4;
    static int tedad_keshti2 = 3;
    static int tedad_keshti3 = 2;
    static int tedad_keshti5 = 1;
    for(int i=0;i<size_naghshe;i++){
        for(int j=0;j<size_naghshe;j++)
            array_naghshe[i][j] = 0;
    }

    for (int i = 0; i < tedad_keshti; i++) {
        printf("Koddom keshtio aval mikhay bezari?\n");
        printf("1)tedad_keshti1:%d\n2)tedad_keshti2:%d\n3)tedad_keshti3:%d\n4)tedad_keshti5:%d\n", tedad_keshti1,
               tedad_keshti2, tedad_keshti3, tedad_keshti5);
        scanf("%d", &x);
        if (x == 1) {
            while (1) {
                printf("bede mokhtasat keshti yeko\n");
                scanf("%d %d", &m1, &n1);
                if (m1<0||m1>10||n1<0||n1>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1)
                    break;
            }
            array_naghshe[m1][n1] = 1;
            por_kardan_naghshe(array_naghshe, m1, n1);
            --tedad_keshti1;
            print1(array_naghshe);
        } else if (x == 2) {
            while (1) {
                printf("bede mokhtasat keshti do\n");
                scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if (m1 == m2 || n1 == n2)
                        break;
                }
            }
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            array_naghshe[m1][n1] = 2;
            array_naghshe[m2][n2] = 2;
            tedad_keshti2--;
            print1(array_naghshe);
        } else if (x == 3) {
            while (1) {
                printf("bede mokhtasat keshti 3ro\n");
                scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if (m1 == m2 || n1 == n2 &&((int)fabs(m2-m1)==1 ||(int)fabs(n2-n1)==1))
                        break;
                }
            }
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            if (m1 == m2) {
                por_kardan_naghshe(array_naghshe, m1, n1 + 1);
                array_naghshe[m1][n1 + 1] = 3;
            } else {
                por_kardan_naghshe(array_naghshe, m1 + 1, n1);
                array_naghshe[m1 + 1][n1] = 3;
            }
            array_naghshe[m1][n1] = 3;
            array_naghshe[m2][n2] = 3;
            tedad_keshti3--;
            print1(array_naghshe);
        }
        else if (x==4){
            while (1) {
                printf("bede mokhtasat keshti 5ro\n");
                scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if ((m1 == m2 || n1 == n2) &&((int) fabs(m2-m1)==4 ||(int) fabs(n2-n1)==4))
                        break;
                }
            }
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            if (m1 == m2) {
                por_kardan_naghshe(array_naghshe, m1, n1 + 1);
                por_kardan_naghshe(array_naghshe, m1, n1 + 2);
                por_kardan_naghshe(array_naghshe, m1, n1 + 3);
                array_naghshe[m1][n1 + 1] = 5;
                array_naghshe[m1][n1 + 2] = 5;
                array_naghshe[m1][n1 + 3] = 5;
            } else {
                por_kardan_naghshe(array_naghshe, m1 + 1, n1);
                por_kardan_naghshe(array_naghshe, m1 + 2, n1);
                por_kardan_naghshe(array_naghshe, m1 + 3, n1);
                array_naghshe[m1 + 1][n1] = 5;
                array_naghshe[m1 + 2][n1] = 5;
                array_naghshe[m1 + 3][n1] = 5;
            }
            array_naghshe[m1][n1] = 5;
            array_naghshe[m2][n2] = 5;
            tedad_keshti5--;
            print1(array_naghshe);
        }

    }
}

void ejra_bazi_do_nafare(){
    int array_naghshe_adad1[size_naghshe][size_naghshe];
    int array_naghshe_adad2[size_naghshe][size_naghshe];
    sakht_naghshe(array_naghshe_adad1);
    sakht_naghshe(array_naghshe_adad2);
    int array_naghshe_char1[size_naghshe][size_naghshe];
    int array_naghshe_char2[size_naghshe][size_naghshe];
    for(int i=0;i<size_naghshe;i++){
        for(int j=0;j<size_naghshe;j++) {
            array_naghshe_char1[i][j] = ' ';
            array_naghshe_char2[i][j] = ' ';
        }
    }
    print_naghshe(array_naghshe_char1);


}
//void show_users(char name[100][100],int n){
//    for (int i=0;i<n;i++){
//        printf("%s",name[i]);
//        printf("\n");
//    }
//}
//void menu(char name[100][100]) {
//    int x;
//    int n=0;
//    int index;
//    printf("1. Play with a Friend\n2. Play with bot\n3. Load game\n4. Load last game\n5. Settings\n6. Score Board\n7. Exit\n");
//    scanf("%d", &x);
//    if (x == 1) {
//        printf("First player:\n1. choose user\n");
//        printf("1. choose from available users\n2. new user\n");
//        scanf("%d", &x);
//        if (x == 1) {
//            show_users(name,n);
//            scanf("%d", &index);
//
//
//        }
//        else if (x == 2) {
//
//
//        }
//        printf("2. put ships\n");
//        printf("1. Auto\n2. Manual\n");
//        scanf("%d", &x);
//        if (x == 1) {
//
//        } else if (x == 2) {
//
//        }
//
//        printf("Second player:\n1. choose user\n");
//        printf("1. choose from available users\n2. new user\n");
//        scanf("%d", &x);
//        if (x == 1) {
//
//        } else if (x == 2) {
//
//        }
//        printf("2. put ships\n");
//        printf("1. Auto\n2. Manual\n");
//        scanf("%d", &x);
//        if (x == 1) {
//
//        } else if (x == 2) {
//
//
//        }
//    }
//}

int main() {
    char name[100][100];

//    menu(name);


    return 0;
}