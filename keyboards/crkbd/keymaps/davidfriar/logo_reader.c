#include "crkbd.h"
#include QMK_KEYBOARD_H
#include <stdio.h>

const char *read_logo(void) {
  static char logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x80,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0x80,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0x80,
      0};

  return logo;
}

const char *read_querty(void) {
  static char logo[] = "\
\x94\x95\x96\x97  QWERT YUIOP\n\
\xb4\xb5\xb6\xb7  ASDFG HJKL;'\n\
\xd4\xd5\xd6\xd7  ZXCVB NM,./";

  return logo;
}

const char *read_num(void) {
  static char logo[] = "\
\x98\x99\x9A\x9B  12345 67890\n\
\xb8\xb9\xbA\xbB  HDUE  \x1B\x19\x18\x1A\n\
\xd8\xd9\xdA\xdB  \x11 F1-F10 \x10";

  return logo;
}

const char *read_sym(void) {
  static char logo[] = "\
\x9C\x9D\x9E\x9F  !@#$% ^&*()\n\
\xbC\xbD\xbE\xbF      ~ -+|{}\n\
\xdC\xdD\xdE\xdF      ` _=\\[]";

  return logo;
}

extern rgblight_config_t rgblight_config;
char settings_info_str[56];
const char *read_settings(void) {
  snprintf(settings_info_str, sizeof(settings_info_str),
    "\
\x01\x02\x03\x04  RGB:%3d\n\
\x05\x06\x07\x08  HUE:%3d\n\
\x0B\x0C\x0D\x0E  SAT:%3d\n\
      VAL:%3d",
    rgblight_config.enable ? rgblight_config.mode : 0,
    rgblight_config.hue,
    rgblight_config.sat,
    rgblight_config.val);

  return settings_info_str;
}
