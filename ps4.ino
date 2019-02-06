
bool isControllerDrivingForward()
{
    return PS4.getAnalogHat(LeftHatY) < 117;
}

bool isControllerDrivingBackward()
{
    return PS4.getAnalogHat(LeftHatY) > 137;
}

bool isControllerDrivingLeft()
{
    return PS4.getAnalogHat(LeftHatX) < 117;
}

bool isControllerDrivingRight()
{
    return PS4.getAnalogHat(LeftHatX) > 137;
}

bool isToggleLaser()
{
    return PS4.getButtonClick(CROSS);
}