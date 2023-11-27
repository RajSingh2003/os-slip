#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_toks(char *s, char *tok[])
{
    int i = 0;
    char *p;

    p = strtok(s, " ");
    while (p != NULL)
    {
        tok[i++] = p;
        p = strtok(NULL, " ");
    }

    tok[i] = NULL;
}

void typeline(char *fn, char *op)
{
    int fh, i, j, n;
    char c;

    fh = open(fn, O_RDONLY);
    if (fh == -1)
    {
        printf("File %s not found.\n", fn);
        return;
    }

    if (strcmp(op, "a") == 0)
    {
        while (read(fh, &c, 1) > 0)
            printf("%c", c);
        close(fh);
        return;
    }

    n = atoi(op);
    if (n > 0)
    {
        i = 0;
        while (read(fh, &c, 1) > 0)
        {
            printf("%c", c);
            if (c == '\n')
                i++;
            if (i == n)
                break;
        }
    }

    if (n < 0)
    {
        i = 0;
        while (read(fh, &c, 1) > 0)
        {
            if (c == '\n')
                i++;
        }
        lseek(fh, 0, SEEK_SET);
        j = 0;
        while (read(fh, &c, 1) > 0)
        {
            if (c == '\n')
                j++;
            if (j == i + n)
                break;
        }
        while (read(fh, &c, 1) > 0)
        {
            printf("%c", c);
        }
    }

    close(fh);
}

int main()
{
    char buff[80], *args[10];
    int pid;

    while (1)
    {
        printf("myshell$ ");
        fflush(stdin);
        fgets(buff, 80, stdin);
        buff[strlen(buff) - 1] = '\0';
        make_toks(buff, args);
        if (strcmp(args[0], "typeline") == 0)
            typeline(args[2], args[1]);
        else
        {
            pid = fork();
            if (pid > 0)
                wait(NULL);
            else
            {
                if (execvp(args[0], args) == -1)
                    printf("Bad command.\n");
            }
        }
    }

    return 0;
}

//search


void search(char *fn, char op, char *pattern) {
    int fh, count = 0, i = 0, j = 0;
    char buff[255], c, *p;

    fh = open(fn, O_RDONLY);
    if (fh == -1) {
        printf("File %s Not Found\n", fn);
        return;
    }

    switch (op) {
        case 'f':
            while (read(fh, &c, 1)) {
                buff[j++] = c;
                if (c == '\n') {
                    buff[j] = '\0';
                    j = 0;
                    i++;
                    if (strstr(buff, pattern)) {
                        printf("%d: %s", i, buff);
                        break;
                    }
                }
            }
            break;
        case 'c':
            while (read(fh, &c, 1)) {
                buff[j++] = c;
                if (c == '\n') {
                    buff[j] = '\0';
                    j = 0;
                    p = buff;
                    while (p = strstr(p, pattern)) {
                        count++;
                        p++;
                    }
                }
            }
            printf("Total No.of Occurrences = %d\n", count);
            break;
        case 'a':
            while (read(fh, &c, 1)) {
                buff[j++] = c;
                if (c == '\n') {
                    buff[j] = '\0';
                    j = 0;
                    i++;
                    if (strstr(buff, pattern))
                        printf("%d: %s", i, buff);
                }
            }
            break;
    }

    close(fh);
}

