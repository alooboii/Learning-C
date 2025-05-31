#include <stdio.h>

int main()
{
    int height;
    FILE *file;

    // Prompt the user to enter the height of the triangle
    // write code here
    printf("Enter the height of the triangle: ");
    scanf("%d", &height);

    file = fopen("triangle.txt", "w");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            fprintf(file, "%c", '*');
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("Right angle triangle has been written to triangle.txt\n");

    return 0;
}