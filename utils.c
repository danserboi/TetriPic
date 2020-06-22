/*Serboi Florea-Dan 315CB*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bmp_header.h"

/*! pentru lucrul cu subpixelii, vom aloca dinamic un vector pe care il vom
interpreta ca pe o matrice*/
/*liniile sunt parcurse de la coada la cap din cauza formatului bmp*/
/*aici punem valorile standard pentru fileheader si infoheader*/
void default_values_bmp(struct bmp_fileheader *file_header,
						struct bmp_infoheader *info_header)
{
	file_header->fileMarker1 = 'B';
	file_header->fileMarker2 = 'M';
	file_header->imageDataOffset = 54;
	info_header->biSize = 40;
	info_header->planes = 1;
	info_header->bitPix = 24;
}

/*in functiile "X_piece" construim piesele*/
/*voi comenta doar prima functie de acest tip, restul sunt analog*/
void O_piece()
{
	/*punem valorile corespunzatoare piesei pentru fileheader si infoheader*/
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 40;
	info_header.height = 40;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	/*alocam dinamic un vector pe care il vom interpreta ca pe o matrice*/
	/*in acest vector vom avea valorile pixelilor + paddding*/
	unsigned char *pixels = malloc(imagesize);
	/*initializam subpixelii cu 0, astfel ne asiguram ca avem si padding-ul*/
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	/*construim matricea cu valorile corespunzatoare piesei*/
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 29; i >= 10; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	/*scriem valorile in fisier*/
	FILE *fout = fopen("piesa_O.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

void I_piece()
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 30;
	info_header.height = 60;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 49; i >= 10; i--)
	{
		for (j = 10; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
	FILE *fout = fopen("piesa_I.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

void S_piece()
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 50;
	info_header.height = 40;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 19; i >= 10; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 29; i >= 20; i--)
	{
		for (j = 20; j <= 39; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	FILE *fout = fopen("piesa_S.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

void Z_piece()
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 50;
	info_header.height = 40;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 19; i >= 10; i--)
	{
		for (j = 20; j <= 39; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
	for (i = 29; i >= 20; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
	FILE *fout = fopen("piesa_Z.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

void L_piece()
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 40;
	info_header.height = 50;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 19; i >= 10; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 140;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 39; i >= 20; i--)
	{
		for (j = 10; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 140;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	FILE *fout = fopen("piesa_L.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

void J_piece()
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 40;
	info_header.height = 50;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 19; i >= 10; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 39; i >= 20; i--)
	{
		for (j = 20; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	FILE *fout = fopen("piesa_J.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

void T_piece()
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = 50;
	info_header.height = 40;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 19; i >= 10; i--)
	{
		for (j = 20; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 130;//red
		}
	}
	for (i = 29; i >= 20; i--)
	{
		for (j = 10; j <= 39; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 130;//red
		}
	}
	FILE *fout = fopen("piesa_T.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

/*rotim piesa, creand un nou fisier cu denumirea dorita*/
void piece_rotation(char old_filename[], char new_filename[])
{
	/*citim piesa*/
	FILE *in = fopen(old_filename, "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	/*initializam valorile pentru noua piesa*/
	struct bmp_fileheader new_file_header = {0};
	struct bmp_infoheader new_info_header = {0};
	default_values_bmp(&new_file_header, &new_info_header);
	new_info_header.width = info_header.height;
	new_info_header.height = info_header.width;
	int new_width_in_bytes, new_imagesize, i, j;
	new_width_in_bytes = new_info_header.width * 3 + new_info_header.width % 4;
	new_imagesize = new_width_in_bytes * new_info_header.height;
	new_file_header.bfSize = new_file_header.imageDataOffset + new_imagesize;
	new_info_header.biSizeImage = new_imagesize;
	unsigned char *new_pixels = malloc(new_imagesize);
	/*initializam subpixelii cu 0, astfel ne asiguram ca avem si padding-ul */
	for (i = new_imagesize - 1; i >= 0; i--)
		new_pixels[i] = 0;
	/*in noua "matrice" vom pune valorile "matricei" initiale rotite*/ 
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			new_pixels[(new_info_header.height - 1 - j) * new_width_in_bytes +
			i * 3 + 0] = pixels[i * width_in_bytes + j * 3 + 0];
			new_pixels[(new_info_header.height - 1 - j) * new_width_in_bytes +
			i * 3 + 1] = pixels[i * width_in_bytes + j * 3 + 1];
			new_pixels[(new_info_header.height - 1 - j) * new_width_in_bytes +
			i * 3 + 2] = pixels[i * width_in_bytes + j * 3 + 2];
		}
	}
	/*scriem in fisier*/
	FILE *new_fout = fopen(new_filename, "wb");
	fwrite(&new_file_header, sizeof(new_file_header), 1, new_fout);
	fwrite(&new_info_header, sizeof(new_info_header), 1, new_fout);
	fwrite(new_pixels, 1, new_imagesize, new_fout);
	fclose(new_fout);
	free(pixels);
	free(new_pixels);
}

void task1()
{
	O_piece();
	I_piece();
	S_piece();
	Z_piece();
	L_piece();
	J_piece();
	T_piece();
}

void task2()
{
	task1();
	piece_rotation("piesa_O.bmp", "piesa_O_90.bmp");
	piece_rotation("piesa_I.bmp", "piesa_I_90.bmp");
	piece_rotation("piesa_S.bmp", "piesa_S_90.bmp");
	piece_rotation("piesa_Z.bmp", "piesa_Z_90.bmp");
	piece_rotation("piesa_L.bmp", "piesa_L_90.bmp");
	piece_rotation("piesa_J.bmp", "piesa_J_90.bmp");
	piece_rotation("piesa_T.bmp", "piesa_T_90.bmp");

	piece_rotation("piesa_O_90.bmp", "piesa_O_180.bmp");
	piece_rotation("piesa_I_90.bmp", "piesa_I_180.bmp");
	piece_rotation("piesa_S_90.bmp", "piesa_S_180.bmp");
	piece_rotation("piesa_Z_90.bmp", "piesa_Z_180.bmp");
	piece_rotation("piesa_L_90.bmp", "piesa_L_180.bmp");
	piece_rotation("piesa_J_90.bmp", "piesa_J_180.bmp");
	piece_rotation("piesa_T_90.bmp", "piesa_T_180.bmp");

	piece_rotation("piesa_O_180.bmp", "piesa_O_270.bmp");
	piece_rotation("piesa_I_180.bmp", "piesa_I_270.bmp");
	piece_rotation("piesa_S_180.bmp", "piesa_S_270.bmp");
	piece_rotation("piesa_Z_180.bmp", "piesa_Z_270.bmp");
	piece_rotation("piesa_L_180.bmp", "piesa_L_270.bmp");
	piece_rotation("piesa_J_180.bmp", "piesa_J_270.bmp");
	piece_rotation("piesa_T_180.bmp", "piesa_T_270.bmp");
}
/*in aceasta functie rotim doar subpixelii corespunzatori unei piese*/
void rotation(unsigned char *pixels, int *width, int *height)
{
	int width_in_bytes = *width * 3;
	int new_width = *height, new_height = *width;
	int new_width_in_bytes, i, j;
	new_width_in_bytes = new_width * 3;
	unsigned char *new_pixels = malloc (new_width_in_bytes * new_height);
	unsigned char *copy = new_pixels;
	for (i = new_width_in_bytes * new_height - 1; i >= 0; i--)
		new_pixels[i] = 0;
	for (i = *height - 1; i >= 0; i--)
	{
		for (j = 0; j < *width; j++)
		{
			new_pixels[(new_height - 1 - j) * new_width_in_bytes + i * 3 + 0]
			= pixels[i * width_in_bytes + j * 3 + 0];
			new_pixels[(new_height - 1 - j) * new_width_in_bytes + i * 3 + 1]
			= pixels[i * width_in_bytes + j * 3 + 1];
			new_pixels[(new_height - 1 - j) * new_width_in_bytes + i * 3 + 2]
			= pixels[i * width_in_bytes + j * 3 + 2];
		}
	}
	for (i = new_height - 1; i >= 0; i--)
	{
		for (j = 0; j < new_width; j++)
		{
			pixels[i * new_width_in_bytes + j * 3 + 0]
			= new_pixels[i * new_width_in_bytes + j * 3 + 0];
			pixels[i * new_width_in_bytes + j * 3 + 1]
			= new_pixels[i * new_width_in_bytes + j * 3 + 1];
			pixels[i * new_width_in_bytes + j * 3 + 2]
			= new_pixels[i * new_width_in_bytes + j * 3 + 2];
		}
	}
	*width = new_width;
	*height = new_height;
	free(copy);
}

/*aici rotim in functie de un anumit unghi doar subpixelii*/
void complete_rotation(int rotate, unsigned char *pixels,
					   int *width, int *height)
{
	switch (rotate)
	{
	case 0:
		break;
	case 90:
		rotation(pixels, &(*width), &(*height));
		break;
	case 180:
		rotation(pixels, &(*width), &(*height));
		rotation(pixels, &(*width), &(*height));
		break;
	case 270:
		rotation(pixels, &(*width), &(*height));
		rotation(pixels, &(*width), &(*height));
		rotation(pixels, &(*width), &(*height));
	}
}

/*functiile "X_pixels" pun doar valorile corespunzatoare subpixelilor unei
piese in "matricea" de subpixeli; "matricea" va fi construita ca un
dreptunghi, pentru piesele care nu au o astfel de forma, restul de subpixeli
vor fi 0 pentru a pune cu usurinta piesele pe harta ulterior*/
void O_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j <= width - 1; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
}

void I_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j <= width - 1; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
}

void S_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = 0; i <= width_in_bytes * height - 1; i++)
		pixels[i] = 0;
	for (i = 19; i >= 10; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 0; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
}

void Z_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = 0; i <= width_in_bytes * height - 1; i++)
		pixels[i] = 0;
	for (i = 19; i >= 10; i--)
	{
		for (j = 0; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 10; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
}

void L_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = 0; i <= width_in_bytes * height - 1; i++)
		pixels[i] = 0;
	for (i = 29; i >= 10; i--)
	{
		for (j = 0; j <= 9; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 140;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 0; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 140;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
}

void J_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = 0; i <= width_in_bytes * height - 1; i++)
		pixels[i] = 0;
	for (i = 29; i >= 10; i--)
	{
		for (j = 10; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 0; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
}

void T_pixels(unsigned char *pixels, int width, int height)
{
	int i, j, width_in_bytes = width * 3;
	for (i = 0; i <= width_in_bytes * height - 1; i++)
		pixels[i] = 0;
	for (i = 19; i >= 10; i--)
	{
		for (j = 0; j <= 29; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 130;//red
		}
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 10; j <= 19; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 130;//red
		}
	}
}

/*in functia map cream o harta goala cu inaltimea si latimea dorita*/
void map(char file_name[], int height, int width)
{
	struct bmp_fileheader file_header = {0};
	struct bmp_infoheader info_header = {0};
	default_values_bmp(&file_header, &info_header);
	info_header.width = width * 10;
	info_header.height = (height + 4) * 10;
	int width_in_bytes, imagesize, i, j;
	width_in_bytes = info_header.width * 3 + info_header.width % 4;
	imagesize = width_in_bytes * info_header.height;
	file_header.bfSize = file_header.imageDataOffset + imagesize;
	info_header.biSizeImage = imagesize;
	unsigned char *pixels = malloc(imagesize);
	for (i = imagesize - 1; i >= 0; i--)
		pixels[i] = 0;
	/*completam partea de sus cu alb*/
	for (i = info_header.height - 1; i >= height * 10; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 255;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 255;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 255;//red
		}
	}
	/*completam partea de jos cu negru*/
	for (i = height * 10 - 1; i >= 0; i--)
	{
		for (j = 0; j < info_header.width; j++)
		{
			pixels[i * width_in_bytes + j * 3 + 0] = 0;//blue
			pixels[i * width_in_bytes + j * 3 + 1] = 0;//green
			pixels[i * width_in_bytes + j * 3 + 2] = 0;//red
		}
	}
	/*scriem fisierul*/
	FILE *fout = fopen(file_name, "wb");
	fwrite(&file_header, sizeof(file_header), 1, fout);
	fwrite(&info_header, sizeof(info_header), 1, fout);
	fwrite(pixels, 1, imagesize, fout);
	fclose(fout);
	free(pixels);
}

/*in functia move plasam o piesa pe coloana dorita din cadrul hartii*/
void move(char file_name[], unsigned char *piece_pixels,
		  int width, int height, int col)
{
	int i, j, k, ok = 1;
	FILE *in = fopen(file_name, "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	int map_pixels_sum, piece_pixels_sum;
	/*pornim mutarea piesei de deasupra partii negre*/
	for (k = (info_header.height - 40) / 10; k >= 0; k--)
	{
		for (i = height - 1; i >= 0; i--)
		{
			for (j = 0; j <= width - 1; j++)
			{
				map_pixels_sum = pixels[(k * 10 + i) * width_in_bytes +
				col * 10 * 3 + j * 3 + 0] + pixels[(k * 10 + i) *
				width_in_bytes + col * 10 * 3 + j * 3 + 1] + 
				pixels[(k * 10 + i) * width_in_bytes
				+ col * 10 * 3 + j * 3 + 2];
				piece_pixels_sum = piece_pixels[i * width * 3 + j * 3 + 0] +
				piece_pixels[i * width * 3 + j * 3 + 1]
				+ piece_pixels[i * width * 3 + j * 3 + 2];
				/*pentru ca piesa sa poata fi plasata pe harta, trebuie ca :
				fie pixelii piesei sa fie negri, fie pixelii hartii sa fie
				negri, fie pixelii hartii sa fie albi, altfel ne oprim si
				plasam piesa pe linia dinainte*/
				if (piece_pixels_sum != 0 && map_pixels_sum != 0
					&& map_pixels_sum != 765)
				{
					ok = 0;
					break;
				}
			}
			if (ok == 0)
				break;
		}
		if (ok == 0)
		{
			break;
		}
	}
	/*ne ducem pe coloana anterioara; e valabil si pentru cazul cand piesa 
	nu are obstacol si ajunge pe ultima linie, deoarece k ar iesi din for
	cu valoarea -1*/
	k++;
	/*punem valorile piesei pe harta*/
	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j <= width - 1; j++)
		{
			piece_pixels_sum = piece_pixels[i * width * 3 + j * 3 + 0] +
			piece_pixels[i * width * 3 + j * 3 + 1] +
			piece_pixels[i * width * 3 + j * 3 + 2];
			if (piece_pixels_sum != 0)
			{
				pixels[(k * 10 + i)* width_in_bytes + col * 10 * 3 + j * 3 + 0]
				= piece_pixels[i * width * 3 + j * 3 + 0];
				pixels[(k * 10 + i)* width_in_bytes + col * 10 * 3 + j * 3 + 1]
				= piece_pixels[i * width * 3 + j * 3 + 1];
				pixels[(k * 10 + i)* width_in_bytes + col * 10 * 3 + j * 3 + 2]
				= piece_pixels[i * width * 3 + j * 3 + 2];
			}
		}
	}
	FILE *new_fout = fopen(file_name, "wb");
	fwrite(&file_header, sizeof(file_header), 1, new_fout);
	fwrite(&info_header, sizeof(info_header), 1, new_fout);
	fwrite(pixels, 1, imagesize, new_fout);
	fclose(new_fout);
	free(pixels);
}

/*eliminam randurile complet*/
void elim_full_row(char file_name[])
{
	unsigned char *aux;
	int i, j, ok = 1, pixels_sum;
	FILE *in = fopen(file_name, "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	for (i = 0; i < (info_header.height - 40) / 10; i++)
	{
		ok = 1;
		for (j = 0; j < info_header.width; j++)
		{
			pixels_sum = pixels[i * 10 * width_in_bytes + j * 3 + 0] +
			pixels[i * 10 * width_in_bytes + j * 3 + 1] +
			pixels[i * 10 * width_in_bytes + j * 3 + 2];
			/*daca toti pixelii sunt negri, nu mai eliminam rand*/
			if (pixels_sum == 0)
				ok = 0;
		}
		/*eliminam randul*/
		if (ok == 1)
		{
			aux = malloc(imagesize);
			memmove(aux, pixels, imagesize);
			/*eliminam caracterele corespunzatoare randului*/
			memmove(aux + i * 10 * width_in_bytes,
			aux + (i + 1) * 10 * width_in_bytes,
			imagesize - (i + 1) * 10 * width_in_bytes);
			/*completam deasupra cu un rand negru si cu un rand alb (pentru a 
			a-l inlocui pe cel eliminat eliminat)*/
			memset(aux + (info_header.height - 50) * width_in_bytes,
			0, 10 * width_in_bytes);
			memset(aux + (info_header.height - 10) * width_in_bytes,
			255, 10 * width_in_bytes);
			memmove(pixels, aux, imagesize);
			free(aux);
			i--;
		}
	}
	/*ne asiguram ca avem padding-ul*/
	for (i = info_header.height - 1; i >= 0; i--)
	{
		for (j = info_header.width * 3; j < width_in_bytes; j++)
		{
			pixels[i * width_in_bytes + j] = 0;
		}
	}
	FILE *new_fout = fopen(file_name, "wb");
	fwrite(&file_header, sizeof(file_header), 1, new_fout);
	fwrite(&info_header, sizeof(info_header), 1, new_fout);
	fwrite(pixels, 1, imagesize, new_fout);
	fclose(new_fout);
	free(pixels);
}

/*functia verifica daca jocul s-a terminat*/
int game_over(char file_name[])
{
	FILE *in = fopen(file_name, "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	int ok = 0, i, j;
	for (i = info_header.height - 1; i >= info_header.height - 40; i--)
	{
		for (j = 0; j <= info_header.width * 3 - 1; j++)
		{
			/*daca avem pixeli diferiti de alb in zona superioara, jocul
			s-a terminat*/
			if ( pixels[i * width_in_bytes + j] != 255)
				ok = 1;
		}
	}
	free(pixels);
	return ok;
}

/*functia creeaza un fisier bmp identic, dar cu alt nume*/
void copy_file(char old_filename[], char new_filename[])
{
	FILE *in = fopen(old_filename, "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	FILE *new_fout = fopen(new_filename, "wb");
	fwrite(&file_header, sizeof(file_header), 1, new_fout);
	fwrite(&info_header, sizeof(info_header), 1, new_fout);
	fwrite(pixels, 1, imagesize, new_fout);
	fclose(new_fout);
	free(pixels);
}

/*functia trateaza task-ul 3*/
void task3()
{
	int i, no_moves, image_height, image_width, rotation, col, width, height;
	char piece_name;
	unsigned char *pixels = NULL;
	FILE *in = fopen("cerinta3.in", "rt");
	/*citim numarul de mutari, inaltimea si latimea hartii*/
	fscanf(in, "%d %d %d\n", &no_moves, &image_height, &image_width);
	/*cream inital o harta goala*/
	map("task3.bmp", image_height, image_width);
	for (i = 1; i <= no_moves; i++)
	{
		/*citim piesa, rotatia si coloana unde trebuie pusa si tratam separat
		fiecare piesa in parte pentru a obtine matricea de subpixeli*/
		fscanf(in, "%c %d %d\n", &piece_name, &rotation, &col);
		switch (piece_name)
		{
		case 'O':
			width = 20; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			O_pixels(pixels, width, height);
			break;
		case 'I':
			width = 10; height = 40;
			pixels = realloc(pixels, width * 3 * height);
			I_pixels(pixels, width, height);
			break;
		case 'S':
			width = 30; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			S_pixels(pixels, width, height);
			break;
		case 'Z':
			width = 30; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			Z_pixels(pixels, width, height);
			break;
		case 'L':
			width = 20; height = 30;
			pixels = realloc(pixels, width * 3 * height);
			L_pixels(pixels, width, height);
			break;
		case 'J':
			width = 20; height = 30;
			pixels = realloc(pixels, width * 3 * height);
			J_pixels(pixels, width, height);
			break;
		case 'T':
			width = 30; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			T_pixels(pixels, width, height);
		}
		/*rotim piesa cu unghiul dorit*/
		complete_rotation(rotation, pixels, &width, &height);
		/*mutam piesa pe harta*/
		move("task3.bmp", pixels, width, height, col);
		/*verificam daca s-a terminat jocul, altfel eliminam randurile pline*/
		if (game_over("task3.bmp") == 1)
			break;
		else
			elim_full_row("task3.bmp");
	}
	free(pixels);
	fclose(in);
}

/*task-ul 4 se trateaza analog cu task-ul 3, cu deosebirea ca punem piesele
pe o harta care contine deja alte piese*/
void task4()
{
	int i, no_moves, rotation, col, width, height;
	char piece_name;
	/*cream un fisier bmp identic cu cel din cerinta in care vom rezolva
	task-ul*/
	copy_file("cerinta4.bmp", "task4.bmp");
	FILE *in = fopen("cerinta4.in", "rt");
	fscanf(in, "%d\n", &no_moves);
	unsigned char *pixels = NULL;
	for (i = 1; i <= no_moves; i++)
	{
		fscanf(in, "%c %d %d\n", &piece_name, &rotation, &col);
		switch (piece_name)
		{
		case 'O':
			width = 20; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			O_pixels(pixels, width, height);
			break;
		case 'I':
			width = 10; height = 40;
			pixels = realloc(pixels, width * 3 * height);
			I_pixels(pixels, width, height);
			break;
		case 'S':
			width = 30; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			S_pixels(pixels, width, height);
			break;
		case 'Z':
			width = 30; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			Z_pixels(pixels, width, height);
			break;
		case 'L':
			width = 20; height = 30;
			pixels = realloc(pixels, width * 3 * height);
			L_pixels(pixels, width, height);
			break;
		case 'J':
			width = 20; height = 30;
			pixels = realloc(pixels, width * 3 * height);
			J_pixels(pixels, width, height);
			break;
		case 'T':
			width = 30; height = 20;
			pixels = realloc(pixels, width * 3 * height);
			T_pixels(pixels, width, height);
		}
		complete_rotation(rotation, pixels, &width, &height);
		move("task4.bmp", pixels, width, height, col);
		if (game_over("task4.bmp") == 1)
			break;
		else
			elim_full_row("task4.bmp");
	}
	free(pixels);
	fclose(in);
}

/*aceasta functie verifica daca subpixelii unei piese sunt pe o anumita linie
si o anumita coloana a hartii,  cu alte cuvinte,
verifica daca piesa se regaseste pe harta*/
int verify_piece(unsigned char *piece_pixels, int width, int height,
				 int row, int col)
{
	FILE *in = fopen("bonus.bmp", "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	int i, j, piece_pixels_sum, ok = 1;
	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j <= width - 1; j++)
		{
			piece_pixels_sum = piece_pixels[i * width * 3 + j * 3 + 0] +
			piece_pixels[i * width * 3 + j * 3 + 1] +
			piece_pixels[i * width * 3 + j * 3 + 2];
			if (piece_pixels_sum != 0)
			{
				if (pixels[(row * 10 + i)* width_in_bytes + col * 10 * 3 +
				j * 3 + 0] != piece_pixels[i * width * 3 + j * 3 + 0])
					ok = 0;
				if (pixels[(row * 10 + i)* width_in_bytes + col * 10 * 3 +
				j * 3 + 1] != piece_pixels[i * width * 3 + j * 3 + 1])
					ok = 0;
				if (pixels[(row * 10 + i)* width_in_bytes + col * 10 * 3 +
				j * 3 + 2] != piece_pixels[i * width * 3 + j * 3 + 2])
					ok = 0;
			}
		}
	}
	free(pixels);
	return ok;
}

/*aceasta functie pune pixeli negri pe harta (in locul pixelilor unei piese), 
pentru a marca faptul ca o piesa a fost gasita pe harta si pentru a evita 
includerea ulterioara a acestor pixeli intr-o noua cautare a pieselor*/
void mark_piece(unsigned char *piece_pixels, int width, int height,
				int row, int col)
{
	FILE *in = fopen("bonus.bmp", "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	int width_in_bytes = info_header.width * 3 + info_header.width % 4;
	int imagesize = width_in_bytes * info_header.height;
	unsigned char *pixels = malloc(imagesize);
	fread(pixels, 1, imagesize, in);
	fclose(in);
	int i, j, piece_pixels_sum;
	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j <= width - 1; j++)
		{
			piece_pixels_sum = piece_pixels[i * width * 3 + j * 3 + 0] +
			piece_pixels[i * width * 3 + j * 3 + 1] +
			piece_pixels[i * width * 3 + j * 3 + 2];
			if (piece_pixels_sum != 0)
			{
				pixels[(row * 10 + i)* width_in_bytes +
				col * 10 * 3 + j * 3 + 0] = 0;
				pixels[(row * 10 + i)* width_in_bytes +
				col * 10 * 3 + j * 3 + 1] = 0;
				pixels[(row * 10 + i)* width_in_bytes +
				col * 10 * 3 + j * 3 + 2] = 0;
			}
		}
	}
	FILE *new_fout = fopen("bonus.bmp", "wb");
	fwrite(&file_header, sizeof(file_header), 1, new_fout);
	fwrite(&info_header, sizeof(info_header), 1, new_fout);
	fwrite(pixels, 1, imagesize, new_fout);
	fclose(new_fout);
	free(pixels);
}

/*aceasta functie trateaza bonus-ul*/
void bonus()
{
	/*cream o structura pentru a retine ulterior informatiile cerute: piesa
	rotatia si coloana si declaram un vector*/
	struct content {
		char piece;
		int rotation;
		int column;
	} image_pieces[20];
	int nr = 0;
	unsigned char *pixels = NULL;
	/*in sirul piece_name am inclus denumirea pieselor pentru a le verifica pe 
	toate o anumita linie si coloana*/
	char *piece_name = "OISZLJT";
	int row, col, len, i, k, width, height;
	FILE *in = fopen("bonus.bmp", "rb");
	struct bmp_fileheader file_header;
	struct bmp_infoheader info_header;
	fread(&file_header, sizeof(file_header), 1, in);
	fread(&info_header, sizeof(info_header), 1, in);
	fclose(in);
	for (row = (info_header.height - 40) / 10; row >= 0; row--)
	{
		for (col = 0; col < info_header.width / 10; col++)
		{
			len = strlen(piece_name);
			/*verificam fiecare piesa in parte, sub toate rotatiile posibile,
			marcam faptul ca am trat aceasta piesa si adaugam informatiile
			cerute in vectorul image_pieces*/
			for (k = 0; k < len; k++)
				switch (piece_name[k])
				{
				case 'O':
					width = 20; height = 20;
					pixels = realloc(pixels, width * 3 * height);
					O_pixels(pixels, width, height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'O';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;
					}
					break;
				case 'I':
					width = 10; height = 40;
					pixels = realloc(pixels, width * 3 * height);
					I_pixels(pixels, width, height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'I';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'I';
						image_pieces[nr].rotation = 90;
						image_pieces[nr].column = col;
					}
					break;
				case 'S':
					width = 30; height = 20;
					pixels = realloc(pixels, width * 3 * height);
					S_pixels(pixels, width, height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'S';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'S';
						image_pieces[nr].rotation = 90;
						image_pieces[nr].column = col;
					}
					break;
				case 'Z':
					width = 30; height = 20;
					pixels = realloc(pixels, width * 3 * height);
					Z_pixels(pixels, width, height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'Z';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'Z';
						image_pieces[nr].rotation = 90;
						image_pieces[nr].column = col;
					}
					break;
				case 'L':
					width = 20; height = 30;
					pixels = realloc(pixels, width * 3 * height);
					L_pixels(pixels, width, height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'L';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'L';
						image_pieces[nr].rotation = 90;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'L';
						image_pieces[nr].rotation = 180;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'L';
						image_pieces[nr].rotation = 270;
						image_pieces[nr].column = col;
					}
					break;
				case 'J':
					width = 20; height = 30;
					pixels = realloc(pixels, width * 3 * height);
					J_pixels(pixels, width, height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'J';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'J';
						image_pieces[nr].rotation = 90;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'J';
						image_pieces[nr].rotation = 180;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'J';
						image_pieces[nr].rotation = 270;
						image_pieces[nr].column = col;
					}
					break;
				case 'T':
					width = 30; height = 20;
					pixels = realloc(pixels, width * 3 * height);
					T_pixels(pixels, width, height); 
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'T';
						image_pieces[nr].rotation = 0;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'T';
						image_pieces[nr].rotation = 90;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'T';
						image_pieces[nr].rotation = 180;
						image_pieces[nr].column = col;
					}
					rotation(pixels, &width, &height);
					if (verify_piece(pixels, width, height, row, col) == 1)
					{
						mark_piece(pixels, width, height, row, col);
						nr++;
						image_pieces[nr].piece = 'T';
						image_pieces[nr].rotation = 270;
						image_pieces[nr].column = col;
					}
				}
		}
	}
	free(pixels);
	/*scriem informatiile cerute in bonus.out*/
	FILE *out = fopen("bonus.out", "wt");
	fprintf(out, "%d\n", nr);
	for (i = 1; i <= nr; i++)
	{
		fprintf(out, "%c %d %d\n", image_pieces[i].piece,
		image_pieces[i].rotation, image_pieces[i].column);
	}
	fclose(out);
}