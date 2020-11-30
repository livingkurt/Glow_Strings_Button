

void handle_button(bool pressed, bool changed)
{

  Serial.println(since_press);
  if (state == "modes")
  {
    modes(pressed, changed);
  }
  else if (state == "state_select")
  {
    state_select(pressed, changed);
  }
  else if (state == "setting_select")
  {
    setting_select(pressed, changed);
  }
  else if (state == "party_modes")
  {
    party_modes(pressed, changed);
  }
  else if (state == "colors")
  {
    colors(pressed, changed);
  }
  else if (state == "value")
  {
    value(pressed, changed);
  }
  else if (state == "saturation")
  {
    saturation(pressed, changed);
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
      flash(255, 255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      Serial.println("Next State");
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

void setting_select(bool pressed, bool changed)
{
  if (pressed)
  {
    if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      Serial.println("Next Setting");
      nextSetting();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {
      go_to_setting();
    }
    else
    {
    }
  }
}
// void interval_select(bool pressed, bool changed)
// {
//   if (pressed)
//   {
//     if (since_press == 1000)
//     {
//       Serial.println(1000);
//       flash(255, 255, 255);
//     }
//   }
//   else if (changed)
//   {
//     if (since_press < 1000 && since_press != 0)
//     {
//       Serial.println("Next Setting");
//       nextSetting();
//       since_press = 0;
//       return;
//     }
//     else if (since_press < 2000 && since_press > 1000)
//     {
//       update_state();
//     }
//     else
//     {
//     }
//   }
// }

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
      // decide_autoplay();
      state = "setting_select";
      last_state = "modes";
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "state_select";
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
      // decide_autoplay();
      state = "setting_select";
      last_state = "party_modes";
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "state_select";
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
      // decide_autoplay();
      state = "setting_select";
      last_state = "all_modes";
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "state_select";
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
    color_menu();
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
      state = "value";
      EEPROM.write(0, 2);
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "saturation";
      EEPROM.write(0, 2);
    }
    else if (since_press < 5000 && since_press > 4000)
    {
      state = "state_select";
    }
    else
    {
    }
  }
}

void saturation(bool pressed, bool changed)
{
  if (pressed)
  {
    if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      Serial.println("Next Color");
      nextSaturation();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {
      state = "colors";
      EEPROM.write(0, 2);
    }
    else
    {
    }
  }
}
void value(bool pressed, bool changed)
{
  if (pressed)
  {
    if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 1000 && since_press != 0)
    {
      Serial.println("Next Color");
      nextValue();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    {
      state = "colors";
      EEPROM.write(0, 2);
    }
    else
    {
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
      flash(255, 0, 255);
    }
    else if (since_press == 4000)
    {
      Serial.println(4000);
      flash(255, 255, 255);
    }
  }
  else if (changed)
  {
    if (since_press < 2000 && since_press > 1000)
    {
      Serial.println("Change States");
      state = last_state;
      EEPROM.write(0, determine_state_number(last_state));
    }
    else if (since_press < 6000 && since_press > 5000)
    {
      Serial.println("Reset Settings");
      reset_setting();
      state = "modes";
      EEPROM.write(0, 0);
    }
    else
    {
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

void go_to_setting()
{
  EEPROM.write(0, gCurrentSettingNumber);
  if (gCurrentSettingNumber == 0)
  {
    // state = "autoplay";
    decide_autoplay();
    state = last_state;
  }
  else if (gCurrentSettingNumber == 1)
  {
    state = "interval";
  }
  else if (gCurrentSettingNumber == 2)
  {
    decide_random_interval();
    state = last_state;
  }
  else if (gCurrentSettingNumber == 3)
  {
    decide_random_order();
    state = last_state;
  }
}

void flash_menus()
{
  if (since_press == 1000)
  {
    flash(255, 255, 255);
  }
  else if (since_press == 2000)
  {
    if (autoplay)
    {
      flash(160, 255, 255);
    }
    else
    {
      flash(96, 255, 255);
    }
  }
  else if (since_press == 3000)
  {
    flash(64, 255, 255);
  }
}

void color_menu()
{
  if (since_press == 1000)
  {
    flash(0, 255, 255);
  }
  else if (since_press == 2000)
  {
    flash(gCurrentHueNumber, 255, 100);
  }
  else if (since_press == 3000)
  {
    flash(gCurrentHueNumber, 150, 255);
  }
  else if (since_press == 4000)
  {
    flash(224, 255, 255);
  }
}

void flash(int color, int sat, int value)
{
  int gap = 150;
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();

  // since_press += 20;
  return;
}