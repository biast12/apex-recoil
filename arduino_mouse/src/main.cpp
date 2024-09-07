#include <Mouse.h>
#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

float scale = 1.0;
const int invert = 1;  // Or -1.
const int BTN_1 = 4;
const int MAX_LENGTH = 55;

String name = "?";
float mx[MAX_LENGTH];
float my[MAX_LENGTH];
long mt[MAX_LENGTH];
long n = 27 ;

const int RECOILS_LENGTH = 13;

int current_recoil = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void init_recoil() {
if (current_recoil == 0) {
  name = "r301";
  float x[28] =  { 0,12.2,10.5,25.0,21.9,25.1,24.6,25.3,34.4,42.6,56.4,60.6,50.4,36.3,23.9,10.4,-4.4,-15.3,-20.7,-18.0,-7.5,1.7,14.2,22.8,33.0,42.9,46.2,43.0 };
  float y[28] =  { 0,-27.6,-63.5,-87.2,-117.6,-141.3,-153.3,-164.5,-168.1,-176.7,-171.8,-182.2,-197.6,-211.1,-216.2,-220.9,-216.2,-217.7,-230.5,-243.1,-253.1,-253.4,-256.1,-256.9,-254.9,-258.7,-266.6,-272.9 };
  int t[28] =  { 0,74,148,222,296,370,444,519,593,667,741,815,889,963,1037,1111,1185,1259,1333,1407,1481,1556,1630,1704,1778,1852,1926,2000 };
  n = 28 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 1) {
  name = "flatline";
  float x[30] =  { 0,-9.4,-10.8,-31.4,-45.7,-52.0,-53.6,-42.4,-21.3,-13.6,-5.1,2.2,-10.7,-36.3,-50.8,-76.5,-86.4,-89.2,-93.0,-111.3,-134.1,-144.1,-144.4,-128.4,-116.5,-98.4,-78.5,-60.5,-55.0,-46.4 };
  float y[30] =  { 0,-49.7,-66.8,-94.4,-113.8,-140.3,-166.9,-176.8,-173.3,-169.4,-180.8,-202.5,-210.0,-224.6,-230.8,-227.7,-232.8,-259.0,-284.5,-294.5,-299.9,-302.6,-318.1,-327.7,-333.6,-342.6,-349.6,-343.7,-357.0,-375.3 };
  int t[30] =  { 0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900 };
  n = 30 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 2) {
  name = "r99";
  float x[27] =  { 0,5.0,3.7,-2.3,4.2,11.0,25.1,43.7,49.6,49.6,38.2,23.7,20.4,17.9,21.1,33.8,46.8,57.6,44.8,30.7,13.2,-3.0,-13.6,1.0,15.9,30.4,37.2 };
  float y[27] =  { 0,-22.4,-42.0,-59.5,-93.4,-133.0,-167.6,-192.2,-218.7,-243.9,-269.4,-297.4,-321.0,-341.7,-355.6,-361.2,-369.4,-369.4,-378.8,-382.3,-386.0,-396.9,-402.7,-402.4,-403.8,-402.9,-404.8 };
  int t[27] =  { 0,56,111,167,222,278,333,389,444,500,556,611,667,722,778,833,889,944,1000,1056,1111,1167,1222,1278,1333,1389,1444 };
  n = 27 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 3) {
  name = "volt";
  float x[26] =  { 0,11.2,13.8,10.4,21.2,20.5,39.3,44.7,35.0,46.2,44.6,28.5,8.0,-5.1,-17.4,-12.8,0.5,10.0,5.9,-3.1,-12.9,-21.1,-23.1,-23.1,-24.9,-26.3 };
  float y[26] =  { 0,-28.6,-64.0,-106.9,-128.8,-177.8,-205.6,-248.3,-279.3,-312.2,-333.8,-339.7,-336.4,-350.0,-365.8,-376.8,-377.4,-379.0,-388.2,-395.3,-399.4,-398.7,-401.0,-407.5,-414.0,-427.0 };
  int t[26] =  { 0,83,167,250,333,417,500,583,667,750,833,917,1000,1083,1167,1250,1333,1417,1500,1583,1667,1750,1833,1917,2000,2083 };
  n = 26 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 4) {
  name = "alternator";
  float x[27] =  { 0,-7.7,5.3,-7.8,4.7,-10.0,2.9,-5.0,14.6,0.9,25.6,11.1,34.2,29.4,41.4,20.3,25.9,6.7,23.4,-2.4,4.7,-17.6,-3.6,-28.7,-18.4,-31.5,-26.2 };
  float y[27] =  { 0,-39.5,-70.1,-104.9,-137.1,-174.5,-207.4,-235.8,-259.1,-293.3,-314.2,-337.3,-345.6,-354.8,-365.3,-390.0,-412.1,-421.1,-443.1,-441.4,-463.4,-458.6,-473.4,-476.7,-488.0,-494.5,-498.2 };
  int t[30] =  { 0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900 };
  n = 27 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 5) {
  name = "devotion_tc";
  float x[48] =  { 0,-1.7,-2.0,-3.2,-8.8,-16.6,-25.1,-33.4,-48.4,-55.8,-64.7,-77.3,-90.7,-106.4,-125.6,-143.3,-153.6,-168.7,-167.4,-166.5,-155.9,-145.1,-132.7,-115.7,-97.3,-89.2,-89.9,-86.2,-75.7,-63.4,-47.5,-32.9,-19.4,-5.7,4.6,9.7,15.2,11.9,9.5,13.6,20.5,29.3,33.2,33.5,25.6,14.3,2.3,-13.0 };
  float y[48] =  { 0,-86.2,-171.8,-226.6,-283.5,-327.3,-361.1,-391.7,-407.1,-428.3,-445.6,-464.8,-477.5,-485.7,-488.7,-490.8,-485.4,-490.0,-503.3,-518.3,-529.6,-536.2,-544.7,-552.7,-563.0,-571.9,-582.7,-596.8,-607.6,-616.2,-621.2,-618.8,-618.9,-628.9,-637.4,-648.8,-658.2,-666.6,-677.4,-688.7,-695.7,-699.6,-705.6,-712.9,-717.6,-739.9,-754.4,-762.6 };
  int t[48] =  { 0,150,270,377,475,564,646,722,792,858,925,991,1057,1123,1189,1255,1321,1388,1454,1520,1586,1652,1718,1784,1851,1917,1983,2049,2115,2181,2248,2314,2380,2446,2512,2578,2644,2711,2777,2843,2909,2975,3041,3108,3174,3240,3306,3372 };
  n = 48 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 6) {
  name = "havoc_tc";
  float x[36] =  { 0,16.4,40.1,31.3,34.7,28.1,15.4,10.7,-3.2,-9.5,-6.2,6.7,23.2,39.0,57.3,66.2,60.6,50.9,35.4,21.4,10.4,-4.9,-6.6,-0.0,-6.9,-16.2,-16.5,-29.0,-47.2,-58.7,-72.4,-73.8,-68.9,-65.0,-69.4,-58.8 };
  float y[36] =  { 0,-38.2,-91.5,-137.8,-180.6,-207.4,-225.5,-254.2,-276.0,-298.6,-317.0,-326.3,-336.7,-331.1,-330.6,-355.1,-369.1,-375.8,-386.4,-381.9,-385.2,-391.0,-416.1,-446.2,-464.2,-481.5,-510.3,-536.0,-550.6,-568.9,-587.1,-608.6,-630.3,-651.0,-671.1,-687.2 };
  int t[36] =  { 0,91,182,273,365,456,547,638,729,820,912,1003,1094,1185,1276,1367,1459,1550,1641,1732,1823,1914,2006,2097,2188,2279,2370,2461,2553,2644,2735,2826,2917,3008,3100,3191 };
  n = 36 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 7) {
  name = "prowler";
  float x[35] =  { 0,-10.2,-11.6,-9.9,-11.5,-33.2,-43.6,-46.6,-58.0,-62.2,-77.1,-85.1,-82.5,-73.6,-45.0,-18.1,-7.6,7.5,-2.5,-0.7,16.3,18.2,22.1,7.8,-7.0,-14.5,-14.1,2.5,24.6,41.4,59.4,66.7,84.9,85.4,76.8 };
  float y[35] =  { 0,-43.4,-66.8,-99.0,-118.8,-141.5,-166.0,-189.6,-211.3,-234.6,-248.4,-263.9,-281.4,-296.0,-299.8,-308.3,-316.9,-329.3,-347.7,-369.5,-388.2,-404.5,-420.4,-429.4,-438.6,-455.2,-461.6,-473.2,-473.2,-474.6,-481.1,-488.5,-503.3,-514.6,-527.4 };
  int t[35] =  { 0,75,150,226,301,377,452,528,603,679,754,830,905,981,1056,1132,1207,1283,1358,1433,1509,1584,1660,1735,1811,1886,1962,2037,2113,2188,2264,2339,2415,2490,2566 };
  n = 35 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 8) {
  name = "re45";
  float x[25] =  { 0,3.8,7.0,22.5,31.4,40.4,61.9,75.6,96.3,115.1,128.2,140.6,137.9,152.7,154.7,162.5,159.2,170.9,177.6,191.6,182.0,193.9,202.6,216.8,225.8 };
  float y[25] =  { 0,-29.4,-56.4,-82.8,-114.0,-140.4,-163.8,-177.4,-194.7,-207.4,-223.6,-234.5,-248.6,-265.0,-279.3,-297.0,-315.2,-329.6,-339.0,-343.4,-351.7,-358.5,-372.0,-379.2,-390.0 };
  int t[25] =  { 0,76,153,230,307,384,461,538,615,692,769,846,923,1000,1076,1153,1230,1307,1384,1461,1538,1615,1692,1769,1846 };
  n = 25 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 9) {
  name = "spitfire";
  float x[55] =  { 0,-2.1,-4.8,-17.1,-24.8,-30.4,-30.4,-24.5,-13.4,-10.5,-5.8,-3.1,-10.2,-24.1,-33.6,-46.6,-53.0,-58.1,-63.0,-73.1,-85.0,-90.8,-88.2,-77.3,-70.1,-59.7,-48.7,-36.8,-32.9,-27.0,-26.4,-13.4,-8.7,-3.4,0.6,-6.1,-19.4,-25.0,-38.4,-45.7,-47.4,-51.3,-61.0,-73.1,-78.5,-75.8,-67.2,-61.4,-50.3,-39.7,-27.7,-23.6,-17.1,-17.6,-3.3 };
  float y[55] =  { 0,-35.4,-47.7,-69.2,-84.4,-105.3,-128.2,-135.1,-131.3,-128.0,-134.7,-150.5,-156.2,-166.2,-170.3,-166.2,-169.8,-188.1,-204.6,-213.7,-217.0,-218.2,-230.6,-236.7,-241.6,-247.7,-252.3,-245.7,-256.0,-269.6,-278.0,-274.4,-269.6,-276.2,-290.2,-293.2,-303.7,-305.8,-300.6,-302.7,-321.3,-340.0,-351.8,-355.8,-357.6,-371.9,-381.2,-388.3,-397.7,-403.3,-398.6,-410.3,-424.8,-437.8,-435.1 };
  int t[55] =  { 0,111,222,333,444,555,666,777,888,1000,1111,1222,1333,1444,1555,1666,1777,1888,2000,2111,2222,2333,2444,2555,2666,2777,2888,3000,3111,3222,3333,3444,3555,3666,3777,3888,4000,4111,4222,4333,4444,4555,4666,4777,4888,5000,5111,5222,5333,5444,5555,5666,5777,5888,6000 };
  n = 55 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 10) {
  name = "lstar";
  float x[28] =  { 0,-26.7,-69.7,-99.3,-88.9,-73.1,-61.2,-44.6,-42.4,-40.3,-43.9,-34.3,-36.0,-35.0,-25.1,-23.4,-19.5,-26.2,-32.7,-29.5,-23.1,-23.1,-14.0,-6.2,-9.4,-13.0,-17.2,1.4 };
  float y[28] =  { 0,-27.9,-39.7,-82.4,-117.8,-128.5,-151.2,-194.1,-228.4,-252.9,-282.0,-310.9,-337.6,-365.3,-391.6,-417.6,-442.1,-464.4,-482.9,-495.3,-515.4,-540.6,-560.1,-580.7,-601.7,-622.2,-642.7,-671.8 };
  int t[28] =  { 0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700 };
  n = 26 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 11) {
  name = "rampage";
  float x[40] =  { 0,5.6,-16.9,-25.9,-10.1,-7.5,4.5,17.6,34.8,44.7,48.7,30.7,12.3,-0.2,-15.9,-28.7,-40.7,-39.0,-32.1,-40.7,-33.2,-40.7,-48.4,-40.5,-49.5,-57.6,-49.1,-61.1,-73.1,-83.4,-80.8,-72.9,-79.1,-72.0,-77.7,-86.2,-79.1,-89.3,-99.5,-92.5 };
  float y[40] =  { 0,-33.5,-53.5,-87.6,-111.2,-149.2,-176.0,-195.0,-213.1,-229.5,-251.2,-262.8,-277.0,-294.5,-298.0,-308.1,-320.7,-335.1,-345.2,-354.6,-367.0,-379.7,-391.9,-408.9,-420.8,-433.5,-450.5,-470.0,-488.9,-508.2,-530.5,-547.8,-562.0,-576.1,-591.6,-605.5,-622.9,-631.4,-639.4,-650.0 };
  int t[40] =  { 0,200,400,600,800,1000,1200,1400,1600,1800,2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000,4200,4400,4600,4800,5000,5200,5400,5600,5800,6000,6200,6400,6600,6800,7000,7200,7400,7600,7800 };
  n = 40 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
if (current_recoil == 12) {
  name = "car";
  float x[27] =  { 0,-4.5,-16.0,-14.8,-31.5,-32.9,-45.7,-61.0,-59.0,-39.0,-35.1,-25.5,-4.6,9.5,12.3,-5.7,-31.5,-46.0,-43.2,-29.2,-16.1,4.5,8.5,8.1,-0.7,-13.2,-17.2 };
  float y[27] =  { 0,-33.7,-60.6,-92.6,-123.8,-153.2,-188.9,-213.2,-250.4,-285.1,-322.7,-333.2,-332.2,-335.6,-351.1,-366.1,-364.0,-375.8,-388.7,-395.2,-397.4,-396.9,-399.0,-409.4,-424.0,-432.5,-448.0 };
  int t[27] =  { 0,64,129,193,258,322,387,451,516,580,645,709,774,838,903,967,1032,1096,1161,1225,1290,1354,1419,1483,1548,1612,1677 };
  n = 27 ;
  for (int i = 0; i < n; i++) { mx[i] = x[i]; my[i] = y[i]; mt[i] = t[i]; }
}
}

void setup() {

//   Serial.begin( 115200 );
// #if !defined(__MIPSEL__)
//   while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
// #endif
//   Serial.println("Start");  
  // Wire.begin();
  lcd.init();
  lcd.home();
  lcd.backlight();
  lcd.setCursor(0,0);
  init_recoil();
  lcd.print(name);
  lcd.setCursor(0, 1);
  lcd.print(String(current_recoil));
  Mouse.begin();
  pinMode(BTN_1, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  Mouse.begin();
}


long start_time = 0;
bool shooting = false;
long idx = 0; // Index of the point we currently moving from;
long mouse_x = 0;
long mouse_y = 0; 
long signals = 0;

void move() {
  // auto& r = recoils[current_recoil];
  long t = millis() - start_time;
  while (idx + 1 < n && mt[idx + 1] <= t) {
    idx++;
    // Serial.println(String("shot ") + String(idx + 1));
  }
  if (idx + 1 >= n) {
    // Serial.println(String(signals) + " finished");    
    shooting = false;
    current_recoil = (current_recoil + 1) % RECOILS_LENGTH;
    init_recoil();
    lcd.home();
    lcd.clear();    
    lcd.print(name);
    lcd.setCursor(0, 1);
    lcd.print(String(current_recoil));
    delay(50);
    Mouse.release(MOUSE_LEFT);
    delay(10);
    Mouse.release(MOUSE_RIGHT);
    return;
  }
  float p = (1.0 * (t - mt[idx])) / (mt[idx + 1] - mt[idx]);
  if (p < 0) p = 0;
  if (p > 1) p = 1;
  long x = -round(scale * (mx[idx] + p * (mx[idx + 1] - mx[idx])));
  long y = - invert * round(scale * (my[idx] + p * (my[idx + 1] - my[idx])));
  if (x != mouse_x || y != mouse_y) {
    // Serial.println(String(t) + " " + String(p) + ": (" + String(x) + "," + String(y)  + ") d (" + String(x - mouse_x) + "," + String(y - mouse_y) + ")");
    Mouse.move(x - mouse_x, y - mouse_y, 0);
    signals++;
    mouse_x = x;
    mouse_y = y;
  }
}

const float circle_speed = 3 * 2 * 3.141 / 1000;
const float radius = 40.0;

int scale_modifer = 0;

void loop()
{
    if (shooting) move();
    // if (shooting) move_line();
    if (digitalRead(BTN_1) == HIGH) {
      if (!shooting) {
        // Serial.println(String("scale ") + String(scale));
        lcd.clear();
        lcd.home();
        lcd.print("running..");
        shooting = true;
        idx = 0;
        mouse_x = 0;
        mouse_y = 0;
        signals = 0;
        Mouse.press(MOUSE_RIGHT);
        delay(700);
        Mouse.press(MOUSE_LEFT);
        // Serial.println(String("shot ") + String(idx + 1));
        start_time = millis();
      }
    }
    // if (digitalRead(5) == HIGH) {
          // scale = 5 * (1.0 - (scale_modifer - 1) * 0.02);
      // Serial.println(String("scale ") + String(scale));
      // scale_modifer = (scale_modifer + 1) % 3;
      // delay(1000);
      // Serial.println(">>>");
      // Mouse.move(-1,0,0); 
    // }
}