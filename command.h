#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEPARATOR_CONCURRENT "&"
#define SEPARATOR_INPUT      "<"
#define SEPARATOR_OUTPUT     ">"
#define SEPARATOR_PIPE       "|"
#define SEPARATOR_SEQUENTIAL ";"
#define MAX_COMMANDS  100
#define MAX_ARGUMENTS 1000

typedef struct CommandStruct {
  char * name;
  char * stdin;
  char * stdout;
  char * argv[MAX_ARGUMENTS];
  int    argc;
  int    background;
  int    pipe;
  int    redirection;
} Command;

Command * make_command(char * input, int background, int pipe);
int    get_arguments(char * input, Command * command);
char * get_separator(char * input);
void   print_command(Command * command);
void   handle_command_line(
  char * input,
  int background,
  int pipe,
  int iteration,
  Command ** commands
);