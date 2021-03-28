# RGBLIGHT_ENABLE = no
# RGB_MATRIX_ENABLE = WS2812


# If you want to change the display of OLED, you need to change here
SRC +=  ./keymaps/davidfriar/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./keymaps/davidfriar/layer_state_reader.c \
				./keymaps/davidfriar/logo_reader.c \
        ./keymaps/davidfriar/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
