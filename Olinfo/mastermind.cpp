#include <bits/stdc++.h>
using namespace std;

typedef enum {BLACK, RED, GREEN} color_t;
void solution(color_t combination[]);
int examine(color_t combination[]);

vector<color_t> sol;
int scanf(const char *format, ...){
  if(string(format).find('d') != string::npos){
    va_list t;
    va_start(t, format);

    int* write_at = va_arg(t, int*);
    cin >> *write_at;
  }else{
    va_list t;
    va_start(t, format);

    char* write_at = va_arg(t, char*);
    cin >> *write_at;
        
    if(*write_at == 'B') sol.push_back(BLACK);
    if(*write_at == 'G') sol.push_back(GREEN);
    if(*write_at == 'R') sol.push_back(RED);
  }

  return 1;
};

void find_secret(int N, int problemtype){ solution(sol.data()); }