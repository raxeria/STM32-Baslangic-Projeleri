// Basit Yeşil LED Yak-Söndür
#define RCC_AHB1ENR  (*((volatile unsigned int *)0x40023830))
#define GPIOD_MODER  (*((volatile unsigned int *)0x40020C00))
#define GPIOD_ODR    (*((volatile unsigned int *)0x40020C14))

int main(void) {
    RCC_AHB1ENR |= (1 << 3);      // D Portunu Aç
    GPIOD_MODER |= (1 << 24);     // PD12 (Yeşil) Çıkış Yap
    while (1) {
        GPIOD_ODR ^= (1 << 12);   // Yan/Sön
        for (int i = 0; i < 1000000; i++); // Bekle
    }
}