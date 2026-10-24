int GetChar() {
  static char buf[1 << 20], *l = 0, *r = 0;
  if(l == r) r = (l = buf) + fread(buf, 1, 1 << 20, stdin);
  return l == r ? EOF : *l++;
}
template <typename T>
void Read(T &n) {
  char c = GetChar(); int sgn = 1; n = 0;
  while(!isdigit(c)) sgn = c == '-' ? -1 : 1, c = GetChar();
  while(isdigit(c)) n = n * 10 + c - '0', c=  GetChar();
  n = n * sgn;
}
template <typename T, typename ...Args>
void Read(T &n, Args ...args) {
  Read(n); Read(args...);
}
