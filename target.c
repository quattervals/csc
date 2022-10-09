#include <stdio.h>

#include "app/app_process.h"

int main() {
  printf("process_foo with input above threshold\n");
  app_process_foo(43);
  printf("process_foo with input below threshold\n");
  app_process_foo(41);

  const int threshold = 20;
  printf("algorithmFix with threshold %u is %u\n", threshold, app_process_algorithmFix(threshold));
  printf("algorithmDi with threshold %u is %u\n",
         threshold,
         app_process_algorithmDi(app_measurement_temperatureMeasurement, threshold));

  printf("Running app_process_setup\n");
  app_process_setup();

  return 0;
}
