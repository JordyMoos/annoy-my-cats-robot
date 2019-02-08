
bool isControllerDrivingForward() {
    return PS4.getAnalogButton(R2) > 10;
}

int getControllerDrivingForwardSpeed() {
  if (isControllerDrivingForward()) {
    return PS4.getAnalogButton(R2);
  } else {
    return 0;
  }
}

bool isControllerDrivingBackward() {
    return PS4.getAnalogButton(L2) > 10;
}

int getControllerDrivingBackwardSpeed() {
  if (isControllerDrivingBackward()) {
    return PS4.getAnalogButton(L2);
  } else {
    return 0;
  }
}

bool isControllerDrivingLeft() {
    return PS4.getAnalogHat(LeftHatX) < 100;
}

bool isControllerDrivingRight() {
    return PS4.getAnalogHat(LeftHatX) > 155;
}

bool isToggleLaser() {
    return PS4.getButtonClick(CIRCLE);
}

bool isToot() {
    return PS4.getButtonPress(CROSS);
}

bool isInvertHorizontalLaserMotor() {
    return PS4.getButtonClick(TRIANGLE);
}

bool isControllerLaserUp() {
    return PS4.getAnalogHat(RightHatY) < 100;
}

bool isControllerLaserDown() {
    return PS4.getAnalogHat(RightHatY) > 155;
}

bool isControllerLaserLeft() {
    return PS4.getAnalogHat(RightHatX) < 100;
}

bool isControllerLaserRight() {
    return PS4.getAnalogHat(RightHatX) > 155;
}
