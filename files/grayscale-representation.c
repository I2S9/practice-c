//Gray scale image

typedef struct pixel{
    unsigned char value; // 0-255 pixel intensity
}Pixel;

int main ()
{
    Pixel image[10][10];
    for(int i=0; i<10; i++)
        for(int j=0; i<10; j++)
           image[i][j].value = (unsigned char)(255.0 / 10 * j);

    FILE* fp = fopen("image.bin", "wb");
    if(fp != NULL)
    {
        fwrite(image, sizeof(Pixel), 10 * 10, fp);
        fclose(fp);
    }
}
