/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_french.h"
#include "keymap_bepo.h"

enum layers {
    BEPO__,     // default layer for bépo layouts
    LAYERS,     // To chose the layer to switch to
    SYMBOL,     // Layer with symbols
    MEDIA_,     // media keys
    B2AZER,     // bépo layout for azerty keyboards
    COLORS,     // Manage the colors of the keyboards
    TERM__,     // Shortcuts to manage the terminal
    VIM___,     // Shortcuts for vim

    __LAYER_END__,  // keep it at the end
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_MAROON,
    COLOR_YELLOW,
    MC_VIM_P_TAB,
    MC_VIM_N_TAB,
    MC_VIM_SAVE,
    MC_VIM_SV_QT,
    MC_VIM_QUIT,
};

// Tap Dance declarations
enum {
    TD_SHF_ALT,
    __TD_END__,  // keep it at the end
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;


/****************************************
 * KEY MAPPING
 ***************************************/

// make the transparent key macro longer
#define ____________ KC_TRNS
// key mapping
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BEPO__] = LAYOUT_moonlander(
    LT(SYMBOL, BP_DLR) , BP_DQOT, BP_LGIL      , BP_RGIL      , BP_LPRN      , BP_RPRN      , KC_HOME               ,          KC_PGUP      , BP_AT        , BP_PLUS      , BP_MINS      , BP_SLSH      , BP_ASTR      , BP_EQL       ,
    KC_TAB       , BP_B         , BP_ECUT      , BP_P         , BP_O         , BP_EGRV      , KC_END                ,          KC_PGDOWN    , BP_DCRC      , BP_V         , BP_D         , BP_L         , BP_J         , BP_Z         ,
    BP_W         , BP_A         , BP_U         , BP_I         , BP_E         , BP_COMM      , KC_INSERT             ,          ____________ , BP_C         , BP_T         , BP_S         , BP_R         , BP_N         , BP_M         ,
    KC_LSHIFT    , BP_AGRV      , BP_Y         , BP_X         , BP_DOT       , BP_K                                                         , BP_APOS      , BP_Q         , BP_G         , BP_H         , BP_F         , BP_CCED      ,
    KC_LCTRL     , MO(1)        , KC_RCTRL     , KC_LGUI      , KC_MEH       ,                MO(6)                 ,          KC_BSPACE                   , KC_LEFT      , KC_DOWN      , KC_UP        , KC_RIGHT     , BP_PERC      ,
                                                                KC_SPACE     , KC_LALT      , LCTL_T(KC_ESCAPE)     ,          MO(7)        , RALT_T(KC_ENTER) , TD(TD_SHF_ALT)
  ),
  [LAYERS] = LAYOUT_moonlander(
    ____________ , TO(0)        , TO(2)        , TO(3)        , TO(4)        , TO(5)        , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    WEBUSB_PAIR  , ____________ , ____________ , ____________ , ____________ , ____________                                                 , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
  [SYMBOL] = LAYOUT_moonlander(
    KC_ESCAPE    , KC_F1        , KC_F2        , KC_F3        , KC_F4        , KC_F5        , KC_HOME               ,          KC_PGUP      , KC_F6        , KC_F7        , KC_F8        , KC_F9        , KC_F10       , KC_F11       ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , KC_END                ,          KC_PGDOWN    , KC_UP        , KC_KP_7      , KC_KP_8      , KC_KP_9      , KC_KP_PLUS   , KC_F12       ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , KC_INSERT             ,          KC_DELETE    , KC_DOWN      , KC_KP_4      , KC_KP_5      , KC_KP_6      , KC_KP_MINUS  , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , KC_KP_1      , KC_KP_2      , KC_KP_3    , KC_KP_ASTERISK , ____________ ,
    ____________ , TO(0)        , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , KC_KP_0      , KC_KP_DOT    , KC_KP_EQUAL  , KC_KP_SLASH  , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
  [MEDIA_] = LAYOUT_moonlander(
    AU_TOG       , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , RESET        ,
    MU_TOG       , ____________ , ____________ , KC_MS_UP     , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    MU_MOD       , ____________ , KC_MS_LEFT   , KC_MS_DOWN   , KC_MS_RIGHT  , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , KC_MEDIA_PLAY_PAUSE ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , ____________ , ____________ ,
    ____________ , TO(0)        , ____________ , ____________ , ____________ ,                ____________          ,          ____________             , KC_AUDIO_VOL_UP , KC_AUDIO_VOL_DOWN , KC_AUDIO_MUTE , ____________ , ____________ ,
                                                                KC_MS_BTN1   , KC_MS_BTN3   , KC_MS_BTN2            ,          ____________ , ____________ , KC_WWW_BACK
  ),
  [B2AZER] = LAYOUT_moonlander(
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , KC_B         , FR_EACU      , KC_P         , KC_O         , FR_EGRV      , ____________          ,          ____________ , FR_CCIRC     , KC_V         , KC_D         , KC_L         , KC_J         , FR_Z         ,
    FR_W         , FR_A         , KC_U         , KC_I         , KC_E         , FR_COMM      , ____________          ,          ____________ , KC_C         , KC_T         , KC_S         , KC_R         , KC_N         , FR_M         ,
    ____________ , FR_AGRV      , KC_Y         , KC_X         , FR_DOT       , KC_K         ,                                                 FR_APOS      , FR_Q         , KC_G         , KC_H         , KC_F         , FR_CCED      ,
    ____________ , TO(0)        , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
  [COLORS] = LAYOUT_moonlander(
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , RGB_SAI      , RGB_VAI      , RGB_HUI      , RGB_SPI      , ____________ , ____________ ,
    ____________ , COLOR_BLUE   , COLOR_GREEN  , COLOR_YELLOW , COLOR_MAROON , COLOR_RED    , ____________          ,          ____________ , RGB_SAD      , RGB_VAD      , RGB_HUD      , RGB_SPD      , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , TO(0)        , ____________ , ____________ , ____________ ,                RGB_MOD               ,          RGB_TOG                     , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                RGB_SLD      , TOGGLE_LAYER_COLOR , ____________    ,          ____________ , ____________ , ____________
  ),
  [TERM__] = LAYOUT_moonlander(
    ____________ , LALT(KC_1)   , LALT(KC_2)   , LALT(KC_3)   , LALT(KC_4)   , LALT(KC_5)   , ____________          ,         LSFT(KC_PGUP) , LALT(KC_6)   , LALT(KC_7)   , LALT(KC_8)   , LALT(KC_9)   , LALT(KC_0)   , ____________ ,
    ____________ , LALT(FR_A)   , LALT(FR_Z)   , LALT(KC_E)   , LALT(KC_R)   , ____________ , ____________          ,       LSFT(KC_PGDOWN) , LCTL(LSFT(BP_C)) , LCTL(LSFT(BP_V)) , ____________ , ____________ , ____________ , ____________ ,
    ____________ , LALT(FR_Q)   , LALT(KC_S)   , LALT(KC_D)   , LALT(KC_F)   , ____________ , LSFT(KC_INSERT)       ,          ____________ , LALT(KC_H)   , LALT(KC_J)   , LALT(KC_K)   , LALT(KC_L)   , LALT(FR_M)   , ____________ ,
    ____________ , ____________ , LALT(KC_X)   , LALT(KC_C)   , LALT(KC_V)   , ____________ ,                                                 ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                              LALT(KC_SPACE) , ____________ , ____________          ,          ____________ , LALT(KC_ENTER) , ____________
  ),
  [VIM___] = LAYOUT_moonlander(
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , MC_VIM_P_TAB , MC_VIM_N_TAB , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    MC_VIM_SAVE  , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , MC_VIM_SV_QT , ____________ , ____________ ,                                                 ____________ , MC_VIM_QUIT  , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                KC_SPACE     , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
/*
 * Add the following line for new layers
 *
  [L_NAME] = LAYOUT_moonlander(
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
 */
};
// undefine transparency
#undef ____________



/****************************************
 * COLOR MAPPING
 ***************************************/

/*
 * The following mapping is to be used to defined the colors of the keys
 *
 * It is advised to define colors as C preprecessor constants.
 * The following constants may also be used: C_TRANS. It is used to define
 * a transparent color and use the color of below layers (like for keys).
 *
 * NOTE: C_TRANS actually use a valid color which cannot then be used. Feel
 * free to modify it if you need that color in your mapping.
 */
#define C_TRANS_R 1
#define C_TRANS_G 1
#define C_TRANS_B 1
#define C_TRANS {C_TRANS_R, C_TRANS_G, C_TRANS_B}

#define COL_LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
) \
{ \
    k00, k10, k20, k30, k40, \
    k01, k11, k21, k31, k41, \
    k02, k12, k22, k32, k42, \
    k03, k13, k23, k33, k43, \
    k04, k14, k24, k34, k44, \
    k05, k15, k25, k35, \
    k06, k16, k26, \
    k50, k51, k52, k53, \
    \
    k66, k76, k86, k96, ka6, \
    k65, k75, k85, k95, ka5, \
    k64, k74, k84, k94, ka4, \
    k63, k73, k83, k93, ka3, \
    k62, k72, k82, k92, ka2, \
    k61, k71, k81, k91, \
    k60, k70, k80, \
    kb6, kb5, kb4, kb3, \
    \
}

#define MAP_ALL_KEYS(col)  { col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col, col }

#define C_LIGHT_RED  {239, 162, 161}
#define C_RED  {255, 51, 50}
#define C_INTENSE_RED  {255, 0, 0}

#define C_LIGHT_BLUE  {88, 147, 218}
#define C_BLUE  {30, 157, 255}
#define C_INTENSE_BLUE  {12, 0, 255}

#define C_LIGHT_GREEN  {204, 255, 153}
#define C_GREEN  {102, 204, 0}
#define C_INTENSE_GREEN  {0, 64, 1}

#define C_LIGHT_YELLOW  {255, 255, 153}
#define C_YELLOW  {214, 161, 0}
#define C_INTENSE_YELLOW  {255, 162, 0}

#define C_LIGHT_PURPLE  {134, 138, 255}
#define C_PURPLE  {127, 0, 255}
#define C_INTENSE_PURPLE  {64, 0, 60}

#define C_LIGHT_ORANGE  {255, 204, 153}
#define C_ORANGE  {227, 84, 26}
#define C_INTENSE_ORANGE  {255, 128, 0}
#define C_BROWN  {149, 86, 51}

// make the transparent color macro for colors
#define ____________ C_TRANS
// Color key mapping
const uint8_t PROGMEM ledmap[__LAYER_END__][DRIVER_LED_TOTAL][3] = {
  [BEPO__] = MAP_ALL_KEYS(C_LIGHT_RED),
  [LAYERS] = COL_LAYOUT_moonlander(
    ____________ , C_LIGHT_RED  , C_GREEN      , C_BLUE       , C_LIGHT_BLUE , C_ORANGE     , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    C_BROWN      , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
  [SYMBOL] = COL_LAYOUT_moonlander(
    ____________ , C_RED        , C_RED        , C_RED        , C_RED        , C_RED        , C_GREEN               ,           C_GREEN     , C_RED        , C_RED        , C_RED        , C_RED        , C_RED        , C_RED        ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , C_GREEN               ,           C_GREEN     , ____________ , C_YELLOW     , C_YELLOW     , C_YELLOW     , C_LIGHT_PURPLE , C_RED        ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , C_GREEN               ,           C_GREEN     , ____________ , C_YELLOW     , C_YELLOW     , C_YELLOW     , C_LIGHT_PURPLE , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , C_YELLOW     , C_YELLOW     , C_YELLOW     , C_LIGHT_PURPLE , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , C_YELLOW     , C_LIGHT_PURPLE , C_LIGHT_PURPLE , C_LIGHT_PURPLE , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
  [MEDIA_] = COL_LAYOUT_moonlander(
    C_BLUE       , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , C_LIGHT_PURPLE,
    C_BLUE       , ____________ , ____________ , C_YELLOW     , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    C_BLUE       , ____________ , C_YELLOW     , C_YELLOW     , C_YELLOW     , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , C_RED        ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , C_RED        , C_RED        , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , C_ORANGE     , C_ORANGE     , C_ORANGE     , ____________ , ____________ ,
                                                                C_YELLOW     , C_YELLOW     , C_YELLOW              ,          ____________ , ____________ , ____________
  ),
  [B2AZER] = MAP_ALL_KEYS(C_LIGHT_BLUE),
  [COLORS] = COL_LAYOUT_moonlander(
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , C_LIGHT_PURPLE , C_LIGHT_PURPLE , C_LIGHT_PURPLE , C_LIGHT_PURPLE , ____________ , ____________ ,
    ____________ , C_INTENSE_BLUE , C_INTENSE_GREEN , C_INTENSE_YELLOW , C_INTENSE_PURPLE , C_INTENSE_RED , ____________          ,          ____________ , C_LIGHT_PURPLE , C_LIGHT_PURPLE , C_LIGHT_PURPLE , C_LIGHT_PURPLE , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                C_ORANGE              ,           C_ORANGE                   , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                C_ORANGE     , C_ORANGE     , ____________          ,          ____________ , ____________ , ____________
  ),
  [TERM__] = MAP_ALL_KEYS(C_TRANS),
  [VIM___] = MAP_ALL_KEYS(C_TRANS),
/*
 * Add the following line for new layers
 *
  [L_NAME] = COL_LAYOUT_moonlander(
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,                                                 ____________ , ____________ , ____________ , ____________ , ____________ , ____________ ,
    ____________ , ____________ , ____________ , ____________ , ____________ ,                ____________          ,          ____________                , ____________ , ____________ , ____________ , ____________ , ____________ ,
                                                                ____________ , ____________ , ____________          ,          ____________ , ____________ , ____________
  ),
 */
};
// undefine transparency
#undef ____________

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

RGB get_key_color(int layer, int key) {
    // handle inactive layers
    if (IS_LAYER_OFF_STATE(layer_state, layer)) {
        if (layer > 0) {
            return get_key_color(layer - 1, key);
        } else {
            // default to no color
            return (RGB) {
                .r = 0,
                .g = 0,
                .b = 0,
            };
        }
    }
    // read the active layer colors
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][key][0]),
      .g = pgm_read_byte(&ledmap[layer][key][1]),
      .b = pgm_read_byte(&ledmap[layer][key][2]),
    };
    if (rgb.r == C_TRANS_R && rgb.g == C_TRANS_G && rgb.b == C_TRANS_B) {
        if (layer > 0) {
            return get_key_color(layer - 1, key);
        } else {
            // default to no color
            return (RGB) {
                .r = 0,
                .g = 0,
                .b = 0,
            };
        }
    }
    return rgb;
}

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
      // find the color for the current key and layer
      RGB rgb = get_key_color(layer, i);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

    uint8_t layer = biton32(layer_state);
    // for layers (it should always be the case, use the color defined in
    // the mapping
    if (layer < __LAYER_END__) {
        set_layer_color(layer);
    } else {
        // else set it to black if led are not enabled
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
            rgb_matrix_set_color_all(0, 0, 0);
    }
}



/****************************************
 * CUSTOM KEYS
 ***************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_VIM_P_TAB:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_TAP(X_COMMA) SS_DELAY(100) SS_TAP(X_Q));

    }
    break;
    case MC_VIM_N_TAB:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_TAP(X_COMMA) SS_DELAY(100) SS_TAP(X_W));

    }
    break;
    case MC_VIM_SAVE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_RBRACKET)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case MC_VIM_SV_QT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_C)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case MC_VIM_QUIT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_M) SS_DELAY(100) SS_TAP(X_A)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case COLOR_BLUE:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case COLOR_GREEN:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case COLOR_YELLOW:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
    case COLOR_MAROON:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,128);
      }
      return false;
    case COLOR_RED:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
  }
  return true;
}


/****************************************
 * TAP DANCE
 ***************************************/

// adaptation of the code from QMK doc
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

static td_tap_t dance_state[__TD_END__];


/*
 * The following macros can be used to have Tap Dance to:
 * - hold mod1 on first press and hold (permissive hold)
 * - hold mod2 on second press and hold (permissive hold)
 * - hold mod3 on third press and hold (permissive hold)
 *
 * Usage:
 *   TD_MOD(TD_KEY_NAME, MOD(mod1), MOD(mod2), MOD(mod3))
 *   TD_MOD2(TD_KEY_NAME, mod1, mod2) --> same as TD_MOD but for 2 mods only
 *   MOD(mod) --> create the modifier for TD_MODE
 *   MOD2(mod1, mod2)  --> same as MOD, but sending 2 modifiers
 *   MOD3(mod1, mod2, mod3)  --> same as MOD, but sending 3 modifiers
 *   TD_MOD_REF(TD_KEY_NAME)
 *
 */
#define _TD_MOD(name, reg_mod1, unreg_mod1, reg_mod2, unreg_mod2, reg_mod3, unreg_mod3)  \
void x_tap_##name(qk_tap_dance_state_t *state, void *user_data) { \
    switch (state->count) { \
        case 1: \
            reg_mod1; \
            dance_state[name].state = TD_SINGLE_HOLD; \
            break; \
        case 2: \
            unreg_mod1; \
            reg_mod2; \
            dance_state[name].state = TD_DOUBLE_HOLD; \
            break; \
        case 3: \
        default: \
            unreg_mod2; \
            reg_mod3; \
            dance_state[name].state = TD_TRIPLE_HOLD; \
            break; \
    } \
} \
void x_reset_##name(qk_tap_dance_state_t *state, void *user_data) { \
    switch (dance_state[name].state) { \
        case TD_SINGLE_HOLD: unreg_mod1; break; \
        case TD_DOUBLE_HOLD: unreg_mod2; break; \
        case TD_TRIPLE_HOLD: unreg_mod3; break; \
        default: break; \
    } \
    dance_state[name].state = TD_NONE; \
}
#define TD_MOD(...)  _TD_MOD(__VA_ARGS__)
#define _TD_MOD2(name, r1, u1, r2, u2)  TD_MOD(name, r1, u1, r2, u2, r2, u2)
#define TD_MOD2(...)  _TD_MOD2(__VA_ARGS__)
#define MOD(mod) { register_code(KC_##mod); }, { unregister_code(KC_##mod); }
#define MOD2(mod1, mod2) { register_code(KC_##mod1); register_code(KC_##mod2); }, { unregister_code(KC_##mod1); unregister_code(KC_##mod2); }
#define MOD3(mod1, mod2, mod3) { register_code(KC_##mod1); register_code(KC_##mod2); register_code(KC_##mod3); }, { unregister_code(KC_##mod1); unregister_code(KC_##mod2); unregister_code(KC_##mod3); }
#define TD_MOD_REF(name) ACTION_TAP_DANCE_FN_ADVANCED(x_tap_##name, NULL, x_reset_##name)

TD_MOD2(TD_SHF_ALT, MOD(RSFT), MOD2(RSFT, RALT))

qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_SHF_ALT] = TD_MOD_REF(TD_SHF_ALT),
};
