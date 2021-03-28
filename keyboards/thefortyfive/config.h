

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0045
#define PRODUCT_ID      0x4500
#define DEVICE_VER      0x0000
#define MANUFACTURER    David Friar
#define PRODUCT         thefortyfive
#define DESCRIPTION     q.m.k. keyboard firmware for thefortyfive

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Set power consumption to work with mobile devices */
/* #define USB_MAX_POWER_CONSUMPTION 100 */

/* key matrix pins */
/* #define MATRIX_ROW_PINS { F0, F7, F1, F6, F4, F5, C7, D1} */
/* #define MATRIX_COL_PINS { D0, C6, D7, B5, B6, B7, D6 } */
#define MATRIX_ROW_PINS { F0, F7, F1, F6, F4, F5, D1, C7}
#define MATRIX_COL_PINS { D6, B7, B6, B5, D7, C6, D0}

/* Temporary fix for reversed connector in pcb v0.1 */
/* #define MATRIX_ROW_PINS { F0, F7, F1, F6, F4, F5, D7, D1} */
/* #define MATRIX_COL_PINS { D0, C6, C7, D6, B7, B6, B5 } */
