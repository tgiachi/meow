#include <stdio.h>
#include <string.h>
#include  <stdbool.h>

typedef struct arg_result
{
    bool success;
    char* file_name;
} arg_result_t;


void print_file_content(const char* filename)
{
    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fp);
}

void print_help()
{
    printf("Usage: meow [options] <file>\n");
    printf("Options:\n");
    printf("  -h, --help    Show this help message and exit\n");
    printf("  -v, --version Show version information and exit\n");
}


arg_result_t parse_arguments(const int argc, char* argv[])
{
    if (argc < 2)
    {
        print_help();
        return (arg_result_t){false, NULL};
    }

    for (int i = 0; i < argc; i++)
    {
        if ((strcmp(argv[i], "--help") == 0) || (strcmp(argv[i], "-h") == 0))
        {
            print_help();
            return (arg_result_t){false, NULL};
        }

        if ((strcmp(argv[i], "--version") == 0) || (strcmp(argv[i], "-v") == 0))
        {
            printf("meow version 1.0.0\n");
            return (arg_result_t){false, NULL};
        }
    }

    char* file_name = argv[1];

    if (file_name == NULL)
    {
        return (arg_result_t){false, NULL};
    }

    return (arg_result_t){true, file_name};
}


int main(const int argc, char* argv[])
{
    const arg_result_t result = parse_arguments(argc, argv);

    if (!result.success)
    {
        printf("Please provide the file to meow meow\n");
        return 1;
    }

    print_file_content(result.file_name);

    return 0;
}
