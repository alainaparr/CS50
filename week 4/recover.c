#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check argument count = 2
    if (argc != 2)
    {
        printf("Usage: ./recpver IMAGE\n");
        return 1;
    }

    // open file
    FILE *input_file = fopen(argv[1], "r");

    // check if input_file valid
    if (input_file == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    // keep blocks 512 in array
    unsigned char buffer[512];

    //track # images made
    int count_image = 0;

    // file pointer for recovered images
    FILE *output_file = NULL;

    // char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // read blocks 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //see if bytes indicate JPEG start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count_image > 0)
            {
                fclose(output_file);
            }

            // write jpeg filenames
            sprintf(filename, "%03i.jpg", count_image);

            //open output_file for writing
            output_file = fopen(filename, "w");

            // count # images
            count_image++;
        }
        //check if output used for valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}
