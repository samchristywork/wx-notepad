#ifndef FONT_H
#define FONT_H

#include "../codegen/noname.h"

class FontWindow : public FontFrame {
public:
  wxTextCtrl *textCtrl;

  FontWindow(wxWindow *parent);

private:
};

#endif
