

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0045
#define PRODUCT_ID      0x4500
#define DEVICE_VER      0x0000
#define MANUFACTURER    David Friar
#define PRODUCT         thefortyfive
#define DESCRIPTION     q.m.k. keyboard firmware for thefortyfive

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 2


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Set power consumption to work with mobile devices */
/* #define USB_MAX_POWER_CONSUMPTION 100 */

/* key matrix pins */
#define MATRIX_ROW_PINS { F5, F4}
#define MATRIX_COL_PINS { F7, F6}


