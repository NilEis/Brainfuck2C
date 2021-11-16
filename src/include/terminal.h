#ifndef TERMINAL_H
#define TERMINAL_H

void terminal_clear(void);
/**
 * @brief sets the color of the console
 * @param f the foreground color
 * @param b the background color
 * @return (void)
 */
void terminal_set_color(int f, int b);

/**
 * @brief resets the color of the console to black and white
 * @return (void)
 */
void terminal_reset_color(void);

/**
 * @brief returns the width of the console buffer
 * @return (int)
 */
int terminal_get_width(void);

/**
 * @brief returns the height of the console buffer
 * @return (int)
 */
int terminal_get_height(void);

/**
 * @brief sets the cursor position to x,y
 * @return (void)
 */
void terminal_set_cursor_pos(int x, int y);

/**
 * @brief pauses the current thread for ms milliseconds 
 * @return (void)
 */
void terminal_sleep(int ms);

/**
 * @brief Reads a char from stdin without waiting for '\n'
 * @return (int)
 */
int terminal_getch(void);

/**
 * @brief returns 1 if a key was pressed.
 * @return (int)
 */

int terminal_kbhit(void);

#if defined(_WIN32) || defined(_WIN64)

enum color
{
    BLACK = 0b0000,         //0x00,
    BLUE = 0b0001,          //0x01,
    GREEN = 0b0010,         //0x02,
    CYAN = 0b0011,          //0x03,
    RED = 0b0100,           //0x04,
    MAGENTA = 0b0101,       //0x05,
    YELLOW = 0b0110,        //0x06,
    WHITE = 0b0111,         //0x07,
    GRAY = 0b1000,          //0x08,
    LIGHT_BLUE = 0b1001,    //0x09,
    LIGHT_GREEN = 0b1010,   //0x0A,
    LIGHT_CYAN = 0b1011,    //0x0B,
    LIGHT_RED = 0b1100,     //0x0C,
    LIGHT_MAGENTA = 0b1101, //0x0D,
    LIGHT_YELLOW = 0b1110,  //0x0E,
    LIGHT_WHITE = 0b1111    //0x0F
};

#elif defined(__unix__)

enum color
{
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    GRAY = 90, /*"LIGHT_BLACK"*/
    LIGHT_RED = 91,
    LIGHT_GREEN = 92,
    LIGHT_YELLOW = 93,
    LIGHT_BLUE = 94,
    LIGHT_MAGENTA = 95,
    LIGHT_CYAN = 96,
    LIGHT_WHITE = 97
};

#define RESET "\x1b[0m"

#endif

#endif // TERMINAL_H
