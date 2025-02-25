#include <Versatile_RotaryEncoder.h>
#include "pico/stdlib.h"
#include <stdio.h>
// SET READING PINS ACCORDINGLY TO YOUR ENCODER TO BOARD CONNECTIONS
// Set here your encoder reading pins (Ex.: EC11 with breakout board)
#define clk 20 
#define dt 21
#define sw 14

// Functions prototyping to be handled on each Encoder Event
void handleRotate(int8_t rotation);
void handlePressRotate(int8_t rotation);
void handleHeldRotate(int8_t rotation);
void handlePress();
void handleDoublePress();
void handlePressRelease();
void handleLongPress();
void handleLongPressRelease();
void handlePressRotateRelease();
void handleHeldRotateRelease();

// Create a global pointer for the encoder object
Versatile_RotaryEncoder *versatile_encoder;

void setup() {

    stdio_init_all();
    
	versatile_encoder = new Versatile_RotaryEncoder(clk, dt, sw);

    // Load to the encoder all nedded handle functions here (up to 9 functions)
    versatile_encoder->setHandleRotate(handleRotate);
    versatile_encoder->setHandlePressRotate(handlePressRotate);
    versatile_encoder->setHandleHeldRotate(handleHeldRotate);
    versatile_encoder->setHandlePress(handlePress);
    versatile_encoder->setHandleDoublePress(handleDoublePress);
    //versatile_encoder->setHandleDoublePress(nullptr); // Disables Double Press
    versatile_encoder->setHandlePressRelease(handlePressRelease);
    versatile_encoder->setHandleLongPress(handleLongPress);
    versatile_encoder->setHandleLongPressRelease(handleLongPressRelease);
    versatile_encoder->setHandlePressRotateRelease(handlePressRotateRelease);
    versatile_encoder->setHandleHeldRotateRelease(handleHeldRotateRelease);

    printf("Ready!\n");

    // set your own defualt values (optional)
    // versatile_encoder->setInvertedSwitch(true); // inverts the switch behaviour from HIGH to LOW to LOW to HIGH
    // versatile_encoder->setReadIntervalDuration(1); // set 2ms as long press duration (default is 1ms)
    // versatile_encoder->setShortPressDuration(35); // set 35ms as short press duration (default is 50ms)
    // versatile_encoder->setLongPressDuration(550); // set 550ms as long press duration (default is 1000ms)
    // versatile_encoder->setDoublePressDuration(350); // set 350ms as double press duration (default is 250ms)

}

void loop() {

    // Do the encoder reading and processing
    if (versatile_encoder->ReadEncoder()) {
        // Do something here whenever an encoder action is read
    }

}

int main(){
    setup();
    while(1){
        loop();
    }
    return 0;
}

// Implement your functions here accordingly to your needs

void handleRotate(int8_t rotation) {
	printf("#1 Rotated: ");
    if (rotation > 0)
	    printf("Right\n");
    else
	    printf("Left\n");
}

void handlePressRotate(int8_t rotation) {
	printf("#2 Pressed and rotated: ");
    if (rotation > 0)
	    printf("Right\n");
    else
	    printf("Left\n");
}

void handleHeldRotate(int8_t rotation) {
	printf("#3 Held and rotated: ");
    if (rotation > 0)
	    printf("Right\n");
    else
	    printf("Left\n");
}

void handlePress() {
	printf("#4.1 Pressed\n");
}

void handleDoublePress() {
	printf("#4.2 Double Pressed\n");
}

void handlePressRelease() {
	printf("#5 Press released\n");
}

void handleLongPress() {
	printf("#6 Long pressed\n");
}

void handleLongPressRelease() {
	printf("#7 Long press released\n");
}

void handlePressRotateRelease() {
	printf("#8 Press rotate released\n");
}

void handleHeldRotateRelease() {
	printf("#9 Held rotate released\n");
}