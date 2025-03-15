#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 5; // 5 рядов
const byte COLS = 10; // 10 столбцов

// массив раскладки
char keys[ROWS][COLS] = {
  {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
  {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
  {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '?'},
  {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'},
  {'\n', 27, 'KEY_LEFT_CTRL', KEY_CAPS_LOCK, ' ', ' ', KEY_CAPS_LOCK, KEY_BACKSPACE, KEY_LEFT_ALT, KEY_TAB}
};

byte rowPins[ROWS] = {2, 3, 4, 5, 6}; // Ряды
byte colPins[COLS] = {7, 8, 9, 10, 16, 14, 15, 18, 19, 20}; // Столбцы

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Keyboard.begin(); // Начинаем использование библиотеки Keyboard
}

void loop() {
  char key = keypad.getKey(); // Получаем нажатую клавишу

  if (key) { // Если клавиша нажата
    if (key == '\n') {
      Keyboard.press(KEY_RETURN); // Нажимаем ENTER
      Keyboard.release(KEY_RETURN);
    } else if (key == 27) { // ESC
      Keyboard.press(KEY_ESC);
      Keyboard.release(KEY_ESC);
    } else if (key == 'KEY_LEFT_CTRL') {
      Keyboard.press(KEY_LEFT_CTRL);
    } else {
      Keyboard.press(key); // Нажимаем кнопку
      Keyboard.release(key); // Отпускаем кнопку
    }
  }
}
