uint32_t since_press = 0; // Tracks how long since last button press
bool was_pressed = false; // Tracks if the button was pressed in previous frame

void handle_button()
{
  bool pressed = digitalRead(PIN_BUTTON) == HIGH; // Button is pressed when pin is low
  bool changed = pressed != was_pressed;          // If pressed state has changed, we might need to act
  Serial.println(since_press);
  if (state == "modes")
  {
    modes(pressed, changed);
  }
  else if (state == "state_select")
  {
    state_select(pressed, changed);
  }
  else if (state == "party_modes")
  {
    party_modes(pressed, changed);
  }
  else if (state == "colors")
  {
    colors(pressed, changed);
  }
  else if (state == "all_modes")
  {
    all_modes(pressed, changed);
  }
  else if (state == "enter_sleep")
  {
    enter_sleep(pressed, changed);
  }
  since_press += 20;
  if (changed)
    since_press = 0;     // If state changed we need to reset since_press
  was_pressed = pressed; // Update was_pressed to this frame's button status
}

void state_select(bool pressed, bool changed)
{
  if (pressed)
  {
    if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      Serial.println("Next Color");
      nextState();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {
      update_state();
    }
    else
    {
    }
  }
}

void modes(bool pressed, bool changed)
{
  if (pressed)
  {
    flash_menus();
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      state = "modes";
      Serial.println("Next pattern");
      nextMode();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {

      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "enter_sleep";
      last_state = "modes";
      EEPROM.write(0, 3);
    }
    else if (since_press < 3000 && since_press > 2000)
    {
      state = "modes";
      decide_autoplay();
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "state_select";
      EEPROM.write(0, 1);
    }
    else
    {
    }
  }
}
void party_modes(bool pressed, bool changed)
{
  if (pressed)
  {
    flash_menus();
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      state = "party_modes";
      Serial.println("Next Party Mode");
      nextPartyMode();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {

      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "enter_sleep";
      last_state = "party_modes";
      EEPROM.write(0, 2);
    }
    else if (since_press < 3000 && since_press > 2000)
    {
      state = "party_modes";
      decide_random_interval();
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "state_select";
      EEPROM.write(0, 1);
    }
    else
    {
    }
  }
}
void all_modes(bool pressed, bool changed)
{
  if (pressed)
  {
    flash_menus();
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      state = "all_modes";
      Serial.println("Next All Mode");
      nextAllMode();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {

      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "enter_sleep";
      last_state = "all_modes";
      EEPROM.write(0, 2);
    }
    else if (since_press < 3000 && since_press > 2000)
    {
      state = "all_modes";
      decide_autoplay();
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "state_select";
      EEPROM.write(0, 1);
    }
    else
    {
    }
  }
}
void colors(bool pressed, bool changed)
{
  if (pressed)
  {
    if (since_press == 500)
    {
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      // state = "menu";
    }
    else if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      state = "colors";
      Serial.println("Next Color");
      nextHue();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {

      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "enter_sleep";
      last_state = "colors";
      EEPROM.write(0, 2);
    }
    else if (since_press < 3000 && since_press > 2000)
    {
      state = "state_select";
      EEPROM.write(0, 1);
    }
    // else if (since_press < 4000 && since_press > 3000)
    // {
    //   state = "state_select";
    //   EEPROM.write(0, 1);
    // }
    else
    { // if more than 4s, lock light
    }
  }
}

void enter_sleep(bool pressed, bool changed)
{
  if (pressed)
  {
    if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 0);
    }
  }
  else if (changed)
  {
    if (since_press < 2000 && since_press > 1000)
    {
      Serial.println("Change States");
      state = last_state;
      EEPROM.write(0, 0);
    }
    else
    { // if more than 4s, lock light
    }
  }
}

void update_state()
{
  EEPROM.write(0, gCurrentStateNumber);
  if (gCurrentStateNumber == 0)
  {
    state = "modes";
  }
  else if (gCurrentStateNumber == 1)
  {
    state = "party_modes";
  }
  else if (gCurrentStateNumber == 2)
  {
    state = "colors";
  }
  else if (gCurrentStateNumber == 3)
  {
    state = "all_modes";
  }
}

void flash_menus()
{
  if (since_press == 500)
  {
    fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    FastLED.show();
    // state = "menu";
  }
  else if (since_press == 1000)
  {
    flash(255, 255);
  }
  else if (since_press == 2000)
  {
    if (autoplay)
    {
      flash(160, 255);
    }
    else
    {
      flash(96, 255);
    }
  }
  else if (since_press == 3000)
  {
    flash(64, 255);
  }
}