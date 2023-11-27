typedef struct pixel{
    unsigned char redIntensity; // red pixel intensity : 0-255
    unsigned char greenIntensity; // green pixel intensity : 0-255
    unsigned char blueIntensity; // blue pixel intensity : 0-255
}RGBPixel;

int main ()
{
    RGBPixel image[10][10];
    for(int i=0; i<10; i++)
        for(int j=0; i<10; j++)
        {
            image[i][j].redIntensity = (unsigned char)((255.0 / 10) * j);
            image[i][j].greenIntensity = 128;
            image[i][j].blueIntensity = (unsigned char)((255.0 / 10) * j);
        }
    FILE* fp = fopen("rgb_image.bin", "wb");
    if(fp != NULL)
    {
        fwrite(image, sizeof(RGBPixel), 10 * 10, fp);
        fclose(fp);
    }
}
