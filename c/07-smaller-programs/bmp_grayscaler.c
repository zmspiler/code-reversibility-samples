#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For int8_t, int16_t, int32_t
#include <stdbool.h>

#pragma pack(1)

#define BYTE uint8_t
#define HWORD uint16_t
#define WORD uint32_t
typedef struct {
    BYTE alpha;
    BYTE blue; // BLUE
    BYTE green;  // green
    BYTE red; // red
} RgbaPixel;

typedef struct {
    BYTE blue;
    BYTE green;
    BYTE red;
} RgbPixel;

typedef struct {
    HWORD bfType;
    WORD _bfSize;
    WORD _bfReserved;
    WORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    WORD _header_size;
    WORD pixelWidth;
    WORD pixelHeight;
    HWORD _colorPlaneCount;
    HWORD bitsPerPixel;
    WORD _compressMethod;
    WORD _imageSize;
    WORD _horizontalRes;
    WORD _verticalRes;
    WORD _colors_count_palette;
    WORD _imp_colors_palette;
} BITMAPINFOHEADER;

void grayscale_it_rgba(void* pixels_, const unsigned int buffer_len) {

    if (pixels_ == NULL) {
        perror("rgb grayscaler: pixels is NULL");
        return;
    }

    RgbaPixel* pixels = pixels_;
    BYTE gray_value;
    for (int i = 0; i < buffer_len; i++) {
        gray_value = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray_value;
        pixels[i].green = gray_value;
        pixels[i].blue = gray_value;
    }
}

void grayscale_it_rgb(void* pixels_, const unsigned int buffer_len) {
    if (pixels_ == NULL) {
        perror("rgb grayscaler: pixels is NULL");
        return;
    }

    RgbPixel* pixels = pixels_;
    int gray_value;
    for (int i = 0; i < buffer_len; i++) {
        gray_value = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray_value;
        pixels[i].green = gray_value;
        pixels[i].blue = gray_value;
    }
}



int main(int argc, char* args[]) {
    if (argc != 3) {
        printf("Usage: %s <input bmp> <output bmp>\n", args[0]);
        return -1;
    }

    FILE* input_file = fopen(args[1], "rb");
    if (input_file == NULL) {
        perror("File could not be opened!");
        return -1;
    }

    BITMAPFILEHEADER* bmpfh = malloc(sizeof(BITMAPFILEHEADER));
    if (bmpfh == NULL) {
        perror("Failed to allocate heap memory for BITMAPFILEHEADER");
        fclose(input_file);
        return -1;
    }
    fread(bmpfh, sizeof(BITMAPFILEHEADER), 1, input_file);
    if (bmpfh == NULL) {
        perror("Error reading BITMAPFILEHEADER");
        free(bmpfh);
        fclose(input_file);
        return -1;
    }
    if (bmpfh->bfType != 0x4D42) {
        perror("Provided file is not in BMP format!");
        free(bmpfh);
        fclose(input_file);
        return -1;
    }

    BITMAPINFOHEADER* bmpih = malloc(sizeof(BITMAPINFOHEADER));
    if (bmpih == NULL) {
        perror("Failed to allocate heap memory for BITMAPINFOHEADER");
        free(bmpfh);
        fclose(input_file);
    }
    fread(bmpih, sizeof(BITMAPINFOHEADER), 1, input_file);
    if (bmpih == NULL) {
        perror("Error reading BITMAPINFOHEADER");
        free(bmpfh);
        free(bmpih);
        fclose(input_file);
        return -1;
    }

    FILE* output_file = fopen(args[2], "wb");
    if (output_file == NULL) {
        perror("Output file could not be opened!");
        free(bmpfh);
        free(bmpih);
        fclose(input_file);
        return -1;
    }


    // Prekopiraj heading in vse podatke razen imageData
    fseek(input_file, 0, SEEK_SET);
    BYTE *headerData = malloc(bmpfh->bfOffBits);
    if (headerData == NULL) {
        printf("Napaka pri alokaciji pomnilnika za headerData\n");
        fclose(input_file);
        fclose(output_file);
        free(bmpfh);
        free(bmpih);
        return 7;
    }
    fread(headerData, 1, bmpfh->bfOffBits, input_file);

    fseek(input_file, 0, SEEK_SET);
    fwrite(headerData, 1, bmpfh->bfOffBits, output_file);
    fseek(input_file, bmpfh->bfOffBits, SEEK_SET); // preskoči na pixle



    //BEGIN: write pixels
    const size_t colorsCount = bmpih->bitsPerPixel / 8;
    const size_t pixelSize = colorsCount == 4 ? sizeof(RgbaPixel) : sizeof(RgbPixel);

    size_t padding = (4 - (bmpih->pixelWidth * colorsCount) % 4) % 4;
    size_t rowSize = (bmpih->pixelWidth * pixelSize) + padding;

    // Allocate memory for a single row of pixels
    void* pixelRow = calloc(rowSize, sizeof(BYTE));
    if (pixelRow == NULL) {
        perror("Memory allocation failed");
        free(bmpfh);
        free(bmpih);
        free(headerData);
        fclose(input_file);
        fclose(output_file);
        return -1;
    }

    void (*grayscaler)(void*, const unsigned int) = colorsCount == 4 ? &grayscale_it_rgba : &grayscale_it_rgb;

    for (int i = 0; i < bmpih->pixelHeight; i++) {
        fread(pixelRow, rowSize, 1, input_file);
        grayscaler(pixelRow, bmpih->pixelWidth);
        fwrite(pixelRow, rowSize, 1, output_file);
    }
    //END: write remaining data left

    free(pixelRow);
    free(bmpfh);
    free(bmpih);
    fclose(input_file);
    fclose(output_file);
    return 0;
}
