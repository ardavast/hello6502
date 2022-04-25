# hello6502

This is my attempt at replicating [Ben Eater](https://eater.net/)'s excellent
[6502 tutorial](https://www.youtube.com/playlist?list=PLowKtXNTBypFbtuVMUVXNR0z1mu7dp7eH)
without spending any money or dragging my lazy ass to the store.
I built it using only things I already have in my possession:
- [W65C02S](https://www.westerndesigncenter.com/wdc/w65c02s-chip.php) (Thanks [user890104](https://github.com/user890104)!)
- [Arduino Mega 2560 Rev3](http://store.arduino.cc/products/arduino-mega-2560-rev3)
- [PICDEM 2 Plus](https://www.microchip.com/en-us/development-tool/DM163022-1) (The only thing with an LCD display that I have)
- Breadboard, jumper wires

The 6502 is on the breadboard, the Arduino Mega below it acts like both ROM,
RAM and VIA and the PICDEM board has its PIC chip removed and is used only as
a passive connection from the Arduino to the LCD display on it.

| Arduino | 6502 |
|--------:|-----:|
|       2 |  RST |
|       3 |  CLK |
|       4 |  RWB |
|      A0 |   A0 |
|      A1 |   A1 |
|      A2 |   A2 |
|      A3 |   A3 |
|      A4 |   A4 |
|      A5 |   A5 |
|      A6 |   A6 |
|      A7 |   A7 |
|      A8 |   A8 |
|      A9 |   A9 |
|     A10 |  A10 |
|     A11 |  A11 |
|     A12 |  A12 |
|     A13 |  A13 |
|     A14 |  A14 |
|     A15 |  A15 |
|      22 |   D0 |
|      23 |   D1 |
|      24 |   D2 |
|      25 |   D3 |
|      26 |   D4 |
|      27 |   D5 |
|      28 |   D6 |
|      29 |   D7 |

| Arduino | LCD |
|--------:|----:|
|      31 |  RS |
|      32 | R/W |
|      33 |   E |
|      34 | DB3 |
|      35 | DB2 |
|      36 | DB1 |
|      37 | DB0 |
