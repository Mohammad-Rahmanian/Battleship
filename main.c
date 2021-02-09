#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>
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
struct ships search_list(struct node *list,int m,int n) {
    struct node *current = list;
    while (current != NULL) {
        if (current->boot.x1 == m && current->boot.x2 == m) {
            if ((current->boot.y1 <=n && n<= current->boot.y2) || (current->boot.y2 <=n && n<= current->boot.y1)) {
                struct ships bt = {current->boot.x1,current->boot.y1,current->boot.x2,current->boot.y2,
                                   current->boot.tool,current->boot.arz};
                return bt;
            }
        }
        else if (current->boot.y1 == n && current->boot.y2 == n) {
            if ((current->boot.x1 <= m && m<= current->boot.x2) || (current->boot.x2 <=m && m<= current->boot.x1)) {
                struct ships bt = {current->boot.x1,current->boot.y1,current->boot.x2,current->boot.y2,
                                   current->boot.tool,current->boot.arz};
                return bt;
            }
        }
        current = current->next;
    }
}
struct node *create(int x1_boot,int y1_boot,int x2_boot,int y2_boot,int tool_boot,int arz_boot){
    struct node *list;
    list=(struct node *)malloc(sizeof(struct node));
    if (list==NULL)
        printf("can not  create link list");
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
        *list=create(x1_boot,y1_boot,x2_boot,y2_boot,tool_boot,arz_boot);
    }
    else {
        struct node *current,*node_list;
        node_list = create(x1_boot,y1_boot,x2_boot,y2_boot,tool_boot,arz_boot);
        for (current=*list;current->next!=NULL;current=current->next);
        current->next=node_list;
        node_list->next=NULL;
    }
}
void delete(struct node **list,int m,int n) {
    struct ships sea=search_list(*list,m,n);
    struct node *current;
    if (*list==NULL)
        return;
    else if (((*list)->boot.x1== sea.x1) && ((*list)->boot.y1== sea.y1 )) {
        current=*list;
        *list=(*list)->next;
        free(current);
    }
        //    else {
//        for (struct node *curr = *list; curr!= NULL; curr = curr->next) {
//            if (curr->boot.x1== sea.x1 && curr->boot.y1== sea.y1) {
//                struct node *delete = curr->next;
//                curr->next = curr->next->next;
//                free(delete);
//                return;
//            }
//        }
//    }
    else{
        struct node *curr=*list;
        struct node *last=NULL;
        while(curr!= NULL)
        {
            if(curr->boot.x1==sea.x1 && curr->boot.y1== sea.y1){
                last->next=curr->next;
                free(curr);
                return;
            }
            last=curr;
            curr=curr->next;
        }
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
void por_kardan_naghshe2(char array_naghshe[size_naghshe][size_naghshe],int m,int n){
    if (m == 0) {
        if (n == 0) {
            array_naghshe[m][n + 1] = 'W';
            array_naghshe[m + 1][n] = 'W';
            array_naghshe[m + 1][n + 1] = 'W';

        } else if (n == 9) {
            array_naghshe[m][n - 1] = 'W';
            array_naghshe[m + 1][n] = 'W';
            array_naghshe[m + 1][n - 1] = 'W';

        } else {
            array_naghshe[m][n - 1] = 'W' ;
            array_naghshe[m][n + 1] = 'W';
            array_naghshe[m + 1][n - 1] = 'W';
            array_naghshe[m + 1][n] = 'W' ;
            array_naghshe[m + 1][n + 1] = 'W';
        }
    } else if (m == 9) {
        if (n == 0) {
            array_naghshe[m][n + 1] = 'W';
            array_naghshe[m - 1][n] = 'W' ;
            array_naghshe[m - 1][n + 1] = 'W';

        } else if (n == 9) {
            array_naghshe[m][n - 1] = 'W';
            array_naghshe[m - 1][n] ='W';
            array_naghshe[m - 1][n - 1] = 'W';

        } else {
            array_naghshe[m][n - 1] = 'W';
            array_naghshe[m][n + 1] = 'W';
            array_naghshe[m - 1][n - 1] = 'W';
            array_naghshe[m - 1][n] = 'W';
            array_naghshe[m - 1][n + 1] = 'W';

        }
    }
    else if (n==0){
        array_naghshe[m][n+1]='W';
        array_naghshe[m+1][n ] = 'W';
        array_naghshe[m - 1][n ] = 'W';
        array_naghshe[m - 1][n+1] = 'W';
        array_naghshe[m + 1][n+1 ] = 'W';

    }
    else if (n==9){
        array_naghshe[m][n-1]='W';
        array_naghshe[m+1][n ] = 'W';
        array_naghshe[m - 1][n ] = 'W';
        array_naghshe[m - 1][n-1] = 'W';
        array_naghshe[m + 1][n-1 ] = 'W';
    }
    else {
        array_naghshe[m][n - 1] = 'W';
        array_naghshe[m][n + 1] = 'W';
        array_naghshe[m - 1][n - 1] = 'W';
        array_naghshe[m - 1][n] = 'W';
        array_naghshe[m - 1][n + 1] = 'W' ;
        array_naghshe[m + 1][n] = 'W' ;
        array_naghshe[m + 1][n - 1] = 'W';
        array_naghshe[m + 1][n +1] = 'W';
    }
}
void print1(int arr[size_naghshe][size_naghshe]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_naghshe(char arr[size_naghshe][size_naghshe]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf("|%2c|",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void sakht_naghshe(int array_naghshe[size_naghshe][size_naghshe],struct node **list) {
    int x, m1, n1,m2,n2,m,n;
    int tedad_keshti1 = 4;
    int tedad_keshti2 = 3;
    int tedad_keshti3 = 2;
    int tedad_keshti5 = 1;
    for(int i=0;i<size_naghshe;i++){
        for(int j=0;j<size_naghshe;j++)
            array_naghshe[i][j] = 0;
    }
    int i = 0;
    while ( i < tedad_keshti) {
        printf("Koddom keshtio aval mikhay bezari?\n");
        printf("1)tedad_keshti1:%d\n2)tedad_keshti2:%d\n3)tedad_keshti3:%d\n4)tedad_keshti5:%d\n", tedad_keshti1,
               tedad_keshti2, tedad_keshti3, tedad_keshti5);
        scanf("%d", &x);
        if (x == 1 && tedad_keshti1!=0) {
            while (1) {
                printf("bede mokhtasat keshti yeko\n");
                scanf("%d %d", &m1, &n1);
                if (m1<0||m1>10||n1<0||n1>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1)
                    break;
            }
            add(&*list,m1,n1,m1,n1,1,1);
            array_naghshe[m1][n1] = 1;
            por_kardan_naghshe(array_naghshe, m1, n1);
            --tedad_keshti1;
            i++;
            print1(array_naghshe);
        } else if (x == 2 && tedad_keshti2!=0) {
            while (1) {
                printf("bede mokhtasat keshti do\n");
                scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if ((m1 == m2 || n1 == n2 )&& ((int)fabs(m2-m1)==1 ||(int)fabs(n2-n1)==1))
                        break;
                }
            }
            if (m1==m2)
                add(&*list,m1,n1,m2,n2,2,1);
            else
                add(&*list,m1,n1,m2,n2,1,2);
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            array_naghshe[m1][n1] = 2;
            array_naghshe[m2][n2] = 2;
            tedad_keshti2--;
            i++;
            print1(array_naghshe);
        } else if (x == 3 && tedad_keshti3!=0) {

            while (1) {
                printf("bede mokhtasat keshti 3ro\n");
                scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if ((m1 == m2 || n1 == n2 )&& ((int)fabs(m2-m1)==2 ||(int)fabs(n2-n1)==2))
                        break;
                }

            }
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            if (m1 == m2) {
                n=fmin(n1,n2);
                por_kardan_naghshe(array_naghshe, m1, n + 1);
                array_naghshe[m1][n + 1] = 3;
                add(&*list,m1,n,m2,n2,3,1);
            } else {
                m=fmin(m1,m2);
                por_kardan_naghshe(array_naghshe, m + 1, n1);
                array_naghshe[m + 1][n1] = 3;
                add(&*list,m1,n1,m2,n2,1,3);
            }
            array_naghshe[m1][n1] = 3;
            array_naghshe[m2][n2] = 3;
            tedad_keshti3--;
            i++;
            print1(array_naghshe);
        }
        else if (x==4 && tedad_keshti5!=0 ){
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
                n=fmin(n1,n2);
                por_kardan_naghshe(array_naghshe, m1, n+ 1);
                por_kardan_naghshe(array_naghshe, m1, n + 2);
                por_kardan_naghshe(array_naghshe, m1, n + 3);
                array_naghshe[m1][n+ 1] = 5;
                array_naghshe[m1][n + 2] = 5;
                array_naghshe[m1][n + 3] = 5;
                add(&*list,m1,n1,m2,n2,5,1);
            } else {
                m=fmin(m1,m2);
                por_kardan_naghshe(array_naghshe, m + 1, n1);
                por_kardan_naghshe(array_naghshe, m + 2, n1);
                por_kardan_naghshe(array_naghshe, m + 3, n1);
                array_naghshe[m + 1][n1] = 5;
                array_naghshe[m + 2][n1] = 5;
                array_naghshe[m + 3][n1] = 5;
                add(&*list,m1,n1,m2,n2,1,5);
            }
            array_naghshe[m1][n1] = 5;
            array_naghshe[m2][n2] = 5;
            tedad_keshti5--;
            i++;
            print1(array_naghshe);
        }

    }
}
void sakht_naghshe_rand(int array_naghshe[size_naghshe][size_naghshe],struct node **list){
    int x, m1, n1,m2,n2,m,n;
    int tedad_keshti1 = 4;
    int tedad_keshti2 = 3;
    int tedad_keshti3 = 2;
    int tedad_keshti5 = 1;
    *list=NULL;
    for(int i=0;i<size_naghshe;i++){
        for(int j=0;j<size_naghshe;j++)
            array_naghshe[i][j] = 0;
    }
    int i = 0;
    while ( i < tedad_keshti) {
        x=rand()%4 + 1;
        if (x == 1 && tedad_keshti1!=0) {
            while (1) {
                m1=rand()%10;
                n1=rand()%10;
//                if (m1<0||m1>10||n1<0||n1>10)
//                    continue;
                if (check(array_naghshe, m1, n1) == 1)
                    break;
            }
            add(&*list,m1,n1,m1,n1,1,1);
            array_naghshe[m1][n1] = 1;
            por_kardan_naghshe(array_naghshe, m1, n1);
            --tedad_keshti1;
            i++;
//            print1(array_naghshe);
        }
        else if (x == 2 && tedad_keshti2!=0) {
            while (1) {
                m1=rand()%10;
                n1=rand()%10;
                m2=rand()%10;
                n2=rand()%10;
//                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
//                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if ((m1 == m2 || n1 == n2 )&& ((int)fabs(m2-m1)==1 ||(int)fabs(n2-n1)==1))
                        break;
                }
            }
            if (m1==m2)
                add(&*list,m1,n1,m2,n2,2,1);
            else
                add(&*list,m1,n1,m2,n2,1,2);
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            array_naghshe[m1][n1] = 2;
            array_naghshe[m2][n2] = 2;
            tedad_keshti2--;
            i++;
//            print1(array_naghshe);
        } else if (x == 3 && tedad_keshti3!=0) {

            while (1) {
                m1=rand()%10;
                n1=rand()%10;
                m2=rand()%10;
                n2=rand()%10;
//                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
//                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if ((m1 == m2 || n1 == n2 )&& ((int)fabs(m2-m1)==2 ||(int)fabs(n2-n1)==2))
                        break;
                }

            }
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            if (m1 == m2) {
                n=fmin(n1,n2);
                por_kardan_naghshe(array_naghshe, m1, n + 1);
                array_naghshe[m1][n + 1] = 3;
                add(&*list,m1,n1,m2,n2,3,1);
            } else {
                m=fmin(m1,m2);
                por_kardan_naghshe(array_naghshe, m + 1, n1);
                array_naghshe[m + 1][n1] = 3;
                add(&*list,m1,n1,m2,n2,1,3);
            }
            array_naghshe[m1][n1] = 3;
            array_naghshe[m2][n2] = 3;
            tedad_keshti3--;
            i++;
//            print1(array_naghshe);
        }
        else if (x==4 && tedad_keshti5!=0 ){
            while (1) {
                m1=rand()%10;
                n1=rand()%10;
                m2=rand()%10;
                n2=rand()%10;
//                if (m1<0||m1>10||m2<0||m2>10||n1<0||n1>10||n2<0||n2>10)
//                    continue;
                if (check(array_naghshe, m1, n1) == 1 && check(array_naghshe, m2, n2) == 1) {
                    if ((m1 == m2 || n1 == n2) &&((int) fabs(m2-m1)==4 ||(int) fabs(n2-n1)==4))
                        break;
                }
            }
            por_kardan_naghshe(array_naghshe, m1, n1);
            por_kardan_naghshe(array_naghshe, m2, n2);
            if (m1 == m2) {
                n=fmin(n1,n2);
                por_kardan_naghshe(array_naghshe, m1, n+ 1);
                por_kardan_naghshe(array_naghshe, m1, n + 2);
                por_kardan_naghshe(array_naghshe, m1, n + 3);
                array_naghshe[m1][n+ 1] = 5;
                array_naghshe[m1][n + 2] = 5;
                array_naghshe[m1][n + 3] = 5;
                add(&*list,m1,n1,m2,n2,5,1);
            } else {
                m=fmin(m1,m2);
                por_kardan_naghshe(array_naghshe, m + 1, n1);
                por_kardan_naghshe(array_naghshe, m + 2, n1);
                por_kardan_naghshe(array_naghshe, m + 3, n1);
                array_naghshe[m + 1][n1] = 5;
                array_naghshe[m + 2][n1] = 5;
                array_naghshe[m + 3][n1] = 5;
                add(&*list,m1,n1,m2,n2,1,5);
            }
            array_naghshe[m1][n1] = 5;
            array_naghshe[m2][n2] = 5;
            tedad_keshti5--;
            i++;
//            print1(array_naghshe);
        }

    }
}
void ejra_bazi_do_nafare(char *user1,char *user2,char c1,char c2) {
    int m, n;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    struct ships boot;
    int seke1=0;
    int seke2=0;
    int array_naghshe_adad1[size_naghshe][size_naghshe];
    int array_naghshe_adad2[size_naghshe][size_naghshe];
    if (c1=='A')
        sakht_naghshe_rand(array_naghshe_adad1, &list1);
    else
        sakht_naghshe(array_naghshe_adad1, &list1);
    if (c2=='A')
        sakht_naghshe_rand(array_naghshe_adad2, &list2);
    else
        sakht_naghshe(array_naghshe_adad2, &list2);
    char array_naghshe_char1[size_naghshe][size_naghshe];
    char array_naghshe_char2[size_naghshe][size_naghshe];
    for (int i = 0; i < size_naghshe; i++) {
        for (int j = 0; j < size_naghshe; j++) {
            array_naghshe_char1[i][j] = ' ';
            array_naghshe_char2[i][j] = ' ';
        }
    }
    print1(array_naghshe_adad1);
    print1(array_naghshe_adad2);
    while (list2 != NULL && list1 != NULL) {
        print_naghshe(array_naghshe_char1);

        do {
            if (list2 == NULL)
                break;
            print_naghshe(array_naghshe_char2);
//            system("cls");
//            system("cls");
            printf("bede mokhtasat hamlaro %s\n",user1);
            scanf("%d %d", &m, &n);
            while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char2[m][n] != ' ') {
                printf("bede mokhtasat hamlaro %s\n",user1);
                scanf("%d %d", &m, &n);
            }
            if (array_naghshe_adad2[m][n] == -1 || array_naghshe_adad2[m][n] == 0) {
                array_naghshe_char2[m][n] = 'W';
            } else if (array_naghshe_adad2[m][n] == 1) {
                por_kardan_naghshe2(array_naghshe_char2, m, n);
                array_naghshe_char2[m][n] = 'C';
                delete(&list2, m, n);
                seke1+=26;

            } else if (array_naghshe_adad2[m][n] == 2) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                ++seke1;
                boot = search_list(list2, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char2[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char2, m, i);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 1);
                            array_naghshe_char2[m][i] = 'C';
                            array_naghshe_char2[m][i + 1] = 'C';
                            delete(&list2, m, n);
                            seke1+=12;

                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char2[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char2, i, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 1, n);
                            array_naghshe_char2[i][n] = 'C';
                            array_naghshe_char2[i + 1][n] = 'C';
                            delete(&list2, m, n);
                            seke1+=12;
                        }
                    }
                }
            } else if (array_naghshe_adad2[m][n] == 3) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                ++seke1;
                boot = search_list(list2, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char2[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char2, m, i);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 2);
                            array_naghshe_char2[m][i] = 'C';
                            array_naghshe_char2[m][i + 1] = 'C';
                            array_naghshe_char2[m][i + 2] = 'C';
                            delete(&list2, m, n);
                            seke1+=8;
                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char2[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char2, i, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 2, n);
                            array_naghshe_char2[i][n] = 'C';
                            array_naghshe_char2[i + 1][n] = 'C';
                            array_naghshe_char2[i + 2][n] = 'C';
                            delete(&list2, m, n);
                            seke1+=8;

                        }
                    }
                }
            } else if (array_naghshe_adad2[m][n] == 5) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                boot = search_list(list2, m, n);
                ++seke1;
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char2[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char2, m, i);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 2);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 3);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 4);
                            array_naghshe_char2[m][i] = 'C';
                            array_naghshe_char2[m][i + 1] = 'C';
                            array_naghshe_char2[m][i + 2] = 'C';
                            array_naghshe_char2[m][i + 3] = 'C';
                            array_naghshe_char2[m][i + 4] = 'C';
                            delete(&list2, m, n);
                            seke1+=5;
                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char2[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char2, i, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 2, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 3, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 4, n);
                            array_naghshe_char2[i][n] = 'C';
                            array_naghshe_char2[i + 1][n] = 'C';
                            array_naghshe_char2[i + 2][n] = 'C';
                            array_naghshe_char2[i + 3][n] = 'C';
                            array_naghshe_char2[i + 4][n] = 'C';
                            delete(&list2, m, n);
                            seke1+=5;
                        }
                    }
                }

            }
        } while (array_naghshe_adad2[m][n] != -1 && array_naghshe_adad2[m][n] != 0);
        print_naghshe(array_naghshe_char2);
//        system("cls");
        do {
            if (list1 == NULL || list2==NULL)
                break;
            print_naghshe(array_naghshe_char1);
//            system("cls");
            printf("bede mokhtasat hamlaro %s\n",user2);
            scanf("%d %d", &m, &n);
            while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char1[m][n] != ' ') {
                printf("bede mokhtasat hamlaro %s\n",user2);
                scanf("%d %d", &m, &n);
            }
            if (array_naghshe_adad1[m][n] == -1 || array_naghshe_adad1[m][n] == 0) {
                array_naghshe_char1[m][n] = 'W';
            } else if (array_naghshe_adad1[m][n] == 1) {
                por_kardan_naghshe2(array_naghshe_char1, m, n);
                array_naghshe_char1[m][n] = 'C';
                delete(&list1, m, n);
                seke2+=26;
            } else if (array_naghshe_adad1[m][n] == 2) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(list1, m, n);
                ++seke2;
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char1[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char1, m, i);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 1);
                            array_naghshe_char1[m][i] = 'C';
                            array_naghshe_char1[m][i + 1] = 'C';
                            delete(&list1, m, n);
                            seke2+=12;
                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char1[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char1, i, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 1, n);
                            array_naghshe_char1[i][n] = 'C';
                            array_naghshe_char1[i + 1][n] = 'C';
                            delete(&list1, m, n);
                            seke2+=12;
                        }
                    }
                }
            }
            else if (array_naghshe_adad1[m][n] == 3) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(list1, m, n);
                ++seke2;
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char1[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char1, m, i);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 2);
                            array_naghshe_char1[m][i] = 'C';
                            array_naghshe_char1[m][i + 1] = 'C';
                            array_naghshe_char1[m][i + 2] = 'C';
                            delete(&list1, m, n);
                            seke2+=12;
                        }
                    }
                }
                else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char1[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char1, i, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 2, n);
                            array_naghshe_char1[i][n] = 'C';
                            array_naghshe_char1[i + 1][n] = 'C';
                            array_naghshe_char1[i + 2][n] = 'C';
                            delete(&list1, m, n);
                            seke2+=12;
                        }
                    }
                }
            }
            else if (array_naghshe_adad1[m][n] == 5) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(list1, m, n);
                seke2++;
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char1[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char1, m, i);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 2);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 3);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 4);
                            array_naghshe_char1[m][i] = 'C';
                            array_naghshe_char1[m][i + 1] = 'C';
                            array_naghshe_char1[m][i + 2] = 'C';
                            array_naghshe_char1[m][i + 3] = 'C';
                            array_naghshe_char1[m][i + 4] = 'C';
                            delete(&list1, m, n);
                            seke2+=5;
                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char1[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char1, i, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 2, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 3, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 4, n);
                            array_naghshe_char1[i][n] = 'C';
                            array_naghshe_char1[i + 1][n] = 'C';
                            array_naghshe_char1[i + 2][n] = 'C';
                            array_naghshe_char1[i + 3][n] = 'C';
                            array_naghshe_char1[i + 4][n] = 'C';
                            delete(&list1, m, n);
                            seke2+=5;
                        }
                    }
                }
            }

        } while (array_naghshe_adad1[m][n] != -1 && array_naghshe_adad1[m][n] != 0);
    }
    if (list1==NULL){
        print_naghshe(array_naghshe_char2);
        printf("%s winner\n",user2 );
    } else{
        print_naghshe(array_naghshe_char1);
        printf("%s winner\n",user1 );
    }
}
void bazi_ba_robot(){
    int m, n;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    struct ships boot;
    int array_naghshe_adad1[size_naghshe][size_naghshe];
    int array_naghshe_adad2[size_naghshe][size_naghshe];
    sakht_naghshe(array_naghshe_adad1, &list1);
    sakht_naghshe_rand(array_naghshe_adad2, &list2);
    char array_naghshe_char1[size_naghshe][size_naghshe];
    char array_naghshe_char2[size_naghshe][size_naghshe];
    for (int i = 0; i < size_naghshe; i++) {
        for (int j = 0; j < size_naghshe; j++) {
            array_naghshe_char1[i][j] = ' ';
            array_naghshe_char2[i][j] = ' ';
        }
    }
    print1(array_naghshe_adad1);
    while (list2 != NULL && list1 != NULL) {
        print_naghshe(array_naghshe_char1);
        do {
            if (list1 == NULL || list2==NULL)
                break;
            print_naghshe(array_naghshe_char2);
            system("cls");
            printf("bede mokhtasat hamlaro SHOMARE 1\n");
            scanf("%d %d", &m, &n);
            while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char2[m][n] != ' ') {
                printf("bede mokhtasat hamlaro SHOMARE 1\n");
                scanf("%d %d", &m, &n);
            }


            if (array_naghshe_adad2[m][n] == -1 || array_naghshe_adad2[m][n] == 0) {
                array_naghshe_char2[m][n] = 'W';
            } else if (array_naghshe_adad2[m][n] == 1) {
                por_kardan_naghshe2(array_naghshe_char2, m, n);
                array_naghshe_char2[m][n] = 'C';
                delete(&list2, m, n);

            } else if (array_naghshe_adad2[m][n] == 2) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                boot = search_list(list2, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char2[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char2, m, i);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 1);
                            array_naghshe_char2[m][i] = 'C';
                            array_naghshe_char2[m][i + 1] = 'C';
                            delete(&list2, m, n);

                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char2[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char2, i, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 1, n);
                            array_naghshe_char2[i][n] = 'C';
                            array_naghshe_char2[i + 1][n] = 'C';
                            delete(&list2, m, n);
                        }
                    }
                }
            } else if (array_naghshe_adad2[m][n] == 3) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                boot = search_list(list2, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char2[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char2, m, i);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 2);
                            array_naghshe_char2[m][i] = 'C';
                            array_naghshe_char2[m][i + 1] = 'C';
                            array_naghshe_char2[m][i + 2] = 'C';
                            delete(&list2, m, n);

                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char2[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char2, i, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 2, n);
                            array_naghshe_char2[i][n] = 'C';
                            array_naghshe_char2[i + 1][n] = 'C';
                            array_naghshe_char2[i + 2][n] = 'C';
                            delete(&list2, m, n);
                        }
                    }
                }
            } else if (array_naghshe_adad2[m][n] == 5) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                boot = search_list(list2, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char2[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char2, m, i);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 2);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 3);
                            por_kardan_naghshe2(array_naghshe_char2, m, i + 4);
                            array_naghshe_char2[m][i] = 'C';
                            array_naghshe_char2[m][i + 1] = 'C';
                            array_naghshe_char2[m][i + 2] = 'C';
                            array_naghshe_char2[m][i + 3] = 'C';
                            array_naghshe_char2[m][i + 4] = 'C';
                            delete(&list2, m, n);

                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char2[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char2, i, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 2, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 3, n);
                            por_kardan_naghshe2(array_naghshe_char2, i + 4, n);
                            array_naghshe_char2[i][n] = 'C';
                            array_naghshe_char2[i + 1][n] = 'C';
                            array_naghshe_char2[i + 2][n] = 'C';
                            array_naghshe_char2[i + 3][n] = 'C';
                            array_naghshe_char2[i + 4][n] = 'C';
                            delete(&list2, m, n);

                        }
                    }
                }

            }
        } while (array_naghshe_adad2[m][n] != -1 && array_naghshe_adad2[m][n] != 0);
        print_naghshe(array_naghshe_char2);
//        system("cls");
        do {
            if (list1 == NULL || list2==NULL)
                break;

//            printf("bede mokhtasat hamlaro SHOMARE 2\n");
            m=rand()%10;
            n=rand()%10;
            while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char1[m][n] != ' ') {
                m=rand()%10;
                n=rand()%10;
            }
            if (array_naghshe_adad1[m][n] == -1 || array_naghshe_adad1[m][n] == 0) {
                array_naghshe_char1[m][n] = 'W';
            } else if (array_naghshe_adad1[m][n] == 1) {
                por_kardan_naghshe2(array_naghshe_char1, m, n);
                array_naghshe_char1[m][n] = 'C';
                delete(&list1, m, n);
            } else if (array_naghshe_adad1[m][n] == 2) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(list1, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char1[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char1, m, i);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 1);
                            array_naghshe_char1[m][i] = 'C';
                            array_naghshe_char1[m][i + 1] = 'C';
                            delete(&list1, m, n);
                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char1[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 2) {
                            por_kardan_naghshe2(array_naghshe_char1, i, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 1, n);
                            array_naghshe_char1[i][n] = 'C';
                            array_naghshe_char1[i + 1][n] = 'C';
                            delete(&list1, m, n);
                        }
                    }
                }
            }
            else if (array_naghshe_adad1[m][n] == 3) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(list1, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char1[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char1, m, i);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 2);
                            array_naghshe_char1[m][i] = 'C';
                            array_naghshe_char1[m][i + 1] = 'C';
                            array_naghshe_char1[m][i + 2] = 'C';
                            delete(&list1, m, n);
                        }
                    }
                }
                else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char1[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 3) {
                            por_kardan_naghshe2(array_naghshe_char1, i, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 2, n);
                            array_naghshe_char1[i][n] = 'C';
                            array_naghshe_char1[i + 1][n] = 'C';
                            array_naghshe_char1[i + 2][n] = 'C';
                            delete(&list1, m, n);

                        }
                    }
                }
            }
            else if (array_naghshe_adad1[m][n] == 5) {
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(list1, m, n);
                if (boot.arz == 1) {
                    i = fmin(boot.y1, boot.y2);
                    for (j = (int) fmin(boot.y1, boot.y2); j <= (int) fmax(boot.y1, boot.y2); j++) {

                        if (array_naghshe_char1[boot.x1][j] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char1, m, i);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 1);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 2);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 3);
                            por_kardan_naghshe2(array_naghshe_char1, m, i + 4);
                            array_naghshe_char1[m][i] = 'C';
                            array_naghshe_char1[m][i + 1] = 'C';
                            array_naghshe_char1[m][i + 2] = 'C';
                            array_naghshe_char1[m][i + 3] = 'C';
                            array_naghshe_char1[m][i + 4] = 'C';
                            delete(&list1, m, n);
                        }
                    }
                } else if (boot.tool == 1) {
                    i = fmin(boot.x1, boot.x2);
                    counter = 0;
                    for (j = (int) fmin(boot.x1, boot.x2); j <= (int) fmax(boot.x1, boot.x2); j++) {
                        if (array_naghshe_char1[j][boot.y1] == 'E')
                            counter++;
                        if (counter == 5) {
                            por_kardan_naghshe2(array_naghshe_char1, i, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 1, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 2, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 3, n);
                            por_kardan_naghshe2(array_naghshe_char1, i + 4, n);
                            array_naghshe_char1[i][n] = 'C';
                            array_naghshe_char1[i + 1][n] = 'C';
                            array_naghshe_char1[i + 2][n] = 'C';
                            array_naghshe_char1[i + 3][n] = 'C';
                            array_naghshe_char1[i + 4][n] = 'C';
                            delete(&list1, m, n);

                        }
                    }
                }
            }
                        print_naghshe(array_naghshe_char1);
            system("cls");

        } while (array_naghshe_adad1[m][n] != -1 && array_naghshe_adad1[m][n] != 0);
    }

}

void show_users(FILE *fp){
    fp=fopen("d:\\s\\aa.txt","r");
    if (fp==NULL){
        printf("can not open file");
    }
    int i=1;
    char str[1000];
    while(fgets(str, 1000, fp) != NULL){
        printf("%d) ",i);
        puts(str);
        i++;
    }

    fclose(fp);
}
int check_user(FILE *fp ,char *user) {
    if (fp == NULL)
        return 0;
    fp = fopen("d:\\s\\aa.txt", "r");
    if (fp == NULL)
        printf("can not open file\n");
    char str[1000];
    while (fgets(str, 1000, fp) != NULL) {
        str[strlen(str)-1]='\0';
        if (strcmpi(user,str) == 0) {
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);
    return 0;
}
FILE* add_user(FILE *fp,char *user) {
    fp = fopen("d:\\s\\aa.txt", "a");
    if (fp == NULL)
        printf("can not open file");
    fprintf(fp,"%s\n", user);
    fclose(fp);
    return fp;
}
void find_user(FILE *fp,int index,char * user){
    fp = fopen("d:\\s\\aa.txt", "r");
    if (fp == NULL)
        printf("can not open file");
    char str[1000];


    for (int i=1;i<index;i++){
        fgets(str, 1000, fp);
    }
    fgets(user,1000,fp);
    fclose(fp);
}
FILE * score_board(FILE *fp,char *user,int emtiaz){
    char str[1000];
    int x;
    char c;
    fp = fopen("d:\\s\\board.txt", "a");
    fclose(fp);
//    if (fp==NULL){
//        fp = fopen("d:\\s\\board.txt", "w");
//        if (fp == NULL)
//            printf("can not open file");
//        fprintf(fp,"%s",user);
//        fprintf(fp," %d",emtiaz);
//        fclose(fp);
//    }
//    else {

        fp = fopen("d:\\s\\board.txt", "r");
        if (fp == NULL)
            printf("can not open file");
        c=fgetc(fp);
        fclose(fp);
        if (c==EOF){
            fp = fopen("d:\\s\\board.txt", "r+");
            fprintf(fp, "%c",'\n');
            fprintf(fp, "%s", user);
            fprintf(fp, " %d", emtiaz);
            fclose(fp);
            fclose(fp);
        }
        else {
            fp = fopen("d:\\s\\board.txt", "r+");
            while (1) {
                fscanf(fp, "%s", str);
                fscanf(fp, "%d", &x);
                if (strcmpi(str, user) == 0) {
                    fprintf(fp, "%d", emtiaz);
                    fclose(fp);
                    return fp;
                } else if (fgetc(fp) == EOF) {
                    fclose(fp);
                    fp = fopen("d:\\s\\board.txt", "a");
                    fprintf(fp, "%c",'\n');
                    fprintf(fp, "%s", user);
                    fprintf(fp, " %d", emtiaz);
                    fclose(fp);
                    return fp;
                }
            }
        }




}
void print_board(FILE *fp){
    fp=fopen("d:\\s\\board.txt","r");
    if (fp==NULL){
        printf("can not open file");
    }
    int i=1;
    char str[1000];
    int emtiaz;
    do{
        fscanf(fp,"%s",str);
        printf("%s","USERS NAME:");
        printf("%20s","USERS POINT:");
        printf("\n");
        printf("%d) ",i);
        printf("%s",str);
        i++;
        fscanf(fp,"%d",&emtiaz);
        printf("%20d",emtiaz);
    }while (feof(fp));

    fclose(fp);

}

void menu() {
    FILE *fp=NULL;
    FILE *file_score_board=NULL;
    int x;
    char c1;
    char c2;
    char user1[100];
    char user2[100];
    int index;
    printf("1. Play with a Friend\n2. Play with bot\n3. Load game\n4. Load last game\n5. Settings\n6. Score Board\n7. Exit\n");
    scanf("%d", &x);
    if (x == 1) {
        printf("First player:\n     1. choose user\n");
        printf("               1. choose from available users\n               2. new user\n");
        scanf("%d", &x);
        if (x == 1) {
            if (fp==NULL){
                printf("File is empty\n");
                printf("please try a gain\n");
                menu();
            }
            show_users(fp);
            printf("bede usreo\n");
            scanf("%d",&index);
            find_user(fp,index,user1);

        }
        else if (x == 2) {
            printf("bede usero\n");
            fflush(stdin);
            gets(user1);
            if(check_user(fp,user1)==0){
                fp=add_user(fp,user1);
                 file_score_board=score_board(file_score_board,user1,0);
            } else{
                while ((check_user(fp,user1)!=0)){
                    printf("user estefade shode\n");
                    printf("bede usero\n");
                    fflush(stdin);
                    gets(user1);
                }
                fp=add_user(fp,user1);
                file_score_board=score_board(file_score_board,user1,0);
            }
        }
        printf("     2. put ships\n");
        printf("               1. Auto\n               2. Manual\n");
        scanf("%d", &x);
        if (x == 1) {
            c1='A';
        }
        else if (x == 2) {
            c1='M';
        }

        printf("Second player:\n     1. choose user\n");
        printf("               1. choose from available users\n               2. new user\n");
        scanf("%d", &x);
        if (x == 1) {
            show_users(fp);
            printf("bede usreo\n");
            scanf("%d",&index);
            find_user(fp,index,user2);

        } else if (x == 2) {
            printf("bede usero\n");
            fflush(stdin);
            gets(user2);
            if(check_user(fp,user2)==0){
                fp=add_user(fp,user2);
                file_score_board=score_board(file_score_board,user2,0);
            } else{
                while ((check_user(fp,user2)!=0)){
                    printf("user estefade shode\n");
                    printf("bede usero\n");
                    fflush(stdin);
                    gets(user2);
                }
                fp=add_user(fp,user2);
                file_score_board=score_board(file_score_board,user2,0);
            }
        }
        printf("     2. put ships\n");
        printf("               1. Auto\n               2. Manual\n");
        scanf("%d", &x);
        if (x == 1) {
             c2='A';
            ejra_bazi_do_nafare(user1, user2, c1, c2);

        } else if (x == 2) {
            c2 = 'M';
            ejra_bazi_do_nafare(user1, user2, c1, c2);
        }

    }
    else if (x==2){
        bazi_ba_robot();
    }
    else if (x==3){

    }
    else if (x==4){

    }
    else if (x==5){
        printf("     1. ships\n     2. map size\n     3. theme (bonus)\n");
        scanf("%d",&x);


    }
    else if (x==6){
        print_board(file_score_board);

    }
    else if (x==7){
        exit(-1);
    }
}

int main() {
    setbuf(stdout, 0);
    time_t t=time(NULL);
    srand(t);
    menu();

//    sakht_naghshe_rand(arr,&list);
//    print1(arr);
//    srand(time(NULL));
//
//    ejra_bazi_do_nafare();

    return 0;
}