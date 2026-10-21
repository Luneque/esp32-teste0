#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

void app_main(void)
{
    printf("\n========================================\n");
    printf("   Hello World - ESP32 Projeto Teste0   \n");
    printf("========================================\n\n");

    /* Obter informacoes do chip */
    esp_chip_info_t chip_info;
    uint32_t flash_size = 0;
    esp_chip_info(&chip_info);

    printf("Chip: %s\n", CONFIG_IDF_TARGET);
    printf("Nucleos de CPU: %d core(s)\n", chip_info.cores);
    printf("Recursos: %s%s%s%s\n",
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi " : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "Bluetooth " : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE " : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? "802.15.4 " : "");

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("Revisao do Silicio: v%d.%d (ECO%d)\n", major_rev, minor_rev, major_rev);

    if (esp_flash_get_size(NULL, &flash_size) == ESP_OK) {
        printf("Tamanho da Flash SPI: %" PRIu32 " MB (%s)\n",
               flash_size / (uint32_t)(1024 * 1024),
               (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embutida" : "externa");
    }

    printf("Heap livre minimo: %" PRIu32 " bytes\n\n", esp_get_minimum_free_heap_size());
    printf("Sistema iniciado com sucesso e operando normalmente!\n");
    printf("----------------------------------------\n\n");

    int counter = 0;
    while (1) {
        printf("[Status] Placa ativa e funcionando! Contador: %d (Uptime: %lu s)\n",
               counter++, (unsigned long)(xTaskGetTickCount() * portTICK_PERIOD_MS / 1000));
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
