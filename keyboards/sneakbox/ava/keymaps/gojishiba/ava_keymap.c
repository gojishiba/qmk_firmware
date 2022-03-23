# keymap.c
static uint8_t top = 1;
static uint8_t left = 1;
static uint8_t right = 1;

void keyboard_pre_init_user(void) {
  setPinOutput(D4);
  setPinOutput(D6);
  setPinOutput(D7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _FN:
    top = 0;
    break;
  case _L3:
    left = 0;
    break;
  case _L4:
    right = 0;
    break;
  default:
    top = 1;
    left = 1;
    right = 1;
    break;
  }

  return state;
}

bool led_update_user(led_t usb_led) {
  writePin(D4, !right);
  writePin(D6, !left);
  writePin(D7, !top);
  return false;
}



// THIS IS WITH CAPS LOCK

static uint8_t left = 1;
static uint8_t right = 1;

void keyboard_pre_init_user(void) {
  setPinOutput(D4);
  setPinOutput(D6);
  setPinOutput(D7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _FN:
    left = 0;
    break;
  case _L3:
    right = 0;
    break;
  case _L4:
    left = 0;
    right = 0;
    break;
  default:
    left = 1;
    right = 1;
    break;
  }

  return state;
}

bool led_update_user(led_t usb_led) {
  writePin(D4, !right);
  writePin(D6, !left);
  writePin(D7, usb_led.caps_lock);
  return false;
}