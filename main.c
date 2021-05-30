/*
** EPITECH PROJECT, 2021
** sc0mmit_b0t
** File description:
** sc0mmit_b0t
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics.h>

char *my_put_nbr_to_char(int n);

int write_file(char  const *filepath, char *str)
{
    FILE *fp = fopen (filepath,"w");
    fwrite(str,1,sizeof(str), fp);
    fclose(fp);
}


int add_int(int x, char  const *file)
{
    struct stat size;
    stat(file, &size);
    int fd = open(file, O_RDONLY);
    char *buffer = malloc(sizeof(char) *(size.st_size + 1));
    read(fd, buffer, size.st_size);
    buffer[size.st_size] = '\0';
    int res = my_getnbr(buffer) - x;
    write_file(file, my_put_nbr_to_char(res));
    return (res);
}

char    *my_revstr(char *str)
{
    int  i;
    int  j;
    char c;

    i = 0;
    j = my_strlen(str) - 1;
    while (i < j)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}

int my_getnbr(const char *str)
{
    int i;
    int nbr;

    i = 0;
    nbr = 0;
    while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
        i = i + 1;
    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') {
        nbr = ((nbr * 10) + (str[i] - '0'));
        i = i + 1;
    }
    if (str[0] == '-')
        nbr *= -1;
    return (nbr);
}

char *my_put_nbr_to_char(int n)
{
    char *nbr = malloc(sizeof(char) * 100000000 + 1);
    int i = 0;
    int reste = 0;

    while (n != 0)
    {
        reste = n % 10;
        if (reste < 10) {
            nbr[i] = reste + 48;
            i++;
        }
        else {
            nbr[i] = reste + 87;
            i++;
        }
        n = n / 10;
    }
    nbr[i] = '\0';
    return (my_revstr(nbr));
}

int my_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

void little_commit()
{
    int i = 0;
    for (i = 0; i < 1; i++) {
        write_file("test", my_put_nbr_to_char(i));
        system("git add test");
        system("git commit -m c0mmit_b0t_3000");
        system("git push");
    }
    system("clear");
    dprintf(2, "Your Number of Commit(If it's taking time just wait it's loading): ");
    system("git log --pretty=format:'' | wc -l");
    exit(0);
}

int main(int argc, char **argv)
{
    system("clear");
    int i;
    char *t1;
    char *t2;
    char *t3;
    char str[100];
    size_t size = 32;
    t1 = NULL;
    t2 = NULL;
    t3 = NULL;
    dprintf(2, "Your Number of commit(If it's taking time just wait it's loading):  ");
    system("git log --pretty=format:'' | wc -l");
    printf("\e[0;33m[Write your number of commit: ] \e[0m");
    getline(&t1, &size, stdin);
    printf("\e[0;33m[Write the number of commit you want: ] \e[0m");
    getline(&t2, &size, stdin);
    if (atoi(t1) >= atoi(t2)) {
        main(argc, argv);
    }
    printf("\e[0;33m[Ecrit ton commit: ] \e[0m");
    getline(&t3, &size, stdin);
    strcpy(str, "git commit --allow-empty -m ");
    strcat(str, t3);
    for(i = atoi(t1); i < atoi(t2); i++) {
        system(str);
    }
    if (i == atoi(t2)) {
        little_commit();
    }
}
