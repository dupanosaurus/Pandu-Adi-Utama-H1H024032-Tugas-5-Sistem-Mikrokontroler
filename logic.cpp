// Definisi Pin

// Kendaraan
int MerahK = 13;
int KuningK = 12;
int HijauK = 11;

// Pedestrian 1
int MerahP1 = 10;
int HijauP1 = 9;

// Pedestrian 2
int MerahP2 = 8;
int HijauP2 = 7;

// Tombol
int tombol = 2;

// Setup
void setup() {
  pinMode(MerahK, OUTPUT);
  pinMode(KuningK, OUTPUT);
  pinMode(HijauK, OUTPUT);

  pinMode(MerahP1, OUTPUT);
  pinMode(HijauP1, OUTPUT);

  pinMode(MerahP2, OUTPUT);
  pinMode(HijauP2, OUTPUT);

  pinMode(tombol, INPUT);

  kondisiAwal();
}

// Looping
void loop() {
  if (digitalRead(tombol) == HIGH) {
    penyebrangan();
  }
}

// Fungsi Modular

// Kondisi awal
void kondisiAwal() {
  // Kendaraan hijau
  digitalWrite(HijauK, HIGH);
  digitalWrite(KuningK, LOW);
  digitalWrite(MerahK, LOW);

  // Pedestrian merah
  digitalWrite(MerahP1, HIGH);
  digitalWrite(HijauP1, LOW);

  digitalWrite(MerahP2, HIGH);
  digitalWrite(HijauP2, LOW);
}

// Fungsi penyebrangan
void penyebrangan() {

  // Kendaraan merah
  digitalWrite(HijauK, LOW);
  digitalWrite(KuningK, LOW);
  digitalWrite(MerahK, HIGH);

  // Pedestrian hijau
  digitalWrite(MerahP1, LOW);
  digitalWrite(HijauP1, HIGH);

  digitalWrite(MerahP2, LOW);
  digitalWrite(HijauP2, HIGH);

  delay(5000); // waktu nyebrang

  // Pedestrian merah lagi
  digitalWrite(MerahP1, HIGH);
  digitalWrite(HijauP1, LOW);

  digitalWrite(MerahP2, HIGH);
  digitalWrite(HijauP2, LOW);

  // Kendaraan kuning kedip 3x
  digitalWrite(MerahK, LOW);
  for(int i=0;i<3;i++){
    digitalWrite(KuningK, HIGH);
    delay(333);
    digitalWrite(KuningK, LOW);
    delay(333);
  }

  // Kembali ke kondisi awal
  kondisiAwal();
}