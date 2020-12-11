
// =================== Shooting Star White One Direction ===================

// void shooting_star_white()
// {
//   // fadeToBlackBy(leds, NUM_LEDS, 30); //change fadeby to smaller or larger number to adjust the length of the tail.
//   // int rate = 10;
//   // uint8_t u = beat8(50, 0); //BPM will allow you to adjust the speed the dot is moving.
//   // uint16_t pos = map(u, 0, 255, 0, NUM_LEDS);
//   // int start_hue;
//   // int delta_hue = 5;
//   // start_hue = -1 * millis() / rate;
//   // leds[pos] = CHSV(start_hue, 255, 255);
//   // FastLED.show();
//   // start_hue += delta_hue;
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   int pos1 = beatsin16(28, 0, NUM_LEDS);
//   int pos2 = beatsin16(23, 0, NUM_LEDS);
//   leds[(pos1 + pos2) / 2] += CHSV(255, 0, 255);
// }

void shooting_star_white()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  start_hue = -1 * millis() / rate;
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u = beat8(determine_speed_shooting_star(), 0);           //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  leds[pos_1] = CHSV(start_hue, 0, 255);
  FastLED.show();
  start_hue += delta_hue;
}

// uint16_t pos = 0;

// void shooting_star_white()
// {
//   fadeToBlackBy(leds, NUM_LEDS, 50);
//   if (pos >= NUM_LEDS - 1)
//   {
//     pos = 0;
//   }
//   else
//   {
//     pos++;
//   }
//   leds[pos] = CHSV(255, 0, 255);
//   FastLED.show();
// }
// void shooting_star_white()
// {
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     fadeToBlackBy(leds, NUM_LEDS, 50);
//     leds[i] += CHSV(255, 0, 255);
//     FastLED.show();
//   }
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.show();
// }

// =================== Shooting Star Rainbow One Direction ===================

// void shooting_star_rainbow()
// {
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   int rate = 5;
//   int start_hue;
//   int delta_hue = 100;
//   start_hue = -1 * millis() / rate;
//   leds[beatsin16(30, 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
//   start_hue += delta_hue;
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   leds[beat8(50, 0)] |= CHSV(255, 0, 255);
// }

void shooting_star_rainbow()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  start_hue = -1 * millis() / rate;
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u = beat8(determine_speed_shooting_star(), 0);           //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  leds[pos_1] = CHSV(start_hue, 255, 255);
  FastLED.show();
  start_hue += delta_hue;
}

int determine_length_shooting_star()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 50;
    break;
  case 100:
    return 20;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 7;
    break;
  case 300:
    return 7;
    break;
  case 400:
    return 5;
    break;
  case 500:
    return 2;
    break;
  default:
    break;
  }
}
int determine_speed_shooting_star()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 50;
    break;
  case 100:
    return 30;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 30;
    break;
  case 300:
    return 20;
    break;
  case 400:
    return 20;
    break;
  case 500:
    return 10;
    break;
  default:
    break;
  }
}

// =================== Shooting Star White Back and Forth ===================

// void shooting_star_white_bnf()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length());
//   leds[beatsin8(determine_speed(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
// }  // fadeToBlackBy(leds, NUM_LEDS, 30);
// leds[beatsin16(15, 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);

void shooting_star_white_bnf()
{
  // fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_bnf);
  // int pos = beatsin8(determine_speed_shooting_star_bnf, 0, NUM_LEDS - 1);
  // leds[pos] += CHSV(255, 0, 255);
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_bnf());
  leds[beatsin8(determine_speed_shooting_star_bnf(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
}

// =================== Shooting Star Rainbow Back and Forth ===================

void shooting_star_rainbow_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_bnf());
  int rate = 5;
  int start_hue;
  int delta_hue = 100;
  start_hue = -1 * millis() / rate;
  leds[beatsin8(determine_speed_shooting_star_bnf(), 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
  start_hue += delta_hue;
}

int determine_length_shooting_star_bnf()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 100;
    break;
  case 100:
    return 20;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 7;
    break;
  case 300:
    return 7;
    break;
  case 400:
    return 5;
    break;
  case 500:
    return 2;
    break;
  default:
    break;
  }
}
int determine_speed_shooting_star_bnf()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 20;
    break;
  case 100:
    return 30;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 30;
    break;
  case 300:
    return 20;
    break;
  case 400:
    return 20;
    break;
  case 500:
    return 10;
    break;
  default:
    break;
  }
}

// =================== Shooting Star White Mirror ===================

void shooting_star_white_mirror()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_mirror()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed_shooting_star_mirror(), 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  // Backward
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS - 1, 0);
  leds[pos_1] = CRGB::White;
  leds[pos_2] = CRGB::White;
  FastLED.show();
}

// =================== Shooting Star Rainbow Mirror ===================

void shooting_star_rainbow_mirror()
{

  int rate = 2;
  int start_hue;
  int delta_hue = 30;
  start_hue = -1 * millis() / rate;
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_mirror()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed_shooting_star_mirror(), 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  // Backward
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS - 1, 0);
  leds[pos_1] = CHSV(start_hue, 255, 255);
  leds[pos_2] = CHSV(start_hue, 255, 255);
  FastLED.show();
  start_hue += delta_hue;
}

int determine_length_shooting_star_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 75;
    break;
  case 100:
    return 20;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 7;
    break;
  case 300:
    return 7;
    break;
  case 400:
    return 5;
    break;
  case 500:
    return 2;
    break;
  default:
    break;
  }
}
int determine_speed_shooting_star_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 60;
    break;
  case 100:
    return 30;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 30;
    break;
  case 300:
    return 20;
    break;
  case 400:
    return 20;
    break;
  case 500:
    return 10;
    break;
  default:
    break;
  }
}