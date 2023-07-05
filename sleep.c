#include <shlwapi.h>
#include <shellapi.h>

int __cdecl main()
{
  int argc = 0;
  LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
  int seconds = argc == 2 ? StrToIntW(argv[1]) : 0;
  if (seconds <= 0)
  {
    DWORD Written;
    LPCSTR s = "Usage: sleep <seconds>\n";
    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), s, lstrlen(s), &Written, NULL);
  }
  else
  {
    Sleep(seconds * 1000);
  }
  return 0;
}
