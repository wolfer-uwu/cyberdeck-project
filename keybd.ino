#include <EasyHID.h>            //пасяба Алексу UwU "https://github.com/GyverLibs/EasyHID"
#include <Keypad.h>
const byte Row = 5;
const byte Col = 10;      //максимум 60 клавишь!!!!!
const char k5x10 [Row][Col] = {
  {'KEY_1', 'KEY_2', 'KEY_3', 'KEY_4', 'KEY_5', 'KEY_6', 'KEY_7', 'KEY_8', 'KEY_9', 'KEY_0'},
  {'KEY_Q', 'KEY_W', 'KEY_E', 'KEY_R', 'KEY_T', 'KEY_Y', 'KEY_U', 'KEY_I', 'KEY_O', 'KEY_P'},
  {'KEY_A', 'KEY_S', 'KEY_D', 'KEY_F', 'KEY_G', 'KEY_H', 'KEY_J', 'KEY_K', 'KEY_L', 'KEY_BACKSLASH'},
  {'KEY_Z', 'KEY_X', 'KEY_C', 'KEY_V', 'KEY_B', 'KEY_N', 'KEY_M', 'KEY_COMMA', 'KEY_PERIOD', 'KEY_SLASH'},
  {'KEY_ENTER', 'KEY_ESC', 'KEY_ALT', 'KEY_TAB', 'kEY_SPACE', 'KEY_SPACE', 'KEY_ARROW_LEFT', 'KEY_ARROW_UP', 'KEY_ARROW_DOWN', 'KEY_ARROW_RIGHT'}
};
byte rowPin[Row] = {3, 5, 6, 7, 8};                  //укажите любые пины, кроме D2 и D4 для строк
byte colPin[Col] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18};        //укажите любые пины, кроме D2 и D4 для столбцов
Keypad keypad = Keypad(makeKeymap(k5x10), rowPin, colPin, Row, Col);        //создается объект keypad, для упрощения работы с матричной клавиатурой
void setup() {
  HID.begin();        //инит HID шины
}

void loop() {
    static uint32_t timer = millis();      //DELAY не использовать!!! только millis!!!!!
  if (millis() - timer >= 1000) {
    timer = millis();
  }
  char key = keypad.getKey();
  if (key) {
    Keyboard.press(key);
    Keyboard.release(key);
  }
  HID.tick();
}

// код будет работать с любой простейшей матричной клавиатурой. в массиве можете указать нужные вам клавиши, а ниже, пины.
// совыетую подключать столбцы через диоды, воизбежания дребезга кнопок, но и без них работает.
