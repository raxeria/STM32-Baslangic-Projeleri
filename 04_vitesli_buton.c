// VITESLI BUTON SISTEMI (State Machine) 🔘🕹️

#define RCC_AHB1ENR  (*((volatile unsigned int *)0x40023830))
#define GPIOD_MODER  (*((volatile unsigned int *)0x40020C00))
#define GPIOD_ODR    (*((volatile unsigned int *)0x40020C14))
#define GPIOA_IDR    (*((volatile unsigned int *)0x40020010))

int main(void) {
    // 1. A (Buton) ve D (LED) Portlarını Aç
    RCC_AHB1ENR |= 0x09; 

    // 2. LED'leri Çıkış Yap
    GPIOD_MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);

    int vites = 0;

    while (1) {
        // Butona basıldı mı?
        if (GPIOA_IDR & 0x01) {
            for(int i=0; i<50000; i++); // Titreşimi bekle (Debounce)
            
            if (GPIOA_IDR & 0x01) { // Hala basılı mı?
                vites++;
                if (vites > 4) vites = 0; // 4'ten sonra başa dön
                
                while(GPIOA_IDR & 0x01); // Parmağını çekene kadar bekle!
            }
        }

        // Işıkları Yak
        GPIOD_ODR = 0; // Önce temizle
        if (vites == 1) GPIOD_ODR = (1 << 12); // Yeşil
        if (vites == 2) GPIOD_ODR = (1 << 13); // Turuncu
        if (vites == 3) GPIOD_ODR = (1 << 14); // Kırmızı
        if (vites == 4) GPIOD_ODR = (1 << 15); // Mavi
    }
}