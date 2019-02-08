
/*
  Laser
*/

void setLaser(bool newState) {
    laserState = newState;
    digitalWrite(PIN_LASER, newState);
}

void toggleLaser() {
    laserState = !laserState;
    digitalWrite(PIN_LASER, laserState);
}

/*
 Horizontal Motor
*/

void invertHorizontalLaserMotor() {
    laserHorizontalInverted = ! laserHorizontalInverted;
}

void laserGoLeft() {
    setLaserHorizontalLocation(max(
            laserHorizontalLocation - LASER_STEP_SIZE,
            LASER_HORIZONTAL_MIN_LOCATION
    ));
}

void laserGoRight() {
    setLaserHorizontalLocation(min(
            laserHorizontalLocation + LASER_STEP_SIZE,
            LASER_HORIZONTAL_MAX_LOCATION
    ));
}

void setLaserCenter() {
    laserHorizontalState = LASER_HORIZONTAL_CENTERED;
    setLaserHorizontalLocation(LASER_HORIZONTAL_CENTER_LOCATION);
}

void startLaserAnimation() {
    laserHorizontalState = LASER_HORIZONTAL_ANIMATING_LEFT;
}

void setLaserHorizontalLocation(float location) {
    laserHorizontalLocation = location;
    laserMotorHorizontal.write((int) location);
}

void updateLaserAnimation() {
    switch (laserHorizontalState) {
        case LASER_HORIZONTAL_CENTERED:
            break;

        case LASER_HORIZONTAL_ANIMATING_LEFT: {
            float newLocation = laserHorizontalLocation - LASER_STEP_SIZE;
            if (newLocation <= LASER_HORIZONTAL_MIN_LOCATION) {
                laserHorizontalState = LASER_HORIZONTAL_ANIMATING_RIGHT;
                setLaserHorizontalLocation(LASER_HORIZONTAL_MIN_LOCATION);
            } else {
                setLaserHorizontalLocation(newLocation);
            }
        }
            break;

        case LASER_HORIZONTAL_ANIMATING_RIGHT: {
            float newLocation = laserHorizontalLocation + LASER_STEP_SIZE;
            if (newLocation >= LASER_HORIZONTAL_MAX_LOCATION) {
                laserHorizontalState = LASER_HORIZONTAL_ANIMATING_LEFT;
                setLaserHorizontalLocation(LASER_HORIZONTAL_MAX_LOCATION);
            } else {
                setLaserHorizontalLocation(newLocation);
            }
        }
            break;
    }
}

/*
 Vertical Motor
*/

void laserGoUp() {
    setLaserVerticalLocation(max(
            laserVerticalLocation - LASER_STEP_SIZE,
            LASER_VERTICAL_MIN_LOCATION
    ));
}

void laserGoDown() {
    setLaserVerticalLocation(min(
            laserVerticalLocation + LASER_STEP_SIZE,
            LASER_VERTICAL_MAX_LOCATION
    ));
}

void setLaserVerticalLocation(float location) {
    laserVerticalLocation = location;
    laserMotorVertical.write((int) location);
}

void laserTargetGround() {
    laserVerticalLocation = LASER_MOTOR_GROUND_LOCATION;
    laserTarget(LASER_MOTOR_GROUND_LOCATION);
}

void laserTargetGroundFar() {
    laserVerticalLocation = LASER_MOTOR_GROUND_FAR_LOCATION;
    laserTarget(LASER_MOTOR_GROUND_FAR_LOCATION);
}

void laserTargetCeiling() {
    laserVerticalLocation = LASER_MOTOR_CEILING_LOCATION;
    laserTarget(LASER_MOTOR_CEILING_LOCATION);
}

void laserTarget(float location) {
    laserMotorVertical.write(location);
}

