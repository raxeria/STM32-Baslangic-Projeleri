// POLIS CAKARI MODU (Police Strobe) 🚓🚨

#define RCC_AHB1ENR  (*((volatile unsigned int *)0x40023830))
#define GPIOD_MODER  (*((volatile unsigned int *)0x40020C00))
#define GPIOD_ODR    (*((volatile unsigned int *)0x40020C14))

int main(void) {
    // 1. D Portunu Aç
    RCC_AHB1ENR |= (1 << 3);

    // 2. Kırmızı(14) ve Mavi(15) LED'leri Çıkış Yap
    GPIOD_MODER |= (1 << 28) | (1 << 30);

    while (1) {
        // KIRMIZI YAK
        GPIOD_ODR = (1 << 14);
        for (int i = 0; i < 500000; i++); // Bekle

        // MAVİ YAK
        GPIOD_ODR = (1 << 15);
        for (int i = 0; i < 500000; i++); // Bekle
    }
}