#include <stdio.h>
#include "catjson.h"

int main (int argc, char ** argv)
{
  st_head * test = create_structure();

  printf("%d\n", test->levels);

  return 0;
}
