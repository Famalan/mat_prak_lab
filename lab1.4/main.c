#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void d_function(FILE *input_file, FILE *output_file)
{
    char character = fgetc(input_file);
    while (character != EOF)
    {
        if (character < '0' || character > '9')
            fputc(character, output_file);
        character = fgetc(input_file);
    }
    return;
}

void i_function(FILE *input_file, FILE *output_file)
{
    char character = fgetc(input_file);
    int letter_count = 0;
    while (character != EOF)
    {
        while (character != EOF && character != '\n')
        {
            if (character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z')
                letter_count++;
            character = fgetc(input_file);
        }
        fprintf(output_file, "%d\n", letter_count);
        letter_count = 0;
        character = fgetc(input_file);
    }
}

void s_function(FILE *input_file, FILE *output_file)
{
    char character = fgetc(input_file);
    int symbols_count = 0;
    while (character != EOF)
    {
        while (character != EOF && character != '\n')
        {
            if (!(character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z' || character == ' ' || character >= '0' && character <= '9'))
                symbols_count++;
            character = fgetc(input_file);
        }
        fprintf(output_file, "%d\n", symbols_count);
        symbols_count = 0;
        character = fgetc(input_file);
    }
}

void a_function(FILE *input_file, FILE *output_file)
{
    char character = fgetc(input_file);
    int ascii_value;
    while (character != EOF)
    {
        if (character < '0' || character > '9')
            fprintf(output_file, "%x", character);
        else
            fputc(character, output_file);
        character = fgetc(input_file);
    }
}

void new_file(char *filename, char *new_filename, int filename_length)
{
    filename_length--;
    while (filename[filename_length] != 92 && filename_length != -1)
    {
        new_filename[filename_length + 4] = filename[filename_length];
        filename_length--;
    }
    new_filename[filename_length + 4] = '_';
    new_filename[filename_length + 3] = 't';
    new_filename[filename_length + 2] = 'u';
    new_filename[filename_length + 1] = 'o';
    while (filename_length != -1)
    {
        new_filename[filename_length] = filename[filename_length];
        filename_length--;
    }
}

int flag_validation(char *flag)
{
    if (flag[2] != 0 && flag[3] != 0)
    {
        return 0;
    }
    if (flag[2] == 0)
    {
        if (!((flag[0] == '-' || flag[0] == '/') && (flag[1] == 'd' || flag[1] == 'i' || flag[1] == 's' || flag[1] == 'a')))
            return 0;
    }
    else if (flag[3] == 0)
        if (!((flag[0] == '-' || flag[0] == '/') && flag[1] == 'n' &&
              (flag[2] == 'd' || flag[2] == 'i' || flag[2] == 's' || flag[2] == 'a')))
        {
            return 0;
        }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        printf("Wrong amount of arguments");
        return 1;
    }
    if (!flag_validation(argv[1]))
    {
        printf("Wrong flag detected");
        return 2;
    }
    if (argv[1][1] == 'n')
    {
        if (argc != 4)
        {
            printf("Wrong amount of arguments");
            return 1;
        }
    }
    else if (argc != 3)
    {
        printf("Wrong amount of arguments");
        return 1;
    }
    FILE *input_file = fopen(argv[2], "r");
    if (input_file == NULL)
    {
        printf("No such file or directory");
        return 3;
    }
    FILE *output_file;
    if (argv[1][1] == 'n')
    {
        output_file = fopen(argv[3], "w");
        if (output_file == NULL)
        {
            printf("No such file or directory");
            return 3;
        }
    }
    else
    {
        int filename_length = strlen(argv[2]);
        char *filename = (char *)malloc(sizeof(char) * (filename_length + 4));
        if (!(filename))
        {
            printf("Allocation error");
            return 4;
        }
        new_file(argv[2], filename, filename_length);
        printf("%c ", filename[1]);
        output_file = fopen(filename, "w");
        if (output_file == NULL)
        {
            printf("No such file or directory");
            return 3;
        }
    }
    char flag;
    if (argv[1][1] == 'n')
        flag = argv[1][2];
    else
        flag = argv[1][1];
    switch (flag)
    {
    case 'd':
        d_function(input_file, output_file);
        break;
    case 'i':
        i_function(input_file, output_file);
        break;
    case 's':
        s_function(input_file, output_file);
        break;
    case 'a':
        a_function(input_file, output_file);
        break;
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}