#include <stdio.h>
#include <stdlib.h>
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
struct node *create_list(int x1_boot,int y1_boot,int x2_boot,int y2_boot,int tool_boot,int arz_boot){
    struct node *list;
    list=(struct node *)malloc(sizeof(struct node));
    if (list==NULL)
        printf("Can not create linked_list");
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
        *list=create_list(x1_boot,y1_boot,x2_boot,y2_boot,tool_boot,arz_boot);
    }
    else {
        struct node *current,*node_list;
        node_list = create_list(x1_boot,y1_boot,x2_boot,y2_boot,tool_boot,arz_boot);
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
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
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
void print_naghshe(char arr[size_naghshe][size_naghshe]){
    char c='A';
    printf("    0    1    2    3    4    5    6    7    8    9\n");
    for (int i=0;i<10;i++) {
        printf("%c",c++);
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 'W') {
                SetColor(3);
                printf("  |%c|", arr[i][j]);
            }
            if (arr[i][j] == 'C') {
                SetColor(12);
                printf("  |%c|", arr[i][j]);
            }
            if (arr[i][j]=='E'){
                SetColor(14);
                printf("  |%c|", arr[i][j]);
            }
            if (arr[i][j]==' '){
                SetColor(0);
                printf("  |%c|", arr[i][j]);
            }
        }
        SetColor(0);
        printf("%c",'\n');
    }
}
void create_map(int array_naghshe[size_naghshe][size_naghshe],struct node **list) {
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
        printf("Which ship do you want to put?\n");
        printf("1)Ship_Size1:%d\n2)Ship_Size2:%d\n3)Ship_Size3:%d\n4)Ship_Size5:%d\n", tedad_keshti1,
               tedad_keshti2, tedad_keshti3, tedad_keshti5);
        scanf("%d", &x);
        if (x == 1 && tedad_keshti1!=0) {
            while (1) {
                printf("Give me an x,y in the map\n");
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
        } else if (x == 2 && tedad_keshti2!=0) {
            while (1) {
                printf("Give me an x,y in the map\n");
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
        } else if (x == 3 && tedad_keshti3!=0) {

            while (1) {
                printf("Give me an x,y in the map\n");
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
        }
        else if (x==4 && tedad_keshti5!=0 ){
            while (1) {
                printf("Give me an x,y in the map\n");
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
        }
    }
}
void create_map_random(int array_naghshe[size_naghshe][size_naghshe],struct node **list){
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
                if (check(array_naghshe, m1, n1) == 1)
                    break;
            }
            add(&*list,m1,n1,m1,n1,1,1);
            array_naghshe[m1][n1] = 1;
            por_kardan_naghshe(array_naghshe, m1, n1);
            --tedad_keshti1;
            i++;
        }
        else if (x == 2 && tedad_keshti2!=0) {
            while (1) {
                m1=rand()%10;
                n1=rand()%10;
                m2=rand()%10;
                n2=rand()%10;
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
        } else if (x == 3 && tedad_keshti3!=0) {

            while (1) {
                m1=rand()%10;
                n1=rand()%10;
                m2=rand()%10;
                n2=rand()%10;
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
        }
        else if (x==4 && tedad_keshti5!=0 ){
            while (1) {
                m1=rand()%10;
                n1=rand()%10;
                m2=rand()%10;
                n2=rand()%10;
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
        }
    }
}
int check_user(FILE *fp ,char *user) {

    fp = fopen("d:\\users.txt", "r");
    if (fp == NULL)
        return 0;
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
    fp = fopen("d:\\users.txt", "a");
    if (fp == NULL)
        printf("can not open file");
    fprintf(fp,"%s\n", user);
    fclose(fp);
    return fp;
}
int show_users(FILE *fp){
    fp=fopen("d:\\users.txt","r");
    if (fp==NULL){
        printf("can not open file\n");
        return 0;
    }
    int i=1;
    char str[1000];
    while(fgets(str, 1000, fp) != NULL){
        printf("%d) ",i);
        puts(str);
        i++;
    }
    fclose(fp);
    return 1;
}
void find_user(FILE *fp,int index,char * user){
    fp = fopen("d:\\users.txt", "r");
    if (fp == NULL)
        printf("can not open file");
    char str[1000];
    for (int i=1;i<index;i++){
        fgets(str, 1000, fp);
    }
    fgets(user,1000,fp);
    fclose(fp);
}
void score_board(char *user,int emtiaz) {
    FILE *fp;
    char str[1000];
    int x;
    char arr_user[1000][100];
    int arr_emtiaz[1000];
    int counter = 0;
    int i = 0;
    char c;
    fp = fopen("d:\\board.txt", "a");
    if (fp == NULL) {
        printf("can not open file");
        return ;
    }
    fclose(fp);
    fp = fopen("d:\\board.txt", "r");
    if (fp == NULL) {
        printf("can not open file");
        return ;
    }
    if (fgetc(fp) == EOF) {
        fclose(fp);
        fp = fopen("d:\\board.txt", "a");
        if (fp == NULL) {
            printf("can not open file");
            return ;
        }
        fprintf(fp, "%s", user);
        fprintf(fp, "%c", '\n');
        fprintf(fp, "%d", 0);
        fprintf(fp, "%c", '\n');
        fclose(fp);
        return ;
    } else {
        fclose(fp);
        fp = fopen("d:\\board.txt", "r");
        if (fp == NULL) {
            printf("can not open file");
            return ;
        }
        for (counter = 0;; ++counter) {
            fscanf(fp, "%s", arr_user[counter]);
            fgetc(fp);
            fscanf(fp, "%d", &arr_emtiaz[counter]);
            if (fgetc(fp) == EOF)
                break;
        }
        fclose(fp);
        fp = fopen("d:\\board.txt", "w");
        if (fp == NULL) {
            printf("can not open file");
            return ;
        }
        if(user[strlen(user)-1]=='\n'){
            user[strlen(user)-1]='\0';
        }
        for (i = 0; i < counter; i++) {
            if (strcmpi(arr_user[i], user) == 0) {
                arr_emtiaz[i] += emtiaz;
                break;
            }
            if (i == counter - 1) {
                strcpy(arr_user[counter], user);
                arr_emtiaz[counter] = 0;
                counter++;
                break;
            }
        }
        for (i = 0; i < counter; i++) {
            fprintf(fp, "%s", arr_user[i]);
            fprintf(fp, "%c", '\n');
            fprintf(fp, "%d", arr_emtiaz[i]);
            fprintf(fp, "%c", '\n');
        }
        fclose(fp);
        return ;
    }
}
void array_int_swap(int a[], int i, int j){
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void array_char_swap(char a[][100], int i, int j){
    char tmp[100];
    strcpy(tmp,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],tmp);
}
void bubble_sort(int a[],char user[][100], int size){
    int i, j;
    for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
            if(a[i] < a[j]) {
                array_int_swap(a, i, j);
                array_char_swap(user, i, j);
            }
}
void save(char array_naghshe_char1[][size_naghshe],int array_naghshe_adad1[][size_naghshe],struct node *list1,
          char *user1,int seke1,char array_naghshe_char2[][size_naghshe],int array_naghshe_adad2[][size_naghshe]
        ,struct node *list2,char *user2,int seke2,int a) {
    struct node *current1=list1;
    struct node *current2=list2;
    int tedad_keshti1=0;
    int tedad_keshti2=0;
    char arr1[100];
    char arr2[100];
    strcpy(arr1,user1);
    strcpy(arr2,user2);
    FILE *fsave = fopen("d:\\save.bin","ab");
    FILE *fsave_lastgame = fopen("d:\\save_lastgame.bin","wb");
    FILE *fuser = fopen("d:\\games_user.txt","a");
    fwrite(arr1,1,100,fsave);
    fwrite(arr1,1,100,fsave_lastgame);
    fwrite(arr2,1,100,fsave);
    fwrite(arr2,1,100,fsave_lastgame);

    if (arr1[strlen(arr1)-1]=='\n') {
        arr1[strlen(arr1) - 1] = '\0';
    }
    if (arr2[strlen(arr2)-1]=='\n') {
        arr2[strlen(arr2) - 1] = '\0';
    }
    fprintf(fuser,"%s %s %s%c",arr1,"vs",arr2,'\n');
    fclose(fuser);
    fwrite(&a,sizeof(int),1,fsave);
    fwrite(&a,sizeof(int),1,fsave_lastgame);
    fwrite(&seke1,sizeof(int),1,fsave);
    fwrite(&seke2,sizeof(int),1,fsave);
    fwrite(&seke1,sizeof(int),1,fsave_lastgame);
    fwrite(&seke2,sizeof(int),1,fsave_lastgame);
    while (current1!=NULL){
        current1=current1->next;
        tedad_keshti1++;
    }  while (current2!=NULL){
        current2=current2->next;
        tedad_keshti2++;
    }
    fwrite(&tedad_keshti1,sizeof(int),1,fsave);
    fwrite(&tedad_keshti2,sizeof(int),1,fsave);
    fwrite(&tedad_keshti1,sizeof(int),1,fsave_lastgame);
    fwrite(&tedad_keshti2,sizeof(int),1,fsave_lastgame);
    for (int i=0;i<tedad_keshti1;i++){
        fwrite(&list1->boot.x1,sizeof(int),1,fsave);
        fwrite(&list1->boot.y1,sizeof(int),1,fsave);
        fwrite(&list1->boot.x2,sizeof(int),1,fsave);
        fwrite(&list1->boot.y2,sizeof(int),1,fsave);
        fwrite(&list1->boot.tool,sizeof(int),1,fsave);
        fwrite(&list1->boot.arz,sizeof(int),1,fsave);
        fwrite(&list1->boot.x1,sizeof(int),1,fsave_lastgame);
        fwrite(&list1->boot.y1,sizeof(int),1,fsave_lastgame);
        fwrite(&list1->boot.x2,sizeof(int),1,fsave_lastgame);
        fwrite(&list1->boot.y2,sizeof(int),1,fsave_lastgame);
        fwrite(&list1->boot.tool,sizeof(int),1,fsave_lastgame);
        fwrite(&list1->boot.arz,sizeof(int),1,fsave_lastgame);
        list1=list1->next;
    }
    for (int i=0;i<tedad_keshti2;i++){

        fwrite(&list2->boot.x1,sizeof(int),1,fsave);
        fwrite(&list2->boot.y1,sizeof(int),1,fsave);
        fwrite(&list2->boot.x2,sizeof(int),1,fsave);
        fwrite(&list2->boot.y2,sizeof(int),1,fsave);
        fwrite(&list2->boot.tool,sizeof(int),1,fsave);
        fwrite(&list2->boot.arz,sizeof(int),1,fsave);
        fwrite(&list2->boot.x1,sizeof(int),1,fsave_lastgame);
        fwrite(&list2->boot.y1,sizeof(int),1,fsave_lastgame);
        fwrite(&list2->boot.x2,sizeof(int),1,fsave_lastgame);
        fwrite(&list2->boot.y2,sizeof(int),1,fsave_lastgame);
        fwrite(&list2->boot.tool,sizeof(int),1,fsave_lastgame);
        fwrite(&list2->boot.arz,sizeof(int),1,fsave_lastgame);
        list2=list2->next;
    }
    fwrite(array_naghshe_char1,sizeof(char ),100,fsave);
    fwrite(array_naghshe_char2,sizeof(char ),100,fsave);
    fwrite(array_naghshe_char1,sizeof(char ),100,fsave_lastgame);
    fwrite(array_naghshe_char2,sizeof(char ),100,fsave_lastgame);
    fwrite(array_naghshe_adad1,sizeof(int),100,fsave);
    fwrite(array_naghshe_adad2,sizeof(int),100,fsave);
    fwrite(array_naghshe_adad1,sizeof(int),100,fsave_lastgame);
    fwrite(array_naghshe_adad2,sizeof(int),100,fsave_lastgame);
    fclose(fsave);
    fclose(fsave_lastgame);
    fclose(fuser);
}
void single_player(char array_naghshe_char1[][size_naghshe],int array_naghshe_adad1[][size_naghshe]
        ,struct node **list1,char *user1,int *seke1,char array_naghshe_char2[][size_naghshe],
                   int array_naghshe_adad2[][size_naghshe],struct node **list2,char *user2,int *seke2){
    int m,x,n;
    *seke1=0;
    *seke2=0;
    struct ships boot;
    while (list2 != NULL && list1 != NULL) {
        printf("Result map\n");
        print_naghshe(array_naghshe_char1);
        do {
            if (list1 == NULL || list2==NULL)
                break;
            printf("Shift map\n");
            print_naghshe(array_naghshe_char2);
            printf("Would you like to save this game?\n");
            printf("1)Yes\n2)NO\n");
            scanf("%d",&x);
            if (x==1) {
                save(array_naghshe_char1, array_naghshe_adad1, *list1, user1, *seke1, array_naghshe_char2,
                     array_naghshe_adad2, *list2, user2, *seke2, 1);

                return;
            }
                printf("Give an x,y for attack %s\n",user1);
                scanf("%d %d", &m, &n);
                while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char2[m][n] != ' ') {
                    printf("Give an x,y for attack\n");
                    scanf("%d %d", &m, &n);
                }
                if (array_naghshe_adad2[m][n] == -1 || array_naghshe_adad2[m][n] == 0) {
                    array_naghshe_char2[m][n] = 'W';
                } else if (array_naghshe_adad2[m][n] == 1) {
                    por_kardan_naghshe2(array_naghshe_char2, m, n);
                    array_naghshe_char2[m][n] = 'C';
                    delete(&*list2, m, n);

                } else if (array_naghshe_adad2[m][n] == 2) {
                    int counter = 0;
                    int j;
                    int i;
                    array_naghshe_char2[m][n] = 'E';
                    boot = search_list(*list2, m, n);
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
                                delete(&*list2, m, n);
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
                                delete(&*list2, m, n);
                            }
                        }
                    }
                } else if (array_naghshe_adad2[m][n] == 3) {
                    int counter = 0;
                    int j;
                    int i;
                    array_naghshe_char2[m][n] = 'E';
                    boot = search_list(*list2, m, n);
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
                                delete(&*list2, m, n);

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
                                delete(&*list2, m, n);
                            }
                        }
                    }
                } else if (array_naghshe_adad2[m][n] == 5) {
                    int counter = 0;
                    int j;
                    int i;
                    array_naghshe_char2[m][n] = 'E';
                    boot = search_list(*list2, m, n);
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
                                delete(&*list2, m, n);

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
                                delete(&*list2, m, n);

                            }
                        }
                    }

                }
            } while (array_naghshe_adad2[m][n] != -1 && array_naghshe_adad2[m][n] != 0);
            do {
                if (list1 == NULL || list2==NULL)
                    break;
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
                    delete(&*list1, m, n);
                } else if (array_naghshe_adad1[m][n] == 2) {
                    int counter = 0;
                    int j;
                    int i;
                    array_naghshe_char1[m][n] = 'E';
                    boot = search_list(*list1, m, n);
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
                                delete(&*list1, m, n);
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
                                delete(&*list1, m, n);
                            }
                        }
                    }
                }
                else if (array_naghshe_adad1[m][n] == 3) {
                    int counter = 0;
                    int j;
                    int i;
                    array_naghshe_char1[m][n] = 'E';
                    boot = search_list(*list1, m, n);
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
                                delete(&*list1, m, n);
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
                                delete(&*list1, m, n);

                            }
                        }
                    }
                }
                else if (array_naghshe_adad1[m][n] == 5) {
                    int counter = 0;
                    int j;
                    int i;
                    array_naghshe_char1[m][n] = 'E';
                    boot = search_list(*list1, m, n);
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
                                delete(&*list1, m, n);
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
                                delete(&*list1, m, n);

                            }
                        }
                    }
                }
            } while (array_naghshe_adad1[m][n] != -1 && array_naghshe_adad1[m][n] != 0);
        }

    }
void multi_player(char array_naghshe_char1[][size_naghshe],int array_naghshe_adad1[][size_naghshe],
                    struct node **list1,char *user1,int *seke1,char array_naghshe_char2[][size_naghshe],
                    int array_naghshe_adad2[][size_naghshe],struct node **list2,char *user2,int *seke2){
    int m, n;
    int x;
    struct ships boot;
    while (*list2 != NULL && *list1 != NULL) {
        printf("Result map:\n");
        print_naghshe(array_naghshe_char1);
        do {
            if (*list2 == NULL)
                break;
            printf("Shift map:\n");
            print_naghshe(array_naghshe_char2);
            printf("Would you like to save this game?\n");
            printf("1)Yes\n2)NO\n");
            scanf("%d",&x);
            if (x==1)  {
                save(array_naghshe_char1,array_naghshe_adad1,*list1,user1,*seke1,array_naghshe_char2
                        ,array_naghshe_adad2,*list2,user2,*seke2,2);
                return;
            } else;
            printf("Give an x,y for attack %s\n",user1);
            scanf("%d %d", &m, &n);
            while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char2[m][n] != ' ') {
                printf("Error\n");
                printf("Please try a gain\n");
                printf("Give an x,y for attack %s\n",user1);
                scanf("%d %d", &m, &n);
            }
            if (array_naghshe_adad2[m][n] == -1 || array_naghshe_adad2[m][n] == 0) {
                array_naghshe_char2[m][n] = 'W';
            }
            else if (array_naghshe_adad2[m][n] == 1) {
                Beep(659, 400);
                por_kardan_naghshe2(array_naghshe_char2, m, n);
                array_naghshe_char2[m][n] = 'C';
                delete(&*list2, m, n);
                *seke1+=26;
            }
            else if (array_naghshe_adad2[m][n] == 2) {
                Beep(659, 400);
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                ++*seke1;
                boot = search_list(*list2, m, n);
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
                            delete(&*list2, m, n);
                            *seke1+=12;
                        }
                    }
                }
                else if (boot.tool == 1) {
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
                            delete(&*list2, m, n);
                            *seke1+=12;
                        }
                    }
                }
            }
            else if (array_naghshe_adad2[m][n] == 3) {
                Beep(659, 400);
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                ++*seke1;
                boot = search_list(*list2, m, n);
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
                            delete(&*list2, m, n);
                            *seke1+=8;
                        }
                    }
                }
                else if (boot.tool == 1) {
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
                            delete(&*list2, m, n);
                            *seke1+=8;
                        }
                    }
                }
            }
            else if (array_naghshe_adad2[m][n] == 5) {
                Beep(659, 400);
                int counter = 0;
                int j;
                int i;
                array_naghshe_char2[m][n] = 'E';
                boot = search_list(*list2, m, n);
                ++*seke1;
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
                            delete(&*list2, m, n);
                            *seke1+=5;
                        }
                    }
                }
                else if (boot.tool == 1) {
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
                            delete(&*list2, m, n);
                            *seke1+=5;
                        }
                    }
                }

            }
        } while (array_naghshe_adad2[m][n] != -1 && array_naghshe_adad2[m][n] != 0);
        printf("Result map:\n");
        print_naghshe(array_naghshe_char2);
//        system("cls");
        do {
            if (*list1 == NULL || *list2==NULL)
                break;
            printf("Shift map:\n");
            print_naghshe(array_naghshe_char1);
            printf("Would you like to save this game?\n");
            printf("1)Yes\n2)NO\n");
            scanf("%d",&x);
            if (x==1)  {
                save(array_naghshe_char1,array_naghshe_adad1,*list1,user1,*seke1,array_naghshe_char2
                        ,array_naghshe_adad2,*list2,user2,*seke2,2);
                return;
            }
            else;
            printf("Give an x,y for attack %s\n",user2);
            scanf("%d %d", &m, &n);
            while (m < 0 || m > 10 || n < 0 || n > 10 || array_naghshe_char1[m][n] != ' ') {
                printf("Error\n");
                printf("Please try a gain\n");
                printf("Give an x,y for attack%s\n",user2);
                scanf("%d %d", &m, &n);
            }
            if (array_naghshe_adad1[m][n] == -1 || array_naghshe_adad1[m][n] == 0) {
                array_naghshe_char1[m][n] = 'W';
            } else if (array_naghshe_adad1[m][n] == 1) {
                Beep(659, 400);
                por_kardan_naghshe2(array_naghshe_char1, m, n);
                array_naghshe_char1[m][n] = 'C';
                delete(&*list1, m, n);
                *seke2+=26;
            } else if (array_naghshe_adad1[m][n] == 2) {
                Beep(659, 400);
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(*list1, m, n);
                ++*seke2;
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
                            delete(&*list1, m, n);
                            *seke2+=12;
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
                            delete(&*list1, m, n);
                            *seke2+=12;
                        }
                    }
                }
            }
            else if (array_naghshe_adad1[m][n] == 3) {
                Beep(659, 400);
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(*list1, m, n);
                ++*seke2;
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
                            delete(&*list1, m, n);
                            *seke2+=8;
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
                            delete(&*list1, m, n);
                            *seke2+=8;
                        }
                    }
                }
            }
            else if (array_naghshe_adad1[m][n] == 5) {
                Beep(659, 400);
                int counter = 0;
                int j;
                int i;
                array_naghshe_char1[m][n] = 'E';
                boot = search_list(*list1, m, n);
                ++*seke2;
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
                            delete(&*list1, m, n);
                            *seke2+=5;
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
                            delete(&*list1, m, n);
                            *seke2+=5;
                        }
                    }
                }
            }

        } while (array_naghshe_adad1[m][n] != -1 && array_naghshe_adad1[m][n] != 0);
    }
    if (*list1==NULL){
        print_naghshe(array_naghshe_char2);
        printf("%s winner\n",user2 );
        score_board(user2,*seke2);
        score_board(user1,(*seke1/2));
    } else{
        print_naghshe(array_naghshe_char1);
        printf("%s winner\n",user1 );
        score_board(user2,*seke2/2);
        score_board(user1,*seke1);
    }
}
int load_lastgame(char array_naghshe_char1[size_naghshe][size_naghshe],int array_naghshe_adad1[size_naghshe][size_naghshe],
                   struct node **list1,char *user1,int *seke1,char array_naghshe_char2[][size_naghshe],
                   int array_naghshe_adad2[][size_naghshe],struct node **list2,char *user2,int *seke2) {
    char arr[200];
    int c;
    int x1,y1,x2,y2,tool,arz;
    int tedad_keshti1 = 0;
    int tedad_keshti2 = 0;
    FILE *fp = fopen("d:\\save_lastgame.bin", "rb");
    fread(user1, 1, 100, fp);
    fread(user2, 1, 100, fp);
    fread(&c, 4, 1, fp);
    fread(seke1, sizeof(int), 1, fp);
    fread(seke2, sizeof(int), 1, fp);
    fread(&tedad_keshti1, sizeof(int), 1, fp);
    fread(&tedad_keshti2, sizeof(int), 1, fp);
    for (int i = 0; i < tedad_keshti1; i++){
        fread(&x1,sizeof(int),1,fp);
        fread(&y1,sizeof(int),1,fp);
        fread(&x2,sizeof(int),1,fp);
        fread(&y2,sizeof(int),1,fp);
        fread(&tool,sizeof(int),1,fp);
        fread(&arz,sizeof(int),1,fp);
        add(&*list1,x1,y1,x2,y2,tool,arz);
}
    for (int i = 0; i < tedad_keshti2; i++){
        fread(&x1,sizeof(int),1,fp);
        fread(&y1,sizeof(int),1,fp);
        fread(&x2,sizeof(int),1,fp);
        fread(&y2,sizeof(int),1,fp);
        fread(&tool,sizeof(int),1,fp);
        fread(&arz,sizeof(int),1,fp);
        add(&*list2,x1,y1,x2,y2,tool,arz);
    }

    fread(array_naghshe_char1,sizeof(char),100,fp);
    fread(array_naghshe_char2,sizeof(char),100,fp);
    fread(array_naghshe_adad1,sizeof(int),100,fp);
    fread(array_naghshe_adad2,sizeof(int),100,fp);
    fclose(fp);
    if (c==2)
        return 2;
    else
        return 1;
}
int load_game(char array_naghshe_char1[size_naghshe][size_naghshe],int array_naghshe_adad1[size_naghshe][size_naghshe],
               struct node **list1,char *user1,int *seke1,char array_naghshe_char2[][size_naghshe],
               int array_naghshe_adad2[][size_naghshe],struct node **list2,char *user2,int *seke2) {
    FILE *fp = fopen("d:\\save.bin", "rb");
    int counter = 0;
    char c;
    char arr[200];
    int x1,y1,x2,y2,tool,arz;
    int tedad_keshti1;
    int tedad_keshti2;
    int shomare;
    char name[100][300];
    FILE *fuser = fopen("d:\\games_user.txt","r");
    while (fgets(name[counter],100,fuser)!=NULL){
        counter++;
    }
    printf("Which game do you want to load?\n");
    for (int i = 0; i < counter; i++) {
        printf("%d)%s", i+1, name[i]);
    }
    printf("\n");
    scanf("%d", &shomare);
    if (shomare > counter) {
        while (shomare > counter) {
            printf("try a gain\n");
            printf("Which game do you want to load?\n");
            for (int i = 0; i < counter; i++) {
                printf("%d)%s", i+1, name[i]);
            }
            scanf("%d", &shomare);
        }
    }
    for (int i = 1; i < shomare; i++) {
        fseek(fp, 212, SEEK_CUR);
        fread(&tedad_keshti1, 4, 1, fp);
        fread(&tedad_keshti2, 4, 1, fp);
        fseek(fp, (tedad_keshti1 + tedad_keshti2) * 24, SEEK_CUR);
        fseek(fp,1000,SEEK_CUR);
    }
    fread(user1, 1, 100, fp);
    fread(user2, 1, 100, fp);
    fread(&c, 4, 1, fp);
    fread(seke1, sizeof(int), 1, fp);
    fread(seke2, sizeof(int), 1, fp);
    fread(&tedad_keshti1, sizeof(int), 1, fp);
    fread(&tedad_keshti2, sizeof(int), 1, fp);
    for (int i = 0; i < tedad_keshti1; i++){
        fread(&x1,sizeof(int),1,fp);
        fread(&y1,sizeof(int),1,fp);
        fread(&x2,sizeof(int),1,fp);
        fread(&y2,sizeof(int),1,fp);
        fread(&tool,sizeof(int),1,fp);
        fread(&arz,sizeof(int),1,fp);
        add(&*list1,x1,y1,x2,y2,tool,arz);
    }
    for (int i = 0; i < tedad_keshti2; i++){
        fread(&x1,sizeof(int),1,fp);
        fread(&y1,sizeof(int),1,fp);
        fread(&x2,sizeof(int),1,fp);
        fread(&y2,sizeof(int),1,fp);
        fread(&tool,sizeof(int),1,fp);
        fread(&arz,sizeof(int),1,fp);
        add(&*list2,x1,y1,x2,y2,tool,arz);
    }
    fread(array_naghshe_char1,sizeof(char),100,fp);
    fread(array_naghshe_char2,sizeof(char),100,fp);
    fread(array_naghshe_adad1,sizeof(int),100,fp);
    fread(array_naghshe_adad2,sizeof(int),100,fp);
    fclose(fp);
    if (c==2)
        return 2;
    else
        return 1;
}
void print_board(){
    FILE *fp;
    fp=fopen("d:\\board.txt","r");
    if (fp==NULL){
        printf("can not open file");
        return;
    }
    char arr_user[1000][100];
    int arr_emtiaz[1000];
    int i =0;
    int j =0;
    char str[1000];
    int emtiaz;
    for (i= 0; ; ++i) {
        fscanf(fp,"%s",arr_user[i]);
        fgetc(fp);
        fscanf(fp,"%d",&arr_emtiaz[i]);
        if(fgetc(fp)==EOF)
            break;
    }
    printf("%s","USERS NAME:");
    printf("%20s","USERS POINT:");
    bubble_sort(arr_emtiaz,arr_user,i);
    printf("\n");
    for (j=0;j<i;j++){
        printf("%10s",arr_user[j]);

        printf("%20d",arr_emtiaz[j]);
        printf("\n");
    }
    fclose(fp);
}
void menu() {
    FILE *fp;
    char array_naghshe_char1[size_naghshe][size_naghshe];
    int array_naghshe_adad1[size_naghshe][size_naghshe];
    struct node *list1 = NULL;
    char user1[100];
    int seke1 = 0;
    char array_naghshe_char2[size_naghshe][size_naghshe];
    int array_naghshe_adad2[size_naghshe][size_naghshe];
    for (int i = 0; i < size_naghshe; i++) {
        for (int j = 0; j < size_naghshe; j++) {
            array_naghshe_char1[i][j] = ' ';
            array_naghshe_char2[i][j] = ' ';
        }
    }
    struct node *list2 = NULL;
    char user2[100];
    int seke2 = 0;
    int x;
    int z;
    int index;
    printf("1. Play with a Friend\n2. Play with bot\n3. Load game\n4. Load last game\n5. Settings\n6. Score Board\n7. Exit\n");
    scanf("%d", &x);
    if (x == 1) {

        printf("First player:\n     1. choose user\n");
        printf("               1. choose from available users\n               2. new user\n");
        scanf("%d", &x);
        if (x == 1) {
            if (show_users(fp) == 0) {
                printf("please try a gain\n");
                menu();
            }
            printf("Give a number for user\n");
            scanf("%d", &index);
            find_user(fp, index, user1);
        } else if (x == 2) {
            printf("Give me a user\n");
            fflush(stdin);
            gets(user1);
            if (check_user(fp, user1) == 0) {
                fp = add_user(fp, user1);
                score_board(user1, 0);
            } else {
                while ((check_user(fp, user1) != 0)) {
                    printf("This user use before\n");
                    printf("Give me a new user\n");
                    fflush(stdin);
                    gets(user1);
                }
                fp = add_user(fp, user1);
                score_board(user1, 0);
            }
        }
        printf("     2. put ships\n");
        printf("               1. Auto\n               2. Manual\n");
        scanf("%d", &x);
        if (x == 1) {
            create_map_random(array_naghshe_adad1, &list1);
        } else if (x == 2) {
            create_map(array_naghshe_adad1, &list1);
        }

        printf("Second player:\n     1. choose user\n");
        printf("               1. choose from available users\n               2. new user\n");
        scanf("%d", &x);
        if (x == 1) {
            show_users(fp);
            printf("Give me a user\n");
            scanf("%d", &index);
            find_user(fp, index, user2);

        } else if (x == 2) {
            printf("Give me a user\n");
            fflush(stdin);
            gets(user2);
            if (check_user(fp, user2) == 0) {
                fp = add_user(fp, user2);
                score_board(user2, 0);
            } else {
                while ((check_user(fp, user2) != 0)) {
                    printf("This user use before\n");
                    printf("Give me a new user\n");
                    fflush(stdin);
                    gets(user2);
                }
                fp = add_user(fp, user2);
                score_board(user2, 0);
            }
        }
        printf("     2. put ships\n");
        printf("               1. Auto\n               2. Manual\n");
        scanf("%d", &x);
        if (x == 1) {
            create_map_random(array_naghshe_adad2, &list2);

        } else if (x == 2) {
            create_map(array_naghshe_adad2, &list2);
        }
        multi_player(array_naghshe_char1, array_naghshe_adad1, &list1, user1, &seke1, array_naghshe_char2,
                            array_naghshe_adad2, &list2, user2, &seke2);
        menu();

    } else if (x == 2) {
        printf("Player:\n     1. choose user\n");
        printf("               1. choose from available users\n               2. new user\n");
        scanf("%d", &x);
        if (x == 1) {
            if (show_users(fp) == 0) {
                printf("please try a gain\n");
                menu();
            }
            printf("Give a number for user\n");
            scanf("%d", &index);
            find_user(fp, index, user1);
        } else if (x == 2) {
            printf("Give me a user\n");
            fflush(stdin);
            gets(user1);
            if (check_user(fp, user1) == 0) {
                fp = add_user(fp, user1);
                score_board(user1, 0);
            } else {
                while ((check_user(fp, user1) != 0)) {
                    printf("This user use before\n");
                    printf("Give me a new user\n");
                    fflush(stdin);
                    gets(user1);
                }
                fp = add_user(fp, user1);
                score_board(user1, 0);
            }
        }
        printf("     2. put ships\n");
        printf("               1. Auto\n               2. Manual\n");
        scanf("%d", &x);
        if (x == 1) {
            create_map_random(array_naghshe_adad1, &list1);
        } else if (x == 2) {
            create_map(array_naghshe_adad1, &list1);
        }
        strcpy(user2,"Robot");
        user2[strlen(user2)]='\0';
        create_map_random(array_naghshe_adad2, &list2);
        single_player(array_naghshe_char1, array_naghshe_adad1, &list1, user1, &seke1, array_naghshe_char2,
                      array_naghshe_adad2, &list2, user2, &seke2);
        menu();

    }
    else if (x == 3) {
        if (load_game(array_naghshe_char1, array_naghshe_adad1, &list1, user1, &seke1, array_naghshe_char2,
                          array_naghshe_adad2, &list2, user2, &seke2) == 2) {
            multi_player(array_naghshe_char1, array_naghshe_adad1, &list1, user1, &seke1, array_naghshe_char2,
                                array_naghshe_adad2, &list2, user2, &seke2);
            menu();
        }
        else;
        create_map_random(array_naghshe_adad2,&list2);
        single_player(array_naghshe_char1,array_naghshe_adad1,&list1,user1,&seke1,array_naghshe_char2,
                      array_naghshe_adad2,&list2,user2,&seke2);
        menu();
    }
    else if (x==4){
        if ( load_lastgame(array_naghshe_char1, array_naghshe_adad1,&list1,user1,&seke1,array_naghshe_char2,
                           array_naghshe_adad2, &list2, user2,&seke2)==2) {
            multi_player(array_naghshe_char1, array_naghshe_adad1, &list1, user1, &seke1, array_naghshe_char2,
                                array_naghshe_adad2, &list2, user2, &seke2);
            menu();
        }
        create_map_random(array_naghshe_adad2,&list2);
        create_map_random(array_naghshe_adad2,&list2);
        single_player(array_naghshe_char1,array_naghshe_adad1,&list1,user1,&seke1,array_naghshe_char2,
                      array_naghshe_adad2,&list2,user2,&seke2);

        menu();
    }
    else if (x==5){
        printf("     1. ships\n     2. map size\n     3. theme (bonus)\n");
        scanf("%d",&x);
        printf("comming soon!\n");
        menu();
    }
    else if (x==6){
        print_board();
        menu();
    }
    else if (x==7){
        exit(-1);
    }
}
int main() {
    time_t t=time(NULL);
    srand(t);
    menu();
    return 0;
}