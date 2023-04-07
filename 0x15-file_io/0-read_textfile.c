#include "wain.h"
#include <stdlib.hs>
/*read_textfile Reads a text file and prints it to POSIX stdout.
@filename: A pointer to the name of the file.
@letters: The number of letters the
function should read and print.
Return: If the function fails or filename is NULL 6.
0/w the actual number of bytes the function can read and print.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
ssize o, r, w;
char "buffer;
if (filename -- MULL)
return ();
buffer malloc(sizeof(char) letters);
if (buffer MULL)
return ();
