 // vim:foldmethod=marker

 // {{{ #include

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

 // }}}
 // {{{ main

int main(int argc, char* argv[])
{
   // {{{ init

  srand(time(NULL));
  char* chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1!2@3#4$5%%6^7&8*9(0)";
  int len = 0;
  int nolen;
  char* arg;
  int v;
  int nv;
  int ent;
  int passes = 1;
  int silent = 0;
  argc--;

   // }}}
   // {{{ read the arguments

  for (int i = 1; i <= argc; i++)
  {
    arg = argv[i];
    v = i + 1;
    i++;

    int carg;

    if      ((strcmp(arg, "-l") == 0) || (strcmp(arg, "--length"))  == 0) carg = 1;
    else if ((strcmp(arg, "-c") == 0) || (strcmp(arg, "--charset")) == 0) carg = 2;
    else if ((strcmp(arg, "-e") == 0) || (strcmp(arg, "--entropy")) == 0) carg = 3;
    else if ((strcmp(arg, "-r") == 0) || (strcmp(arg, "--repeat"))  == 0) carg = 4;
    else if ((strcmp(arg, "-s") == 0) || (strcmp(arg, "--silent"))  == 0) carg = 5;

        switch (carg)
    {
      case 1:
        if (argv[v] != NULL) len = atoi(argv[v]);
        else len = 0;
        //printf("\nlen : %d\n\n", len);
      break;

      case 2:
        if (argv[v] != NULL)
        {
          if (strlen(argv[v]) > 1)
          {
            chars = argv[v];
            }
          else
          {
            switch (atoi(argv[v]))
            {
              case 1:
                chars = "abcdefghijklmnopqrstuvwxyz";
              break;

              case 2:
                chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
              break;

              case 3:
                chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
              break;

              case 4:
                chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
              break;

              case 5:
                chars = "1234567890";
              break;

              case 6:
                chars = "1234567890!@#$%^&*()";
              break;
            }
          }
        }
        else len = 0;
      break;

      case 3:
        ent = 1;
      break;

      case 4:
        if (argv[v] != NULL) passes = atoi(argv[v]);
      break;

      case 5:
        silent = 1;
      break;
    }
  }

   // }}}
   // {{{ do the stuff

  while (1)
  {
    if (len > 0)
    {
      while (passes--)
      {
        for (int i = 0; i < len; i++)
        {
          putchar(chars[rand() % strlen(chars)]);
        }
        putchar('\n');
        
        if (ent == 1)
        {
          printf("%f\n", log2(pow(strlen(chars), len)));
        }
      }

      return 0;
    }
    else
    {
      break;
    }
  }
   // │├└─
  char* help[18] =
  {
    "Usage: strgen [OPTION]...",
    "Possible options:",
    "├── -l, --length  │ Define the length of the string",
    "│   └── [INTEGER] │ Amount of characters to generate",
    "├── -c, --charset │ The characters available to the generator",
    "│   ├── [STRING]  │ Any character",
    "│   └── [1-6]     │ Uses a corresponding preset:",
    "│                 │ 1:a-z, 2:a-Z, 3:a-Z 1-0, 4:a-Z 1-), 5:1-0, 6:1-)",
    "├── -e, --entropy │ Display the entropy of the resulting string",
    "└── -r, --repeat  │ Generate in bulk, separated by \\n",
    "    └── [INTEGER] │ How many passes for the generator to do",
    "",
    "Example:",
    "    strgen -l 32                              │ Generate a 32 character string using the default charset",
    "    strgen -l 4 -c 5                          │ Generate a random PIN",
    "    strgen -l 24 -c 4 -e                      │ Generate a secure password applicable to most web sites",
    "    strgen -l 1 -c 1234567890                 │ Generate a random number 0-9",
    "    echo (strgen -l 32 -r 10) > passwords.txt │ Generate a list of 10 passwords and write them to a file",
  };
  for (int i = 0; i < 18; i++)
  {
    printf("%s\n", help[i]);
  }
  return 1;

   // }}}
}

 // }}}
