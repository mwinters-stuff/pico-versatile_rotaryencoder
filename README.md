## **Versatile_RotaryEncoder Library V1.3.1** for Arduino
**Written by:** _Rui Seixas Monteiro_.

## Installation - CMakeLists.txt

In your project, create or add to a `libraries.cmake` or similar file, and add to it:

```
cmake_minimum_required(VERSION 3.16)
function (includeLibraries)

include(FetchContent)

FetchContent_Declare(
  versatile_rotaryencoder
  GIT_REPOSITORY    https://github.com/mwinters-stuff/pico-versatile_rotaryencoder.git
  GIT_TAG           main
  GIT_SHALLOW       1
)

FetchContent_MakeAvailable(versatile_rotaryencoder)


endfunction()

```

If you are adding to a similar file you might only need the `FetchContent_Declare` and `FetchContent_MakeAvailable`.


Now add to your main `CMakeLists.txt` after `pico_sdk_init()`:
```
include(libraries.cmake)
includeLibraries()

```

Then add to `target_link_libraries` the library `Versatile_RotaryEncoder`.


## What is Versatile_RotaryEncoder
The Versatile_RotaryEncoder library allows the callback of up to 10 different functions representing the same number of different encoder events. These different functions can be associated with events like press rotate and long press among many others.

## Usage
### **How to include**
```cpp
#include <Versatile_RotaryEncoder.h>


```

### **Library functions**
#### **`Versatile_RotaryEncoder(clk, dt, sw)`**
This function returns a pointer to an object of type `Versatile_RotaryEncoder` to be used as function calls and sets.

#### **`Versatile_RotaryEncoder.setHandleRotate( void (*)(int8_t rotation) )`**
This function sets the handle function for the rotation of the encoder.
Its only parameter is the handle function as `void (*)(int8_t rotation)` that would be used to process the rotation value.

#### **`Versatile_RotaryEncoder.setHandlePressRotate( void (*)(int8_t rotation) )`**
This function sets the handle function for the rotation of the encoder while being pressed.
Its only parameter is the handle function as `void (*)(int8_t rotation)` that would be used to process the rotation value.

#### **`Versatile_RotaryEncoder.setHandleHeldRotate( void (*)(int8_t rotation) )`**
This function sets the handle function for the rotation of the encoder after being long pressed while held.
Its only parameter is the handle function as `void (*)(int8_t rotation)` that would be used to process the rotation value.

#### **`Versatile_RotaryEncoder.setHandlePress( void (*)() )`**
This function sets the handle function for the button press of the encoder.
Its only parameter is the handle function as `void (*)()` that would be used to process the pressed encoder switch.

#### **`Versatile_RotaryEncoder.setHandleDoublePress( void (*)() )`**
This function sets the handle function for the button double press of the encoder.
Its only parameter is the handle function as `void (*)()` that would be used to process the double pressed encoder switch.
Giving the function value of 'nullptr' will completly disable the double press feature!

#### **`Versatile_RotaryEncoder.setHandlePressRelease( void (*)() )`**
This function sets the handle function for the button release of the encoder.
Its only parameter is the handle function as `void (*)()` that would be used to process the released encoder switch.

#### **`Versatile_RotaryEncoder.setHandleLongPress( void (*)() )`**
This function sets the handle function for the button long press of the encoder.
Its only parameter is the handle function as `void (*)()` that would be used to process the long pressed encoder switch.

#### **`Versatile_RotaryEncoder.setHandleLongPressRelease( void (*)() )`**
This function sets the handle function for the button long press released of the encoder.
Its only parameter is the handle function as `void (*)()` that would be used to process the release of the long pressed encoder switch.

#### **`Versatile_RotaryEncoder.setHandlePressRotateRelease( void (*)() )`**
This function sets the handle function for the button release of the encoder after being press rotated.
Its only parameter is the handle function as `void (*)()` that would be used to process the release encoder switch after being press rotated.

#### **`Versatile_RotaryEncoder.setHandleHeldRotateRelease( void (*)() )`**
This function sets the handle function for the button release of the encoder after being long press and then rotated.
Its only parameter is the handle function as `void (*)()` that would be used to process the release encoder switch after being held rotated.

#### **`Versatile_RotaryEncoder.ReadEncoder()`**
This function reads the encoder and runs all Handle functions accordingly. It returns a `bool` with true whenever any handle function is called.

#### **`Versatile_RotaryEncoder.setInvertedSwitch( bool invert_switch )`**
By default the switch is triggered from vcc to ground (HIGH to LOW), using this function you can invert this behavior from LOW to HIGH.

#### **`Versatile_RotaryEncoder.setReadIntervalDuration( uint8_t duration )`**
By default every 1 ms the encoder is readed, you can set a different value with this function.

#### **`Versatile_RotaryEncoder.setShortPressDuration( uint8_t duration )`**
By default it's set 50 ms for the encoder switch debounce, you can set a different value with this function.

#### **`Versatile_RotaryEncoder.setLongPressDuration( unsigned int duration )`**
By default it's set 1000 ms for the press be considered a long press, you can set a different value with this function.

#### **`Versatile_RotaryEncoder.setDoublePressDuration( unsigned int duration )`**
By default it's set up to 250 ms for repeated presses be considered a double press, you can set a different value with this function.

#### **`Versatile_RotaryEncoder.getRotary()`**
This function returns a `short int` with a positive 1 or negative 1 accordingly to the rotation of the encoder.
The purpose of this function is to allow a more specific use of the library.

#### **`Versatile_RotaryEncoder.getButton()`**
This function returns a `short unsigned int` with a value related to released, holdup, switchup, switchdown, pressed, holddown or held respectively.
The purpose of this function is to allow a more specific use of the library.

#### **`Versatile_RotaryEncoder.getEncoder()`**
This function returns a `short unsigned int` with a value related to inactive, release, press, hold, rotate, pressrotate or heldrotate respectively.
The purpose of this function is to allow a more specific use of the library.

#### **`Versatile_RotaryEncoder.getEncoderBits()`**
This function returns a `short unsigned int` representing the last rotary bits set by the encoder.
The purpose of this function is to allow a more specific use of the library.

#### **`Versatile_RotaryEncoder.getButtonBits()`**
This function returns a `short unsigned int` representing the last button bits set by the encoder.
The purpose of this function is to allow a more specific use of the library.

### **Examples**

See the example in the source.
