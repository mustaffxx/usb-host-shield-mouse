#include <Mouse.h>
#include <hiduniversal.h>
#include "hidmouserptparser.h"

USB Usb;
HIDUniversal Hid(&Usb);
HIDMouseReportParser Mou(nullptr);

void setup() {
	Mouse.begin();
	Serial.begin(115200);
	Serial.println("Start");

	if (Usb.Init() == -1)
		Serial.println("OSC did not start.");
	
	delay(200);

	if (!Hid.SetReportParser(0, &Mou))
		ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
}

void loop() {
  	Usb.Task();
}

void onButtonDown(uint16_t buttonId) {
	Mouse.press(buttonId);
	Serial.print("Button ");
	switch (buttonId) {
		case MOUSE_LEFT:
			Serial.print("MOUSE_LEFT");
			break;

		case MOUSE_RIGHT:
			Serial.print("MOUSE_RIGHT");
			break;
		
		case MOUSE_MIDDLE:
			Serial.print("MOUSE_MIDDLE");
			break;

		case MOUSE_BUTTON4:
			Serial.print("MOUSE_BUTTON4");
			break;

		case MOUSE_BUTTON5:
			Serial.print("MOUSE_BUTTON5");
			break;
		default:
			Serial.print("OTHER_BUTTON");
			break;
	}
	Serial.println(" pressed");
}

void onButtonUp(uint16_t buttonId) {
	Mouse.release(buttonId);
	Serial.print("Button ");
	switch (buttonId) {
		case MOUSE_LEFT:
			Serial.print("MOUSE_LEFT");
			break;

		case MOUSE_RIGHT:
			Serial.print("MOUSE_RIGHT");
			break;
		
		case MOUSE_MIDDLE:
			Serial.print("MOUSE_MIDDLE");
			break;

		case MOUSE_BUTTON4:
			Serial.print("MOUSE_BUTTON4");
			break;

		case MOUSE_BUTTON5:
			Serial.print("MOUSE_BUTTON5");
			break;
		default:
			Serial.print("OTHER_BUTTON");
			break;
	}
	Serial.println(" released");
}

void onTiltPress(int8_t tiltValue) {
	Serial.print("Tilt pressed: ");
	Serial.println(tiltValue);
}

void onMouseMove(int8_t xMovement, int8_t yMovement, int8_t scrollValue) {
	Mouse.move(xMovement, yMovement, scrollValue);
	Serial.print("Mouse moved:\t");
	Serial.print(xMovement);
	Serial.print("\t");
	Serial.print(yMovement);
	Serial.print("\t");
	Serial.println(scrollValue);
}