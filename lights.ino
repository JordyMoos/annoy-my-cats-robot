

void writeLights() {
    digitalWrite(PIN_LIGHTS_STCP, LOW);

    for (int i = LIGHTS_COUNT - 1; i >= 0; i--) {
        digitalWrite(PIN_LIGHTS_SHCP, LOW);
        digitalWrite(PIN_LIGHTS_DS, lights[i]);
        digitalWrite(PIN_LIGHTS_SHCP, HIGH);
    }

    digitalWrite(PIN_LIGHTS_STCP, HIGH);
}

void toggleMainLights() {
    for (int i = 0; i < MAIN_LIGHTS_COUNT; i++) {
        lights[mainLightIndexes[i]] = !lights[mainLightIndexes[i]];
    }

    redrawLights = true;
}


void updateTurningLights() {
    if (driveStatus == DRIVING_LEFT) {
        int x = (millis() / TURNING_BLINKING_TIME) % 2;
        if (lights[LIGHTS_HEAD_TURN_LEFT] != x) {
            lights[LIGHTS_HEAD_TURN_LEFT] = x;
            lights[LIGHTS_TAIL_TURN_LEFT] = x;

            redrawLights = true;
        }
    }

    if (driveStatus == DRIVING_RIGHT) {
        bool x = (millis() / TURNING_BLINKING_TIME) % 2;
        if (lights[LIGHTS_HEAD_TURN_RIGHT] != x) {
            lights[LIGHTS_HEAD_TURN_RIGHT] = x;
            lights[LIGHTS_TAIL_TURN_RIGHT] = x;

            redrawLights = true;
        }
    }
}

void setReverseLights(boolean newState) {
    lights[LIGHTS_REVERSE_LEFT] = newState;
    lights[LIGHTS_REVERSE_RIGHT] = newState;

    redrawLights = true;
}

void setTurnLeftLights(boolean newState) {
    lights[LIGHTS_HEAD_TURN_LEFT] = newState;
    lights[LIGHTS_TAIL_TURN_LEFT] = newState;

    redrawLights = true;
}

void setTurnRightLights(boolean newState) {
    lights[LIGHTS_HEAD_TURN_RIGHT] = newState;
    lights[LIGHTS_TAIL_TURN_RIGHT] = newState;

    redrawLights = true;
}

