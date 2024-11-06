/* main.c
 *
 * Copyright (c) 2024 Robert Buj <rbuj#uoc.edu>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */
#include <stdio.h>

#ifndef N
#include <ctype.h> /* isprint */
#include <unistd.h> /* getopt */
#include <stdlib.h> /* atoi */
#include <errno.h> 

int main(int argc, char *argv[])
{
  int opt;
  long n = -1;

  while((opt = getopt(argc, argv, "n:")) != -1)
  {
    switch(opt)
    {
      case 'n':
      {
        char *endptr;
        errno = 0;
        n = strtol(optarg, &endptr, 10);  
        if (errno == ERANGE || (endptr == optarg))
        { 
          fprintf (stderr, "Not a valid number: %s\n", optarg);
          goto ERROR;
        }
        if (n<=0)
        {
          fprintf (stderr, "The number should be greather than 0.\n");
          goto ERROR;
        }
        break;
      }
      case '?':
        if (optopt == 'n')
          goto ERROR;
        if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        goto ERROR;
      default:
        fprintf (stderr, "Usage: %s -n NUM\n", argv[0]);
        goto ERROR;
    }
  }
  if (n==-1)
  {
    fprintf (stderr, "Usage: %s -n NUM\n", argv[0]);
    goto ERROR;
  }
#else
int main(int argc, char *argv[])
{
  long n=N;

  if (argc != 1)
  {
    fprintf (stderr, "Usage: %s\n", argv[0]);
    goto ERROR;
  }
#endif

  for (long i=0;i<n;i++)
    printf("%ld\n",i);
  return 0;
ERROR:
  return 1;
}
