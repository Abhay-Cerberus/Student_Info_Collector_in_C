#include<stdio.h>
#include<conio.h>
int entry();
int stunam(int n, int dowht);
int studid(int n, int dowht);
int stucour(int n, int dowht);
int stupn(int n, int dowht);
int fchk(char fname[25]);
int sear(int nos);
int nstu();
struct student{
    char name[50];
    int id;
    char course[20];
    int phno;
};
struct student st[100];
int main()
{
    int ns,chk=0,dowht,sn;
    printf("\t!! WELCOME TO STUDENT FILES APP !!\n");
    printf("If you want to have check Student Information then Enter '1'\n");
    printf("\t\t\tOR\nIf you Want to add some Details Enter any Number Except '1'\n");
    scanf("%d",&dowht);     //variable for checking what the user want to do
    ns=entry();     //For taking the Number of Students in 'ns'
    if(dowht != 1)
    {
        if(ns<0 || ns==0)
        {
            printf("You Have entered 0 as the Number of students \n\t\t\tOR \nTheData stored in some files have been Deleted/Altered\n");
        }
        else
        {
            stunam(ns,dowht);
            studid(ns,dowht);
            stucour(ns,dowht);
            stupn(ns,dowht);
        }
    }
    else
    {
        sear(ns);
        while(dowht == 1)
        {
            printf("\nEnter the Number of Student from ( 0 to %d ) :",ns-1);
            scanf("%d",sn);
            printf("\nNAME OF THE STUDENT : %s",st[sn].name);
            printf("\nID OF THE STUDENT : %d",st[sn].id);
            printf("\nCOURSE OF THE STUDENT : %s",st[sn].course);
            printf("\nPHONE NO. OF THE STUDENT : %d",st[sn].phno);
            printf("\nIf you want to continue to check the information then enter '1' :");
            scanf("%d",dowht);
        }
    }
    getch();
    return 0;
}
//function to take the number of students
int nstu()
{
    int nos;
    printf("Enter how many Students are there (maximum 100) : ");
    scanf("%d",&nos);
    return nos;
}
//function to check if the log file was made or not
int entry()
{
    int n;
    FILE *fptr;     //file pointer
    fptr=fopen("log.txt","r"); //opening log.txt FILE
    if( fptr == NULL )
    {
        printf("\nThe log.txt file is not present so we are creating one\n");
        fclose(fptr);
        fptr=fopen("log.txt","w");  //making a new file if deleted or if unsing for the first time
        n=nstu();   //Calling the function for taking the number of Students
        fprintf(fptr ,"%d", n);
    }
    else
    {
        fscanf(fptr ,"%d", &n);     //printing the value present in the file
    }
    fclose(fptr);   //closing the log.txt file either the read one or the write one
    
    return n;
}
//function to take the name of students
int stunam(int n, int dowht)
{
    fchk("stdnam.txt");
    FILE *namfptr;
    namfptr=fopen("stdnam.txt","w");
    printf("\n\t!! NAME ENTERING PHASE !!\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the Name of Student Number %d : ",i);
        scanf("%s",&st[i].name);
        fprintf(namfptr, "%s\n" ,st[i].name);
    }
    fclose(namfptr);
}
//function to take the Id of Students
int studid(int n, int dowht)
{
    fchk("stdid.txt");
    FILE *idfptr;
    idfptr=fopen("stdid.txt","w");
    printf("\n\t!! STUDENT ID ENTERING PHASE !!\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the ID of Student Number %d : ",i);
        scanf("%d",&st[i].id);
        fprintf(idfptr, "%d\n" ,st[i].id);
    }
    fclose(idfptr);
}
//function to take the COURSE of Students
int stucour(int n, int dowht)
{
    fchk("stucour.txt");
    FILE *cufptr;
    cufptr=fopen("stucour.txt","w");
    printf("\n\t!! STUDENT COURSE ENTERING PHASE !!\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the COURSE of Student Number %d : ",i);
        scanf("%s",&st[i].course);
        fprintf(cufptr, "%s\n" ,st[i].course);
    }
    fclose(cufptr);
}
//function to take the PHONE NUMBERS of Students
int stupn(int n, int dowht)
{
    fchk("stupn.txt");
    FILE *pnfptr;
    pnfptr=fopen("stupn.txt","w");
    printf("\n\t!! STUDENT PHONE NO. ENTERING PHASE !!\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the PHONE NO. of Student Number %d : ",i);
        scanf("%d",&st[i].phno);
        fprintf(pnfptr, "%d\n" ,st[i].phno);
    }
    fclose(pnfptr);
}
//Function to check if the file exists or not if not then create one
int fchk(char fname[25])
{
    FILE *cfptr;
    cfptr=fopen(fname,"r");
    if(cfptr == NULL)
    {
        printf("The %s file is not present so we are creating one",fname);
        fclose(cfptr);
        cfptr=fopen(fname,"w");
    }
    fclose(cfptr);
}
int sear(int nos)
{
    fchk("stdnam.txt");
    fchk("stdid.txt");
    fchk("stucour.txt");
    fchk("stupn.txt");
    FILE *namfptr, *idfptr, *cufptr, *pnfptr;
    namfptr=fopen("stdnam.txt","r");
    idfptr=fopen("stdid.txt","r");
    cufptr=fopen("stucour.txt","r");
    pnfptr=fopen("stupn.txt","r");
    for(int i=0;i<nos;i++)
    {
        fscanf(namfptr,"%s",st[i].name);
        fscanf(idfptr,"%d",st[i].id);
        fscanf(cufptr,"%s",st[i].course);
        fscanf(pnfptr,"%d",st[i].phno);
    }
    fclose(namfptr);
    fclose(idfptr);
    fclose(cufptr);
    fclose(pnfptr);
    return 0;
}