#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Student_Num 10
#define Max_Str_len 20

typedef struct  T_student{
    int number;
    char name [Max_Student_Num];
    char phone[Max_Student_Num];
};

typedef struct T_Node{
    struct T_student s;
    struct T_Node * next;
};

char command_str[]={"\n1 display all member（显示所有）;\n2 insert member（插入）;\n3 del member（删除）;\n4 exit（退出）\nCommand selection:"};

struct T_student students[Max_Student_Num];
struct T_Node * head = NULL;

int main(int argc, char* argv[])
{
    int command, i;
    struct T_student student;
    struct T_Node * pStu =head;
    memset(&student,0,sizeof(student));

    while(1){
        printf("%s",command_str);
        scanf("%d", &command);
        switch(command)
        {
        case 1:
            if(head==NULL){
               printf("空!!!!!!!!!!!!\n");
               break;
            }
            if(head->next==head){
                display_student(head);
            }else{
                pStu=head->next;
                do
                {
                    display_student(pStu);
                    pStu=pStu->next;
                }while(pStu!= head->next);
//
            }

            break;
        case 2:
            printf("enter new student number:");
            scanf("%d", &student.number);
            printf("enter new student name:");
            scanf("%s", &student.name);
            if(strlen(student.name) > Max_Str_len)
            {
                printf("name is too long!!\n");
                continue;
            }

            printf("enter new student phone:");
            scanf("%s", &student.phone);

            if(strlen(student.phone) > Max_Str_len)
            {
                printf("phone is too long!!\n");
                continue;
            }

            printf("\n");

            if(student.number != 0)
                 insert_student(student);

            break;
        case 3:
            printf("Inter deleted student number:");
            scanf("%d", &student.number);
            del_student(student);
            break;
        case 4:
            return 0;
        default:
            printf("error command, try again\n");
            break;
        }
    }
}


void display_student( struct T_Node * pStu){
    printf("number:%d name:%s phone:%s \n",pStu->s.number,pStu->s.name,pStu->s.phone);
}

void insert_student(struct T_student student){

    struct T_Node* pNode ;
    struct T_Node* pStu =NULL;
    int size = sizeof(struct T_Node);
    pStu=(struct T_Node *)malloc (size);
    if(pStu == NULL){
        return ;
    }
    memcpy(&pStu->s,&student,sizeof(student));

    if(head==NULL){

            pStu->next=head;
            head=pStu;
            head->next=head;
            return ;
    }
    pStu->next = head->next;
    head->next=pStu;


}

void del_student(struct T_student student){
    struct T_Node *pNode =NULL,*p=NULL;
    if(head->next==head && head->s.number==student.number){
        pNode=head;
        head=NULL;
        free(pNode);
        printf("success");
        return;
    }
    for(pNode=head->next;pNode != head;pNode=pNode->next){
        if( pNode->next->s.number == student.number){
            p=pNode->next->next;

            free(pNode->next);
            pNode->next=p;

            printf("Delete success!\n");
            return;
        }

    }
    printf("Not Found\n");
}
