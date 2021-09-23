#if !defined(__HIDMOUSERPTPARSER_H__)

#define __HIDMOUSERPTPARSER_H__

#include <usbhid.h>

class HIDMouseEvents {
  public:
    virtual void OnButtonDn(uint8_t but_id);
    virtual void OnButtonUp(uint8_t but_id);
    virtual void Move(int8_t xm, int8_t ym, int8_t scr, int8_t tilt);
};

#define RPT_LEN  8

class HIDMouseReportParser : public HIDReportParser {
    HIDMouseEvents *mouEvents;
    uint8_t oldButtons;
    uint8_t xbrute;
    uint8_t ybrute;
    int8_t xm;
    int8_t ym;
    int8_t scr;
    int8_t tilt;

  public:
    HIDMouseReportParser(HIDMouseEvents *evt);
    virtual void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
};

#endif//__HIDMOUSERPTPARSER_H__
