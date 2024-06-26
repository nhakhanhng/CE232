#include <stdio.h>
#include "mqtt.h"
#include "wifi_connect.h"
#include "ble_compatibility.h"

#include "nvs_flash.h"

void app_main(void)
{
    esp_err_t ret;

    /* Initialize NVS. */
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );
    /* Initialize the underlying TCP/IP stack */
    ESP_ERROR_CHECK(esp_netif_init());
    /* Create default event loop */
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    /* Creates default WIFI STA */
    esp_netif_create_default_wifi_sta();
    /* Initialize ble */
    ble_init();
    wifi_init_sta();
    mqtt_app_start();
}