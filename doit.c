#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include<assert.h>
enum StandardNames { STDNAMES_WRITE };
enum StandardNamesCount
{ STDNAMES_WRITE_CT = 06
};
struct stdnames
{ char t_write [STDNAMES_WRITE_CT]; }
const sc_stdnames = { "write" };
int main (
int argc, char const *const 
argv[]
)
{
  assert (strlen (sc_stdnames .t_write)
    == STDNAMES_WRITE_CT - 01)
    ;
  if (printf ("Arguments: %'d\n", argc) < 01)
{ perror (sc_stdnames .t_write)
  ; } else {
  register int i = 0;
  for (; i < argc; ++ i)
    if (printf ("%'d: %s\n", i, argv [i]) < 02)
    { perror (sc_stdnames .t_write); break; }
  if (i == argc &&
    putchar
    ('\n'))
      perror (sc_stdnames .t_write);
}
  return EXIT_FAILURE; }
