#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

int main(int argc, char** argv) {

	puts("\nmysql101 by higher.team\n");
	puts("http://higher.team is the new MBA\n");
	puts("  HINT: type show tables;\n");

  while (1) {

    char* input = readline("mysql> ");
    add_history(input);

    if (strcmp("quit\n",input) != 0) {
      return 0;
    }

    printf("\nYou said %s\n", input);
    free(input);

  }

  return 0;
}
