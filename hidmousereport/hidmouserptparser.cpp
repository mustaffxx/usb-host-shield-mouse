#include "hidmouserptparser.h"


HIDMouseReportParser::HIDMouseReportParser(void *) : previousButtonsState(0) {};

void HIDMouseReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) { 
	for (uint16_t buttonId = 1; buttonId <= 16; buttonId <<= 1) {
		if (buf[0] & buttonId) {
			if (!(previousButtonsState & buttonId)) {
				onButtonDown(buttonId);
			}
		} else {
			if (previousButtonsState & buttonId) {
				onButtonUp(buttonId);
			}
		}
	}
	previousButtonsState = buf[0];

	int8_t xMovement = buf[2];
	int8_t yMovement = buf[4];
	int8_t scrollValue = buf[6];
	int8_t tiltValue = buf[7];

	if (xMovement > 127) xMovement -= 256;
	if (yMovement > 127) yMovement -= 256;

	if (xMovement != 0 || yMovement != 0 || scrollValue != 0)
		onMouseMove(xMovement, yMovement, scrollValue);
	
	if (tiltValue != 0)
		onTiltPress(tiltValue);
}
