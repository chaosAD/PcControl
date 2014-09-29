#include "unity.h"
#include "rs232.h"

void setUp(void) {}

void tearDown(void) {}

void test_RS232_OpenComport(void) {
  RS232_OpenComport(4, 9600);
  RS232_SendByte(4, 0x6a);
}
