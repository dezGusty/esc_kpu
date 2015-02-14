//   This file is part of the "ESC Key Pressing Utility", licensed under 
//   the terms of the MIT License (seen below).
//
//   The MIT License
//   Copyright (C) 2015  Augustin Preda (thegusty999@gmail.com)
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy
//   of this software and associated documentation files (the "Software"), to deal
//   in the Software without restriction, including without limitation the rights
//   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//   copies of the Software, and to permit persons to whom the Software is
//   furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in
//   all copies or substantial portions of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//   THE SOFTWARE.
//
//   @file esc_kpu_main.cpp Main file of utility
//

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

//
// Use WinAPI to send the key
//
#include <windows.h>

// C RunTime Header Files
#include <tchar.h>

//
// Send a key-down event
//
void SendKeyDown(short keyCode)
{
  INPUT keyInput;
  keyInput.type = INPUT_KEYBOARD;
  keyInput.ki.dwExtraInfo = 0;
  keyInput.ki.dwFlags = 0;
  keyInput.ki.time = 0;
  keyInput.ki.wScan = MapVirtualKey(keyCode, MAPVK_VK_TO_VSC);;
  keyInput.ki.wVk = keyCode;
  UINT result = SendInput(1, &keyInput, sizeof(keyInput));
}

//
// Send a key-up event
//
void SendKeyUp(short keyCode)
{
  INPUT keyInput;
  keyInput.type = INPUT_KEYBOARD;
  keyInput.ki.dwExtraInfo = 0;
  keyInput.ki.dwFlags = KEYEVENTF_KEYUP;
  keyInput.ki.time = 0;
  keyInput.ki.wScan = MapVirtualKey(keyCode, MAPVK_VK_TO_VSC);;
  keyInput.ki.wVk = keyCode;
  UINT result = SendInput(1, &keyInput, sizeof(keyInput));
}

//
// Main entry point.
//
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPTSTR    lpCmdLine,
                      _In_ int       nCmdShow)
{
  SendKeyDown(27);
  Sleep(10);
  SendKeyUp(27);
  return 0;
}

