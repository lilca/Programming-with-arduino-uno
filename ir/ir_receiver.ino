#define IRPIN 11
#define BUF_SIZE 200
#define TIME_OVER 30000
#define TERM 425

char val;
unsigned long scur, ecur;
unsigned long low[BUF_SIZE];
int fbit[20];
int bits[BUF_SIZE];
int bit_len;
int count;
int timeover;
unsigned char tmp;


int r0und(float src) {
  return (int)(src + TERM / 2) / TERM;
}

void output() {
  int idx;
  int top, bottom;
  char buf = 0;

  for (idx = 1; idx<count; idx++) { 
    top = r0und(low[idx]);
    idx++;
    bottom = r0und(low[idx]);
    if (top == 1) {
      if (bottom == 3) {
        bits[bit_len++] = 1;
      } else if (bottom == 1) {
        bits[bit_len++] = 0;
      } else {
        bits[bit_len++] = 5;
      }
    }
  }

  if (bit_len > 0)
    Serial.print("Code = ");
  for (idx = 0; idx<bit_len; idx++) {
    if (bits[idx] == 1) {
      buf = (buf << 1) | 0x01; 
    } else if (bits[idx] == 0) {
      buf = (buf << 1) | 0x00;
    } else {
      Serial.println(".");
      break;
    }
    if (idx % 4 == 3) {
      buf &= 0x0f;
      Serial.print(buf, HEX);
    }
  }
  if (bit_len > 0) {
    Serial.print("Bit data[");
    Serial.print(bit_len, DEC);
    Serial.print("] = ");
    for (idx = 0; idx<bit_len; idx++) {
      Serial.print(bits[idx], DEC);
    }
    Serial.println();
  }
  bit_len = 0;
}

void setup() {
  Serial.begin(57600);
  pinMode(IRPIN, INPUT);
  val = digitalRead(IRPIN);
  scur = 0;
  ecur = 0;
  count = 0;
  for (int idx = 0; idx<BUF_SIZE; idx++) {
    low[idx]= 0;
    bits[idx] = -1;
  }
  bit_len = 0;
  count = 0;
  timeover = TIME_OVER;
}

void recv(unsigned char tmp) {
  while (1) {
    if (val != tmp) {
      ecur = micros();
      low[count] = ecur - scur;
      count++;
      val = tmp;
      scur = ecur;
    }
    if (timeover <= 0) {
      return;
    }
    timeover--;
    tmp = digitalRead(IRPIN);
  }
}

void loop() {

  tmp = digitalRead(IRPIN);
  if (tmp == 1) {
    recv(tmp);
    output();
    timeover = TIME_OVER;
    count = 0;
    tmp = 0;
    delay(1000);
  }
}
