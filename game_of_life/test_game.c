#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 80

// Прототипы функций
void print_board(const int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);
int count_neighbors(int i, int j, const int board[ROWS][COLS]);
void compute_next_generation(const int current[ROWS][COLS], int next[ROWS][COLS]);
void copy_board(const int src[ROWS][COLS], int dest[ROWS][COLS]);
int is_board_empty(const int board[ROWS][COLS]);
int are_boards_equal(const int board1[ROWS][COLS], const int board2[ROWS][COLS]);
void init_ncurses(void);
void handle_input(int* delay, int* running);
int run_game_loop(int board[ROWS][COLS], int delay, int running, int generation);
void show_final_screen(const int board[ROWS][COLS], int generation);
int get_start_configuration(void);
void load_configuration(int file_number, int matrix[ROWS][COLS]);
int smart_delay(int delay_ms, int* delay, int* running);

int get_start_configuration(void) {
    int choice;
    printf("Enter the initial configuration number (1-5):\n");
    printf("1. Simple ship\n2. Complex pattern\n3. Cross\n");
    printf("4. Glider gun\n5. Symmetric pattern\n");
    printf("Your choice: ");

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        choice = 1;
    }
    return choice;
}

int main(int argc, const char* argv[]) {
    int board[ROWS][COLS];
    int file_number = 0;

    // Если передан аргумент - используем его как номер конфигурации
    if (argc > 1) {
        file_number = atoi(argv[1]);
    }

    // Загружаем конфигурацию
    if (file_number >= 1 && file_number <= 5) {
        load_configuration(file_number, board);
    } else {
        if (argc > 1) {
            printf("Error: Invalid number. Using interactive mode.\n");
        }
        file_number = get_start_configuration();
        load_configuration(file_number, board);
    }

    init_ncurses();

    int delay = 150;
    int running = 1;
    int generation = 0;
    int final_generation;

    final_generation = run_game_loop(board, delay, running, generation);

    show_final_screen(board, final_generation);

    endwin();
    return 0;
}

void load_configuration(int file_number, int matrix[ROWS][COLS]) {
    FILE* file = NULL;
    char filename[20];

    sprintf(filename, "%d.txt", file_number);
    file = fopen(filename, "r");

    if (file == NULL) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                matrix[i][j] = 0;
            }
        }
        return;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                matrix[i][j] = 0;
            }
        }
    }
    fclose(file);
}

void copy_board(const int src[ROWS][COLS], int dest[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int are_boards_equal(const int board1[ROWS][COLS], const int board2[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board1[i][j] != board2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int is_board_empty(const int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                return 0;
            }
        }
    }
    return 1;
}

void print_board(const int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printw(".");
            } else {
                printw("O");
            }
        }
        printw("\n");
    }
}

int count_neighbors(int i, int j, const int board[ROWS][COLS]) {
    int live_neighbors = 0;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) {
                continue;
            }

            int x = (i + k + ROWS) % ROWS;
            int y = (j + l + COLS) % COLS;

            live_neighbors += board[x][y];
        }
    }
    return live_neighbors;
}

void compute_next_generation(const int current[ROWS][COLS], int next[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(i, j, current);

            if (current[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    next[i][j] = 0;
                } else {
                    next[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next[i][j] = 1;
                } else {
                    next[i][j] = 0;
                }
            }
        }
    }
}

void update_board(int board[ROWS][COLS]) {
    int next_board[ROWS][COLS];
    compute_next_generation(board, next_board);
    copy_board(next_board, board);
}

void init_ncurses(void) {
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
}

void handle_input(int* delay, int* running) {
    int ch;
    static int key_processed = 0;

    while ((ch = getch()) != ERR) {
        if (key_processed == 0) {
            if (ch == 'a' || ch == 'A') {
                key_processed = 1;
                if (*delay + 25 <= 300) {
                    *delay += 25;
                }
            } else if (ch == 'z' || ch == 'Z') {
                key_processed = 1;
                if (*delay - 25 >= 50) {
                    *delay -= 25;
                }
            } else if (ch == ' ') {
                *running = 0;
                return;
            }
        }
    }

    if (key_processed == 1) {
        key_processed = 0;
    }
}

int smart_delay(int delay_ms, int* delay, int* running) {
    int elapsed = 0;
    int step = 10;

    while (elapsed < delay_ms) {
        napms(step);
        elapsed += step;

        handle_input(delay, running);

        if (*running == 0) {
            return 0;
        }
    }
    return 1;
}

int run_game_loop(int board[ROWS][COLS], int delay, int running, int generation) {
    int prev_board[ROWS][COLS];

    copy_board(board, prev_board);

    while (1) {
        clear();
        print_board(board);
        mvprintw(
            ROWS, 0,
            "Generation: %d | Speed: %d ms (min: 50 ms, max: 300 ms) | Commands: A/Z +/-25ms, SPACE - exit",
            generation, delay);
        refresh();

        handle_input(&delay, &running);

        if (running == 0) {
            break;
        }

        if (smart_delay(delay, &delay, &running) == 0) {
            break;
        }

        update_board(board);
        generation++;

        if (are_boards_equal(board, prev_board) == 1 || is_board_empty(board) == 1) {
            break;
        }

        copy_board(board, prev_board);
    }

    return generation;
}

void show_final_screen(const int board[ROWS][COLS], int generation) {
    clear();
    print_board(board);
    mvprintw(ROWS, 0, "Game Over! Press any key to exit...");
    mvprintw(ROWS + 1, 0, "Final generation: %d", generation);
    refresh();

    nodelay(stdscr, FALSE);
    getch();
}