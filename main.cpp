#include "count.h"

int32_t main() {
  // filename is defined in count.h
  int count = countWords(fileName);
  cout << "Total words in the file were " << count << endl;
  return 0;
}
