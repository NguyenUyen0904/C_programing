#include<stdio.h>
#include<stdlib.h>
#include"structbst.h"

int main(void) {
  FILE* f;
  nodetype* tree = NULL;
  char s[100];
  if( (f= fopen("student.txt", "r")) == NULL ) {
    puts("Could not open file");
  }
  else {
     while( (fscanf(f, " %[^\n]", s)) != EOF ) {
      elmtype data = nameToData(s);
      tree = insertNode(tree, data);
    }
    int choice;
    do {
      printf("1.display students\n2.Search student\n3.Delete student\n4.Exit\nYour choice ? ");
      scanf("%d", &choice);
      if( choice == 1 ) {
	display(tree);
      }
      else if( choice == 2 ) {
	char last[20];
	printf("Enter last name: ");
	scanf("%s", last);
	nodetype* result = search(tree, last);
	if( result == NULL ) puts("Could not found");
	else printf("Result: %s %s %s\n", result->element.firstName, result->element.middleName, result->element.lastName);
      }
      else if( choice == 3 ) {
	char s[100];
	printf("Enter name: ");
	scanf(" %[^\n]", s);
	elmtype data = nameToData(s);
	deleteNode(tree, data);
	puts("Done");
      }
      else if( choice == 4 ) puts("Exit");
      else puts("Invalid choice");
    } while( choice != 4 );
  }
  freetree(tree);
  fclose(f);
}
