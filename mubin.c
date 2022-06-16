#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

long int pat_id[1000]={130521001,140521001,140521002};//data for patient id
char pat_name[1000][100]={"Mubin","Wasif","Guts"};//data for patient name
char disease[1000][100]={"AIDS","COVID-19","Life"};//data for patient's disease name
int room_no[1000]={201,901,101};//data for patient room no
int n=3;//total patient number

void updater(int i);
void deleter(int i);
void displayer(int i);

int main(void)
{
    int choice,i;
    long int id;
    char s[100],c;
    while(1){
        printf("1.See all data\n2.Look up data by ID\n3.Look up data by Name\n4.Add new data\n5.Update existing data\n6.Delete data\n7.Exit.\n\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                for(i=0;i<n;i++)displayer(i);
                break;
            case 2:
                printf("\nID:");
                scanf("%ld",&id);
                for(i=0;i<n;i++){
                    if(id==pat_id[i])displayer(i);
                }
                break;
            case 3:
                printf("\nName:");
                scanf("%[^\n]",s);
                for(i=0;i<n;i++){
                    if(!strcmp(s,pat_name[i]))displayer(i);
                }
                break;
            case 4:
                updater(n);
                n++;
                break;
            case 5:
                printf("\nID to update:");
                scanf("%ld",&id);
                for(i=0;i<n;i++){
                    if(id==pat_id[i]){
                        printf("Data to be updated:\n");
                        displayer(i);
                        updater(i);
                        break;
                    }
                }
                if(i==n)printf("ID not found\n");
                break;
            case 6:
                printf("\nID to delete:");
                scanf("%ld",&id);
                getchar();
                for(i=0;i<n;i++){
                    if(id==pat_id[i]){
                        printf("Data to be deleted:\n");
                        displayer(i);
                        printf("Press y to confirm command or any other key to cancel.\n");
                        scanf("%c",&c);
                        if(c=='y' || c=='Y')deleter(i);
                        break;
                    }
                }
                if(i==n)printf("ID not found\n");
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid command\n");
        }
        getch();
        printf("\n\n");
    }
}

void updater(int i)
{
    long int ID,j;
L:  printf("\nEnter new ID :");
    scanf("%ld",&ID);
    for(j=0;j<n;j++){
        if(j==i)continue;
        else if(ID==pat_id[j]){
            printf("ID needs to be unique.\n");
            goto L;
        }
    }
    pat_id[i]=ID;
    getchar();
    printf("Enter Name :");
    scanf("%[^\n]",pat_name[i]);
    getchar();
    printf("Enter Disease :");
    scanf("%[^\n]",disease[i]);
    printf("Enter Room No. :");
    scanf("%d",&room_no[i]);
}

void displayer(int i)
{
    printf("\nID : %ld\nName : %s\nDisease : %s\nRoom No. : %d\n\n",pat_id[i],pat_name[i],disease[i],room_no[i]);
}

void deleter(int i)
{
    int j;
    for(j=i;j<n-1;j++){
        pat_id[i]=pat_id[i+1];
        strcpy(pat_name[i],pat_name[i+1]);
        strcpy(disease[i],disease[i+1]);
        room_no[i]=room_no[i+1];
    }
    n--;
}
