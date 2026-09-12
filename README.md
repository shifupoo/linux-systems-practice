# linux-systems-practice
int add(int a, int b);
int maximum(int a, int b);
int clamp(int value, int min, int max);
int raw_to_millivolts(int raw);
void print_measurement(int raw, int millivolts);

int add(int x, int y) {
  return x + y;
}

int maximum(int a, int b) {
   return (a > b) ? a : b;
}

int clamp(int value, int min, int max) {
  if (value > max) {
    return max;
  }
  if(value < min) {
    return min;
    }
  
  return value;
}

int raw_to_millivolts(int raw)
{
    return clamp(raw, 0, 4095) * 3300 / 4095;
}

void print_measurement(int raw, int millivolts);
{
  printf("raw = %d, millivolts = %d mV\n", raw, millivolts);
}
