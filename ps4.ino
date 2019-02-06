
bool isControllerDrivingForward()
{
    return PS4.getAnalogHat(LeftHatY) < 100;
}

bool isControllerDrivingBackward()
{
    return PS4.getAnalogHat(LeftHatY) > 155;
}

bool isControllerDrivingLeft()
{
    return PS4.getAnalogHat(LeftHatX) < 100;
}

bool isControllerDrivingRight()
{
    return PS4.getAnalogHat(LeftHatX) > 155;
}

bool isToggleLaser()
{
    return PS4.getButtonClick(CROSS);
}

bool isControllerLaserUp()
{
    return PS4.getAnalogHat(RightHatX) < 100;
}

bool isControllerLaserDown()
{
    return PS4.getAnalogHat(RightHatX) > 155;
}

bool isControllerLaserLeft()
{
    return PS4.getAnalogHat(RightHatY) < 100;
}

bool isControllerLaserRight()
{
    return PS4.getAnalogHat(RightHatY) > 155;
}
