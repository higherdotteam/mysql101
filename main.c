#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

char **name_completion(const char *, int, int);
char *name_generator(const char *, int);

char *names[] = {
  "companies",
  "people",
  "hackernews",
  NULL
};

int startsWith(const char *str, const char *pre) {
  size_t lenpre = strlen(pre),
         lenstr = strlen(str);
  return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

int main(int argc, char** argv) {
  rl_attempted_completion_function = name_completion;

	puts("\nmysql101 by higher.team\n");
	puts("http://higher.team is the new MBA\n");
	puts("  READ THIS FIRST:\n");
	puts("  Hello future higher.team MBA student, welcome to mysql101.");
	puts("  This is a fake version of the popular database program mysql.");
	puts("  It is designed to help you learn how to type commands to mysql.");
	puts("  Let's get started. Type anything and hit enter.\n");

  int step = 1;

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
		} else if (startsWith(input, "show tables") == 1) {
			puts("+-------------------+");
			puts("| Tables_in_this_db |");
			puts("+-------------------+");
			puts("| companies         |");
			puts("| people            |");
			puts("| hackernews        |");
			puts("+-------------------+");
			puts("3 rows in set (0.00 sec)\n");
			puts("  HINT: type desc companies;\n");
		} else if (startsWith(input, "desc ") == 1 || startsWith(input, "describe ") == 1) {
			puts("+-------------+--------------+------+-----+---------+----------------+");
			puts("| Field       | Type         | Null | Key | Default | Extra          |");
			puts("+-------------+--------------+------+-----+---------+----------------+");
			puts("| id          | int(11)      | NO   | PRI | NULL    | auto_increment |");
      puts("| name        | varchar(255) | YES  |     | NULL    |                |");
      puts("+-------------+--------------+------+-----+---------+----------------+");
			puts("2 rows in set (0.00 sec)\n");
			puts("  HINT: type select * from companies;\n");
		} else if (startsWith(input, "select ") == 1) {
			puts("+-------------+--------------+");
			puts("| id          | name         |");
			puts("+-------------+--------------+");
			puts("| 1           | Twitter      |");
      puts("| 2           | github       |");
      puts("+-------------+--------------+");
			puts("2 rows in set (0.00 sec)\n");
			puts("  HINT: type select * from companies;\n");
		} else {
			puts("\nI don't understand.\n");
		}

    free(input);

    if (step == 1) {
			puts("Try it again, type something else.\n");
    } else if (step == 2) {
			puts("Great, now we are having a conversation.\n");
    }

    step++;

  }

  return 0;
}

char **name_completion(const char *text, int start, int end) {
  rl_attempted_completion_over = 1;
  return rl_completion_matches(text, name_generator);
}

char *name_generator(const char *text, int state) {
	static int list_index, len;
  char *name;

  if (!state) {
    list_index = 0;
    len = strlen(text);
  }

	while ((name = names[list_index++])) {
		if (strncmp(name, text, len) == 0) {
			return strdup(name);
		}
	}

  return NULL;
}
