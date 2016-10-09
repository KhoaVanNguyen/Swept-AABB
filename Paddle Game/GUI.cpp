#include "GUI.h"


void GUI::DrawLabel(string message, RECT rect, DWORD dword) {
	if (font != NULL) {
		font->DrawTextA(NULL, message.c_str(), -1, &rect, dword, D3DCOLOR_XRGB(255, 255, 255));

	}
}
bool GUI::Init() {
	font = NULL;
	fontResult = D3DXCreateFont(G_Device, 40, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);
	if (!SUCCEEDED(fontResult)) {
		return false;
	}
}
GUI::GUI()
{
	
}


GUI::~GUI()
{
	if (font != NULL) {
		font->Release();
	}
}
