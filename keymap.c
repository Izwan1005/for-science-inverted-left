
#include QMK_KEYBOARD_H

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

//tap dance enum
enum {
 CT_CLN= 0
 ,G_EXL
 ,J_QUE
 ,NO_AO
 ,NO_AE
 ,NO_OE
 ,NB_S_D
 ,SS_SB
 ,CAP_ESC
};

//macros enum
enum custom_keycodes {
	MACRO00 = SAFE_RANGE, //password office
	MACRO01, // ./administrator
	MACRO02, //personnummer
	MACRO03, //email
	MACRO04, //ANSYS take picture
	MACRO05, //ACROBAT accept comment
	MACRO06, //MS word insert table
	MACRO07, //MS word insert figure
	MACRO08, //MS word insert docx reference
	MACRO09, //UNICODE degree 
	MACRO10, //UNICODE plusminus
	MACRO11, // 
	MACRO12, // 
	MACRO13, // 
	MACRO14, // 
	MACRO15, // 
	ALT_TAB, // Alt tab, cycle window
};

//COMBO enum
enum combos {
  // COMBO_LENGTH,
  BSPC_LSFT_CLEAR,
  QW_CMT,
  NE_HYPHEN,
  EI_UNDSCO,
  IO_DLR,
  LU_SQUO, 
  UY_DQUO,
  YCLN_HASH,
  WIN_LEFT,
  WIN_RGHT,
  OF_HIDE,
  OF_ELEV,
};



//Special key
#define SUB_SCP C(S(KC_EQL)) 	//subscript 
#define SUP_SCP C(KC_EQL)		//superscript
#define NB_SPC C(S(KC_SPC))		//non-breaking space
#define NB_MIN C(S(KC_MINS))	//non-breaking dash

//tap-dance term

//#1 Send : on Single Tap, ; on Double Tap
void dance_cln_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    // register_code (KC_RSFT);
    register_code (KC_SLSH);
  }
}

void dance_cln_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    // unregister_code (KC_RSFT);
    unregister_code (KC_SLSH);
  }
}

//#2 Send ' on Single Tap, " on Double Tap
// void dance_quo_finished (tap_dance_state_t *state, void *user_data) {
  // if (state->count == 1) {
    // register_code (KC_T);
  // } else {
    // register_code (KC_QUOT);
  // }
// }

// void dance_quo_reset (tap_dance_state_t *state, void *user_data) {
  // if (state->count == 1) {
    // unregister_code (KC_T);
  // } else {
    // unregister_code (KC_QUOT);
  // }
// }

//#3 Send / on Single Tap, ? on Double Tap
void dance_JQUE_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_J);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SLSH);
  }
}

void dance_JQUE_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_J);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SLSH);
  }
}

//#4 Send a on Single Tap, ao on Double Tap
void dance_NOR_AO_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LALT);
    register_code (KC_P0);
	register_code (KC_P2);
	register_code (KC_P2);
	register_code (KC_P9);
  } else {
    register_code (KC_LALT);
    register_code (KC_P0);
	register_code (KC_P1);
	register_code (KC_P9);
	register_code (KC_P7);
  }
}

void dance_NOR_AO_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LALT);
    unregister_code (KC_P0);
	unregister_code (KC_P2);
	unregister_code (KC_P2);
	unregister_code (KC_P9);
  } else {
    unregister_code (KC_LALT);
    unregister_code (KC_P0);
	unregister_code (KC_P1);
	unregister_code (KC_P9);
	unregister_code (KC_P7);
  }
}

//#5 Send e on Single Tap, ae on Double Tap
void dance_NOR_AE_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LALT);
    register_code (KC_P0);
    register_code (KC_P2);
    register_code (KC_P3);
    register_code (KC_P0);
  } else {
    register_code (KC_LALT);
    register_code (KC_P0);
    register_code (KC_P1);
    register_code (KC_P9);
    register_code (KC_P8);
  }
}

void dance_NOR_AE_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LALT);
    unregister_code (KC_P0);
    unregister_code (KC_P2);
    unregister_code (KC_P3);
    unregister_code (KC_P0);
  } else {
    unregister_code (KC_LALT);
    unregister_code (KC_P0);
    unregister_code (KC_P1);
    unregister_code (KC_P9);
    unregister_code (KC_P8);
  }
}

//#6 Send o on Single Tap, oe on Double Tap
void dance_NOR_OE_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LALT);
    register_code (KC_P0);
    register_code (KC_P2);
    register_code (KC_P4);
    register_code (KC_P8);
  } else {
    register_code (KC_LALT);
    register_code (KC_P0);
    register_code (KC_P2);
    register_code (KC_P1);
    register_code (KC_P6);
  }
}

void dance_NOR_OE_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LALT);
    unregister_code (KC_P0);
    unregister_code (KC_P2);
    unregister_code (KC_P4);
    unregister_code (KC_P8);
  } else {
    unregister_code (KC_LALT);
    unregister_code (KC_P0);
    unregister_code (KC_P2);
    unregister_code (KC_P1);
    unregister_code (KC_P6);
  }
}

//macros boolean
//SS_TAP() presses and releases a key.
//SS_DOWN() presses (but does not release) a key.
//SS_UP() releases a key.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	
	case MACRO00: // IKM PC password
		if (record->event.pressed) {
		   SEND_STRING(SS_TAP(X_RGHT) SS_DELAY(500) SS_TAP(X_RGHT) "password" SS_TAP(X_ENT)); 
		}
		break;
	
	case MACRO01: // admin password and login
		if (record->event.pressed) {
		   SEND_STRING(SS_TAP(X_RGHT) ".\\administrator" SS_TAP(X_TAB) "my-password" SS_TAP(X_ENT)); 
		}
		break;
	
	case MACRO02: // personnummer
		if (record->event.pressed) {
		   SEND_STRING("01234567890" SS_TAP(X_ENT)); 
		}
		break;	
	
	case MACRO03: // email personal
		if (record->event.pressed) {
		   SEND_STRING("myemail@gmail.com"); 
		}
		break;	
		
	case MACRO04: // save ANSYS image
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(500) 
		   SS_TAP(X_H) SS_DELAY(500) 
		   SS_TAP(X_I) SS_DELAY(500) 
		   SS_TAP(X_I) SS_DELAY(500) 
		   SS_TAP(X_T) SS_DELAY(500) 
		   SS_TAP(X_ENT)); 
		}
		break;	
		
	case MACRO05: // accept acrobat pro comment
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_MS_BTN2) SS_DELAY(300) 
		   SS_TAP(X_DOWN) 
		   SS_TAP(X_DOWN) 
		   SS_TAP(X_DOWN) 
		   SS_TAP(X_RGHT) 
		   SS_TAP(X_DOWN) 
		   SS_TAP(X_ENT) SS_DELAY(300) 
		   SS_TAP(X_DOWN)) ; 
		}
		break;
		
	case MACRO06: // insert table cross ref
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(200) 
		   SS_TAP(X_S) SS_DELAY(50) 
		   SS_TAP(X_R) SS_DELAY(50) 
		   SS_TAP(X_F) SS_DELAY(50) 
		   "tab" 
		   SS_TAP(X_TAB) SS_DELAY(700) 
		   SS_TAP(X_O) SS_DELAY(150) 
		   SS_TAP(X_N) SS_DELAY(150) 
		   SS_TAP(X_TAB)
		   ); 
		}
		break;	
		
	case MACRO07: // insert figure cross ref
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(200) 
		   SS_TAP(X_S) SS_DELAY(50)
		   SS_TAP(X_R) SS_DELAY(50)
		   SS_TAP(X_F) SS_DELAY(50) 
		   "fig" 
		   SS_TAP(X_TAB) SS_DELAY(700) 
		   SS_TAP(X_O) SS_DELAY(150) 
		   SS_TAP(X_N) SS_DELAY(150) 
		   SS_TAP(X_TAB)
		   ); 
		}
		break;	
		
	case MACRO08: // insert docx reference
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(200) 
		   SS_TAP(X_S) SS_DELAY(50)
		   SS_TAP(X_R) SS_DELAY(50)
		   SS_TAP(X_F) SS_DELAY(50)
		   
		   SS_TAP(X_N) SS_DELAY(50) 
		   SS_TAP(X_U) SS_DELAY(50) 
		   SS_TAP(X_M) SS_DELAY(50) 
		   
		   SS_TAP(X_TAB) SS_DELAY(700) 
		   SS_TAP(X_N) SS_DELAY(150) 
		   SS_TAP(X_O) SS_DELAY(150) 
		   SS_TAP(X_DOWN) SS_DELAY(50)
		   SS_TAP(X_DOWN) SS_DELAY(50)
		   SS_TAP(X_TAB) 
		   ); 
		}
		break;
		
	case MACRO09: // degree sign
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_DOWN(X_LALT)
		   SS_TAP(X_P0) 
		   SS_TAP(X_P1) 
		   SS_TAP(X_P7) 
		   SS_TAP(X_P6) 
		   SS_UP(X_LALT)
		   ); 
		}
		break;	
		
	case MACRO10: // insert caption
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(100)
		   SS_TAP(X_S) SS_DELAY(100)
		   SS_TAP(X_P) SS_DELAY(100)
		   ); 
		}
		break;	
		
	case MACRO11: // insert link
		if (record->event.pressed) {
		   SEND_STRING(		   
		   SS_TAP(X_LALT) SS_DELAY(200) 
		   SS_TAP(X_N) SS_DELAY(50) 
		   SS_TAP(X_I) SS_DELAY(50) 
		   SS_TAP(X_I) 
		   
		   ); 
		}
		break;	
		
	case MACRO12: // plus minus sign 
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_DOWN(X_LALT)
		   SS_TAP(X_P0) 
		   SS_TAP(X_P1) 
		   SS_TAP(X_P7) 
		   SS_TAP(X_P7) 
		   SS_UP(X_LALT)
		   );  
		}
		break;	
		
	case MACRO13: // insert highlight
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(200) 
		   SS_TAP(X_H) SS_DELAY(50) 
		   SS_TAP(X_I) SS_DELAY(50) 
		   SS_TAP(X_ENT) 
		   ); 
		}
		break;	
		
	case MACRO14: // new TXT file in Explorer
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_MS_BTN2) SS_DELAY(150) 
		   SS_TAP(X_W) 
		   SS_TAP(X_T) 
		   
		   );
		}
		break;	
		
	case MACRO15: // 
		if (record->event.pressed) {
		   SEND_STRING(
		   SS_TAP(X_LALT) SS_DELAY(200) 
		   SS_TAP(X_H) SS_DELAY(50) 
		   SS_TAP(X_I) SS_DELAY(50) 
		   SS_TAP(X_ENT) 
		   );
		}
		break;		
	
	case ALT_TAB:
		if (record->event.pressed) {
			if (!is_alt_tab_active) {
			  is_alt_tab_active = true;
			  register_code(KC_LALT);
			}
			alt_tab_timer = timer_read();
			register_code(KC_TAB);
		  } else {
			unregister_code(KC_TAB);
		}
		break;
	
    }
    return true;
};

void matrix_scan_user(void) { // The very important timer for ALT+TAB feature.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

//All tap dance functions would go here. f
tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN] 		= ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
 ,[G_EXL] 		= ACTION_TAP_DANCE_DOUBLE(KC_G, KC_EXLM) // tap once for G, twice for !
 ,[J_QUE] 		= ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_JQUE_finished, dance_JQUE_reset) // tap once for J, twice for ?"
 ,[NO_AO] 		= ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_NOR_AO_finished, dance_NOR_AO_reset) // tap once for a, twice for ao"
 ,[NO_AE]      = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_NOR_AE_finished, dance_NOR_AE_reset) // tap once for e, twice for ae"
 ,[NO_OE]      = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_NOR_OE_finished, dance_NOR_OE_reset) // tap once for o, twice for oe"
 ,[NB_S_D]		= ACTION_TAP_DANCE_DOUBLE(C(S(KC_SPC)), C(S(KC_MINS))) //tap once for NB_space, twice for NB_dash 
 ,[SS_SB]		= ACTION_TAP_DANCE_DOUBLE(C(S(KC_EQL)), C(KC_EQL)) //tap once for subscript, twice for superscript 
 ,[CAP_ESC]		= ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS) //tap once for ESC, twice for CAPSLOCK 
};

//All combos below
// uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
const uint16_t PROGMEM clear_line_combo[]   	= {LCTL_T(KC_ENT), LT(1,KC_BSPC), COMBO_END};
const uint16_t PROGMEM comment_npp[]   			= {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM NE_dash_hyphen[]   		= {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM EI_underscore[]   		= {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM IO_dollar[]   			= {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM LU_singlequot[]   		= {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM UY_dobbelquot[]   		= {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM YCLN_hashtag[]   		= {KC_Y, TD(CT_CLN), COMBO_END};
const uint16_t PROGMEM DESKTOP_left[]   		= {KC_LEFT, KC_UP, COMBO_END};
const uint16_t PROGMEM DESKTOP_right[]   		= {KC_RGHT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM ORCAFLEX_elevation[]   	= {KC_P, TD(G_EXL), COMBO_END};
const uint16_t PROGMEM ORCAFLEX_hide[]   		= {KC_V, LCA_T(KC_B), COMBO_END};

combo_t key_combos[] = {
  [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
  [QW_CMT] 			= COMBO(comment_npp, C(KC_Q)),
  [NE_HYPHEN] 		= COMBO(NE_dash_hyphen, KC_MINS),
  [EI_UNDSCO] 		= COMBO(EI_underscore, S(KC_MINS)),
  [IO_DLR] 			= COMBO(IO_dollar, KC_DLR),
  [LU_SQUO] 		= COMBO(LU_singlequot, KC_QUOT),
  [UY_DQUO] 		= COMBO(UY_dobbelquot, KC_DQUO),
  [YCLN_HASH] 		= COMBO(YCLN_hashtag, KC_HASH),
  [WIN_LEFT] 		= COMBO(DESKTOP_left, C(G(KC_LEFT))),
  [WIN_RGHT] 		= COMBO(DESKTOP_right, C(G(KC_RGHT))),
  [OF_HIDE] 		= COMBO(ORCAFLEX_hide, C(KC_H)),
  [OF_ELEV] 		= COMBO(ORCAFLEX_elevation, C(KC_E)),
};

// define advance combo for COMBO_ACTION
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {

    case BSPC_LSFT_CLEAR:
      if (pressed) {
        tap_code16(KC_END);
        tap_code16(S(KC_HOME));
        tap_code16(KC_BSPC);
      }
      break;
/*	  
	case QW_CMT:
      if (pressed) {
        tap_code16(C(KC_Q));
      }
      break;  

    case PRN_LEFT:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_LEFT);
      }
      break;

    case SB_LEFT:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
        tap_code16(KC_LEFT);
      }
      break;

    case CB_LEFT:
      if (pressed) {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_LEFT);
      }
      break;

    case Z_CUT:
      if (pressed) {
        tap_code16(C(KC_X));
      }
      break;

    case Z_COPY:
      if (pressed) {
        tap_code16(C(KC_C));
      }
      break;

    case Z_PASTE:
      if (pressed) {
        tap_code16(C(KC_V));
      }
      break;

    case V_DELETE:
      if (pressed) {
        tap_code16(KC_DEL);
      }
      break;

    case XC_UNDO:
      if (pressed) {
        tap_code16(C(KC_Z));
      }
      break;
*/
  }
}


// BASE5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_4x5_3(                                                         
    KC_ESC, 	KC_W, 		KC_F, 		KC_P, 			TD(G_EXL), 					TD(J_QUE), 		KC_L, 		KC_U, 			KC_Y, 		KC_SLSH, 
	KC_Q, 		LT(3,KC_R), LT(4,KC_S), LT(5,KC_T), 	LGUI_T(KC_D),				KC_H, 			KC_N, 		KC_E, 			KC_I, 		TD(CT_CLN),
	LT(2,KC_A),	KC_X, 		KC_C, 		KC_V, 			LCA_T(KC_B),  				KC_K, 			KC_M, 		KC_COMM, 		KC_DOT, 	KC_O,
	LSFT_T(KC_Z),KC_LALT, 	KC_HOME, 	KC_END, 		KC_DEL, 					TD(2), 			KC_LEFT, 	KC_UP,			KC_DOWN, 	KC_RGHT, 
							KC_TAB, 	LCTL_T(KC_ENT), LT(1,KC_BSPC), 				RSFT_T(KC_SPC), KC_ENT, 	RCTL_T(KC_ESC)			
  ),
// MACRO
  [1] = LAYOUT_split_4x5_3(
    KC_CAPS,	KC_F9, 		MACRO10, 	MACRO06,		MACRO02, 					LSFT(KC_END), 	KC_NO, 		KC_NO, 			KC_APP, 	KC_DEL, 
	LCTL(KC_H), MACRO05,	MACRO13, 	MACRO07,		MACRO00, 					RCS(KC_LEFT), 	KC_NO, 		TD(NO_AE), 		KC_NO, 		KC_NO, 
	TD(NO_AO),	KC_NO, 		MACRO11, 	MACRO08,		MACRO01, 					LSFT(KC_LEFT), 	TD(SS_SB), 	KC_BTN2, 		KC_NO, 		TD(NO_OE), 	
	LSFT(KC_F3),KC_NO, 		KC_NO, 		MACRO14,		MACRO03, 					KC_NO, 			KC_NO, 		KC_NO, 			KC_NO, 		KC_NO, 
							KC_NO, 		KC_NO, 			KC_TRNS, 					TD(NB_S_D), 	KC_TAB, 	KC_NO		  
  ),
// NUMBERS
  [2] = LAYOUT_split_4x5_3(
    KC_NO, 		LCTL(KC_5), KC_UP, 		KC_NO, 			KC_NO, 						KC_PPLS, 		KC_P1, 		KC_P2, 			KC_P3, 		KC_EQL, 
	KC_ESC, 	KC_LEFT, 	KC_DOWN, 	KC_RGHT, 		KC_VOLU, 					KC_PMNS, 		KC_P4, 		KC_P5, 			KC_P6, 		KC_PAST, 
	KC_TRNS, 	KC_MPRV, 	KC_MPLY, 	KC_MNXT, 		KC_VOLD, 					KC_DOT, 		KC_P7, 		KC_P8, 			KC_P9, 		KC_PSLS, 
	KC_NUM, 	KC_LALT, 	KC_MPLY, 	KC_NO, 			KC_NO, 						KC_TRNS, 		KC_DLR,	 	KC_F2, 			KC_LPRN, 	KC_RPRN, 
							KC_TAB, 	LCTL_T(KC_ENT), KC_BSPC, 					KC_P0, 			KC_ENT, 	KC_ESC
  ),			
// ADDITIONAL			
  [3] = LAYOUT_split_4x5_3(			
    KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 		KC_TRNS, 					KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 
	KC_TRNS, 	KC_TRNS, 	KC_DEL, 	KC_TRNS, 		KC_TRNS, 					KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 
	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 		KC_TRNS, 					KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 
	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 		KC_TRNS, 					KC_TRNS, 		KC_TRNS, 	KC_TRNS, 		KC_TRNS, 	KC_TRNS, 
							KC_TRNS, 	KC_TRNS, 		KC_TRNS, 					KC_TRNS, 		KC_TRNS, 	KC_TRNS
  ),
  
// SYMBOLS
  [4] = LAYOUT_split_4x5_3(
    KC_NO, 		KC_NO, 		KC_NO, 		KC_HASH, 		KC_MINS, 					MACRO09, 		KC_LBRC, 	KC_RBRC, 		KC_AMPR, 	KC_BSLS, 
	KC_NO,		SGUI(KC_S), KC_TRNS, 	KC_QUOT, 		LSFT(KC_MINS), 				MACRO12, 		KC_LPRN, 	KC_RPRN, 		KC_DLR, 	KC_CIRC,
	KC_EQL, 	KC_NO, 		KC_NO, 		KC_DQUO, 		KC_TILD, 					KC_NO, 			KC_LCBR, 	KC_RCBR, 		KC_PERC, 	KC_AT,  
	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 			KC_NO, 						KC_NO, 			KC_PPLS, 	KC_PMNS, 		KC_PAST, 	KC_NO, 
							KC_NO, 		KC_EXLM, 		KC_SPC, 					LSFT_T(KC_PEQL),KC_QUES, 	KC_NO
  ),
 // FUNCTIONS
  [5] = LAYOUT_split_4x5_3(
    KC_NO,		KC_NO, 		  KC_F2, 	KC_NO, 			RCS(KC_8), 					KC_NO, 			KC_NO, 		KC_F1, 			KC_F5, 		KC_F9, 
	LCA(KC_DEL),LGUI(KC_TAB), KC_TAB, 	KC_NO, 			KC_NO, 						KC_NO, 			KC_NO, 		KC_F2, 			KC_F6, 		KC_F10, 
	ALT_TAB, 	KC_NO, 		  KC_NO, 	KC_NO, 			KC_NO, 						KC_NO, 			KC_NO, 		KC_F3, 			KC_F7, 		KC_F11, 
	RCS(KC_N), 	KC_LALT, 	  KC_NO, 	KC_NO, 			KC_NO, 						KC_NO, 			KC_NO, 		KC_F4, 			KC_F8, 		KC_F12, 
				KC_NO, 		  KC_LCTL, 	LCTL(KC_BSPC), 	KC_NO, 						KC_RSFT, 		KC_RCTL
  ),
};
