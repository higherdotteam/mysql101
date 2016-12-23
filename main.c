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
    int size = strlen(input);
    char last = input[size-1];

    if (strcmp(input, "quit") == 0) {
      puts("Bye");
      return 0;
    }
    if (last != ';') {
      puts("\nYou forgot the ;\n");
		} else if (strcmp(input, "show tables;") == 0) {
			puts("+-------------------+");
			puts("| Tables_in_this_db |");
			puts("+-------------------+");
			puts("| companies         |");
			puts("| people            |");
			puts("| hackernews        |");
			puts("+-------------------+");
			puts("3 rows in set (0.00 sec)\n");
			puts("  HINT: type desc companies;\n");
		} else if (strcmp(input, "desc companies;") == 0) {
			puts("+-------------+--------------+------+-----+---------+----------------+");
			puts("| Field       | Type         | Null | Key | Default | Extra          |");
			puts("+-------------+--------------+------+-----+---------+----------------+");
			puts("| id          | int(11)      | NO   | PRI | NULL    | auto_increment |");
			puts("3 rows in set (0.00 sec)\n");
			puts("  HINT: type desc companies;\n");
		} else {
			puts("\nI don't understand.\n");
		}

    free(input);

  }

  return 0;
}
