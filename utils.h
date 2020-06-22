void default_values_bmp(struct bmp_fileheader *file_header,
						struct bmp_infoheader *info_header);

void O_piece();

void I_piece();

void S_piece();

void Z_piece();

void L_piece();

void J_piece();

void T_piece();

void piece_rotation(char old_filename[], char new_filename[]);

void task1();

void task2();

void rotation(unsigned char *pixels, int *width, int *height);

void complete_rotation(int rotate, unsigned char *pixels,
					   int *width, int *height);

void O_pixels(unsigned char *pixels, int width, int height);

void I_pixels(unsigned char *pixels, int width, int height);

void S_pixels(unsigned char *pixels, int width, int height);

void Z_pixels(unsigned char *pixels, int width, int height);

void L_pixels(unsigned char *pixels, int width, int height);

void J_pixels(unsigned char *pixels, int width, int height);

void T_pixels(unsigned char *pixels, int width, int height);

void map(char file_name[], int height, int width);

void move(char file_name[], unsigned char *piece_pixels,
		  int width, int height, int col);

void elim_full_row(char file_name[]);

int game_over(char file_name[]);

void copy_file(char old_filename[], char new_filename[]);

void task3();

void task4();

int verify_piece(unsigned char *piece_pixels, int width, int height,
				 int row, int col);

void mark_piece(unsigned char *piece_pixels, int width, int height,
				int row, int col);

void bonus();
