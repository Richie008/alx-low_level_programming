#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

void print_error(char *msg);
void print_elf_header(char *file_path);

/**
 * print_error - prints an error message to stderr and exits with status code 98
 * @msg: the error message to print
 */
void print_error(char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

/**
 * print_elf_header - prints the ELF header information
 * @file_path: the path to the ELF file
 */
void print_elf_header(char *file_path)
{
    int fd, i;
    char buffer[BUFFER_SIZE];
    Elf64_Ehdr *header;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        print_error("Can't open file");

    if (read(fd, buffer, BUFFER_SIZE) == -1)
        print_error("Can't read file");

    header = (Elf64_Ehdr *)buffer;

    if (header->e_ident[EI_MAG0] != ELFMAG0 ||
        header->e_ident[EI_MAG1] != ELFMAG1 ||
        header->e_ident[EI_MAG2] != ELFMAG2 ||
        header->e_ident[EI_MAG3] != ELFMAG3)
        print_error("File is not an ELF file");

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("None\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
            break;
    }

    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("None\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
            break;
    }

    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX ABI\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD ABI\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux ABI\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris ABI\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX ABI\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX ABI\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD ABI\n");

