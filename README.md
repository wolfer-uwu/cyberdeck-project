# hacingdeck

!НА МОМЕНТ СОЗДАНИЯ СТРАНИЦЫ НА ГИТХАБ ПРОЭКТ ТОЛЬКО НА СТАДИИ КОНЦЕПТА!

## Задумка:

Создать устройство с защищенным GPIO для {} в удобном, небольшом корпусе, полноценной(на сколько это возможно) клавиатурой, сенсорным дисплеем, и саме главное - все компоненты должны быть со открытым исходным кодом!

!FAIL!

Изначальная попытка реализации:
Разработать плату для Allwinner fc200s, и написать свою ос.

!FAIL!(~~fc200s пропал из продажи~~ снова появился, но работать с ним уже не хочу)

### ЧТО НА ДАННЫЙ МОМЕНТ

-> Решил использовать готовый opensource одноплатник orange pi zero 2w (z3(maybe =]))

~~-> Для создания клавиатуры было решено использовать STM32~~

-> Для клавиатуры взял ~~Atmega328p(использую библитоеку https://github.com/GyverLibs/EasyHID)~~ Atmega32u

-> Использую отдельный контроллер питания!

#### СОСТОЯНИЕ ПРОЭКТА:

ГОТОВО
+ ПРОЭКТ НАЧАТ
+ ГОТОВ КОНЦЕПТ
+ ЗАКУПЛЕНЫ ВСЕ МАТЕРИАЛЫ
+ СХЕМА
+ КЛАВИАТУРА

В ПРОЦЕССЕ
- ЗАЩИТА GPIO
- КОРПУС
- ПРОТОТИП
- ПО
