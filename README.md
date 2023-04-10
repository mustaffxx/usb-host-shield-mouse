# usb-host-shield-mouse
This project is an example of using a [USB HOST SHIELD 2.0](https://github.com/felis/USB_Host_Shield_2.0) to interface with a Logitech G502 mouse. The problem with many USB Host Shield examples is that they use the HID Boot Protocol, whereas the G502 uses the HID Report Protocol. This example demonstrates how to use the USB Host Shield with the G502, by interpreting 8-bit data from the mouse and replicating it to the computer.
```
[USB Mouse] --> [USB Host Shield 2.0] --> [Arduino Leonardo] --FAKE HID USB--> [Computer]
```

# Hardware Requirements
- Arduino Leonardo
- USB Host Shield 2.0
- Logitech G502 

# How to Use
1.  Connect the USB Host Shield to the Arduino Leonardo.
2.  Connect the G502 mouse to the USB Host Shield.
3.  Upload the USBHostShieldMouse.ino sketch to the Arduino Leonardo.
4.  Open the Arduino Serial Monitor and select a baud rate of 115200.
5.  Move the mouse around and click the buttons to see the output on the Serial Monitor.

## To Do
- Parse 16-bit precision
