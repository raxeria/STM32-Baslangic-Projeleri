// NEFES ALAN LED (Software PWM) 🌬️🧡

#define RCC_AHB1ENR  (*((volatile unsigned int *)0x40023830))
#define GPIOD_MODER  (*((volatile unsigned int *)0x40020C00))
#define GPIOD_ODR    (*((volatile unsigned int *)0x40020C14))

int main(void) {
    // 1. D Portunu Aç
    RCC_AHB1ENR |= (1 << 3);

    // 2. Turuncu LED'i (PD13) Çıkış Yap
    GPIOD_MODER |= (1 << 26);

    int parlaklik = 0;
    int artis = 5;

    while (1) {
        // PWM Döngüsü (Göz Yanılması)
        for (int i = 0; i < 1000; i++) {
            if (i < parlaklik) GPIOD_ODR = (1 << 13); // Yak
            else GPIOD_ODR = 0;         // Söndür
        }

        // Parlaklığı Ayarla
        parlaklik += artis;
        if (parlaklik >= 1000 || parlaklik <= 0) artis = -artis; // Yön çevir

        for(int k=0; k<1000; k++); // Biraz bekle
    }
}