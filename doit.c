#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include<assert.h>
enum StandardNames { STDNAMES_WRITE };
enum StandardNamesCount
{
STDNAMES_WRITE_CT = 06,
STDNAMES_LOCALE_CT = 07
};
struct stdnames
{
char
t_write [STDNAMES_WRITE_CT],
t_locale [STDNAMES_LOCALE_CT]
; }
const sc_stdnames = { "write", "locale"
};
int main (
int argc, char const *const 
argv[]
)
{
  assert (strlen (sc_stdnames .t_write)
    == STDNAMES_WRITE_CT - 01)
    ;
  assert
    (strlen (sc_stdnames .t_locale)
    == STDNAMES_LOCALE_CT - 01);
  if
    (setlocale
    (LC_ALL,
    sc_stdnames .t_locale
    + STDNAMES_LOCALE_CT - 01))
  {
    register char const
    *const my_message_locale
    = setlocale (LC_MESSAGES, NULL);
    if (my_message_locale)
    { GET_MESSAGE_LOCALE_SUCCEEDED:
      if (printf ("@%s\n", my_message_locale) < 01)
      {
        PRINT_LOCALE_FAILED:
        perror (sc_stdnames .t_write); }
      else { PRINT_LOCALE_SUCCEEDED: ; }}
    else
    {
      GET_MESSAGE_LOCALE_FAILED:
      perror (sc_stdnames .t_locale); }}
  if (printf ("Arguments: %'d\n", argc) < 01)
{ perror (sc_stdnames .t_write)
  ; } else {
  register int i = 0;
  for (; i < argc; ++ i)
    if (printf ("%'d: %s\n", i, argv [i]) < 02)
    { perror (sc_stdnames .t_write); break; }
  if (i == argc &&
    putchar
    ('\n') != '\n'
    )
      perror (sc_stdnames .t_write);
}
  return EXIT_FAILURE; }
