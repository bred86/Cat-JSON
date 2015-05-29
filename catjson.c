#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct json
{
  int level;
  int int_value;
  bool bool_value;
  char * str_value;

  struct st_json * next_element;
  struct st_json * next_level;

} st_json;

typedef struct head
{
  int levels;

  st_json * start;
  st_json * runner;

} st_head;

st_head * create_structure ()
{
  st_json * structure = (st_json*) malloc(sizeof(st_json));
  if (structure == NULL)
  {
    printf("[255] Something gone bad creating the JSON structure");
    exit(255);
  }

  st_head * runner = (st_head*) malloc(sizeof(st_head));
  if (runner == NULL)
  {
    printf("[256] Something gone bad creating the JSON structure");
    exit(256);
  }
  else
  {
    runner->start = structure;
    runner->runner = structure;
    runner->levels = 1;
  }

  return runner;
}
