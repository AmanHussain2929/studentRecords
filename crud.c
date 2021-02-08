#include<stdio.h>
#include<string.h>
struct Student
{
int rollNumber;
char name[21];
};
void addStudent()
{
char name[22];
int rollNumber;
struct Student g;
char m;
FILE *f;
printf("Student (Add Module)\n");
printf("Enter roll number : ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0) {
printf("Invalid roll number\n");
return; }
f=fopen("students.dat","rb");
if(f!=NULL) {
while(1) {
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber) {
printf("That roll number alloted to %s\n",g.name);
fclose(f);
return; }}
fclose(f); }
printf("Enter name : ");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Save (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y') {
printf("Student not added\n");
return; }
g.rollNumber=rollNumber;
strcpy(g.name,name);
f=fopen("students.dat","ab");
fwrite(&g,sizeof(struct Student),1,f);
fclose(f);
printf("Student added, press enter to continue......");
m=getchar();
fflush(stdin); }
void editStudent() {
int found;
struct Student g,j;
char m;
int rollNumber;
char name[22];
FILE *f,*t;
printf("Student (Edit Module)\n");
printf("Enter roll number of the student to edit : ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0) {
printf("Invalid roll number\n");
return; }
f=fopen("students.dat","rb");
if(f==NULL) {
printf("Invalid roll number\n");
return; }
found=0;
while(1) {
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber) {
found=1;
break; }}
fclose(f);
if(found==0) {
printf("Invalid roll number\n");
return; }
printf("Name %s\n",g.name);
printf("Edit (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y') {
printf("Student not edited\n");
return; }
printf("Enter new name : ");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Update (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y') {
printf("Student not updated\n");
return; }
strcpy(g.name,name);
f=fopen("students.dat","rb");
t=fopen("fhaltu.ddd","wb");
while(1) {
fread(&j,sizeof(struct Student),1,f);
if(feof(f)) break;
if(g.rollNumber!=j.rollNumber) {
fwrite(&j,sizeof(struct Student),1,t); }
else {
fwrite(&g,sizeof(struct Student),1,t); }}
fclose(f);
fclose(t);
f=fopen("students.dat","wb");
t=fopen("fhaltu.ddd","rb");
while(1) {
fread(&j,sizeof(struct Student),1,t);
if(feof(t)) break;
fwrite(&j,sizeof(struct Student),1,f); }
fclose(f);
fclose(t);
t=fopen("fhaltu.ddd","wb");
fclose(t);
printf("Student updated\n"); }
void deleteStudent() {
int found;
struct Student g,j;
char m;
int rollNumber;
FILE *f,*t;
printf("Student (Delete Module)\n");
printf("Enter roll number of the student to delete : ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0) {
printf("Invalid roll number\n");
return; }
f=fopen("students.dat","rb");
if(f==NULL) {
printf("Invalid roll number\n");
return; }
found=0;
while(1) {
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber) {
found=1;
break; }}
fclose(f);
if(found==0) {
printf("Invalid roll number\n");
return; }
printf("Name %s\n",g.name);
printf("Delete (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
 {
printf("Student not deleted\n");
return; }
f=fopen("students.dat","rb");
t=fopen("fhaltu.ddd","wb");
while(1) {
fread(&j,sizeof(struct Student),1,f);
if(feof(f)) break;
if(g.rollNumber!=j.rollNumber) {
fwrite(&j,sizeof(struct Student),1,t); }}
fclose(f);
fclose(t);
f=fopen("students.dat","wb");
t=fopen("fhaltu.ddd","rb");
while(1) {
fread(&j,sizeof(struct Student),1,t);
if(feof(t)) break;
fwrite(&j,sizeof(struct Student),1,f); }
fclose(f);
fclose(t);
t=fopen("fhaltu.ddd","wb");
fclose(t);
printf("Student deleted\n"); }
void searchStudent() {
int found;
struct Student g;
char m;
int rollNumber;
FILE *f;
printf("Student (Search Module)\n");
printf("Enter roll number of the student to search : ");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0) {
printf("Invalid roll number\n");
return; }
f=fopen("students.dat","rb");
if(f==NULL) {
printf("Invalid roll number\n");
return; }
found=0;
while(1) {
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber) {
found=1;
break; }}
fclose(f);
if(found==0) {
printf("Invalid roll number\n");
return; }
printf("Name %s\n",g.name);
printf("Press enter to continue......");
m=getchar();
fflush(stdin); }
void displayListOfStudents() {
int x;
FILE *k;
char m;
struct Student u;
k=fopen("students.dat","rb");
printf("Student (List Module)\n");
if(k==NULL) {
printf("No students added\n");
return; }
x=0;
while(1) {
fread(&u,sizeof(struct Student),1,k);
if(feof(k)) break;
x++;
printf("%d.) Roll number %d, Name %s\n",x,u.rollNumber,u.name); }
fclose(k);
if(x==0) {
printf("No students added, press enter to continue......"); }
else {
printf("Press enter to continue......."); }
m=getchar();
fflush(stdin); }
int main() {
int ch;
while(1) {
printf("1. Add\n");
printf("2. Edit\n");
printf("3. Delete\n");
printf("4. Search\n");
printf("5. List\n");
printf("6. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addStudent();
if(ch==2) editStudent();
if(ch==3) deleteStudent();
if(ch==4) searchStudent();
if(ch==5) displayListOfStudents();
if(ch==6) break; }
return 0;
}