// KARA SIMSEK MODU (Knight Rider) 🏎️💨

#define RCC_AHB1ENR  (*((volatile unsigned int *)0x40023830))
#define GPIOD_MODER  (*((volatile unsigned int *)0x40020C00))
#define GPIOD_ODR    (*((volatile unsigned int *)0x40020C14))

int main(void) {
    // 1. D Portunu Aç
    RCC_AHB1ENR |= (1 << 3);

    // 2. Tüm LED'leri (12,13,14,15) Çıkış Yap
    GPIOD_MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);

    while (1) {
        // İLERİ GİT (Yeşil -> Turuncu -> Kırmızı -> Mavi)
        for (int i = 12; i <= 15; i++) {
            GPIOD_ODR = (1 << i);
            for (int k = 0; k < 200000; k++);
        }

        // GERİ DÖN (Mavi -> Kırmızı -> Turuncu)
        for (int i = 14; i > 12; i--) {
            GPIOD_ODR = (1 << i);
            for (int k = 0; k < 200000; k++);
        }
    }
}