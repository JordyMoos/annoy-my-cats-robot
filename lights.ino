

void writeLights()
{
  digitalWrite(PIN_LIGHTS_STCP, LOW);

  for (int i = LIGHTS_COUNT - 1; i >= 0; i--)
  {
    digitalWrite(PIN_LIGHTS_SHCP, LOW);
    digitalWrite(PIN_LIGHTS_DS, lights[i]);
    digitalWrite(PIN_LIGHTS_SHCP, HIGH);
  }

  digitalWrite(PIN_LIGHTS_STCP, HIGH);
}

void toggleMainLights()
{
  for (int i = 0; i < MAIN_LIGHTS_COUNT; i++)
  {
    lights[mainLightIndexes[i]] = ! lights[mainLightIndexes[i]];
  }

  redrawLights = true;
}

void setReverseLights(boolean newState)
{
  lights[LIGHTS_REVERSE_LEFT] = newState;
  lights[LIGHTS_REVERSE_RIGHT] = newState;

  redrawLights = true;
}

