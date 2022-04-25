const int reset = 3;
const int clk = 2;
const int rw = 4;

#define RW_R 1
#define RW_W 0

#define DDR_IN 0x00
#define DDR_OUT 0xff

#define DDR_ADDR_LO DDRF
#define DDR_ADDR_HI DDRK

#define DDR_DATA DDRA
#define DATA_IN PINA
#define DATA_OUT PORTA

#define DDR_LED DDRC
#define LED_IN PINC
#define LED_OUT PORTC

extern const byte rom0[];
extern const byte rom1[];
byte ram[2048];

word get_addr(void) {
  word addr;

  addr = PINF;
  addr |= (word)PINK << 8;

  return addr;
}

void clk_wait() {
  delay(5);
}

void clk_low() {
  digitalWrite(clk, LOW);
}

void clk_high() {
  digitalWrite(clk, HIGH);
}

void setup() {
  pinMode(reset, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(rw, INPUT);

  DDR_ADDR_LO = DDR_IN;
  DDR_ADDR_HI = DDR_IN;
  DDR_DATA = DDR_IN;

  clk_high();

  digitalWrite(reset, LOW);
  clk_wait();
  for (int i = 0; i < 2; i++) {
    clk_low();
    clk_wait();
    clk_high();
    clk_wait();
  }
  digitalWrite(reset, HIGH);
  for (int i = 0; i < 6; i++) {
    clk_low();
    clk_wait();
    clk_high();
    clk_wait();
  }
}

void loop() {
  char buf[10];

  DDR_DATA = DDR_IN;

  clk_low();
  clk_wait();

  byte op = digitalRead(rw);
  word addr = get_addr();

  if (op == RW_R) {
    if (addr >= 0xc000) {
      DATA_OUT = pgm_read_byte(rom1 + (addr - 0xc000));
      DDR_DATA = DDR_OUT;
    } else if (addr >= 0x8000) {
      DATA_OUT = pgm_read_byte(rom0 + (addr - 0x8000));
      DDR_DATA = DDR_OUT;
    } else if (addr == 0x6001) {
      DATA_OUT = LED_IN;
      DDR_DATA = DDR_OUT;
    } else if (addr == 0x6003) {
      DATA_OUT = DDR_LED;
      DDR_DATA = DDR_OUT;
    } else if (addr >= 0 && addr < 0x200) {
      DDR_DATA = DDR_OUT;
      DATA_OUT = ram[addr];
    }
    clk_high();
  } else {
    // clk_high() must be as close as possible to the data read.
    // Putting it here results in wrong timing.
    if (addr >= 0 && addr < 0x200) {
      clk_high();
      ram[addr] = DATA_IN;
    } else if (addr == 0x6001) {
      clk_high();
      LED_OUT = DATA_IN;
    } else if (addr == 0x6003) {
      clk_high();
      DDR_LED = DATA_IN;
    } else {
      clk_high();
    }
  }

  clk_wait();
}
