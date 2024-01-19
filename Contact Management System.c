#include <stdio.h>
#include <string.h>
int n;
int flag=0;
void add();
void edit();
void delete();
void display();
struct info{
    long long int num;
    char name[15];
};struct info person[15];
int main()
{
    int op,i;
    int*p;
    FILE*f;
    f=fopen("E:\\program.txt","a+");
    if(flag==0){
    	fscanf(f,"%d",&n);
        p=&n;
    if(p!=NULL){
        for(i=0;i<n;i++){
        fscanf(f,"%d\n",&n);
        fscanf(f,"%[^\n]%*c",person[i].name);
        fscanf(f,"%lld",&person[i].num);
        }
        flag=1;
    }
    else{
        n=0;
        flag=1;
	}}
    printf("1.Add\n2.Edit\n3.Delete\n4.Display\n5.Exit\nEnter option:");
    scanf("%d",&op);
	switch(op)
	{
		case 1:
			add(f);
		    break;
		case 2:
			edit(f);
		    break;
		case 3:
			delete(f);
		    break;
		case 4:
		    display(f);
		    break;
		case 5:
		f=fopen("E:\\program.txt","w+");
		if(n==0){
			fprintf(f,"%d",NULL);
		}
		else
		for(i=0;i<n;i++)
		fprintf(f,"%d\n%s\n%lld\n",n,person[i].name,person[i].num);
	}
}
void add(FILE* f){
    printf("Enter Name of the person:");
    scanf("\n");
    scanf("%[^\n]%*c",person[n].name);
    printf("Enter his/her Phone Number:");
    scanf("%lld",&person[n].num);
    n=n+1;
	f=fopen("E:\\program.txt","w+");
    fprintf(f,"%d",n);
    main();
}
void edit(FILE* f){
    int i,ele;
    if(n==0){
    printf("\nNO DATA FOUND.\n\n");
    main();
	}
	else{
    printf("Select Person you want to edit:\n");
    for(i=0;i<n;i++)
    printf("%d.%s\n",i+1,person[i].name);
    printf("Number:");
    scanf("%d",&ele);
    ele=ele-1;
    printf("Enter New Name:");
    scanf("\n");
    scanf("%[^\n]%*c",person[ele].name);
    printf("Enter New Number:");
    scanf("%lld",&person[ele].num);
    main();
	}
}
void delete(FILE* f){
	int i,ele;
	if(n==0){
    printf("\nNO DATA FOUND.\n\n");
    main();
	}
	else{
    printf("Select Person you want to delete:\n");
    for(i=0;i<n;i++)
    printf("%d.%s\n",i+1,person[i].name);
    printf("Number:");
    scanf("%d",&ele);
    ele=ele-1;
    for(i=ele;i<n-1;i++){
    	strcpy(person[i].name,person[i+1].name);
    	person[i].num=person[i+1].num;
	}
	n=n-1;
	main();
	}
}
void display(FILE* f){
    int i;
    if(n==0){
    printf("\nNO DATA FOUND.\n\n");
    main();
	}
	else{
    for(i=0;i<n;i++)
        printf("\nName:%s\nPhone Number:%lld\n",person[i].name,person[i].num);
    main();
	}
}
