#include <bits/stdc++.h>

using namespace std;
char fileName[] = "/Users/adarshsingh/Adarsh/coding/wc_multithreaded/input.txt";



int readChunk(FILE* file, int start, int end, char* buffer) {
  fseek(file, start, SEEK_SET);
  fread(buffer, 1, end - start, file);
  return 0;
}

int getCount(const int start, const int end, FILE* file, char s[] = nullptr) {
  int count = 0;
  if (end <= start) return 0;
  // if s is null then threads read file on their own
  if (s == nullptr) {
    // cout << "Reading file from child thread";
    s = new char[end - start];
    readChunk(file, start, end, s);
  }
  else {
    // cout << "Reading file from main";
  }

  for (int i = start; i < end; i++) {
    if (isspace(s[i]) && i && !isspace(s[i - 1])) {
      count++;
    }
  }
  return count;
}

int countWords(char* fileName, int cores = 4, bool multiRead = false) {

  FILE* fend = fopen(fileName, "r");
  fseek(fend, 0, SEEK_END);
  int size = ftell(fend);
  fclose(fend);
  int chunk = size / cores;
  int rem = size % cores;
  FILE* file = fopen(fileName, "r");
  char* s;
  if (multiRead) {
    s = nullptr;
  }
  else {
    s = new char[size + 1];
    readChunk(file, 0, size, s);
  }

  vector<future<int>> v;
  // end is exclusive [start, end)
  int start = 0, end = start + chunk;
  for (int i = 0; i < cores; i++) {
    if (rem) {
      end++;
      rem--;
    }
    v.push_back(async(getCount, start, end, file, s));
    start = end;
    end = start + chunk;
  }

  int count = 0;
  for (auto& i : v) {
    count += i.get();
  }
  fclose(file);
  return count;
}
