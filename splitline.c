#include "shell.h"


char **split_line(char *line, char *delimiter)
{
    size_t buffer_size = 64;
    char **alltokens = NULL, *token = NULL;
    int i = 0;

    printf("%s  %s", line, delimiter);
    alltokens = malloc(sizeof(char *) * buffer_size);
    if (alltokens == NULL)
    {
        perror("Error");
        return (NULL);
    }
    token = strtok(line, delimiter);
    for (i = 0; token; i++)
    {
        alltokens[i] = token;
        token = strtok(NULL, delimiter);
    }
    alltokens[i] = NULL;
    printf(" [%s] [%s]\n", alltokens[0], alltokens[1]);

    return (alltokens);
}

int main (void)
{
        char **ptr = NULL, *ptr1 = NULL;
        char *buffer = "lslsl  ljj;j ljljl  lll";

        ptr1 = strdup(buffer);
        ptr = split_line(ptr1, " ");
        printf("main --> [%s] [%s]\n", ptr[0], ptr[1]);
        //split_line(lslsl", " ");
        //split_line("lslsl", " ");
        //plit_line("lslsl", " ");
        free(ptr[0]);
         
        return (0); 
}
