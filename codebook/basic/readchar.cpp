inline char readchar() {
  static const int size = 65536;
  static char buf[size];
  static char *p = buf, *end = buf;
  if (p == end) end = buf +
    fread_unlocked(buf, 1, size, stdin), p = buf;
  return *p++; }
