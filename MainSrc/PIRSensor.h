#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

class PIRSensor {
public:
    PIRSensor(int pin);
    void begin();
    bool isMotionDetected();

private:
    int _pin;
};

#endif // PIR_SENSOR_H

